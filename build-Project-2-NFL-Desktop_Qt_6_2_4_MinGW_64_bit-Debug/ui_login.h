/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *loginContainer;
    QPushButton *pushButton_login;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *username;
    QLabel *password;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(640, 480);
        loginContainer = new QWidget(Login);
        loginContainer->setObjectName(QString::fromUtf8("loginContainer"));
        loginContainer->setGeometry(QRect(10, 10, 621, 461));
        pushButton_login = new QPushButton(loginContainer);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(220, 300, 191, 61));
        verticalLayoutWidget_2 = new QWidget(loginContainer);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(120, 130, 451, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));

        verticalLayout_2->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        verticalLayout_2->addWidget(lineEdit_password);

        verticalLayoutWidget = new QWidget(loginContainer);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 140, 71, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username = new QLabel(verticalLayoutWidget);
        username->setObjectName(QString::fromUtf8("username"));

        verticalLayout->addWidget(username);

        password = new QLabel(verticalLayoutWidget);
        password->setObjectName(QString::fromUtf8("password"));

        verticalLayout->addWidget(password);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Login", "LOGIN \"click\" here", nullptr));
        username->setText(QCoreApplication::translate("Login", "Username:", nullptr));
        password->setText(QCoreApplication::translate("Login", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
