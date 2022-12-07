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

/*****************************************************************//**
 * \file   shortestDistance.h
 * \brief  perform the trip by finding the shortest distance
 *
 *
 * \date   December 2022
 *********************************************************************/

/**
 *  \namespace Ui
 */
namespace Ui
{
     class shortestDistance;
}

/**
 * \class shortestDistance
 * \public QWidget
 * \brief plan the trip based on shortest distance
 */
class shortestDistance : public QWidget
{
    Q_OBJECT
public:
    explicit shortestDistance(QWidget *parent = nullptr); /*!< constructor*/
    ~ shortestDistance() {} /*!< destructor */


private:
    Ui::shortestDistance *ui; /*!< an Ui variable*/



};







#endif // SHORTESTDISTANCE_H
