#ifndef MCAMERA_H
#define MCAMERA_H

#include <QObject>
#include "CameraApi.h" //相机SDK的API头文件
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>

class MCamera : public QObject
{
    Q_OBJECT
public:
    explicit MCamera(QObject *parent = nullptr);
    ~MCamera();
    void getFrame(cv::Mat & _dst);

    /*
     * bAuto      TRUE，则表示使能自动模式。
     * FALSE，则表示使用手动模式，通过调用
     * setWhiteBlance()
     */
    void setWhiteBlanceMode(BOOL bAuto)
    {
        CameraSetWbMode(hCam , bAuto);
    }
    void setWhiteBlance()
    {
        CameraSetOnceWB(hCam);
    }
    int                     hCam;
signals:

public slots:
private:
    unsigned char           * g_pRgbBuffer;     //处理后数据缓存区
    int                     iCameraCounts = 1;
    int                     iStatus=-1;
    tSdkCameraDevInfo       tCameraEnumList;
    tSdkCameraCapbility     tCapability;      //设备描述信息
    tSdkFrameHead           sFrameInfo;
    BYTE*			        pbyBuffer;
    IplImage *iplImage = NULL;
    int                     channel=3;
};

#endif // MCAMERA_H
