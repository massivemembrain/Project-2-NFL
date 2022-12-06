#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // makes the password invisible
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    //qDebug() << username << "\t" << password;
    if (username == "admin" && password == "loginasadmin")
    {
        ui->loginContainer->hide();
        admin = new Admin(this);
        admin->show();

        qInfo() << "You are now login as admin!";
    }
    else
    {
        QMessageBox::warning(this, "Login", "username or password is incorrect");
    }
}

