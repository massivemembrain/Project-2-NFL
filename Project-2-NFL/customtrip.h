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

class CustomTrip : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTrip(); /*!< constructor*/
    ~CustomTrip(); /*!< destructor */

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
   int shortestPath(int, int);

private slots:
   void on_pushButton_find_clicked();

private:

    int matrix[NUMBER_CITIES][NUMBER_CITIES]; /*!< matrix store all the distance data*/
};

#endif // DIJKSTRA_H
