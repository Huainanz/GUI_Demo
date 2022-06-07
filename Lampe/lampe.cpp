#include "lampe.h"
#include "ui_lampe.h"
Lampe::Lampe(QWidget *parent): QLabel(parent), ui(new Ui::Lampe)
{
    ui->setupUi(this);
    this->setText("");
    this->size=20;
    this->color="rgb(0,255,0)";
    QString min_width = QString("min-width: %1px;").arg(size);
    QString min_height = QString("min-height: %1px;").arg(size);
    QString max_width = QString("max-width: %1px;").arg(size);
    QString max_height = QString("max-height: %1px;").arg(size);

    QString border_radius = QString("border-radius: %1px;").arg(size/2);
    QString border = QString("border:1px solid black;");

    QString background = "background-color:";
    background +=color;
    this->SheetStyle = min_width + min_height + max_width + \
            max_height + border_radius + border + background;
    this->setStyleSheet(SheetStyle);
}
void Lampe::change_diameter(int d)
{
    this->size = d;
}

void Lampe::change_color(bool c)
{
    if ( c == true )
    {
        this->SheetStyle = this->SheetStyle.left(this->SheetStyle.length()-12);
        this->color = QString("rgb(255,0,0)");
        this->SheetStyle+=this->color;
        this->setStyleSheet(this->SheetStyle);
    }
    else
    {
        this->SheetStyle = this->SheetStyle.left(this->SheetStyle.length()-12);
        this->color = QString("rgb(0,255,0)");
        this->SheetStyle+=this->color;
        this->setStyleSheet(this->SheetStyle);
    }
}
Lampe::~Lampe()
{
    delete ui;
}

