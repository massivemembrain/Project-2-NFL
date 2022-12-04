#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include <list>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <QSqlDatabase>
#include <QString>

using namespace std;

/* Graph
 * brief:
 * 4D Structure
 */
template <typename T>
class Graph
{
public:
// Constructor
  Graph()
    : vertex_name_array{vector<QString>()}, is_directed{false},
      weight_matrix{vector<vector<T>>(0, vector<bool>(0, false))}, direction_matrix{vector<vector<bool>>(0, vector<bool>(0, false))}
    {

    }
  // Undirected constructor
  Graph(
    vector<QString> vertex_name_array,
    vector<vector<T>> weight_matrix)
    : vertex_name_array{vertex_name_array}, is_directed{false},
      weight_matrix{weight_matrix}, direction_matrix{vector<vector<bool>>(0, vector<bool>(0, false))}
    {
        //direction_matrix = vector<vector<bool>>(0, vector<bool>(0, false));
    }
  // Directed constructor
  Graph(
    vector<QString> vertex_name_array,
    vector<vector<T>> weight_matrix,
    vector<vector<bool>> direction_matrix)
    : vertex_name_array{vertex_name_array}, is_directed{true},
      weight_matrix{weight_matrix}, direction_matrix{direction_matrix}
    {}
  // DB undirected constructor
  Graph(QSqlDatabase& SqlDatabase, QString SqlTable)
      : is_directed{false}, direction_matrix{vector<vector<bool>>(0, vector<bool>(0, false))}
    {
        vertex_name_array = vector<QString>();
        weight_matrix = vector<vector<int>>();

        // PULL IN SQL

    }

// Destructor
  ~Graph()
  {
      // Not needed b/c vectors
//    for(int i = 0; i < NUMBER_VERTICES; i++)
//    {
//      delete[] weight_matrix[i];
//    }
//    if(direction_matrix != nullptr)
//    {
//      for(int i = 0; i < NUMBER_VERTICES; i++)
//      {
//          delete[] direction_matrix[i];
//      }
//    }
  }
// Member functions
  void modEdge(const int start_vertex, const int end_vertex, const T weight, const bool is_directional = false)
{
  weight_matrix[start_vertex][end_vertex] = weight;
  // if is_directional == false
  weight_matrix[end_vertex][end_vertex] = weight;

  // UPDATE IN SQL
}
  void addVertex(const QString vertex)
{

  vertex_name_array.push_back(vertex);
  for(auto itWeight = weight_matrix.begin(); itWeight != weight_matrix.end(); itWeight++)
  {
    // same as .pushback(0), but more efficient
    itWeight->emplace_back();
  }
  weight_matrix.emplace_back();

  // CREATE IN SQL
}
  void displayDFS(const QString start_vertex)
{

}
  void displayBFS(const QString start_vertex)
{

}
  const int INF = 9999;
  typedef pair<int, int> iPair;
  void displayDijkstra(const QString START_VERTEX)
{
      const int START_INDEX = getIndexFromValue(START_VERTEX);

      // Create a priority queue to store vertices that
      // are being preprocessed. This is weird syntax in C++.
      priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
      // Container for every vertice traversed from src to destination
      vector<int> vertices_to_destination;

      // Create a vector for distances and initialize all
      // distances as infinite (INF)
      vector<int> dist(vertex_name_array.size(), INF);

      // Insert source itself in priority queue and initialize
      // its distance as 0.
      pq.push(make_pair(0, START_INDEX));
      dist[START_INDEX] = 0;
      vertices_to_destination.push_back(START_INDEX);

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
          for (i = weight_matrix[u].begin(); i != weight_matrix[u].end(); ++i) {
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

      // Print shortest distances stored in dist[]
      cout << "\n\nCity Distance from " << vertex_name_array[START_INDEX].toStdString() << " to\n";
      for (int i = 0; i < vertex_name_array.size(); ++i)
      {
          cout << left << setw(14) << vertex_name_array[i].toStdString() << ": " << dist[i] << " km\n";
      }
//  priority_queue<int> city_queue;
//  for(int i = 0; i < NUMBER_VERTICES; i++)
//    {

//    }
}
  void displayMST(const QString start_vertex)
{

}
  void displayASMST(const QString start_vertex)
{

}
  bool isStronglyConnected()
{
  return true;
}
  void operator()()
  {}
// Member vars
private:
  // implicit: vertex_name_array.size()
  //int NUMBER_VERTICES;
  vector<QString> vertex_name_array;
  vector<vector<T>> weight_matrix;
  vector<vector<bool>> direction_matrix;
  bool is_directed;
  QSqlDatabase sqlDatabase;
  QString sqlTable;
// Helper functions
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
};


#endif // GRAPHCLASS_H
