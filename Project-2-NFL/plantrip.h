#ifndef PLANTRIP_H
#define PLANTRIP_H

#include <iostream>
#include <iomanip>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "ui_planTrip.h"

namespace Ui
{
    class planTrip;
}

class planTrip : public QWidget
{
    Q_OBJECT
public:
    explicit planTrip(QWidget *parent = nullptr); /*!< constructor*/
     ~planTrip(); /*!< destructor */

private slots:
    void on_pushButton_choose_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::planTrip *ui;
    QSqlDatabase myDb;
};

#endif // PLANTRIP_H
