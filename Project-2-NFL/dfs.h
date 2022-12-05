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

namespace Ui
{
     class DFS;
}

struct nodeEdge
{
    string startCity;
    string endCity;
    bool discEdge;
    int weight;

    nodeEdge()
   {
         startCity = "";
         endCity = "";
         discEdge = false;
         weight = 0;
    }
};
//================================
struct nodeVertex
{
    string city;
    bool visited;
    vector<nodeEdge> edgeList;

    nodeVertex()
    {
        city = "";
        visited = false;
    }
};
//================================
class DFS : public QWidget
{
    Q_OBJECT
public:
    explicit DFS(QWidget *parent = nullptr);
    ~DFS(){};

    void insertVertex(string city);
    int findVertex(string city);
    void insertEdge(string startCity, string endCity, int weight);
    int DFSFunction(string startingCity, vector<string> &dfsGraph);
   // vector<string> getDiscoveryEdges(vector<string> &dfsGraph);
   // vector<string> getBackEdges(vector<string> &dfsGraph);


private slots:
    void on_pushButton_clicked();

private:
    Ui::DFS *ui;

    int smallestEdgeDFS(int currVertex, vector<string> &dfs);
    int verticesVisited();
    int edgesDiscovered(int currVertex);
    //void deleteDuplicates(vector<nodeEdge> &edgeList);
    vector<nodeVertex> graph;
    int dfsDistance;
    string otherVertex(nodeEdge currEdge, string startingCity);
    int distance(nodeVertex * v1, nodeVertex * v2);

};

#endif // DFS_H

