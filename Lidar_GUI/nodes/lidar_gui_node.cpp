#include <QApplication>
#include <QIcon>
#include "Lidar_GUI/lidar_gui.h"
//#include "Lidar_GUI/qrviz_widget.h"


int main(int argc, char *argv[])
{

  ros::init(argc, argv, "lidar_gui_node");//ros::init_options::AnonymousName
  QApplication a(argc, argv);


  LidarGui w;
  //qrviz=new QrvizWidget(ui.widget_rviz);
  //QrvizWidget qrviz;



  // set the window title as the node name
  w.setWindowTitle(QString::fromStdString(
                       ros::this_node::getName()));

  // load the icon from our qrc file and set it as the application icon
  //QIcon icon(":/icons/*****.png"); //related to resources/images.qrc
  //w.setWindowIcon(icon);

  w.show();
  //qrviz.showFullScreen();
  //qrviz.show();
  //qrviz->showFullScreen();
  //qrviz->show();

  return a.exec();
}
