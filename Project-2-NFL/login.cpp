#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QMainWindow{parent},
    ui(new Ui::Login)
{
    ui -> setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButtom_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "loginasadmin")
    {
        hide();
        admin = new Admin(this);
        admin->show();
        qInfo() << "You are now login as admin!";
    }
    else
    {
        QMessageBox::warning(this, "Login", "username or password is incorrect");
    }
}

