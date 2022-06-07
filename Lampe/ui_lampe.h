/********************************************************************************
** Form generated from reading UI file 'lampe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAMPE_H
#define UI_LAMPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lampe
{
public:

    void setupUi(QWidget *Lampe)
    {
        if (Lampe->objectName().isEmpty())
            Lampe->setObjectName(QString::fromUtf8("Lampe"));
        Lampe->resize(50, 25);

        retranslateUi(Lampe);

        QMetaObject::connectSlotsByName(Lampe);
    } // setupUi

    void retranslateUi(QWidget *Lampe)
    {
        Lampe->setWindowTitle(QCoreApplication::translate("Lampe", "Lampe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lampe: public Ui_Lampe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAMPE_H
