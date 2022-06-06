#ifndef DEMOWIDGET_H
#define DEMOWIDGET_H

#include <QWidget>
#include "qsub.h"
#include "qrviz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DemoWidget; }
QT_END_NAMESPACE

class DemoWidget : public QWidget
{
    Q_OBJECT

public:
    DemoWidget(int argc,char **argv,QWidget *parent = nullptr);
    ~DemoWidget();

private:
    Ui::DemoWidget *ui;
    Qsub *subscriber;
    Qrviz *qrviz;
};
#endif // DEMOWIDGET_H
