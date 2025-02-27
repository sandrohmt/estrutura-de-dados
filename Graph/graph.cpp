#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(int max, int nullEdgeValue)
{
  nullEdge = nullEdgeValue;
  maxVertices = max;
  qttVertices = 0;

  vertices = new ItemType[maxVertices];

  adjacencyMatrix = new int *[maxVertices]; // Criando um vetor de um vetor de inteiros
  for (int i = 0; i < maxVertices; i++)
  {
    adjacencyMatrix[i] = new int[maxVertices];
  }

  for (int i = 0; i < maxVertices; i++)
  {
    for (int j = 0; j < maxVertices; j++)
    {
      adjacencyMatrix[i][j] = nullEdgeValue; // Por enquanto não tem aresta em ninguém, então bota aresta nula em todos os itens
    }
  }
}

Graph::~Graph()
{
  delete[] vertices;
  for (int i = 0; i < maxVertices; i++)
  {
    delete[] adjacencyMatrix[i];
  }
  delete[] adjacencyMatrix;
}

int Graph::getIndex(ItemType item) // Modificar o método para se precaver caso o usuário escreva um vértice inexistente.
{
  int index = 0;
  while (item != vertices[index])
  {
    index++;
  }
  return index;
}

bool Graph::isFull()
{
  return (qttVertices == maxVertices);
}

void Graph::insertVertex(ItemType item)
{
  if (isFull())
  {
    cout << "O número máximo de vértices foi alcançado!\n";
  }
  else
  {
    vertices[qttVertices] = item;
    qttVertices++;
  }
}

void Graph::insertEdge(ItemType sourceVertex, ItemType targetVertex, int weight)
{
  int line = getIndex(sourceVertex);
  int column = getIndex(targetVertex);

  adjacencyMatrix[line][column] = weight;
  adjacencyMatrix[column][line] = weight; // Remover se for um grafo direcionado
}

int Graph::getWeight(ItemType sourceVertex, ItemType targetVertex)
{
  int line = getIndex(sourceVertex);
  int column = getIndex(targetVertex);
  return (adjacencyMatrix[line][column]);
}

int Graph::getDegree(ItemType item)
{
  int line = getIndex(item);
  int degree = 0;
  for (int i = 0; i < maxVertices; i++)
  {
    if (adjacencyMatrix[line][i] != nullEdge)
    {
      degree++;
    }
  }
  return degree;
}

void Graph::printMatrix()
{
  cout << "Matriz de adjacências\n";
  for (int i = 0; i < maxVertices; i++)
  {
    for (int j = 0; j < maxVertices; j++)
    {
      cout << adjacencyMatrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Graph::printVertices()
{
  cout << "Lista de vértices:\n";
  for (int i = 0; i < qttVertices; i++)
  {
    cout << i << ": " << vertices[i] << endl;
  }
}
