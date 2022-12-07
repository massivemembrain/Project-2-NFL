#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlQueryModel>

/*****************************************************************//**
 * \file   amin.h
 * \brief  admin object to perform all the featurns for maintenance
 *
 *
 * \date   December 2022
 *********************************************************************/


/**
 *  \namespace Ui
 */
namespace Ui {
class Admin;
}

/**
 * \class Admin
 * \public QWidget
 * \brief Admin contains all the featurns for maintenance
 */
class Admin : public QWidget
{
    Q_OBJECT

public:

    explicit Admin(QWidget *parent = nullptr); /*!< constructor*/
    ~Admin(); /*!< destructor */


private slots:


    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_editButton_clicked();

    void on_editStadiumButton_clicked();

    void on_editCapacityButton_clicked();

    void on_pushButton_clicked();

    void on_importButton_2_clicked();

    void on_importButton_3_clicked();

    void on_testingButton_clicked();

private:
    Ui::Admin *ui; /*!< an Ui variable*/
    QSqlDatabase myDb; /*!< a database variable*/
};

#endif // ADMIN_H
