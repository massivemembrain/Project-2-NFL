#ifndef DFS_H
#define DFS_H

#include <QWidget>
#include <iostream>
#include <iomanip>
#include <QWidget>
#include <QDebug>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include"ui_dfs.h"

/*****************************************************************//**
 * \file   dfs.h
 * \brief  dfs object to perform DFS algorithm
 *
 *
 * \date   December 2022
 *********************************************************************/

/**
 *  \namespace Ui
 */
namespace Ui
{
     class DFS;
}

/**
 *  \struct  nodeEdge
 */
struct nodeEdge
{
    string startCity; /*!< starting city*/
    string endCity; /*!< ending city*/
    bool discEdge; /*!< tell if the edge is discovered*/
    int weight; /*!< distance*/

    nodeEdge()
   {
         startCity = "";
         endCity = "";
         discEdge = false;
         weight = 0;
    }
};
//================================

/**
 *  \struct  nodeVertex
 */
struct nodeVertex
{
    string city; /*!< starting city*/
    bool visited; /*!< tell if the city is visited*/
    vector<nodeEdge> edgeList; /*!< stores all the edge*/

    nodeVertex()
    {
        city = "";
        visited = false;
    }
};
//================================

/**
 * \class DFS
 * \public QWidget
 * \brief DFS class perform DFS algorithm
 */
class DFS : public QWidget
{
    Q_OBJECT
public:
    explicit DFS(QWidget *parent = nullptr); /*!< constructor*/
    ~DFS(){}; /*!< destructor */

    /**
     * \fn insertVertex.
     * \brief insert new city
     * \param city
     */
    void insertVertex(string city);

    /**
     * \fn findVertex.
     * \brief find the city
     * \param city
     * \return index
     */
    int findVertex(string city);

    /**
     * \fn insertEdge.
     * \brief insert new distance
     * \param startCity
     * \param endCity
     * \param weight
     */
    void insertEdge(string startCity, string endCity, int weight);

    /**
     * \fn DFSFunction.
     * \brief perform the DFS algorithm
     * \param startCity
     * \param &dfsGraph
     * \return dfsDistance
     */
    int DFSFunction(string startingCity, vector<string> &dfsGraph);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DFS *ui; /*!< an Ui variable*/

    /**
     * \fn smallestEdgeDFS.
     * \brief find the smallest edge
     * \param currVertex
     * \param &dfs
     * \return smallestEdgeDFS
     */
    int smallestEdgeDFS(int currVertex, vector<string> &dfs);

    /**
     * \fn verticesVisited.
     * \brief tell the number of visited vertex
     * \param currVertex
     * \param &dfs
     * \return numVisited
     */
    int verticesVisited();

    /**
     * \fn edgesDiscovered.
     * \brief find the smallest edge
     * \param currVertex
     * \return numVisited
     */
    int edgesDiscovered(int currVertex);


    vector<nodeVertex> graph; /*!< vector stores the nodeVertex*/
    int dfsDistance; /*!< vtotal distance for DFS*/

    /**
     * \fn otherVertex.
     * \brief tell the other city on the same adge
     * \param currEdge
     * \param startingCity
     * \return currEdge.endCity
     * \return currEdge.startCity
     */
    string otherVertex(nodeEdge currEdge, string startingCity);

    /**
     * \fn distance.
     * \brief return the weight of the edge which is distance
     * \param v1
     * \param v2
     * \return v1->edgeList.at(i).weight
     * \return -1
     */
    int distance(nodeVertex * v1, nodeVertex * v2);

};

#endif // DFS_H

