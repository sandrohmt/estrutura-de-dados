// Grafo simples, direcionado e ponderado
#include <iostream>
#include "dynamicQueue.h"
#include "dynamicStack.h"

using namespace std;

class Graph
{
private:
  int nullEdge;
  int maxVertices;
  int qttVertices;
  ItemType *vertices;
  int **adjacencyMatrix;
  bool *visited;

public:
  Graph(int max, int nullEdgeValue);
  ~Graph();
  int getIndex(ItemType item);
  bool isFull();
  void insertVertex(ItemType item);
  void insertEdge(ItemType sourceVertex, ItemType targetVertex, int weight);
  int getWeight(ItemType sourceVertex, ItemType targetVertex);
  int getDegree(ItemType item);
  void printMatrix();
  void printVertices();
  void resetVisited(); // Antes de começar ambas as buscas ele reseta todo os marcadores
  void breadthFirstSearch(ItemType source, ItemType target);
  void depthFirstSearch(ItemType source, ItemType target);
};