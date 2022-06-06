#include "qsub.h"

Qsub::Qsub(QObject *parent): QThread{parent}
{

}
void Qsub::run()
{
    ros::init(this->argc,this->argv,"Qsubscriber");
    ros::NodeHandle n;
    ros::Subscriber timer = n.subscribe<morpheus_object_detection::timing_msg>("/od_node/od_node_timing",1,boost::bind(callback_cycletime_bach,_1,this));
    ros::spin();
}

void callback_cycletime_bach(const morpheus_object_detection::timing_msg::ConstPtr& timer,Qsub *qsub)
{
    qDebug() <<"subscribe";
    emit qsub->send_timer(timer->Cycletime);
}
