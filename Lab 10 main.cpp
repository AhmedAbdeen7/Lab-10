#include <iostream>
#include <fstream>
#include <vector>
#include "undirectedweightedgraph.cpp"
using namespace std;

int main()
{
    ifstream matrix("Board.txt");
     int vertexnum;
    matrix >> vertexnum;
    vector<vector<int>> adjacencyMatrix(vertexnum, vector<int>(vertexnum));
      for (int i = 0; i < vertexnum; i++) 
      {
        for (int j = 0; j < vertexnum; j++) 
        {
            matrix >> adjacencyMatrix[i][j];
        }
        }
        matrix.close();
        unDirectedweightedGraph graph(vertexnum);
           for (int i = 0; i < vertexnum; i++) {
        for (int j = i + 1; j < vertexnum; j++) {
            int weight = adjacencyMatrix[i][j];
            if (weight != -1) {
                Edge edge = {i, j, weight};
                graph.addEdge(edge);
            }
        }
    }
    cout << "DFS: ";
    graph.DFS();
    cout << "BFS: ";
    graph.BFS(0);
      return 0;
}