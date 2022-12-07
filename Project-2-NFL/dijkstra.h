#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QWidget>
#include "mst.h"

/*****************************************************************//**
 * \file   dijkstra.h
 * \brief  dijkstra object to perform Dijkstra algorithm
 *
 *
 * \date   December 2022
 *********************************************************************/

/**
 *  \namespace Ui
 */
namespace Ui {
class Dijkstra;
}

/**
 * \class Dijkstra
 * \public QWidget
 * \brief Dijkstra class perform Dijkstra algorithm
 */
class Dijkstra : public QWidget
{
    Q_OBJECT

public:
    explicit Dijkstra(QWidget *parent = nullptr); /*!< constructor*/
    ~Dijkstra(); /*!< destructor */

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

private slots:
   void on_pushButton_find_clicked();

private:
    Ui::Dijkstra *ui; /*!< an Ui variable*/

    int matrix[NUMBER_CITIES][NUMBER_CITIES]; /*!< matrix store all the distance data*/
};

#endif // DIJKSTRA_H
