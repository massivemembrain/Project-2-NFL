#include "mst.h"
#include "ui_mst.h"
#include "bfs.h"

#include <QWidget>
#include<iostream>

MST:: MST(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MST)
{
    ui->setupUi(this);

    // declaring our matrix here
    int matrix2[NUMBER_CITIES][NUMBER_CITIES];

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    myDb.setDatabaseName("../NFLProject.db");
    if (myDb.open())
    {
        qDebug().noquote() << "db found and open";
    }
    else
    {
        qDebug().noquote() << "db not found";
    }

    for (int i = 0; i < NUMBER_CITIES; i++)
    {
        for (int j = 0; j < NUMBER_CITIES; j++)
        {
            matrix2[i][j] = 0;
        }
    }

    QSqlQuery query;
    query.prepare("SELECT Start_Number, End_Number, Distance FROM Distances");
    query.exec();

    int start;
    int end;

    for (int i = 0; query.next(); i++)
    {
        start = query.value(0).toInt();
        end = query.value(1).toInt();

        matrix2[start][end] = query.value(2).toInt();
        //cout << "["<< start << "]" << "[" << end << "]" << " = " << matrix2[start][end]  << endl;
    }

    for (int i = 0; i < NUMBER_CITIES; i++)
    {
        for (int j = 0; j < NUMBER_CITIES; j++)
        {
            //qDebug() << matrix[i][j];
            //cout << "["<< i << "]" << "[" << j << "]" << " = " << matrix2[i][j]  << endl;
        }
    }

       // calling the prim mst function
       primMST(matrix2);
}

// ********************************
// search for the min weight
// ********************************
int MST :: minKey (int key[], bool set[])
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < NUMBER_CITIES; i++)
    {
        if (set[i] == false && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
// ********************************
// A utility function to print the
// constructed MST stored in parent[]
// ********************************

void MST ::printMST(int parent[], int graph[NUMBER_CITIES][NUMBER_CITIES])
{
    int total = 0;

    for (int i = 1; i < NUMBER_CITIES; i++)
      {
        // converting int(weight) to qstring
        QString s = QString::number(graph[i][parent[i]]);

         ui -> textBrowser-> append( CityToStr[parent[i]] + " -> " + CityToStr[i] + " \t" +  s + " \n");
          total += graph[i][parent[i]];
      }
      //converting int(total distance) to qstring
       QString t = QString::number(total);

      ui -> textBrowser -> append("\n***************************************************************************");
      ui -> textBrowser-> append( "Total mileage is " + t + " miles.");
      ui -> textBrowser -> append("***************************************************************************");
}

// ********************************
// prim jarnik's MST algorithm
// ********************************
void MST :: primMST(int graph[NUMBER_CITIES][NUMBER_CITIES])
{
    int parent[NUMBER_CITIES];
    int key[NUMBER_CITIES];
    bool set[NUMBER_CITIES];

    for (int i =0; i < NUMBER_CITIES; i++)
    {
        key[i]= INT_MAX;
        set[i] = false;
    }

   key[0] = 0;
   parent[0] = -1;

    for (int j = 0; j < NUMBER_CITIES - 1; j++)
    {
        int u = minKey(key, set);
        set[u] = true;
        for (int k = 0; k < NUMBER_CITIES; k++)
        {
            if ((graph[u][k] && set[k] == false) && (graph[u][k] < key[k]))
            {
                parent[k] = u;
                key[k] = graph[u][k];
            }
        }
    }
    printMST(parent, graph);
}



