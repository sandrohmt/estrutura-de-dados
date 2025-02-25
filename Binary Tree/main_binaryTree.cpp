#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
  BinarySearchTree binarySearchTree1;
  int option, ra, imp;
  string name;
  bool search;

  cout << "Programa gerador de Árvore binária de busca!:\n";

  do
  {
    cout << "Digite 0 para parar o programa! \n";
    cout << "Digite 1 para inserir um elemento! \n";
    cout << "Digite 2 para remover um elemento! \n";
    cout << "Digite 3 para buscar um elemento! \n";
    cout << "Digite 4 para imprimir a árvore! \n";

    cin >> option;

    switch (option)
    {
    case 1:
    {
      cout << "Digite o RA do aluno:\n";
      cin >> ra;
      cout << "Digite o nome do aluno:\n";
      cin >> name;
      Student student(ra, name);
      if (binarySearchTree1.isFull())
      {
        cout << "A árvore está cheia!\n";
        cout << "Não foi possível inserir o elemento!\n";
      }
      else
      {
        binarySearchTree1.push(student);
      }
      break;
    }

    case 2:
    {
      cout << "Digite o RA do aluno a ser removido:\n";
      cin >> ra;
      Student student(ra, " ");
      if (binarySearchTree1.isEmpty())
      {
        cout << "A árvore está vazia!\n";
        cout << "Não foi possível remover o elemento!\n";
      }
      else
      {
        binarySearchTree1.pop(student);
      }
      break;
    }

    case 3:
    {
      cout << "Digite o RA do aluno a ser buscado:\n";
      cin >> ra;
      Student student(ra, " ");
      binarySearchTree1.search(student, search);
      if (search)
      {
        cout << "Aluno encontrado:\n";
        cout << "RA: " << student.getRa() << endl;
        cout << "Nome: " << student.getName() << endl;
      }
      else
      {
        cout << "Aluno não encontrado!\n";
      }
      break;
    }

    case 4:
    {
      cout << "Digite 1 para fazer a impressão em ordem! \n";
      cout << "Digite 2 para fazer a impressão em pré ordem! \n";
      cout << "Digite 3 para fazer a impressão em pós ordem! \n";

      cin >> imp;

      switch (imp)
      {
      case 1:
      {
        binarySearchTree1.inOrderPrint(binarySearchTree1.getRoot());
        break;
      }

      case 2:
      {
        binarySearchTree1.preOrderPrint(binarySearchTree1.getRoot());
        break;
      }

      case 3:
      {
        binarySearchTree1.postOrderPrint(binarySearchTree1.getRoot()); 
        break;
      }
      }
    }
    }

  } while (option != 0);

  return 0;
}