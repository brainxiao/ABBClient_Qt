#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
#include <QtNetwork>
//using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cam = new MCamera;
    actionOpenCam = new QAction(this);
    camIcon = new QIcon(":/Icon/image/cam.jpg");
    qImg = new QImage();
    timer = new QTimer(this);
    camLabel = new QLabel(this);
    SocketToABB = new QTcpSocket(this);
    SocketToServer = new QTcpSocket(this);

    actionOpenCam -> setObjectName("OpenCam");
    actionOpenCam -> setIcon(*camIcon);
    ui -> mainToolBar ->addAction(actionOpenCam);
    camLabel->move(5,65);
    camLabel->resize(320,240);
    camLabel->setStyleSheet("background-color: rgb(170, 85, 127);");
    camLabel->setScaledContents(true);
    ui -> lineEdit_ABBAddr -> setText("192.168.1.99");
    ui -> lineEdit_ABBPort -> setText("2099");
    ui -> lineEdit_ServerAddr -> setText("192.168.1.24");
    ui -> lineEdit_ServerPort -> setText("2098");
    ui -> lineEditPos_x -> setText("-200");
    ui -> lineEditPos_y -> setText("-300");
    ui -> lineEditPos_z -> setText("550");
    ui -> pushButtonRun -> setDisabled(true);
    saveName = qEnvironmentVariable("HOME") + QString("/share/image/img.jpg");
    initSlot();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cam;
    delete qImg;
}

void MainWindow::initSlot()
{
    connect(actionOpenCam,SIGNAL(triggered(bool)),this,SLOT(camOpenSlot()));
    connect(timer,SIGNAL(timeout()),this,SLOT(camShow()));
    connect(ui->actionauto_while_balance,SIGNAL(triggered(bool)),this,SLOT(WBSlot()));
    connect(ui->actionconnect,&QAction::triggered,this,&MainWindow::buildConnect);
    connect(SocketToABB,&QTcpSocket::connected,this,&MainWindow::ABBConnected);
    connect(SocketToServer,&QTcpSocket::connected,this,&MainWindow::ServerConnected);
    connect(SocketToServer,&QTcpSocket::readyRead,this,&MainWindow::ServerReadSlot);
}

void MainWindow::camOpenSlot()
{
    timer->start(33);
    WBSlot();
}

void MainWindow::camShow()
{
    cv::Mat frame,dstMat;
    cam->getFrame(frame);
    if(frame.empty()){
        qDebug() << "ERROR!blank frame grabbed\n";
        //break;
    }
    cv::cvtColor(frame,dstMat,cv::COLOR_BGR2RGB);
    *qImg = QImage((const unsigned char*)(dstMat.data), dstMat.cols, dstMat.rows, QImage::Format_RGB888);
    camLabel->setPixmap(QPixmap::fromImage(*qImg));
    if(captureSaveSign)
    {
        cv::imwrite(saveName.toStdString(),frame);
    }
    captureSaveSign = false;
}

void MainWindow::WBSlot()
{
    CameraSetOnceWB(cam -> hCam);
}

void MainWindow::buildConnect()
{
    SocketToABB -> abort();
    SocketToServer -> abort();
    //SocketToABB ->
    SocketToABB -> connectToHost(ui -> lineEdit_ABBAddr ->text(),
                                 ui -> lineEdit_ABBPort -> text().toInt());
    SocketToServer -> connectToHost(ui -> lineEdit_ServerAddr -> text(),
                                    ui -> lineEdit_ServerPort -> text().toInt());
}

void MainWindow::ABBConnected()
{
    //QMessageBox::information(this,tr("Tip"),
    //                         tr("ABB has connected!"),QMessageBox::Ok);
    //ui -> statusBar -> showMessage(tr("ABB has connected!") , 2000);
    //enable the pushButton
    ui -> pushButtonRun -> setDisabled(false);
}

void MainWindow::ServerConnected()
{
    //QMessageBox::information(this,tr("Tip"),
    //                         tr("Server has connected!"),QMessageBox::Ok);
    ui -> statusBar -> showMessage(tr("Server has connected!") , 2000);
}

void MainWindow::on_pushButtonRun_clicked()
{
    QByteArray block;
    float data[3];
    data[0] = ui ->lineEditPos_x->text().toFloat();
    data[1] = ui ->lineEditPos_y->text().toFloat();
    data[2] = ui ->lineEditPos_z->text().toFloat();
    int i;
    for(i = 0 ; i < 3 ; i++)
    {
        block.append(reinterpret_cast<const char*>(&data[i]),4);
    }
    SocketToABB ->write(block);
}

void MainWindow::on_pushButtonGo_clicked()
{
    QByteArray block;
    block.append(QString("1"));
    captureSaveSign = true;
    SocketToServer->write(block);
}

void MainWindow::ServerReadSlot()
{
    qDebug() << "lkkkfkfkffkfk";
    QByteArray block;
    float x , y , z = 190;
    FILE* pos = std::fopen("/home/brain/share/position.txt","r");
    std::fscanf(pos , "%f,%f" , &x , &y);
    posExchange(x , y);
    float data[3] = {x , y ,z};
    int i;
    for(i = 0 ; i < 3 ; i++)
    {
        block.append(reinterpret_cast<const char*>(&data[i]),4);
    }
    SocketToABB ->write(block);
    std::fclose(pos);
}

void MainWindow::posExchange(float &x, float &y)
{
    double K = 232.0 / 1011.0;
    x = K * (271.0 - x) - 102.34 - 30.0;
    y = K * (y - 143.0) - 478 + 30.0;
}
