/********************************************************************************
** Form generated from reading UI file 'primmst.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMMST_H
#define UI_PRIMMST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_primmst
{
public:

    void setupUi(QWidget *primmst)
    {
        if (primmst->objectName().isEmpty())
            primmst->setObjectName(QString::fromUtf8("primmst"));
        primmst->resize(400, 300);

        retranslateUi(primmst);

        QMetaObject::connectSlotsByName(primmst);
    } // setupUi

    void retranslateUi(QWidget *primmst)
    {
        primmst->setWindowTitle(QCoreApplication::translate("primmst", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class primmst: public Ui_primmst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMMST_H
