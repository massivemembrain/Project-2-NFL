/********************************************************************************
** Form generated from reading UI file 'dij.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJ_H
#define UI_DIJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dij
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *dij)
    {
        if (dij->objectName().isEmpty())
            dij->setObjectName(QString::fromUtf8("dij"));
        dij->resize(603, 419);
        textBrowser = new QTextBrowser(dij);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 150, 271, 221));

        retranslateUi(dij);

        QMetaObject::connectSlotsByName(dij);
    } // setupUi

    void retranslateUi(QWidget *dij)
    {
        dij->setWindowTitle(QCoreApplication::translate("dij", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dij: public Ui_dij {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJ_H
