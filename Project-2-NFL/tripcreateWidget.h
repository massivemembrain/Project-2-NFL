#ifndef TRIPCREATEWIDGET_H
#define TRIPCREATEWIDGET_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <map>
#include "mst.h"
#include "mainwindow.h"

using namespace std;


namespace Ui {
class TripCreateWidget;
}

class TripCreateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TripCreateWidget(QWidget *parent = nullptr);
    ~TripCreateWidget();

    int V; /*!< number of vertex */

   list<pair<int, int> >* adj; /*!< list that stores wight for evry edge*/

   /**
    * \fn addEdge.
    * \brief add new edge
    * \param int
    * \param int
    * \param int
    */
   void addEdge(int , int , int);

   /**
    * \fn shortestPath.
    * \brief find the shortest path
    * \param int
    * \param int
    */
   void shortestPath(int, int);


   vector<int> teams;
   vector<QString> teamNames;


   int totalDistance;



private slots:
   void on_pushButton_done_clicked();


   void on_pushButton_select_clicked();


   void on_proceedButtons_accepted();

private:
    Ui::TripCreateWidget *ui;

    int matrix[NUMBER_CITIES][NUMBER_CITIES]; /*!< matrix store all the distance data*/

    QSqlDatabase myDb;
};

#endif // TRIPCREATEWIDGET_H
