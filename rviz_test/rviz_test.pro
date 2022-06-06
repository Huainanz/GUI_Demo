QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    rviz_widget.cpp

HEADERS += \
    rviz_widget.h

FORMS += \
    rviz_widget.ui

TRANSLATIONS += \
    rviz_test_en_DE.ts
CONFIG += lrelease
CONFIG += embed_translations

INCLUDEPATH +=/opt/ros/noetic/include

DEPENDPATH +=/opt/ros/noetic/include

LIBS += -L/opt/ros/noetic/lib -lroscpp -lrospack -lpthread -lrosconsole -lrosconsole_log4cxx -lrosconsole_backend_interface -lxmlrpcpp -lroscpp_serialization \
        -lrostime -lcpp_common -lroslib -ltf -lyaml-cpp -lkdl_conversions -lrviz
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
