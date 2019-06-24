#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CameraApi.h" //相机SDK的API头文件
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <QAbstractSocket>
#include "mcamera.h"
class QLabel;
class QTcpSocket;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void WBSlot();
    void camOpenSlot();
    void camShow();
    void buildConnect();
    void ABBConnected();
    void ServerConnected();
    void ServerReadSlot();

private slots:
    void on_pushButtonRun_clicked();

    void on_pushButtonGo_clicked();

private:
    void initSlot();
    void posExchange(float &x , float &y);
    Ui::MainWindow *ui;
    MCamera *cam;
    QAction *actionOpenCam;
    QIcon *camIcon;
    QImage *qImg;
    QTimer *timer;
    QLabel *camLabel;
    QTcpSocket *SocketToABB;
    QTcpSocket *SocketToServer;
    QString saveName;
    bool captureSaveSign = false;
};

#endif // MAINWINDOW_H
