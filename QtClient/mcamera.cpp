#include "mcamera.h"
#include <QDebug>
using namespace cv;
MCamera::MCamera(QObject *parent) : QObject(parent)
{
    CameraSdkInit(1);

    //枚举设备，并建立设备列表
    iStatus = CameraEnumerateDevice(&tCameraEnumList,&iCameraCounts);
    printf("state = %d\n", iStatus);

    printf("count = %d\n", iCameraCounts);
    //没有连接设备
    if(iCameraCounts==0){
        qDebug() << "没有连接设备";
        exit(1);
    }

    //相机初始化。初始化成功后，才能调用任何其他相机相关的操作接口
    iStatus = CameraInit(&tCameraEnumList,-1,-1,&hCam);

    //初始化失败
    printf("state = %d\n", iStatus);
    if(iStatus!=CAMERA_STATUS_SUCCESS){
        qDebug() << "初始化失败";
        exit(1);
    }

    //获得相机的特性描述结构体。该结构体中包含了相机可设置的各种参数的范围信息。决定了相关函数的参数
    CameraGetCapability(hCam,&tCapability);
    //
    g_pRgbBuffer = (unsigned char*)malloc(tCapability.sResolutionRange.iHeightMax*tCapability.sResolutionRange.iWidthMax*3);
    //g_readBuf = (unsigned char*)malloc(tCapability.sResolutionRange.iHeightMax*tCapability.sResolutionRange.iWidthMax*3);

    /*让SDK进入工作模式，开始接收来自相机发送的图像
        数据。如果当前相机是触发模式，则需要接收到
        触发帧以后才会更新图像。    */
    CameraPlay(hCam);

    /*其他的相机参数设置
        例如 CameraSetExposureTime   CameraGetExposureTime  设置/读取曝光时间
             CameraSetImageResolution  CameraGetImageResolution 设置/读取分辨率
             CameraSetGamma、CameraSetConrast、CameraSetGain等设置图像伽马、对比度、RGB数字增益等等。
             更多的参数的设置方法，，清参考MindVision_Demo。本例程只是为了演示如何将SDK中获取的图像，转成OpenCV的图像格式,以便调用OpenCV的图像处理函数进行后续开发
        */

    if(tCapability.sIspCapacity.bMonoSensor){
        channel=1;
        CameraSetIspOutFormat(hCam,CAMERA_MEDIA_TYPE_MONO8);
    }else{
        channel=3;
        CameraSetIspOutFormat(hCam,CAMERA_MEDIA_TYPE_BGR8);
    }
}
void MCamera::getFrame(cv::Mat & _dst)
{
    if(CameraGetImageBuffer(hCam,&sFrameInfo,&pbyBuffer,5000) == CAMERA_STATUS_SUCCESS)
    {

        CameraImageProcess(hCam, pbyBuffer, g_pRgbBuffer,&sFrameInfo);

        if (iplImage)
        {
            cvReleaseImageHeader(&iplImage);
        }
        iplImage = cvCreateImageHeader(cvSize(sFrameInfo.iWidth,sFrameInfo.iHeight),IPL_DEPTH_8U,channel);
        cvSetData(iplImage,g_pRgbBuffer,sFrameInfo.iWidth*channel);//此处只是设置指针，无图像块数据拷贝，不需担心转换效率
        Mat Iimag(iplImage);
        _dst = Iimag;
//        imshow("OpenCV Demo",Iimag);
//        waitKey(100000);

        //在成功调用CameraGetImageBuffer后，必须调用CameraReleaseImageBuffer来释放获得的buffer。
        //否则再次调用CameraGetImageBuffer时，程序将被挂起一直阻塞，直到其他线程中调用CameraReleaseImageBuffer来释放了buffer
        CameraReleaseImageBuffer(hCam,pbyBuffer);
    }
    else
        qDebug() << "test2";
}
MCamera::~MCamera()
{
    CameraUnInit(hCam);
    //注意，现反初始化后再free
    free(g_pRgbBuffer);
}
