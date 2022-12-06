#ifndef MST_H
#define MST_H

#include <iostream>
//#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#include"ui_mst.h"

#include <QWidget>
#include <QDebug>
#include<QString>
#include <QSqlDatabase>
#include <QSqlQuery>

const int NUMBER_CITIES = 33;

/*
const QString CityToStr[NUMBER_CITIES] = {
    "Arizona Cardinals", "Atlanta Falcons", "Baltimore Ravens", "Buffalo Bills",
    "Carolina Panthers",   "Chicago Bears",  "Cincinnati Bengals", "Cleveland Browns"
    "Dallas Cowboys",  "Denver Broncos",      "Detroit Lions",     "Green Bay Packers"
    "Houston Texans"  "Indianapolis Colts"  "Jacksonville Jaguars" "Kansas City Chiefs"
    "Las Vegas Raiders" "Los Angeles Chargers" "Los Angeles Rams" "Miami Dolphins"
    "Minnesota Vikings" "New England Patriots" "New Orleans Saints" "New York Giants"
    "New York Jets" "Philadelphia Eagles" "Pittsburgh Steelers" "San Francisco 49ers"
    "Seattle Seahawks" "Tampa Bay Buccaneers" "Tennessee Titans" "Washington Redskins"};
*/

const QString CityToStr[NUMBER_CITIES] =
{
    "State Farm Stadium",        // i = 0
    "Mercedes-Benz Stadium",     // i = 1
    "M&T Bank Stadium",          // i = 2
    "Highmark Stadium",          // i = 3
    "Bank of America Stadium",   // i = 4
    "Soldier Field",             // i = 5
    "Paycor Stadium",            // i = 6
    "FirstEnergy Stadium",       // i = 7
    "AT&T Stadium",              // i = 8
    "Empower Field at Mile High",// i = 9
    "Ford Field",                // i = 10
    "Lambeau Field",             // i = 11
    "NRG Stadium",               // i = 12
    "Lucas Oil Stadium",         // i = 13
    "TIAA Bank Field",           // i = 14
    "Arrowhead Stadium",         // i = 15
    "Allegiant Stadium",         // i = 16
    "SoFi Stadium",              // i = 17
    "SoFi Stadium",              // i = 18
    "Hard Rock Stadium",         // i = 19
    "U.S. Bank Stadium",         // i = 20
    "Gillette Stadium",          // i = 21
    "Caesars Superdome",         // i = 22
    "MetLife Stadium",           // i = 23
    "MetLife Stadium",           // i = 24
    "Lincoln Financial Field",   // i = 25
    "Acrisure Stadium",          // i = 26
    "Levi's Stadium",            // i = 27
    "Lumen Field",               // i = 28
    "Raymond James Stadium"      // i = 29
    "Nissan Stadium",            // i = 30
    "FedExField"                 // i = 31
  };



namespace Ui
{
     class MST;
}

class MST :  public QWidget
{
    Q_OBJECT
public:
    explicit MST(QWidget *parent = nullptr);
    ~MST() {}
    int minKey (int key[], bool set[]);
    void printMST(int parent[], int graph[NUMBER_CITIES][NUMBER_CITIES]);
    void primMST(int graph[NUMBER_CITIES][NUMBER_CITIES]);

    int matrix2[33][33];

private:
    Ui::MST *ui;

};


#endif // MST_H
