#ifndef ORDEREDTRIP_H
#define ORDEREDTRIP_H

#include <QWidget>
#include <iostream>
#include <iomanip>
#include <QSqlQueryModel>
#include "ui_orderedtrip.h"
#include "dijkstra.h"

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
    void addEdge(int,int,int);
    void shortestPath(int,int);

    int V;
    list<pair<int,int>> * adj;


private slots:
    void on_pushButton_selectOrigin_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_done_clicked();

    void on_pushButton_startAnotherTrip_clicked();

private:
    Ui::orderedTrip *ui; /*!< an Ui variable*/

    // vector holding teams
    QVector <QString> myVector;

    // vector holding distances
    QVector <int> totaldistanceVector;

    int matrix[NUMBER_CITIES][NUMBER_CITIES];

};

#endif // ORDEREDTRIP_H

