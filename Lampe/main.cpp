#include "lampe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lampe w;
    w.show();
    return a.exec();
}
