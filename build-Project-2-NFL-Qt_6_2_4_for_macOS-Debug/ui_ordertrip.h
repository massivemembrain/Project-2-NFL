/********************************************************************************
** Form generated from reading UI file 'ordertrip.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERTRIP_H
#define UI_ORDERTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderedTrip
{
public:
    QComboBox *comboBox;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QLabel *label_4;
    QPushButton *pushButton_selectOrigin;

    void setupUi(QWidget *orderedTrip)
    {
        if (orderedTrip->objectName().isEmpty())
            orderedTrip->setObjectName(QString::fromUtf8("orderedTrip"));
        orderedTrip->resize(888, 612);
        comboBox = new QComboBox(orderedTrip);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 120, 151, 32));
        tableView = new QTableView(orderedTrip);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(240, 60, 256, 551));
        label = new QLabel(orderedTrip);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 181, 41));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label_2 = new QLabel(orderedTrip);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 201, 16));
        label_3 = new QLabel(orderedTrip);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 30, 201, 16));
        pushButton = new QPushButton(orderedTrip);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 20, 141, 32));
        textBrowser = new QTextBrowser(orderedTrip);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(560, 140, 256, 192));
        label_4 = new QLabel(orderedTrip);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 110, 281, 20));
        pushButton_selectOrigin = new QPushButton(orderedTrip);
        pushButton_selectOrigin->setObjectName(QString::fromUtf8("pushButton_selectOrigin"));
        pushButton_selectOrigin->setGeometry(QRect(160, 120, 61, 32));

        retranslateUi(orderedTrip);

        QMetaObject::connectSlotsByName(orderedTrip);
    } // setupUi

    void retranslateUi(QWidget *orderedTrip)
    {
        orderedTrip->setWindowTitle(QCoreApplication::translate("orderedTrip", "Form", nullptr));
        label->setText(QCoreApplication::translate("orderedTrip", "Ordered Trip ", nullptr));
        label_2->setText(QCoreApplication::translate("orderedTrip", "1 - select your starting team", nullptr));
        label_3->setText(QCoreApplication::translate("orderedTrip", "2- select all other teams ", nullptr));
        pushButton->setText(QCoreApplication::translate("orderedTrip", "finished selecting", nullptr));
        label_4->setText(QCoreApplication::translate("orderedTrip", "your total distance : ", nullptr));
        pushButton_selectOrigin->setText(QCoreApplication::translate("orderedTrip", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderedTrip: public Ui_orderedTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERTRIP_H
