#ifndef LOGIN_MAINWINDOW_H
#define LOGIN_MAINWINDOW_H

#include <QWidget>
#include <QWidget>
#include <admin.h>

namespace Ui
{
    class Login;
}
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButtom_login_clicked();

private:
    Ui::Login *ui;
    Admin *admin;

};

#endif // LOGIN_MAINWINDOW_H
