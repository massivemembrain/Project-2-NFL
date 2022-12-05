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
    Arizona_Cardinals, Atlanta_Falcons, Baltimore_Ravens, Buffalo_Bills,
    Carolina_Panthers,   Chicago_Bears,  Cincinnati_Bengals, Cleveland_Browns,
    Dallas_Cowboys,  Denver_Broncos,      Detroit_Lions,     Green_Bay_Packers,
    Houston_Texans,  Indianapolis_Colts,  Jacksonville_Jaguars, Kansas_City_Chiefs,
    Las_Vegas_Raiders, Los_Angeles_Chargers, Los_Angeles_Rams, Miami_Dolphins,
    Minnesota_Vikings, New_England_Patriots, New_Orleans_Saints, New_York_Giants,
    New_York_Jets, Philadelphia_Eagles, Pittsburgh_Steelers, San_Francisco_49ers,
    Seattle_Seahawks, Tampa_Bay_Buccaneers, Tennessee_Titans, Washington_Redskins
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
    void minBFS(const int matrix[][33], int origin);
    City origin_vertex;

    int matrix[33][33];

private slots:
    void on_selectTeamButton_clicked();

private:
    Ui::BFS *ui;

};

#endif // BFS_H
