/********************************************************************************
** Form generated from reading UI file 'planTrip.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANTRIP_H
#define UI_PLANTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_planTrip
{
public:
    QComboBox *starting_comboBox;
    QPushButton *pushButton_choose;
    QTableView *rest_tableView;
    QTextBrowser *textBrowser;
    QPushButton *clear;

    void setupUi(QWidget *planTrip)
    {
        if (planTrip->objectName().isEmpty())
            planTrip->setObjectName(QString::fromUtf8("planTrip"));
        planTrip->resize(919, 475);
        starting_comboBox = new QComboBox(planTrip);
        starting_comboBox->setObjectName(QString::fromUtf8("starting_comboBox"));
        starting_comboBox->setGeometry(QRect(100, 50, 301, 31));
        pushButton_choose = new QPushButton(planTrip);
        pushButton_choose->setObjectName(QString::fromUtf8("pushButton_choose"));
        pushButton_choose->setGeometry(QRect(400, 50, 81, 31));
        rest_tableView = new QTableView(planTrip);
        rest_tableView->setObjectName(QString::fromUtf8("rest_tableView"));
        rest_tableView->setGeometry(QRect(100, 80, 381, 311));
        textBrowser = new QTextBrowser(planTrip);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(520, 50, 331, 341));
        clear = new QPushButton(planTrip);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(430, 420, 80, 24));

        retranslateUi(planTrip);

        QMetaObject::connectSlotsByName(planTrip);
    } // setupUi

    void retranslateUi(QWidget *planTrip)
    {
        planTrip->setWindowTitle(QCoreApplication::translate("planTrip", "Form", nullptr));
        pushButton_choose->setText(QCoreApplication::translate("planTrip", "Choose", nullptr));
        clear->setText(QCoreApplication::translate("planTrip", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class planTrip: public Ui_planTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTRIP_H
