/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenCamera;
    QAction *actionOpenCamera_2;
    QAction *actionOpenCamera_3;
    QAction *actionauto_while_balance;
    QAction *actionconnect;
    QWidget *centralWidget;
    QLineEdit *lineEdit_ABBAddr;
    QLineEdit *lineEdit_ABBPort;
    QLineEdit *lineEdit_ServerAddr;
    QLineEdit *lineEdit_ServerPort;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame;
    QLineEdit *lineEditPos_x;
    QLineEdit *lineEditPos_y;
    QLineEdit *lineEditPos_z;
    QPushButton *pushButtonRun;
    QPushButton *pushButtonGo;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTool;
    QMenu *menuConnection;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(539, 412);
        actionOpenCamera = new QAction(MainWindow);
        actionOpenCamera->setObjectName(QStringLiteral("actionOpenCamera"));
        actionOpenCamera_2 = new QAction(MainWindow);
        actionOpenCamera_2->setObjectName(QStringLiteral("actionOpenCamera_2"));
        actionOpenCamera_3 = new QAction(MainWindow);
        actionOpenCamera_3->setObjectName(QStringLiteral("actionOpenCamera_3"));
        actionauto_while_balance = new QAction(MainWindow);
        actionauto_while_balance->setObjectName(QStringLiteral("actionauto_while_balance"));
        actionconnect = new QAction(MainWindow);
        actionconnect->setObjectName(QStringLiteral("actionconnect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_ABBAddr = new QLineEdit(centralWidget);
        lineEdit_ABBAddr->setObjectName(QStringLiteral("lineEdit_ABBAddr"));
        lineEdit_ABBAddr->setGeometry(QRect(70, 260, 113, 24));
        lineEdit_ABBPort = new QLineEdit(centralWidget);
        lineEdit_ABBPort->setObjectName(QStringLiteral("lineEdit_ABBPort"));
        lineEdit_ABBPort->setGeometry(QRect(240, 260, 61, 24));
        lineEdit_ServerAddr = new QLineEdit(centralWidget);
        lineEdit_ServerAddr->setObjectName(QStringLiteral("lineEdit_ServerAddr"));
        lineEdit_ServerAddr->setGeometry(QRect(70, 290, 113, 24));
        lineEdit_ServerPort = new QLineEdit(centralWidget);
        lineEdit_ServerPort->setObjectName(QStringLiteral("lineEdit_ServerPort"));
        lineEdit_ServerPort->setGeometry(QRect(240, 290, 61, 24));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 260, 51, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 290, 51, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 260, 41, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 290, 41, 21));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(340, 10, 191, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEditPos_x = new QLineEdit(frame);
        lineEditPos_x->setObjectName(QStringLiteral("lineEditPos_x"));
        lineEditPos_x->setGeometry(QRect(10, 10, 81, 21));
        lineEditPos_y = new QLineEdit(frame);
        lineEditPos_y->setObjectName(QStringLiteral("lineEditPos_y"));
        lineEditPos_y->setGeometry(QRect(10, 50, 81, 21));
        lineEditPos_z = new QLineEdit(frame);
        lineEditPos_z->setObjectName(QStringLiteral("lineEditPos_z"));
        lineEditPos_z->setGeometry(QRect(10, 90, 81, 21));
        pushButtonRun = new QPushButton(frame);
        pushButtonRun->setObjectName(QStringLiteral("pushButtonRun"));
        pushButtonRun->setGeometry(QRect(110, 40, 61, 51));
        pushButtonGo = new QPushButton(centralWidget);
        pushButtonGo->setObjectName(QStringLiteral("pushButtonGo"));
        pushButtonGo->setGeometry(QRect(340, 170, 91, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QStringLiteral("menuConnection"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuConnection->menuAction());
        menuTool->addAction(actionauto_while_balance);
        menuConnection->addAction(actionconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenCamera->setText(QApplication::translate("MainWindow", "OpenCamera", nullptr));
        actionOpenCamera_2->setText(QApplication::translate("MainWindow", "OpenCamera", nullptr));
        actionOpenCamera_3->setText(QApplication::translate("MainWindow", "OpenCamera", nullptr));
        actionauto_while_balance->setText(QApplication::translate("MainWindow", "auto while balance", nullptr));
        actionconnect->setText(QApplication::translate("MainWindow", "connect", nullptr));
        label->setText(QApplication::translate("MainWindow", "ABBIP:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "ServIP:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "PORT:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "PORT:", nullptr));
        pushButtonRun->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        pushButtonGo->setText(QApplication::translate("MainWindow", "Go", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", nullptr));
        menuConnection->setTitle(QApplication::translate("MainWindow", "Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
