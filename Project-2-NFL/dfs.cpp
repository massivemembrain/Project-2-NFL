#include "dfs.h"
#include "ui_dfs.h"
#include <QWidget>

DFS::DFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFS)
{
    ui->setupUi(this);

    dfsDistance = 0;

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

}
//=================================================
// insert vertex
void DFS::insertVertex(string city)
{
    if (findVertex(city) == graph.size()) {
        // adds the vertex if not added already
        nodeVertex newVertex;

        newVertex.city = city;
        newVertex.visited = false;
        graph.push_back(newVertex);
    }
}
// ================================
// insert edge
void DFS::insertEdge(string startCity, string endCity, int weight) {
    int index = findVertex(startCity);	// returns the vertex

    if (index == graph.size()) {		// adds the vertex if not added already
        insertVertex(startCity);
        insertEdge(startCity, endCity, weight);
    }
    else
    {
        nodeEdge newEdge;

        newEdge.startCity = startCity;
        newEdge.endCity = endCity;
        newEdge.weight = weight;

        graph.at(index).edgeList.push_back(newEdge);
    }
}
// ================================
// distance/weight
int DFS::distance(nodeVertex * v1, nodeVertex * v2) {
    for (int i = 0; i < v1->edgeList.size(); i++) {		// get connecting edge
        if (v1->edgeList.at(i).startCity == v2->city
                || v1->edgeList.at(i).endCity == v2->city)
            return v1->edgeList.at(i).weight;
    }
    return -1;
}

// ================================
// DFS search
int DFS::DFSFunction(string startingCity, vector<string> &dfsGraph) {
    int currVertex = findVertex(startingCity);		// gets the vertex

    graph.at(currVertex).visited = true;			// marks it as visited

    vector<string>::iterator nextCityIt = ::find(dfsGraph.begin(), dfsGraph.end(),startingCity);	// gets the cities visited

    if (nextCityIt == dfsGraph.end()) {
        dfsGraph.push_back(startingCity);
    }

    if (verticesVisited() != graph.size()) {				// recursive call
        int nextVertex = smallestEdgeDFS(currVertex, dfsGraph);
        DFSFunction(graph.at(nextVertex).city, dfsGraph);
    }
    return dfsDistance;
}
// ================================
// goes to the smallest edge for DFS search
int DFS::smallestEdgeDFS(int currVertex, vector<string> &dfsGraph)
{
    if (edgesDiscovered(currVertex) != graph.at(currVertex).edgeList.size())
    {
        int smallestIndex = 0;
        int compIndex = smallestIndex + 1;

        int size = graph.at(currVertex).edgeList.size();	// get current size

        while (compIndex < size) {
            int smallestVertex = findVertex(
                    graph.at(currVertex).edgeList.at(smallestIndex).endCity);
            int compVertex = findVertex(
                    graph.at(currVertex).edgeList.at(compIndex).endCity);

            if (graph.at(smallestVertex).visited) {
                smallestIndex++;
            } else {
                if (!(graph.at(compVertex).visited)) {
                    if (graph.at(currVertex).edgeList.at(smallestIndex).weight
                            >= graph.at(currVertex).edgeList.at(compIndex).weight) {
                        smallestIndex = compIndex;
                    }
                }
            }
            compIndex++;
        }
        graph.at(currVertex).edgeList.at(smallestIndex).discEdge = true;
        dfsDistance += graph.at(currVertex).edgeList.at(smallestIndex).weight;
        string nextCity =
                graph.at(currVertex).edgeList.at(smallestIndex).endCity;
        smallestIndex = findVertex(nextCity);

        for (int i = 0; i < graph.at(smallestIndex).edgeList.size(); i++)
        {
            if (graph.at(currVertex).city
                    == graph.at(smallestIndex).edgeList.at(i).endCity)
            {
                graph.at(smallestIndex).edgeList.at(i).discEdge = true;
            }
        }
        return smallestIndex;
    } else {
        vector<string>::iterator dfsIt = ::find(dfsGraph.begin(), dfsGraph.end(),
                graph.at(currVertex).city);
        dfsIt--;

        int backIndex = findVertex(*dfsIt);

        return smallestEdgeDFS(backIndex, dfsGraph);
    }
}
// ================================
// find other vertex of the node
string DFS::otherVertex(nodeEdge currEdge, string startingCity) {
    if (currEdge.startCity == startingCity) {
        return currEdge.endCity;
    } else {
        return currEdge.startCity;
    }
}
// ================================
// get all the vertices visited
int DFS::verticesVisited() {
    int numVisited = 0;

    vector<nodeVertex>::iterator graphIt = graph.begin();

    while (graphIt != graph.end()) {
        if (graphIt->visited) {
            numVisited++;
        }

        graphIt++;
    }
    return numVisited;
}
// ================================
// finds how many edges discovered
int DFS::edgesDiscovered(int currVertex) {
    int numVisited = 0;

    for (int i = 0; i < graph.at(currVertex).edgeList.size(); i++) {
        if (graph.at(findVertex(graph.at(currVertex).edgeList.at(i).endCity)).visited) {
            numVisited++;
        }
    }

    return numVisited;
}
// ================================
// finds the vertex of the city
int DFS::findVertex(string city) {
    int index = 0;
    bool found = false;

    while (index < graph.size() && !found) {		// finds the city
        if (graph.at(index).city == city) {
            found = true;
        } else {
            index++;
        }
    }
    return index;
}
// =================================================
// this part loads the db values inside the adj list
// =================================================
void DFS::on_pushButton_clicked()
{
        // graph object
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
     int totalDistance = G.DFSFunction("U.S. Bank Stadium", dfsVertexList);

     ui -> textBrowser -> append( "DFS Traversal:\n\n");

     // Will loop around the dfsvertexlist vector and display the elements
     //in the correct order of the dfs
   for (int i = 0; i < dfsVertexList.size(); i++)
    {
       ui -> textBrowser -> append(QString::number(i+1) + " - "  + QString::fromStdString(dfsVertexList.at(i)));
    }

   ui -> textBrowser -> append("\n***************************************************************************");
   ui -> textBrowser -> append("Total distance traveled by discovery edges : " + QString::number(totalDistance));
   ui -> textBrowser -> append("***************************************************************************\n");

}
