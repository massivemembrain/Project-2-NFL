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


const int NUMBER_CITIES = 12;


const QString CityToStr[NUMBER_CITIES] = {
    "Seattle", "San Francisco", "Los Angeles", "Denver",
    "Chicago", "Kansas City",   "Dallas",      "Houston",
    "Boston",  "New York",      "Atlanta",     "Miami"};


/*
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
    "Hard Rock Stadium",         // i = 18
    "U.S. Bank Stadium",         // i = 19
    "Gillette Stadium",          // i = 20
    "Caesars Superdome",         // i = 21
    "MetLife Stadium",           // i = 22
    "Lincoln Financial Field",   // i = 23
    "Acrisure Stadium",          // i = 24
    "Levi's Stadium",            // i = 25
    "Lumen Field",               // i = 26
    "Raymond James Stadium"      // i = 27
    "Nissan Stadium",            // i = 28
    "FedExField"                 // i = 29
  };
*/


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

private:
    Ui::MST *ui;

};


#endif // MST_H
