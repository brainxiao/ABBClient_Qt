#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T18:47:12
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mcamera.cpp

HEADERS += \
        mainwindow.h \
    CameraApi.h \
    mcamera.h

FORMS += \
        mainwindow.ui
# 导入opencv的路径
# must be opencv version2
INCLUDEPATH += /home/brain/opencv/opencv2/include/
# 导入opencv的完整库
LIBS += -L/home/brain/opencv/opencv2/lib \
    -lopencv_calib3d \
    #-lopencv_contrib \
    -lopencv_core \
    -lopencv_features2d \
    -lopencv_flann \
    #-lopencv_gpu \
    -lopencv_highgui \
    -lopencv_imgproc \
    #-lopencv_legacy \
    -lopencv_ml \
    #-lopencv_nonfree \
    -lopencv_objdetect \
    #-lopencv_ocl \
    -lopencv_photo \
    -lopencv_stitching \
    #-lopencv_superres \
    -lopencv_video \
    #-lopencv_videostab \
    -lopencv_videoio \
    -lopencv_imgcodecs \

LIBS += -lpthread
LIBS += -lMVSDK

RESOURCES += \
    resources.qrc
