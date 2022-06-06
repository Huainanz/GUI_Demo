#ifndef QSUB_H
#define QSUB_H

#include <QThread>
#include <std_msgs/UInt16.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Float32.h>
#include <std_msgs/UInt32.h>
#include "std_msgs/String.h"
#include <timing_msg.h>
#include <ros/ros.h>
#include <QDebug>

class Qsub : public QThread
{
    Q_OBJECT
public:
    explicit Qsub(QObject *parent = nullptr);
    int argc;
    char **argv;
protected:
    void run();
signals:
    void send_timer(float time);
};
void callback_cycletime_bach(const morpheus_object_detection::timing_msg::ConstPtr& timer,Qsub *qsub);
#endif // QSUB_H
