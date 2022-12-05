#include "travelgraphClass.h"
#include <QDebug>
#include <QSqlQuery>

TravelGraph::TravelGraph()
{
    vertex_name_array = vector<QString>();
    //weight_matrix = vector<vector<int>>();
    // init db
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }
    database.setDatabaseName("../NFLProject.db");
    if(database.open())
    {
        qDebug("Graph: Database opened.");
    }
    else
    {
        qDebug("Graph: Database not opened.");
    }
    // PULL IN SQL
    QSqlQuery query("SELECT * FROM DistanceMatrix");
    // 1st dimension matrix access
//    while(query.next())
//    {
//        vertex_name_array.push_back(query.value());
//        team_name = query.value(TEAM_FIELD).toString();
//        stadium_origin_name = query.value(ORIGIN_FIELD).toString();
//        // if stadium has not yet been added to matrix
//        if( !contains(stadium_origin_name) )
//        {
//             addVertex(stadium_origin_name);
//        }
//        stadium_origin_index = getIndexFromValue(stadium_origin_name);
//        // 2nd dimension matrix access
//        while(query.)
//        {
//            stadium_destination_name = query.value(DESTINATION_FIELD).toString();
//            if( !contains(stadium_destination_name) )
//            {
//                addVertex(stadium_destination_name);
//            }
//            stadium_destination_index = getIndexFromValue(stadium_destination_name);
//            // Assign db weight to matrix
//            weight_matrix[stadium_origin_index][stadium_destination_index] = query.value(DISTANCE_FIELD).toInt();

//            query.next();
//        } while(query.isValid() && query.value(TEAM_FIELD).toString() == team_name);
//        //if()
//        //QString country = query.value(0).toString();
//        //doSomething(country);
//    }
}

// Helper functions
const QString& TravelGraph::getValueFromIndex( int index )
{
    return vertex_name_array[index];
}
int TravelGraph::getIndexFromValue( QString value )
{
    for(int i = 0; i < vertex_name_array.size(); i++)
    {
      if(vertex_name_array[i] == value)
      {
        return i;
      }
    }
    qDebug() << "Value " << value << " not in array.";
    return -1;
}
bool TravelGraph::contains(QString& vertex)
{
      return count(vertex_name_array.begin(), vertex_name_array.end(), vertex);
}
