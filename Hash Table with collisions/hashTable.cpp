#include <iostream>
#include "hashTable.h"

using namespace std;

int HashTable::hashFunction(Student student)
{
  return (student.getRa() % maxPositions);
}

HashTable::HashTable(int arraySize, int max)
{
  qttItems = 0;
  maxItems = max;
  maxPositions = arraySize;
  structure = new Student[arraySize];
}

HashTable::~HashTable()
{
  delete[] structure;
}

bool HashTable::isFull()
{
  return (qttItems == maxItems);
}

int HashTable::getLength()
{
  return (qttItems);
}

void HashTable::push(Student student)
{
  if (isFull())
  {
    cout << "A tabela está cheia!\n";
    cout << "O elemento não pode ser inserido\n";
  } else
  {
    int location = hashFunction(student);
    while (structure[location].getRa() > 0) 
    {
      location = (location + 1) % maxPositions; // Garante que ele volte ao inicio do array caso chegue na última posição
    } 
    
    structure[location] = student;
    qttItems++;
  }
}

void HashTable::pop(Student student)
{
  int location = hashFunction(student);
  bool teste = false;
  while (structure[location].getRa() != -1)
  {
    if (structure[location].getRa() == student.getRa())
    {
      cout << "Elemento removido!\n";
      structure[location] = Student(-2, " ");
      qttItems--;
      teste = true;
      break;
    }
    location = (location + 1) % maxPositions;
  }
  if (!teste)
    {
      cout << "Elemento não encontrado!\n";
      cout << "Nenhum elemento foi removido!\n";
    }
}

void HashTable::search(Student &student, bool &search)
{
  int location = hashFunction(student);
  while (structure[location].getRa() != -1)
  {
    if (structure[location].getRa() == student.getRa())
    {
      search = true;
      student = structure[location];
      break;
    }
    location = (location + 1) % maxPositions;
  }
}

void HashTable::print()
{
  cout << "Tabela Hash:\n";
  for (int i = 0; i < maxPositions; i++)
  {
    if (structure[i].getRa() > 0)
    {
      cout << i << ":" << structure[i].getRa() << " ";
      cout << structure[i].getName() << endl;
    }
  }
}
