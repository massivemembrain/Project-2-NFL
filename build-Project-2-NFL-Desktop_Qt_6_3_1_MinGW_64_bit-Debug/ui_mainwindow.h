/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_displayWindow;
    QPushButton *pushButton_MST;
    QPushButton *pushButton_trip;
    QPushButton *pushButton_BFS;
    QPushButton *pushButton_DFS;
    QPushButton *pushButton_shortdist;
    QPushButton *pushButton_dijkstra;
    QPushButton *pushButton_souvenir;
    QPushButton *pushButton_orderTrip;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 140, 111, 31));
        QFont font;
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_displayWindow = new QPushButton(centralwidget);
        pushButton_displayWindow->setObjectName(QString::fromUtf8("pushButton_displayWindow"));
        pushButton_displayWindow->setGeometry(QRect(40, 70, 100, 32));
        pushButton_displayWindow->setFont(font);
        pushButton_displayWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_MST = new QPushButton(centralwidget);
        pushButton_MST->setObjectName(QString::fromUtf8("pushButton_MST"));
        pushButton_MST->setGeometry(QRect(40, 150, 100, 32));
        pushButton_MST->setFont(font);
        pushButton_MST->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_trip = new QPushButton(centralwidget);
        pushButton_trip->setObjectName(QString::fromUtf8("pushButton_trip"));
        pushButton_trip->setGeometry(QRect(510, 70, 111, 31));
        pushButton_trip->setFont(font);
        pushButton_trip->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_BFS = new QPushButton(centralwidget);
        pushButton_BFS->setObjectName(QString::fromUtf8("pushButton_BFS"));
        pushButton_BFS->setGeometry(QRect(40, 220, 100, 32));
        pushButton_BFS->setFont(font);
        pushButton_BFS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_DFS = new QPushButton(centralwidget);
        pushButton_DFS->setObjectName(QString::fromUtf8("pushButton_DFS"));
        pushButton_DFS->setGeometry(QRect(40, 290, 100, 32));
        pushButton_DFS->setFont(font);
        pushButton_DFS->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_shortdist = new QPushButton(centralwidget);
        pushButton_shortdist->setObjectName(QString::fromUtf8("pushButton_shortdist"));
        pushButton_shortdist->setGeometry(QRect(510, 210, 141, 32));
        pushButton_shortdist->setFont(font);
        pushButton_shortdist->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_dijkstra = new QPushButton(centralwidget);
        pushButton_dijkstra->setObjectName(QString::fromUtf8("pushButton_dijkstra"));
        pushButton_dijkstra->setGeometry(QRect(510, 270, 101, 31));
        pushButton_dijkstra->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(201, 236, 255);\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"}"));
        pushButton_souvenir = new QPushButton(centralwidget);
        pushButton_souvenir->setObjectName(QString::fromUtf8("pushButton_souvenir"));
        pushButton_souvenir->setGeometry(QRect(510, 330, 141, 32));
        pushButton_orderTrip = new QPushButton(centralwidget);
        pushButton_orderTrip->setObjectName(QString::fromUtf8("pushButton_orderTrip"));
        pushButton_orderTrip->setGeometry(QRect(510, 380, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        pushButton_displayWindow->setText(QCoreApplication::translate("MainWindow", "display", nullptr));
        pushButton_MST->setText(QCoreApplication::translate("MainWindow", "M S T ", nullptr));
        pushButton_trip->setText(QCoreApplication::translate("MainWindow", "Plan a Trip", nullptr));
        pushButton_BFS->setText(QCoreApplication::translate("MainWindow", "B F S", nullptr));
        pushButton_DFS->setText(QCoreApplication::translate("MainWindow", "D F S ", nullptr));
        pushButton_shortdist->setText(QCoreApplication::translate("MainWindow", "shortest Distance", nullptr));
        pushButton_dijkstra->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        pushButton_souvenir->setText(QCoreApplication::translate("MainWindow", "souvenir shop", nullptr));
        pushButton_orderTrip->setText(QCoreApplication::translate("MainWindow", "order trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
