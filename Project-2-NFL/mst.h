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

    MST(QString sqlTable)
        : is_directed{false}, direction_matrix{vector<vector<bool>>(0, vector<bool>(0, false))},
          sqlTable{sqlTable}
      {
          vertex_name_array = vector<QString>();
          weight_matrix = vector<vector<int>>();
          // init db
          if(QSqlDatabase::contains("qt_sql_default_connection"))
          {
              sqlDatabase = QSqlDatabase::database("qt_sql_default_connection");
          }
          else
          {
              sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
          }
          sqlDatabase.setDatabaseName("C:/Users/Trazler McGrath/source/repos/Project-2-NFL/Project-2-NFL/NFLProject.db");
          if(sqlDatabase.open())
          {
              qDebug("Graph: Database opened.");
          }
          else
          {
              qDebug("Graph: Database not opened.");
          }
          // PULL IN SQL
          const int TEAM_FIELD = 0;
          const int ORIGIN_FIELD = 1;
          const int DESTINATION_FIELD = 2;
          const int DISTANCE_FIELD = 3;
          QSqlQuery query("SELECT * FROM :table");
          query.bindValue(":table", sqlTable);
          //
          QString team_name;
          QString stadium_origin_name;
          QString stadium_destination_name;
          int stadium_origin_index = -1;
          int stadium_destination_index = -1;
          query.next();
          // 1st dimension matrix access
          do
          {
              team_name = query.value(TEAM_FIELD).toString();
              stadium_origin_name = query.value(ORIGIN_FIELD).toString();
              // if stadium has not yet been added to matrix
              if( !contains(stadium_origin_name) )
              {
                   addVertex(stadium_origin_name);
              }
              stadium_origin_index = getIndexFromValue(stadium_origin_name);
              // 2nd dimension matrix access
              do
              {
                  stadium_destination_name = query.value(DESTINATION_FIELD).toString();
                  if( !contains(stadium_destination_name) )
                  {
                      addVertex(stadium_destination_name);
                  }
                  stadium_destination_index = getIndexFromValue(stadium_destination_name);
                  // Assign db weight to matrix
                  weight_matrix[stadium_origin_index][stadium_destination_index] = query.value(DISTANCE_FIELD).toInt();

                  query.next();
              } while(query.isValid() && query.value(TEAM_FIELD).toString() == team_name);
              //if()
              //QString country = query.value(0).toString();
              //doSomething(country);
          } while(query.isValid());

        //  primMST(weight_matrix);
      }

    ~MST() {}
    int minKey (int key[], bool set[]);
    void printMST(int parent[], int graph[NUMBER_CITIES][NUMBER_CITIES]);
    void primMST(int graph[NUMBER_CITIES][NUMBER_CITIES]);


    void addVertex(const QString vertex)
  {
      qDebug() << vertex;
    vertex_name_array.push_back(vertex);
    for(auto itWeight = weight_matrix.begin(); itWeight != weight_matrix.end(); itWeight++)
    {
      // same as .pushback(0), but more efficient
      itWeight->emplace_back();
    }
    weight_matrix.emplace_back();

    // CREATE IN SQL
  }

private:
    Ui::MST *ui;

    // implicit: vertex_name_array.size()
    //int NUMBER_VERTICES;
    vector<QString> vertex_name_array;
    vector<vector<int>> weight_matrix;
    vector<vector<bool>> direction_matrix;
    bool is_directed;
    QSqlDatabase sqlDatabase;
    QString sqlTable;
    //Helper functions
    const QString& getValueFromIndex( int index )
    {
       return vertex_name_array[index];
    }
    int getIndexFromValue( QString value )
    {
      for(int i = 0; i < vertex_name_array.size(); i++)
      {
        if(vertex_name_array[i] == value)
        {
          return i;
        }
      }
      cout << "Value " << value.toStdString() << " not in array.";
      return -1;
    }
    bool contains(QString& vertex)
    {
        return count(vertex_name_array.begin(), vertex_name_array.end(), vertex);
    }
};


#endif // MST_H
