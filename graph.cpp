#include "graph.h"

using namespace std;

int main() {
  cout << "making graph" << endl;
  Graph g = Graph();
  auto a = g.addVertex("a"), b = g.addVertex("b"), c = g.addVertex("c"), x = g.addVertex("x");
  g.addEdge(1, a, b); 
  g.addEdge(2, b, c); 
  g.addEdge(3, c, a); 
  g.addEdge(4, a, x); 
  g.addEdge(5, x, a); 
  g.addEdge(6, b, x); 
  g.addEdge(7, x, b); 
  g.addEdge(8, c, x); 
  g.addEdge(9, x, c); 
  g.getAdjVertices(x);
  
  return 0;
}
