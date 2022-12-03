#include "bfs.h"
#include "ui_bfs.h"

#include <QWidget>

BFS:: BFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BFS)
{
    ui -> setupUi(this);

    // Adjacency Matrix
      int city_edges_adjacency_matrix[NUMBER_CITIES][NUMBER_CITIES] = {
      /*Seattle*/ {0, 807, 0, 1331, 2097, 0, 0, 0, 0, 0, 0, 0},
      /*SanFran*/ {807, 0, 381, 1267, 0, 0, 0, 0, 0, 0, 0, 0},
      /*LosAnge*/ {0, 381, 0, 1015, 0, 1663, 1435, 0, 0, 0, 0, 0},
      /*Denver */ {1331, 1267, 1015, 0, 1003, 599, 0, 0, 0, 0, 0, 0},
      /*Chicago*/ {2097, 0, 0, 1003, 0, 533, 0, 0, 983, 787, 0, 0},
      /*KansasC*/ {0, 0, 1663, 599, 533, 0, 496, 0, 0, 1260, 864, 0},
      /*Dallas */ {0, 0, 1435, 0, 0, 496, 0, 239, 0, 0, 781, 0},
      /*Houston*/ {0, 0, 0, 0, 0, 0, 239, 0, 0, 0, 810, 1187},
      /*Boston */ {0, 0, 0, 0, 983, 0, 0, 0, 0, 214, 0, 0},
      /*NewYork*/ {0, 0, 0, 0, 787, 1260, 0, 0, 214, 0, 888, 0},
      /*Atlanta*/ {0, 0, 0, 0, 0, 864, 781, 810, 0, 888, 0, 661},
      /*Miami  */ {0, 0, 0, 0, 0, 0, 0, 1187, 0, 0, 661, 0}};

      minBFS(city_edges_adjacency_matrix, int(DALLAS));
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

/** minBFS
 * brief: Iterative Breadth-first search for path from an origin city to a
 * destination
 *
 * INPUT:
 *   cityDistAdjacencyMat (int[][]): lists of all city edges
 *   origin_vertex (City): starting vertex for current iteration
 * OUTPUT:
 *   result (SearchResult): all edges traversed, grouped by type,
 *          as well as other search info
 */
void BFS::minBFS(const int cityDistAdjacencyMat[NUMBER_CITIES][NUMBER_CITIES], const int origin_vertex)
{
  // Flushed with each level group
  std::vector<int> parent_index;
  std::vector<int> sample_index;

  // Persistent throughout loops
  bool adjacencyVisited[NUMBER_CITIES][NUMBER_CITIES] = { {false} };
  bool city_visited[NUMBER_CITIES] = { false };
  int discovery_distance = 0;

  //Initiallize
  parent_index.push_back(origin_vertex);
  city_visited[origin_vertex] = true;

  //Debug: cout << "In Function\n";

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
            //Debug: << "(" << parent_index.back() << ")"
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
