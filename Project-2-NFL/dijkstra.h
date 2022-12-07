#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QWidget>
#include "mst.h"

namespace Ui {
class Dijkstra;
}

class Dijkstra : public QWidget
{
    Q_OBJECT

public:
    explicit Dijkstra(QWidget *parent = nullptr);
    ~Dijkstra();

    int V; // No. of vertices

       // In a weighted graph, we need to store vertex
       // and weight pair for every edge
   list<pair<int, int> >* adj;

   void addEdge(int , int , int);

   void shortestPath(int, int);

private slots:
   void on_pushButton_find_clicked();

private:
    Ui::Dijkstra *ui;

    int matrix[NUMBER_CITIES][NUMBER_CITIES];
};

#endif // DIJKSTRA_H
