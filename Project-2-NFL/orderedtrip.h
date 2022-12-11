#ifndef ORDEREDTRIP_H
#define ORDEREDTRIP_H

#include <QWidget>
#include <iostream>
#include <iomanip>
#include <QSqlQueryModel>
#include "ui_orderedtrip.h"

namespace Ui
{
     class orderedTrip;
}


class OrderedTrip :  public QWidget
{
    Q_OBJECT
public:
    explicit OrderedTrip(QWidget *parent = nullptr);
    ~OrderedTrip();


private slots:
    void on_pushButton_selectOrigin_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_done_clicked();

    void on_pushButton_startAnotherTrip_clicked();

private:
    Ui::orderedTrip *ui; /*!< an Ui variable*/

};

#endif // ORDEREDTRIP_H
