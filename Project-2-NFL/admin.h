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
    void on_comboBox_activated(int index);

private:
    Ui::Admin *ui;

};

#endif // ADMIN_H
