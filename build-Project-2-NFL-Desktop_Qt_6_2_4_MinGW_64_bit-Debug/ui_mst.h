/********************************************************************************
** Form generated from reading UI file 'mst.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MST_H
#define UI_MST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MST
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MST)
    {
        if (MST->objectName().isEmpty())
            MST->setObjectName(QString::fromUtf8("MST"));
        MST->resize(582, 424);
        textBrowser = new QTextBrowser(MST);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 71, 391, 311));

        retranslateUi(MST);

        QMetaObject::connectSlotsByName(MST);
    } // setupUi

    void retranslateUi(QWidget *MST)
    {
        MST->setWindowTitle(QCoreApplication::translate("MST", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MST: public Ui_MST {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MST_H
