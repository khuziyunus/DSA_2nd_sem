#include <iostream>
#include <list>

using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
  void DFS(int vertex);
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}
