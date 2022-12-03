/********************************************************************************
** Form generated from reading UI file 'displayWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayWindow
{
public:
    QTableView *tableView;
    QComboBox *comboBox;
    QPushButton *pushButton_selectTeam;
    QPushButton *pushButton_displayStadium;
    QPushButton *pushButton_displayTeam;
    QPushButton *pushButton_stadiumByCapacity;
    QPushButton *pushButton_NFC;
    QPushButton *pushButton_teamsByConf;
    QPushButton *pushButton_stadiumByDate;
    QPushButton *pushButton_AFC;
    QPushButton *pushButton_NFCNORTH;
    QPushButton *pushButton_openRoof;
    QTableView *tableView_2;
    QPushButton *pushButton_displaySouvenir;
    QPushButton *pushButton_totalseatcapacity;
    QPushButton *pushButton_bermudaGrass;

    void setupUi(QWidget *displayWindow)
    {
        if (displayWindow->objectName().isEmpty())
            displayWindow->setObjectName(QString::fromUtf8("displayWindow"));
        displayWindow->resize(1055, 638);
        tableView = new QTableView(displayWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(230, 90, 821, 531));
        comboBox = new QComboBox(displayWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(12, 10, 141, 32));
        pushButton_selectTeam = new QPushButton(displayWindow);
        pushButton_selectTeam->setObjectName(QString::fromUtf8("pushButton_selectTeam"));
        pushButton_selectTeam->setGeometry(QRect(150, 10, 101, 32));
        pushButton_selectTeam->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(88, 142, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_displayStadium = new QPushButton(displayWindow);
        pushButton_displayStadium->setObjectName(QString::fromUtf8("pushButton_displayStadium"));
        pushButton_displayStadium->setGeometry(QRect(20, 100, 111, 32));
        pushButton_displayStadium->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_displayTeam = new QPushButton(displayWindow);
        pushButton_displayTeam->setObjectName(QString::fromUtf8("pushButton_displayTeam"));
        pushButton_displayTeam->setGeometry(QRect(20, 50, 111, 32));
        pushButton_displayTeam->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_stadiumByCapacity = new QPushButton(displayWindow);
        pushButton_stadiumByCapacity->setObjectName(QString::fromUtf8("pushButton_stadiumByCapacity"));
        pushButton_stadiumByCapacity->setGeometry(QRect(20, 400, 141, 32));
        pushButton_stadiumByCapacity->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_NFC = new QPushButton(displayWindow);
        pushButton_NFC->setObjectName(QString::fromUtf8("pushButton_NFC"));
        pushButton_NFC->setGeometry(QRect(20, 200, 201, 32));
        pushButton_NFC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_teamsByConf = new QPushButton(displayWindow);
        pushButton_teamsByConf->setObjectName(QString::fromUtf8("pushButton_teamsByConf"));
        pushButton_teamsByConf->setGeometry(QRect(20, 450, 141, 32));
        pushButton_teamsByConf->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_stadiumByDate = new QPushButton(displayWindow);
        pushButton_stadiumByDate->setObjectName(QString::fromUtf8("pushButton_stadiumByDate"));
        pushButton_stadiumByDate->setGeometry(QRect(20, 350, 151, 32));
        pushButton_stadiumByDate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_AFC = new QPushButton(displayWindow);
        pushButton_AFC->setObjectName(QString::fromUtf8("pushButton_AFC"));
        pushButton_AFC->setGeometry(QRect(20, 150, 201, 32));
        pushButton_AFC->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_NFCNORTH = new QPushButton(displayWindow);
        pushButton_NFCNORTH->setObjectName(QString::fromUtf8("pushButton_NFCNORTH"));
        pushButton_NFCNORTH->setGeometry(QRect(20, 250, 121, 32));
        pushButton_NFCNORTH->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_openRoof = new QPushButton(displayWindow);
        pushButton_openRoof->setObjectName(QString::fromUtf8("pushButton_openRoof"));
        pushButton_openRoof->setGeometry(QRect(20, 300, 121, 32));
        pushButton_openRoof->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        tableView_2 = new QTableView(displayWindow);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(300, 10, 161, 71));
        pushButton_displaySouvenir = new QPushButton(displayWindow);
        pushButton_displaySouvenir->setObjectName(QString::fromUtf8("pushButton_displaySouvenir"));
        pushButton_displaySouvenir->setGeometry(QRect(20, 500, 141, 32));
        pushButton_displaySouvenir->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_totalseatcapacity = new QPushButton(displayWindow);
        pushButton_totalseatcapacity->setObjectName(QString::fromUtf8("pushButton_totalseatcapacity"));
        pushButton_totalseatcapacity->setGeometry(QRect(20, 550, 161, 32));
        pushButton_totalseatcapacity->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_bermudaGrass = new QPushButton(displayWindow);
        pushButton_bermudaGrass->setObjectName(QString::fromUtf8("pushButton_bermudaGrass"));
        pushButton_bermudaGrass->setGeometry(QRect(20, 600, 151, 32));
        pushButton_bermudaGrass->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(192, 214, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));

        retranslateUi(displayWindow);

        QMetaObject::connectSlotsByName(displayWindow);
    } // setupUi

    void retranslateUi(QWidget *displayWindow)
    {
        displayWindow->setWindowTitle(QCoreApplication::translate("displayWindow", "Form", nullptr));
        pushButton_selectTeam->setText(QCoreApplication::translate("displayWindow", "select team", nullptr));
        pushButton_displayStadium->setText(QCoreApplication::translate("displayWindow", "display Stadium ", nullptr));
        pushButton_displayTeam->setText(QCoreApplication::translate("displayWindow", "display Teams", nullptr));
        pushButton_stadiumByCapacity->setText(QCoreApplication::translate("displayWindow", "stadium by Capacity", nullptr));
        pushButton_NFC->setText(QCoreApplication::translate("displayWindow", "National Football Conference", nullptr));
        pushButton_teamsByConf->setText(QCoreApplication::translate("displayWindow", "Teams by Conference", nullptr));
        pushButton_stadiumByDate->setText(QCoreApplication::translate("displayWindow", "stadium by date opened", nullptr));
        pushButton_AFC->setText(QCoreApplication::translate("displayWindow", " American Football Conference", nullptr));
        pushButton_NFCNORTH->setText(QCoreApplication::translate("displayWindow", "NFC North", nullptr));
        pushButton_openRoof->setText(QCoreApplication::translate("displayWindow", "open Roof stadium", nullptr));
        pushButton_displaySouvenir->setText(QCoreApplication::translate("displayWindow", "Team Souvenir", nullptr));
        pushButton_totalseatcapacity->setText(QCoreApplication::translate("displayWindow", "total seating capacaity", nullptr));
        pushButton_bermudaGrass->setText(QCoreApplication::translate("displayWindow", "bermuda grass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displayWindow: public Ui_displayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
