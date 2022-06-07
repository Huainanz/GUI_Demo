#ifndef RVIZWIDGET_H
#define RVIZWIDGET_H

#include <QWidget>
//#include <rviz_show.h>>
//#include <QWidget>
#include <QGridLayout>
#include <ros/ros.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/tool_manager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class RvizWidget; }
QT_END_NAMESPACE

class RvizWidget : public QWidget
{
    Q_OBJECT

public:
    RvizWidget(QWidget *parent = nullptr);
    ~RvizWidget();

private slots:
    void on_rosbag_PB_clicked();

    void on_mergepoint_PB_clicked();

private:
    Ui::RvizWidget *ui;
};
#endif // RVIZWIDGET_H
