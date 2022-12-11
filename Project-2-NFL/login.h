#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admin.h"

/*****************************************************************//**
 * \file   dfs.h
 * \brief  dfs object to perform DFS algorithm
 *
 *
 * \date   December 2022
 *********************************************************************/


/**
 *  \namespace Ui
 */
namespace Ui {
class Login;
}

/**
 * \class Login
 * \public QWidget
 * \brief Login window to login as admin
 */
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr); /*!< constructor*/
     ~Login(); /*!< destructor */


private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Login *ui; /*!< an Ui variable*/
    Admin *admin = nullptr; /*!< an admin pointer*/
};

#endif // LOGIN_H
