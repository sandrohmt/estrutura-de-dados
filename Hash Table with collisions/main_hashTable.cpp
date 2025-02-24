#include <iostream>
#include "hashTable.h"
using namespace std;

int main()
{
  cout << "Programa gerador de hash:\n";

  int arraySize, max;

  cout << "Digite o tamanho da Hash!\n";
  cin >> arraySize;

  cout << "Digite o numero máximo de elementos!\n";
  cin >> max;

  cout << "O fator de carga é: " << float(max) / float(arraySize) << endl;

  HashTable studentHash(arraySize, max);

  int option;
  int ra;
  string name;
  bool search;

  do
  {
    cout << "Digite 0 para parar o programa! \n";
    cout << "Digite 1 para inserir um elemento! \n";
    cout << "Digite 2 para remover um elemento! \n";
    cout << "Digite 3 para buscar um elemento! \n";
    cout << "Digite 4 para imprimir a tabela hash! \n";

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
      studentHash.push(student);
      break;
    }
      
    case 2:
    {
      cout << "Digite o RA do aluno:\n";
      cin >> ra;
      Student student(ra, " ");
      studentHash.pop(student);
      break;
    }

    case 3:
    {
      cout << "Digite o RA do aluno:\n";
      cin >> ra;
      Student student(ra, " ");
      studentHash.search(student, search);
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
      studentHash.print();
      break;
    }
    }
  } while (option != 0);

  return 0;
}