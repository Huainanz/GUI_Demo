#ifndef LIDAR_GUI_H
#define LIDAR_GUI_H

#include <QWidget>
#include <QGridLayout>
#include <ros/ros.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>
//#include <rviz_visual_tools/rviz_visual_tools.h>

namespace Ui {
class LidarGui;
}

class LidarGui : public QWidget
{
  Q_OBJECT

public:
  explicit LidarGui(QWidget *parent = nullptr);
  ~LidarGui();

private slots:
  void on_roslaunch_PB_clicked();

  void on_rosbag_PB_clicked();

  void on_start_PB_clicked();

private:
  Ui::LidarGui *ui;
};

#endif // LIDAR_GUI_H
