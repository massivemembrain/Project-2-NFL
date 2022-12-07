/********************************************************************************
** Form generated from reading UI file 'shortestDistance.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTDISTANCE_H
#define UI_SHORTESTDISTANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shortestDistance
{
public:
    QTableView *tableView;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *shortestDistance)
    {
        if (shortestDistance->objectName().isEmpty())
            shortestDistance->setObjectName(QString::fromUtf8("shortestDistance"));
        shortestDistance->resize(818, 641);
        tableView = new QTableView(shortestDistance);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(690, 20, 71, 51));
        label = new QLabel(shortestDistance);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 481, 41));
        textBrowser = new QTextBrowser(shortestDistance);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 90, 381, 521));

        retranslateUi(shortestDistance);

        QMetaObject::connectSlotsByName(shortestDistance);
    } // setupUi

    void retranslateUi(QWidget *shortestDistance)
    {
        shortestDistance->setWindowTitle(QCoreApplication::translate("shortestDistance", "Form", nullptr));
        label->setText(QCoreApplication::translate("shortestDistance", "visit all teams starting at England patriots, travelling the shortest distance ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shortestDistance: public Ui_shortestDistance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTDISTANCE_H
