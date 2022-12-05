#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admin.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    Admin *admin = nullptr;
};

#endif // LOGIN_H
