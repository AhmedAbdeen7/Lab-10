#include <iostream>
#include <vector>
#include <queue>
#include "undirectedweightedgraph.h"
#ifndef UNDIRECTEDWEIGHTEDGRAPH_H
#define UNDIRECTEDWEIGHTEDGRAPH_H

    void unDirectedweightedGraph :: addEdge(Edge edge)
    {
        adjacencyList[edge.destination].push_back(edge.source);
        edge.weight = 1;
        adjacencyList[edge.source].push_back(edge.destination);
    }
   unDirectedweightedGraph :: unDirectedweightedGraph(int count)
   {
     numberOfVertices = count;
     adjacencyList.resize(count);
   }
  void  unDirectedweightedGraph :: DFSRec(int vertex, vector<bool>& visited)
  {
    visited[vertex] = true;
    cout << vertex << " ";  
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        int next_vertex = adjacencyList[vertex][i];
         if (!visited[next_vertex])
          DFSRec(next_vertex, visited);

    }
  }
  void unDirectedweightedGraph :: BFS(int v)
  {
      vector<bool> visited(numberOfVertices, false);
     queue<int> q;
     visited[v] = true;
     q.push(v);
     while (!q.empty())
     {
        int v = q.front();
        cout << v << " ";
        q.pop();
    for (int i = 0; i < adjacencyList[v].size(); i++) 
    {
        int adjacentVertex = adjacencyList[v][i];
        if (!visited[adjacentVertex]) 
        {

            visited[adjacentVertex] = true;
            q.push(adjacentVertex);
        }
        }

     }

  }
   void unDirectedweightedGraph :: DFS()
   {
     vector<bool> visited(numberOfVertices, false);
     for (int i = 0; i < numberOfVertices;i++)
     {
        if (!visited[i])
          DFSRec(i, visited);
     }

   }
   #endif
