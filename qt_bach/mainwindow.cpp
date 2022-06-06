#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(int argc,char** argv,QWidget *parent): QWidget(parent), ui(new Ui::mainwindow),subscriber(new Qsub),qrviz(new Qrviz)
{
    ui->setupUi(this);
    this->subscriber->argc = argc;
    this->subscriber->argv = argv;

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ros::shutdown();
        this->subscriber->quit();
    });
    connect(this->subscriber,&Qsub::send_timer,[=](float time){
       ui->lineEdit->setText(QString("%1").arg(time)) ;
    });
    this->subscriber->start();

    //add in rviz_layout
    this->qrviz->argc = argc;
    this->qrviz->argv = argv;
    this->qrviz->start();
    ui->qrviz_layout->addWidget(qrviz->render_panel_);
}

mainwindow::~mainwindow()
{
    delete ui;
    delete subscriber;
}

