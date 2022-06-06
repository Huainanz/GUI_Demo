#include "lidar_gui.h"
#include "ui_lidar_gui.h"
#include <stdio.h>
#include <string.h>

//#include <QProcess>

//#include <rosbag/bag.h>
//#include <rosbag/view.h>
//#include <std_msgs/Int32.h>
//#include <std_msgs/String.h>
//#include <boost/foreach.hpp>
//#define foreach BOOST_FOREACH

LidarGui::LidarGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LidarGui)
{
  ui->setupUi(this);
  int argc;
  char **argv;
  //ros::init(argc,argv,"QRviz",ros::init_options::AnonymousName);
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

  //manage tool of rviz
  rviz::ToolManager* tool_man;
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

LidarGui::~LidarGui()
{
    delete ui;
}


void LidarGui::on_roslaunch_PB_clicked()
{

  // launch file
  std::string cmd_roslaunch = "roslaunch morpheus_merge morpheus_merge.launch\
                               fov:=180 phase_lock_mode:=0 replay:=true\
                               metadata_sensor_1:=$HOME/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/metadata_sensor_1\
                               metadata_sensor_2:=$HOME/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/metadata_sensor_2\
                               metadata_sensor_3:=$HOME/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/metadata_sensor_3\
                               rviz:=false";
  FILE *fp;
  char _info[20];
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

void LidarGui::on_rosbag_PB_clicked()
{
  // rosbag play
  std::string cmd_rosbag = "rosbag play --loop ~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag";
  FILE *fp;
  char _info[200];
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




  //QString cmd_rosbag = "rosbag play --loop ~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag ";
//  QProcess *p_rosbag= new QProcess;
//  //QProcess p_rosbag;
//  //QStringList arg_rosbag;
//  //arg_rosbag<<"play"<<"--loop"<<"~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag";
//  //p_rosbag.setProgram("rosbag");
//  //p_rosbag.setArguments(arg_rosbag);
//  //p_rosbag->start("rosbag", QStringList()<<"play"<<"--loop"<<"~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag");
//  //p_rosbag->start("/bin/sh", QStringList()<<"-c"<<"rosbag"<<"play"<<"--loop"<<"~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag");
//  p_rosbag->start("rosbag play --loop ~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode=none/2021-08-17-14-47-08.bag");
//  if (p_rosbag->waitForStarted()==true) {
//    ui->textBrowser->append("success play rosbag");//line break
//  }
//  p_rosbag->write("rosbag play --loop ~\\Lidar_Messdaten\\rosbags_17082021\\raw_1024x20_mode\=none\\2021-08-17-14-47-08.bag");
//  p_rosbag->write("\n\r");






//  rosbag::Bag bag;
//  bag.open("~/Lidar_Messdaten/rosbags_17082021/raw_1024x20_mode\=none/2021-08-17-14-47-08.bag", rosbag::bagmode::Read);

//  std::vector<std::string> topics;
//  topics.push_back(std::string("/merge_node/merged_points"));

//  rosbag::View view(bag, rosbag::TopicQuery(topics));

//  foreach(rosbag::MessageInstance const m, view)
//  {
//      std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
//      if (s != NULL)
//          std::cout << s->data << std::endl;

//      std_msgs::Int32::ConstPtr i = m.instantiate<std_msgs::Int32>();
//      if (i != NULL)
//          std::cout << i->data << std::endl;
//  }

  //bag.close();

}

void LidarGui::on_start_PB_clicked()
{
  QString str = "start";
  int ret=2022;
  ui->textBrowser->append(str+QString("%1").arg(ret));// String is not std::string!! int-->QString
}
