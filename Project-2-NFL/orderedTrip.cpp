#include "orderedtrip.h"
#include "ui_orderedtrip.h"
#include <QTableView>
#include <QTableWidget>
#include <QItemSelectionModel>
#include<QVector>
#include<queue>
#include<QSqlQueryModel>


const int INF = 9999;
typedef pair<int, int> iPair;

OrderedTrip::OrderedTrip(QWidget *parent)
    :     QWidget(parent),
      ui(new Ui::orderedTrip)
{
    ui->setupUi(this);

    this->V = NUMBER_CITIES;
    adj = new list<iPair>[V];

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    //myDb.setDatabaseName("/Users/nedamohseni/Documents/GitHub/Project-2-NFL/NFLProject.db");
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
            matrix[i][j] = 0;
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

        matrix[start][end] = query.value(2).toInt();
    }

    for (int u = 0; u < NUMBER_CITIES; u++)
        {
          for(int v = u + 1; v < NUMBER_CITIES; v++)
          {
            if(matrix[u][v] != 0)
            {
              addEdge(u, v, matrix[u][v]);
            }
          }
        }

    // code for combobox options
    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT DISTINCT Team FROM Distances");
    ui->comboBox->setModel(comboquery);
}
// =============================================================================
 OrderedTrip :: ~ OrderedTrip()
 {
     myVector.clear();
     totaldistanceVector.clear();
     ui -> textBrowser -> clear();
 }
// =============================================================================
void OrderedTrip::on_pushButton_selectOrigin_clicked()
{
    // stores the team selected in combobox in a variable
    QString originTeam = ui-> comboBox ->currentText();

    myVector.push_back(originTeam);

     //ui -> textBrowser -> insertPlainText("start Team : " + originTeam + "\n");

    QSqlQueryModel* qryModel = new QSqlQueryModel();
    qryModel->setQuery("SELECT DISTINCT Team FROM Distances WHERE Team NOT LIKE '%"+ originTeam +"%' ");
   ui->tableView->setModel(qryModel);
   ui->tableView->setAlternatingRowColors(true);
   ui->tableView->horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
}
// ===================================================================================
void OrderedTrip::on_tableView_clicked(const QModelIndex &index)
{
   ui -> tableView -> setSelectionMode(QAbstractItemView::MultiSelection);
   ui -> tableView -> setSelectionBehavior(QAbstractItemView:: SelectItems);

    // gets the data on the which was cell clicked on & store it in chosen
    QString chosen = ui -> tableView -> model() -> data(index).toString();

    qDebug() << "selected : " << chosen;

    myVector.push_back(chosen);

    //ui -> textBrowser -> insertPlainText(chosen);
    // ui -> textBrowser -> insertPlainText("\n");
}
// ======================================================================================
void OrderedTrip::on_pushButton_done_clicked()
{
    ui -> textBrowser -> append("order of your trip:\n");

    for (int i = 0; i < myVector.size(); i ++)
    {
         ui -> textBrowser -> append(QString::number(i+1) + " - " + myVector.at(i));
    }

    QString startString;
    QString endString;

    for (int i = 0; i < myVector.size() - 1  ; i ++)
    {
       QSqlQuery query;
       query.prepare("SELECT Start_Number FROM Distances WHERE Team = :Team");
       query.bindValue(":Team", myVector.at(i));
       query.exec();

       if (query.first())
           startString = query.value(0).toString();

       int start = startString.toInt();

       // ======================================

       QSqlQuery query2;
       query2.prepare("SELECT Start_Number FROM Distances WHERE Team = :Team");
       query2.bindValue(":Team", myVector.at(i+1));
       query2.exec();

       if (query2.first())
           endString = query2.value(0).toString();

       int end = endString.toInt();

       //qDebug() << "initial :" << myVector.at(i);
       //qDebug() << "final :" << myVector.at(i+1);

       // calling dij function
       shortestPath(start, end);
  }
    int totDist = 0;

    for (int i = 0; i < totaldistanceVector.size(); i ++)
    {
        totDist += totaldistanceVector.at(i);
    }

   ui -> textBrowser -> append("\n\n*************************");
   ui -> textBrowser -> append("total distance: "  + QString::number(totDist));
   ui -> textBrowser -> append("*************************");

}
// =====================================================
void OrderedTrip::on_pushButton_startAnotherTrip_clicked()
{
    myVector.clear();
    totaldistanceVector.clear();
    ui -> textBrowser -> clear();
}
// =============================================
void OrderedTrip::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
// =============================================
void OrderedTrip::shortestPath(int src, int end)
{
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    vector<int> vertices_to_destination;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;
    vertices_to_destination.push_back(src);

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int> >::iterator i;
      int save_v = 0;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));

                save_v = v;
            }
        }
      vertices_to_destination.push_back(save_v);
    }

    QString str = QString::number(dist[end]);
    totaldistanceVector.push_back(dist[end]);

    ui -> textBrowser -> append ( "\n" + CityToTeam[src] + " --> " + CityToTeam[end] + ": " + str + " km");

}

