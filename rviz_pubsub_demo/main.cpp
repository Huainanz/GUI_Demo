#include "demo_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DemoWidget w(argc,argv);
    w.show();
    return a.exec();
}
