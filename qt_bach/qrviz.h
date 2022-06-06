#ifndef QRVIZ_H
#define QRVIZ_H

#include <QThread>
#include <ros/ros.h>
#include <QGridLayout>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>
//#include <rviz_visual_tools/rviz_visual_tools.h>

class Qrviz : public QThread
{
    Q_OBJECT
public:
    explicit Qrviz(QObject *parent = nullptr);
    int argc;
    char **argv;
    //new docker for rviz
    rviz::RenderPanel *render_panel_=new rviz::RenderPanel;
protected:
    void run();
};

#endif // QRVIZ_H
