#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
	int source;
	int destination;
	int weight;
};

class unDirectedweightedGraph
{
private:
	int numberOfVertices;
	vector<vector<int>> adjacencyList;
	void DFSRec(int vertex, vector<bool>& visited);
public:
	unDirectedweightedGraph(int count);
	void addEdge(Edge edge);
	void BFS(int v);// Breadth First Search
	void DFS(); // Depth First Search
};