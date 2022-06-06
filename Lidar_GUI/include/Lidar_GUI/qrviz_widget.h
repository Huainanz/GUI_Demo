#ifndef QRVIZ_WIDGET_H
#define QRVIZ_WIDGET_H

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
class QrvizWidget;
}

class QrvizWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QrvizWidget(QWidget *parent = nullptr);
    ~QrvizWidget();

private:
    Ui::QrvizWidget *ui;
};

#endif // QRVIZ_WIDGET_H
