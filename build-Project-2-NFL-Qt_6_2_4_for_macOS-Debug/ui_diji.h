/********************************************************************************
** Form generated from reading UI file 'diji.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJI_H
#define UI_DIJI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diji
{
public:

    void setupUi(QWidget *diji)
    {
        if (diji->objectName().isEmpty())
            diji->setObjectName(QString::fromUtf8("diji"));
        diji->resize(634, 439);

        retranslateUi(diji);

        QMetaObject::connectSlotsByName(diji);
    } // setupUi

    void retranslateUi(QWidget *diji)
    {
        diji->setWindowTitle(QCoreApplication::translate("diji", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class diji: public Ui_diji {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJI_H
