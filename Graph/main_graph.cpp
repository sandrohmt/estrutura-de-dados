#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
  cout << "Programa gerador de Grafos!:\n";

  int max, valueNullEdge;
  cout << "Digite a quantidade máxima de vértices:\n";
  cin >> max;
  cout << "Digite o valor para representar a ausência de aresta:\n";
  cin >> valueNullEdge;

  Graph graph1(max, valueNullEdge);
  ItemType item1, item2;

  int option, value, weight;

  do
  {
    cout << "Digite 0 para parar o programa! \n";
    cout << "Digite 1 para inserir um vértice! \n";
    cout << "Digite 2 para inserir uma aresta! \n";
    cout << "Digite 3 para imprimir o grau de um vértice! \n";
    cout << "Digite 4 para imprimir o peso de uma aresta! \n";
    cout << "Digite 5 para imprimir a matriz de adjacências! \n";
    cout << "Digite 6 para imprimir a lista de vértices! \n";

    cin >> option;

    switch (option)
    {
    case 1:
    {
      cout << "Digite o elemento do vértice que será inserido:\n";
      cin >> item1;
      graph1.insertVertex(item1);
      break;
    }

    case 2:
    {
      cout << "Digite o vértice de saída:\n";
      cin >> item1;
      cout << "Digite o vértice de entrada:\n";
      cin >> item2;
      cout << "Digite o peso desta aresta:\n";
      cin >> weight;
      graph1.insertEdge(item1, item2, weight);
      break;
    }

    case 3:
    {
      cout << "Digite o vértice que será calculado com o grau:\n";
      cin >> item1;
      value = graph1.getDegree(item1);
      cout << "O grau desse vértice é: " << value << endl;
      break;
    }

    case 4:
    {
      cout << "Digite o vértice de saída:\n";
      cin >> item1;
      cout << "Digite o vértice de entrada:\n";
      cin >> item2;
      value = graph1.getWeight(item1, item2);
      cout << "O peso dessa aresta é: " << value << endl;
      break;
    }

    case 5:
    {
      graph1.printMatrix();
      break;
    }

    case 6:
    {
      graph1.printVertices();
      break;
    }
    }

  } while (option != 0);

  return 0;
}