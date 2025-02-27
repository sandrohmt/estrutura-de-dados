// Grafo simples, não direcionado e ponderado
#include <iostream>

using namespace std;

typedef string ItemType;

class Graph
{
  private:
    int nullEdge;
    int maxVertices;
    int qttVertices;
    ItemType *vertices;
    int **adjacencyMatrix; // Um vetor de vetores é uma matriz, por isso são dois asteriscos

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
};