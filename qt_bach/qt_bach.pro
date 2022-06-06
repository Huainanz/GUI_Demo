QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qsub.cpp \
    qrviz.cpp

HEADERS += \
    mainwindow.h \
    qsub.h \
    timing_msg.h \
    qrviz.h

FORMS += \
    mainwindow.ui

INCLUDEPATH +=/opt/ros/noetic/include

DEPENDPATH +=/opt/ros/noetic/include

LIBS += -L/opt/ros/noetic/lib -lroscpp -lrospack -lpthread -lrosconsole -lrosconsole_log4cxx -lrosconsole_backend_interface -lxmlrpcpp -lroscpp_serialization \
        -lrostime -lcpp_common -lroslib -ltf -lyaml-cpp -lkdl_conversions -lrviz

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
