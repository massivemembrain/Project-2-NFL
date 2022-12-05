#ifndef TRAVELGRAPH_H
#define TRAVELGRAPH_H
#include <vector>
#include <QString>
#include <QSqlDatabase>

using namespace std;

class TravelGraph
{
    vector<QString> vertex_name_array;
    vector<vector<int>> weight_matrix;
    // DB is both Map team->stadium & Matrix [origin][destination]->distance
    QSqlDatabase database;

public:
    TravelGraph();
private:
    // Helper functions
      const QString& getValueFromIndex( int index );
      int getIndexFromValue( QString value );
      bool contains(QString& vertex);
};

#endif // TRAVELGRAPH_H
