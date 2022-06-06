#include "rviz_widget.h"
#include <QApplication>
#include <QIcon>

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"QRviz");//ros::init_options::AnonymousName;
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "rviz_test_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    RvizWidget w;
    w.show();
    return a.exec();
}
