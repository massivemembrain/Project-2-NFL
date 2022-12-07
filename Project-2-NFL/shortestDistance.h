#ifndef SHORTESTDISTANCE_H
#define SHORTESTDISTANCE_H

#include <QWidget>
#include"ui_shortestDistance.h"

#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QStandardItemModel>

namespace Ui
{
     class shortestDistance;
}

class shortestDistance : public QWidget
{
    Q_OBJECT
public:
    explicit shortestDistance(QWidget *parent = nullptr);
    ~ shortestDistance() {}


private:
    Ui::shortestDistance *ui;



};







#endif // SHORTESTDISTANCE_H
