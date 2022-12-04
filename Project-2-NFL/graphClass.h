#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <queue>

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
    : NUMBER_VERTICES{0}, vertex_name_array{vertex_name_array},
    weight_matrix{weight_matrix}
    {

    }

  Graph(
    int number_vertices,
    string vertex_name_array[],
    T* weight_matrix[],
    bool* direction_matrix[] = nullptr)
    : NUMBER_VERTICES{number_vertices}, vertex_name_array{vertex_name_array},
    weight_matrix{weight_matrix}
    {
      if(direction_matrix != nullptr)
      {
        this->direction_matrix = direction_matrix;
      }
      else
      {
        is_directed = false;
      }
    }
  Graph(QSqlDatabase& SqlDatabase, QString SqlTable)
    : NUMBER_VERTICES{number_vertices}, vertex_name_array{vertex_name_array},
    weight_matrix{weight_matrix}
    {

    }

// Destructor
  ~Graph()
  {
    for(int i = 0; i < NUMBER_VERTICES; i++)
    {
      delete[] weight_matrix[i];
    }
    if(direction_matrix != nullptr)
    {
      for(int i = 0; i < NUMBER_VERTICES; i++)
      {
          delete[] direction_matrix[i];
      }
    }
  }
// Member functions
  void modEdge(const int start_vertex, const int end_vertex, const T weight, const bool is_directional = false)
{
  weight_matrix[start_vertex][end_vertex] = weight;
}
  void addVertex(const string vertex)
{
  NUMBER_VERTICES++;
  vertex_name_array = new string[NUMBER_VERTICES];
  int** new_matrix = new T[NUMBER_VERTICES][NUMBER_VERTICES];
  for(int i = 0; i < NUMBER_VERTICES - 1; i++)
    {}
}
  void displayDFS(const string start_vertex)
{

}
  void displayBFS(const string start_vertex)
{

}
  const int INF = 9999;
  typedef pair<int, int> iPair;
  void displayDijkstra(const string start_vertex)
{
      // Create a priority queue to store vertices that
      // are being preprocessed. This is weird syntax in C++.
      priority_queue<iPair, vector<iPair>, greater<iPair> pq;
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

      // Print shortest distances stored in dist[]
      cout << "\n\nCity Distance from " << CityToStr[src] << " to\n";
      for (int i = 0; i < V; ++i)
      {
          cout << left << setw(14) << CityToStr[i] << ": " << dist[i] << " km\n";
      }
//  priority_queue<int> city_queue;
//  for(int i = 0; i < NUMBER_VERTICES; i++)
//    {

//    }
}
  void displayMST(const string start_vertex)
{

}
  void displayASMST(const string start_vertex)
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
  int NUMBER_VERTICES;
  string* vertex_name_array;
  T** weight_matrix;
  bool** direction_matrix;
  bool is_directed;
// Helper functions
  const string& getValueFromIndex( int index )
  {
    return vertex_name_array[index];
  }
  int getIndexFromValue( string value )
  {
    for(int i = 0; i < NUMBER_VERTICES; i++)
    {
      if(vertex_name_array[i] == value)
      {
        return i;
      }
    }
    cout << "Value " << value << " not in array.";
    return -1;
  }
};


#endif // GRAPHCLASS_H
