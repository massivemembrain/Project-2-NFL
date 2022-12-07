#include "shortestDistance.h"
#include <QStandardItemModel>
#include <QSql>

#include"dfs.h"

int minFunction2(double arr[], int size, int *index);

//prototype
void travelEfficiently(Ui::shortestDistance* ui,QStandardItemModel *model, QString city,
                      int count,QVector<QString> Prohibited_City_Names,
                      int row, int column,double total_kilometers);


shortestDistance::shortestDistance(QWidget *parent) :
                   QWidget(parent),
                   ui(new Ui::shortestDistance)
{
        ui->setupUi(this);
/*
        QSqlDatabase myDb;

        if(QSqlDatabase::contains("qt_sql_default_connection"))
        {
            myDb = QSqlDatabase::database("qt_sql_default_connection");
        }
        else
        {
            myDb = QSqlDatabase::addDatabase("QSQLITE");
        }

        //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/Project-2-NFL/NFLProject.db");
        //myDb.setDatabaseName("../NFLProject.db");
        if (myDb.open())
        {
            qDebug().noquote() << "db found and open";
        }
        else
        {
            qDebug().noquote() << "db not found";
        }


        QStandardItemModel *model = new QStandardItemModel(0,4);
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("Starting City Name"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("Ending City Name"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("Kilometers"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("Total Distance Traveled"));

             ui->tableView->setModel(model);
             ui->tableView->show();

            //QString city = "Lambeau";
             QString city = "Gillette Stadium";

             QVector<QString> Prohibited_City_Names;
             double total_kilometers = 0;

             // call to the recursive function
             travelEfficiently(ui,model,city,12,Prohibited_City_Names,0,0,total_kilometers);
*/
             DFS G;

             // code to insert vertices from db
             QSqlQuery *qry1 = new QSqlQuery();
             qry1->prepare("select DISTINCT Starting_Stadium from Distances");

             if (qry1->exec())
             {
                 while(qry1->next())
                 {
                     G.insertVertex(qry1->value(0).toString().toStdString());
                 }
             }

             // code to insert edges from db
             QSqlQuery *qry2 = new QSqlQuery();
             qry2->prepare("select * from Distances");

             if (qry2->exec())
             {
                 while(qry2->next())
                 {
                     G.insertEdge(qry2->value(1).toString().toStdString(), // starting stadium
                                  qry2->value(2).toString().toStdString(), // ending stadium
                                  qry2->value(3).toInt());                 // distance
                 }
             }


             vector<string> dfsVertexList; // Will hold the vertecies in the correct order of a DFS

             // Will perform the DFS starting at chosen vertex and store the vertecies
             // while also calculating the total distance
             //int totalDistance = G.DFSFunction("U.S. Bank Stadium", dfsVertexList);
             int totalDistance = G.DFSFunction("Gillette Stadium", dfsVertexList);


             // Will loop around the dfsvertexlist vector and display the elements
             //in the correct order of the dfs
           for (int i = 0; i < dfsVertexList.size(); i++)
            {
               ui -> textBrowser -> append(QString::number(i+1) + " - "  + QString::fromStdString(dfsVertexList.at(i)));
            }

           ui -> textBrowser -> append("\nTotal distance traveled : " + QString::number(totalDistance));
}
/*
// ===========================================================
int minFunction2(double arr[], int size, int *index)
{
    int min;
    for(int i = 0 ; i < size ; i++)
    {
        if(i==0)
        {
            min = arr[i];
            *index = i;
        }
        else
        {
            if(min > arr[i])
            {
                min = arr[i];
                *index = i;
            }
        }
    }
    return min;
}
// ===========================================================
void travelEfficiently(Ui::shortestDistance* ui,QStandardItemModel *model, QString city,
                      int count,QVector<QString> Prohibited_City_Names,
                      int row, int column,double total_kilometers)
{
    QSqlQuery query;
    QString Ending_City_Names[30];
    double Kilometers[30];
    int index = 0;
    QString min_city;
    double min_kilometer;

    bool flag = true;
    int size = 0;

    query.exec("SELECT Ending_Stadium, Distance FROM Distances WHERE Starting_Stadium LIKE '%"+city+"%'");

                while(query.next())
                {
                    if(count!=30)
                    {// not the first time
                        for (int i = 0; i < Prohibited_City_Names.size(); ++i)
                        {
                            if (Prohibited_City_Names.at(i) == query.value(0).toString())
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag)
                    {
                        Ending_City_Names[index] = query.value(0).toString();
                        Kilometers[index++] = query.value(1).toDouble();
                        //flag = true;
                        size++;
                    }
                    flag = true;

                }

                int city_index=0; // respective city name index will be returned from function into the pointer
                min_kilometer = minFunction2(Kilometers,size,&city_index);
                min_city = Ending_City_Names[city_index];

                Prohibited_City_Names.push_back(city);

                QStandardItem *item0 = new QStandardItem(QString(city));
                model->setItem(row,column++,item0);

                QStandardItem *item1 = new QStandardItem(QString(min_city));
                model->setItem(row,column++,item1);

                QStandardItem *item2 = new QStandardItem(QString(QString::number(min_kilometer)));
                model->setItem(row,column++,item2);
                total_kilometers+=min_kilometer;

               ui->tableView->update();
               row++;
               column=0;

               if(count > 1)
                    travelEfficiently(ui, model, min_city, --count, Prohibited_City_Names, row, column,total_kilometers);
               else
               {
                   QStandardItem *item2 = new QStandardItem(QString(QString::number(total_kilometers)+" distance"));
                   model->setItem(--row,3,item2);
                   ui->tableView->update();
               }
}
*/
