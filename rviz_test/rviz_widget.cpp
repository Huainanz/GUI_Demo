#include "rviz_widget.h"
#include "ui_rviz_widget.h"

#include <stdio.h>
#include <string.h>

RvizWidget::RvizWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RvizWidget)
{
    ui->setupUi(this);
    //int argc;
    //char **argv;
    //ros::init(argc,argv,"QRviz");//ros::init_options::AnonymousName;
    //new docker for rviz
    rviz::RenderPanel *render_panel_=new rviz::RenderPanel;
    //form of cursor
    render_panel_->setCursor(Qt::PointingHandCursor);
    //add in rviz_layout
    ui->rviz_layout->addWidget(render_panel_);
    //new Object of rviz to control this rviz
    rviz::VisualizationManager* manager_=new rviz::VisualizationManager(render_panel_);
    //initial camera : zoom in/out, translation
    render_panel_->initialize(manager_->getSceneManager(),manager_);

    //manage tool of rviz in slot()
    //rviz::ToolManager* tool_man;
    // slot() - rviz send a signal to rvviz itself slot()
    //       connect( tool_man, SIGNAL( toolAdded( Tool* )), this, SLOT( addTool( Tool* )));

    // Display
    manager_->initialize();
    manager_->removeAllDisplays();

    // set grid
    rviz::Display* grid_ = manager_->createDisplay( "rviz/Grid", "adjustable grid", true );
    ROS_ASSERT( grid_ != NULL );
    // Parameter
    grid_->subProp( "Line Style" )->setValue( "Billboards" );
    grid_->subProp( "Color" )->setValue(QColor(125,125,125));

    // set frame
    manager_->setFixedFrame("/morpheus_frame");

    // set PointCloud2
    rviz::Display* PCmap_ = manager_->createDisplay("rviz/PointCloud2", "PointCloud2", true);
    ROS_ASSERT( PCmap_ != NULL );
    PCmap_->subProp("Topic")->setValue("/merge_node/merged_points");
    PCmap_->subProp("Invert Rainbow")->setValue("true");
    PCmap_->subProp("Style")->setValue("Flat Squares");
    PCmap_->subProp("Size (m)")->setValue("0.01");
    PCmap_->subProp("Color Transformer")->setValue("FlatColor");
    PCmap_->subProp("Queue Size")->setValue("10");
    PCmap_->subProp("Alpha")->setValue("1");
    PCmap_->subProp("Color")->setValue("0,0,255");

    manager_->startUpdate();
}

RvizWidget::~RvizWidget()
{
    delete ui;
}


void RvizWidget::on_rosbag_PB_clicked()
{
    // rosbag play
    std::string cmd_rosbag = "rosbag play --loop ~/Lidar_Messdaten/rosbags_28102021/raw_1024x20_mode=sync/2021-10-28-16-00-56.bag";
    FILE *fp;
    //char _info[200];
    const char *cmd_rb = cmd_rosbag.data();
    if ((fp=popen(cmd_rb,"w"))==NULL){
      ui->textBrowser->append("can not play rosbag!!!");
    }else {
      //fgets(_info,sizeof(_info),fp);
      ui->textBrowser->append("success play rosbag");//line break
      //ui->textBrowser->insertPlainText(_info);// not line break
      ui->textBrowser->insertPlainText("...");
    }
    //pclose(fp);
    //int ret = system(cmd_rosbag.c_str()); //blockt!
}


void RvizWidget::on_mergepoint_PB_clicked()
{
    // launch file
    std::string cmd_roslaunch = "roslaunch morpheus_merge morpheus_merge.launch\
                                 fov:=180 phase_lock_mode:=0 replay:=true\
                                 metadata_sensor_1:=$HOME/Lidar_Messdaten/rosbags_28102021/raw_1024x20_mode=sync/metadata_sensor_1\
                                 metadata_sensor_2:=$HOME/Lidar_Messdaten/rosbags_28102021/raw_1024x20_mode=sync/metadata_sensor_2\
                                 metadata_sensor_3:=$HOME/Lidar_Messdaten/rosbags_28102021/raw_1024x20_mode=sync/metadata_sensor_3\
                                 rviz:=false";
    FILE *fp;
    //char _info[20];
    const char *cmd_rl = cmd_roslaunch.data();
    if ((fp=popen(cmd_rl,"w"))==NULL){
      ui->textBrowser->append("can not launch file!!!");
    }else {
      //fgets(_info,sizeof(_info),fp);
      ui->textBrowser->append("success launch file");//line break
      //ui->textBrowser->insertPlainText(_info);// not line break
      ui->textBrowser->insertPlainText("...");
    }
    //pclose(fp);
    //int ret = system(cmd_roslaunch.c_str());//blockt
}

