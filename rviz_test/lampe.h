#ifndef LAMPE_H
#define LAMPE_H

#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Lampe; }
QT_END_NAMESPACE

class Lampe : public QLabel
{
    Q_OBJECT

public:
    Lampe(QWidget *parent = nullptr);
    ~Lampe();
    void change_diameter(int d);
    void change_color(bool);
private:    
    Ui::Lampe *ui;
    int size;
    QString SheetStyle;
    QString color;
};
#endif // LAMPE_H
