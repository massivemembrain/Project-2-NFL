#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include <string>
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
  void displayDijkstra(const string start_vertex)
{
  priority_queue<int> city_queue;
  for(int i = 0; i < NUMBER_VERTICES; i++)
    {

    }
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
  const int getIndexFromValue( string value )
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
