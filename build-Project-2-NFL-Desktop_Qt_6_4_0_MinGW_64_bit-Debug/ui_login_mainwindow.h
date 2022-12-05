/********************************************************************************
** Form generated from reading UI file 'login_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_MAINWINDOW_H
#define UI_LOGIN_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_mainwindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_login;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *username;
    QLabel *password;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login_mainwindow)
    {
        if (Login_mainwindow->objectName().isEmpty())
            Login_mainwindow->setObjectName("Login_mainwindow");
        Login_mainwindow->resize(800, 600);
        centralwidget = new QWidget(Login_mainwindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 30, 671, 481));
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(230, 290, 191, 61));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 130, 71, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username = new QLabel(verticalLayoutWidget);
        username->setObjectName("username");

        verticalLayout->addWidget(username);

        password = new QLabel(verticalLayoutWidget);
        password->setObjectName("password");

        verticalLayout->addWidget(password);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(130, 120, 451, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout_2->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout_2->addWidget(lineEdit_password);

        Login_mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login_mainwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Login_mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Login_mainwindow);
        statusbar->setObjectName("statusbar");
        Login_mainwindow->setStatusBar(statusbar);

        retranslateUi(Login_mainwindow);

        QMetaObject::connectSlotsByName(Login_mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Login_mainwindow)
    {
        Login_mainwindow->setWindowTitle(QCoreApplication::translate("Login_mainwindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Login_mainwindow", "Admin Login", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Login_mainwindow", "LOGIN \"click\" here", nullptr));
        username->setText(QCoreApplication::translate("Login_mainwindow", "Username:", nullptr));
        password->setText(QCoreApplication::translate("Login_mainwindow", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_mainwindow: public Ui_Login_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_MAINWINDOW_H
