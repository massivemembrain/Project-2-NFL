#include "mst.h"
#include "ui_mst.h"
#include"bfs.h"

#include <QWidget>


MST:: MST(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MST)
{
    ui->setupUi(this);


    // Adjacency Matrix
     // int city_edges_adjacency_matrix[NUMBER_CITIES][NUMBER_CITIES] = {
    //  /*Seattle*/ {0, 807, 0, 1331, 2097, 0, 0, 0, 0, 0, 0, 0},
    //  /*SanFran*/ {807, 0, 381, 1267, 0, 0, 0, 0, 0, 0, 0, 0},
    //  /*LosAnge*/ {0, 381, 0, 1015, 0, 1663, 1435, 0, 0, 0, 0, 0},
    //  /*Denver */ {1331, 1267, 1015, 0, 1003, 599, 0, 0, 0, 0, 0, 0},
    //  /*Chicago*/ {2097, 0, 0, 1003, 0, 533, 0, 0, 983, 787, 0, 0},
    //  /*KansasC*/ {0, 0, 1663, 599, 533, 0, 496, 0, 0, 1260, 864, 0},
    //  /*Dallas */ {0, 0, 1435, 0, 0, 496, 0, 239, 0, 0, 781, 0},
    //  /*Houston*/ {0, 0, 0, 0, 0, 0, 239, 0, 0, 0, 810, 1187},
    //  /*Boston */ {0, 0, 0, 0, 983, 0, 0, 0, 0, 214, 0, 0},
    // /*NewYork*/ {0, 0, 0, 0, 787, 1260, 0, 0, 214, 0, 888, 0},
     // /*Atlanta*/ {0, 0, 0, 0, 0, 864, 781, 810, 0, 888, 0, 661},
     // /*Miami  */ {0, 0, 0, 0, 0, 0, 0, 1187, 0, 0, 661, 0}};


       //primMST(city_edges_adjacency_matrix);
         // primMST(matrix);

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
    //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/NFLProject.db");
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
    }

    for (int i = 0; i < NUMBER_CITIES; i++)
    {
        for (int j = 0; j < NUMBER_CITIES; j++)
        {
            qDebug() << matrix2[i][j];
        }
    }
   // primMST(matrix2);

}

// ********************************
// search for the min weight
// ********************************
int MST:: minKey (int key[], bool set[])
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
void MST:: printMST(int parent[], int graph[NUMBER_CITIES][NUMBER_CITIES])
{
    int total = 0;

    ui -> textBrowser -> append("MINIMUM SPANNING TREE:\n");
    for (int i = 1; i < NUMBER_CITIES; i++)
    {
        // converting int(weight) to qstring
        QString s = QString::number(graph[i][parent[i]]);

        ui -> textBrowser -> append(CityToStr[parent[i]] + " --> " + CityToStr[i] + " \t" + s);

        total += graph[i][parent[i]];
    }
    // converting int(total distance) to qstring
    QString t = QString::number(total);
    ui -> textBrowser -> append("\ntotal distance: " + t);
}
// ********************************
// prim jarnik's MST algorithm
// ********************************
void MST:: primMST(int graph[NUMBER_CITIES][NUMBER_CITIES])
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
