#include "demo_widget.h"
#include "ui_demo_widget.h"

DemoWidget::DemoWidget(int argc,char** argv,QWidget *parent): QWidget(parent), ui(new Ui::DemoWidget),subscriber(new Qsub),qrviz(new Qrviz)
{
    ros::init(argc,argv,"QRviz");//ros::init_options::AnonymousName;
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
        this->qrviz->start();
        ui->rviz_layout->addWidget(qrviz->render_panel_);
}

DemoWidget::~DemoWidget()
{
    delete ui;
    delete subscriber;
    delete qrviz;
}

