#include "qsqlquery.h"
#include "ui_tripcreateWidget.h"
#include "tripcreateWidget.h"
#include "customtrip.h"
#include <queue>

const int INF = 9999;
typedef pair<int, int> iPair;
int currentTeam;
int totalCost;

TripCreateWidget::TripCreateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TripCreateWidget)
{
    ui->setupUi(this);
    this->V = NUMBER_CITIES;
    adj = new list<iPair>[V];
    totalDistance = 0;

    ui->comboBox_algorithm->addItem("Selective");
    ui->comboBox_algorithm->addItem("Shortest");


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

     QSqlQueryModel* qryModel2 = new QSqlQueryModel();
     ui->teamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->teamTable->setAlternatingRowColors(true);

     qryModel2->setQuery("SELECT DISTINCT Team FROM Distances");

     ui->teamTable->setModel(qryModel2);

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

     QSqlQueryModel* comboquery = new QSqlQueryModel();
     comboquery->setQuery("SELECT DISTINCT Team FROM Distances");
     ui->comboBox_team->setModel(comboquery);


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

}

void TripCreateWidget::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void TripCreateWidget::shortestPath(int src, int end)
{
 // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
        // Container for every vertice traversed from src to destination
        vector<int> vertices_to_destination;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INF);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, src));
        dist[src] = 0;
        vertices_to_destination.push_back(src);

        /* Looping till priority queue becomes empty (or all
        distances are not finalized) */
        while (!pq.empty()) {

            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a
            // vertex
            list<pair<int, int> >::iterator i;
          int save_v = 0;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                // Get vertex label and weight of current
                // adjacent of u.
                int v = (*i).first;
                int weight = (*i).second;

                // If there is a shorter path to v through u.
                if (dist[v] > dist[u] + weight) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));

                    save_v = v;
                }
            }
          vertices_to_destination.push_back(save_v);

        }
        qDebug() << "I made it this far" << CityToTeam[end];

        totalDistance += dist[end];

//       //  Print shortest distances stored in dist[]
//        qDebug() << "\n\nCity Distance from " << CityToTeam[src] << " to\n";

//        qDebug() << CityToTeam[end] << ": " << dist[end] << " km\n";
//        QString str = QString::number(dist[end]);

//        qDebug -> textBrowser -> append ("\n\nCity Distance from " + CityToTeam[src] + " to\n");
//        ui -> textBrowser -> append (CityToTeam[end] + ": " + str + " km\n");


}

TripCreateWidget::~TripCreateWidget()
{
    myDb.close();
    qDebug("Database closed.");
    delete ui;


}




void TripCreateWidget::on_pushButton_done_clicked()
{
    if (ui->comboBox_algorithm->currentText() == "Selective")
    {

    for (auto i = 1; i < teams.size(); i++)
        shortestPath(teams[i - 1], teams[i]);

    QString intToString = QString::number(totalDistance);
    ui->textBrowser_team->append("Total Distance: " + intToString);

    QSqlQuery query;
    for (int i = 0; i < teamNames.size(); i++)
    {
        query.prepare("INSERT INTO Custom_Trip (City) VALUES (:Team)");
        query.bindValue(":Team", teamNames[i]);
        qDebug() << query.exec();
    }
    }
    else if (ui->comboBox_algorithm->currentText() == "Shortest")
    {
        int smallestDistance[33] = { 0 };
        int size = teams.size();
        smallestDistance[0] = teams[0];
        teams.erase(teams.begin() + 0);
        for (auto i = 1; !teams.empty(); i++)
        {
            smallestDistance[i] = teams[0];
            for (auto j = 0; j < teams.size(); j++)
            {
                if (shortestPathCompare(smallestDistance[i - 1], teams[j]) < shortestPathCompare(smallestDistance[i - 1], smallestDistance[i]))
                {
                    smallestDistance[i] = teams[j];
                }
            }

            for (auto j = 0; j < teams.size(); j++)
            {
                if (smallestDistance[i] == teams[j])
                {
                    teams.erase(teams.begin() + j);
                }
            }



        }

        for (auto i = 1; i < size; i++)
        {
            shortestPath(smallestDistance[i - 1], smallestDistance[i]);
        }

        QString intToString = QString::number(totalDistance);
        ui->textBrowser_team->append("Total Distance: " + intToString);

        QSqlQuery query;
        for (int i = 0; i < size; i++)
        {
            query.prepare("INSERT INTO Custom_Trip (City) VALUES (:Team)");
            query.bindValue(":Team", teamNames[i]);
            qDebug() << query.exec();
        }

    }

}


void TripCreateWidget::on_pushButton_select_clicked()
{
    QString teamString;
    QString numberString;
    QSqlQuery query;
    query.prepare("SELECT Team, Start_Number FROM Distances WHERE Team = :Team");
    query.bindValue(":Team", ui->comboBox_team->currentText());
    qDebug() << query.exec();
    if (query.first())
    {
        teamString = query.value(0).toString();
        numberString = query.value(1).toString();
    }

    qDebug() << " start team id here " << teamString << numberString;

    int start;
    start = numberString.toInt();

    teams.push_back(start);
    teamNames.push_back(teamString);

    ui->textBrowser_team->append(teamString + "\n");
}


void TripCreateWidget::on_proceedButtons_accepted()
{

}

int TripCreateWidget::shortestPathCompare(int src, int end)
{
 // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
        // Container for every vertice traversed from src to destination
        vector<int> vertices_to_destination;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INF);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, src));
        dist[src] = 0;
        vertices_to_destination.push_back(src);

        /* Looping till priority queue becomes empty (or all
        distances are not finalized) */
        while (!pq.empty()) {

            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a
            // vertex
            list<pair<int, int> >::iterator i;
          int save_v = 0;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                // Get vertex label and weight of current
                // adjacent of u.
                int v = (*i).first;
                int weight = (*i).second;

                // If there is a shorter path to v through u.
                if (dist[v] > dist[u] + weight) {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));

                    save_v = v;
                }
            }
          vertices_to_destination.push_back(save_v);

        }
        qDebug() << "I made it this far" << CityToTeam[end];

        return dist[end];

//       //  Print shortest distances stored in dist[]
//        qDebug() << "\n\nCity Distance from " << CityToTeam[src] << " to\n";

//        qDebug() << CityToTeam[end] << ": " << dist[end] << " km\n";
//        QString str = QString::number(dist[end]);

//        qDebug -> textBrowser -> append ("\n\nCity Distance from " + CityToTeam[src] + " to\n");
//        ui -> textBrowser -> append (CityToTeam[end] + ": " + str + " km\n");


}


void TripCreateWidget::on_pushButton_finished_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Custom_Trip");
    qDebug() << "Delete query" << query.exec();

}


void TripCreateWidget::on_comboBox_algorithm_currentTextChanged(const QString &arg1)
{

}

