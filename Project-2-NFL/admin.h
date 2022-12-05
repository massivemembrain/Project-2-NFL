#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

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
    Ui::Admin *ui;
    QSqlDatabase myDb;
};

#endif // ADMIN_H
