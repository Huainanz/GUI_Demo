#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "qsub.h"
#include "qrviz.h"
QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(int argc,char **argv,QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindow *ui;
    Qsub *subscriber;
    Qrviz *qrviz;
};
#endif // MAINWINDOW_H
