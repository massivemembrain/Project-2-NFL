#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include <admin.h>

namespace Ui
{
    class Login;
}
class Login : public QMainWindow
{
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButtom_login_clicked();

private:
    Ui::Login *ui;
    Admin *admin;

};

#endif // LOGIN_H
