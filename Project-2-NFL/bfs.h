#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <iomanip>
#include "ui_bfs.h"
#include <QWidget>
#include <QString>
#include <QDebug>
#include "mst.h"

enum City {
  SEATTLE,
  SANFRANCISCO,
  LOSANGELES,
  DENVER,
  CHICAGO,
  KANSASCITY,
  DALLAS,
  HOUSTON,
  BOSTON,
  NEWYORK,
  ATLANTA,
  MIAMI,
};


namespace Ui
{
    class BFS;
}
class BFS : public QWidget
{
    Q_OBJECT
public:
    explicit BFS(QWidget *parent = nullptr);
    ~BFS() {}
    void setNextLowestIndex(int& low_index, const int& row_index, const bool city_visited[NUMBER_CITIES], const int city_edges[NUMBER_CITIES]);
    void minBFS(const int matrix[][33]);

    int matrix[33][33];

private slots:
    void on_selectTeamButton_clicked();

private:
    Ui::BFS *ui;

};

#endif // BFS_H
