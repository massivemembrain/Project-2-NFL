#include "bfs.h"
#include "ui_bfs.h"

#include <QWidget>
#include <QSqlQueryModel>

BFS:: BFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BFS)
{
    ui -> setupUi(this);

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

    for (int i = 0; i < NUMBER_CITIES; i++)
    {
        for (int j = 0; j < NUMBER_CITIES; j++)
        {
            //qDebug() << matrix[i][j];
            //cout << "["<< i << "]" << "[" << j << "]" << " = " << matrix[i][j]  << endl;
        }
    }

    QSqlQueryModel* comboquery = new QSqlQueryModel();
    comboquery->setQuery("SELECT Team FROM Teams");
    ui->comboBox->setModel(comboquery);

    origin_vertex = Los_Angeles_Rams;
    //minBFS(matrix, int(origin_vertex));
}

/* setNextLowestIndex
 * brief: temporary helper function to provide child indeces for a given slice of the adj matrix
 * INPUT:
 *   low_index
 *   row_index
 *   city_visited
 *   city_edges
 * OUTPUT:
 *   low_index (int): modified
*/
void BFS::setNextLowestIndex(int& low_index, const int& row_index, const bool city_visited[NUMBER_CITIES], const int city_edges[NUMBER_CITIES])
{
  int next_lowest_value = 0;
  int next_lowest_index = row_index;
  for(int i = 0; i < NUMBER_CITIES; i++)
    {
      if(city_edges[i] != 0 && i != low_index)
      {
        if((next_lowest_value == 0 && city_visited[i] == false) || (city_edges[i] > city_edges[low_index] && city_edges[i] < next_lowest_value))
        {
          next_lowest_value = city_edges[i];
          next_lowest_index = i;
        }
      }
    }
  //Debug: cout << next_lowest_index << " ";
  low_index = next_lowest_index;
}

/* minBFS
 * brief: Iterative Breadth-first search for path from an origin city to a
 * destination
 *
 * INPUT:
 *   matrix (int[][]): lists of all city edges
 *   origin_vertex (City): starting vertex for current iteration
 * OUTPUT:
 *   result (SearchResult): all edges traversed, grouped by type,
 *          as well as other search info
 */

void BFS::minBFS(const int cityDistAdjacencyMat[NUMBER_CITIES][NUMBER_CITIES], int origin_vertex)
{
    // Flushed with each level group
      std::vector<int> parent_index;
      std::vector<int> sample_index;

      // Persistent throughout loops
      bool adjacencyVisited[NUMBER_CITIES][NUMBER_CITIES] =  {false} ;
      bool city_visited[NUMBER_CITIES] = { false };
      int discovery_distance = 0;

      //Initiallize
      parent_index.push_back(origin_vertex);
      city_visited[origin_vertex] = true;

      int level = 0;
      // For each city entry we need
      while(parent_index.size() > 0)
      {
        QString l = QString::number(level);
        ui -> textBrowser -> append("Level " + l + " edges:\n");
        sample_index.clear();
          // ** Discovery Edges
          // For each parent vertex
          for(int p = parent_index.size(); p > 0;  p--)
          {
            //cout << "re";
            // For every possible child edge
            int low_index = 0;
            //for(int i = 0; i < NUMBER_CITIES; i++)
            do
            {
              setNextLowestIndex(low_index, parent_index.back(), adjacencyVisited[parent_index.back()], cityDistAdjacencyMat[parent_index.back()]);
              //cout << "peat\n";
              // Rule out children that are not valid edges (ie. create level groups)
              if(cityDistAdjacencyMat[parent_index.back()][low_index] != 0 && adjacencyVisited[parent_index.back()][low_index] == false)
              {
                adjacencyVisited[parent_index.back()][low_index] = true;
                adjacencyVisited[low_index][parent_index.back()] = true;
                //qDebug() << "(" << parent_index.back() << ")";
                ui -> textBrowser -> append(CityToStr[parent_index.back()] + " - " + CityToStr[low_index]);
                // **Discovery only
              if(city_visited[low_index] == false)
              {
                // Discovery
                ui -> textBrowser -> append(" (Discovery Edge)\n");
                city_visited[low_index] = true;
                discovery_distance += cityDistAdjacencyMat[parent_index.back()][low_index];
                sample_index.push_back(low_index);
              }
                  //** Cross only
              else
              {
                ui -> textBrowser -> append(" (Cross Edge)\n");
              }
              }
              //Debug: cout << "SEE MEE (" << cityDistAdjacencyMat[parent_index.back()][low_index] << ")\n";
            } while(cityDistAdjacencyMat[parent_index.back()][low_index] != 0);
            parent_index.pop_back();
          }
    // sort sample_index by

        reverse(sample_index.begin(), sample_index.end());

        parent_index = sample_index;
        level++;
         /*Debug: cout << "Next: ";
        for(int& i : sample_index)
          {
            cout << i << ", ";
          }*/
        }
      //Debug: cout << "End function" << endl;
      QString dd = QString::number(discovery_distance);
      ui -> textBrowser -> append("\n\nThe total distance traveled over discovery edges is " + dd + " km.");
}

void BFS::on_selectTeamButton_clicked()
{

   //minBFS(matrix, origin_vertex);     // this one starts from hard rock stadium
   minBFS(matrix, 17);                  // this start from sofi

//    vector<int> parent_index;
//      vector<int> sample_index;

//      // Persistent throughout loops
//      bool adjacencyVisited[NUMBER_CITIES][NUMBER_CITIES] = { false };
//      bool city_visited[NUMBER_CITIES] = { false };
//      int discovery_distance = 0;

//      //Initiallize
//      parent_index.push_back(origin_vertex);
//      city_visited[origin_vertex] = true;

//      //Debug: cout << "In Function\n";

//      int level = 0;
//      // For each city entry we need
//      while(parent_index.size() > 0)
//      {
//        cout << "Level " << level << " edges:\n";
//        sample_index.clear();
//          // ** Discovery Edges
//          // For each parent vertex
//          for(int p = parent_index.size(); p > 0;  p--)
//          {
//            //cout << "re";
//            // For every possible child edge
//            int low_index = 0;
//            //for(int i = 0; i < NUMBER_CITIES; i++)
//            do
//            {
//              setNextLowestIndex(low_index, parent_index.back(), adjacencyVisited[parent_index.back()], matrix[parent_index.back()]);
//              //cout << "peat\n";
//              // Rule out children that are not valid edges (ie. create level groups)
//              if(matrix[parent_index.back()][low_index] != 0 && adjacencyVisited[parent_index.back()][low_index] == false)
//              {
//                adjacencyVisited[parent_index.back()][low_index] = true;
//                adjacencyVisited[low_index][parent_index.back()] = true;
//                //Debug: << "(" << parent_index.back() << ")"
//                ui -> textBrowser -> append(CityToStr[parent_index.back()] + " - " + CityToStr[low_index]);
//                // **Discovery only
//              if(city_visited[low_index] == false)
//              {
//                // Discovery
//                cout << " (Discovery Edge)\n";
//                city_visited[low_index] = true;
//                discovery_distance += matrix[parent_index.back()][low_index];
//                sample_index.push_back(low_index);
//              }
//                  //** Cross only
//              else
//              {
//                cout << " (Cross Edge)\n";
//              }
//              }
//              //Debug: cout << "SEE MEE (" << cityDistAdjacencyMat[parent_index.back()][low_index] << ")\n";
//            } while(matrix[parent_index.back()][low_index] != 0);
//            parent_index.pop_back();
//          }
//    // sort sample_index by

//        reverse(sample_index.begin(), sample_index.end());

//        parent_index = sample_index;
//        level++;
//         /*Debug: cout << "Next: ";
//        for(int& i : sample_index)
//          {
//            cout << i << ", ";
//          }*/
//        }
//      //Debug: cout << "End function" << endl;
//      cout << "\n\nThe total distance traveled over discovery edges is " << discovery_distance << " km.";
}

