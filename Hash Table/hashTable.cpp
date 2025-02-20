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
  int location = hashFunction(student);
  structure[location] = student;
  qttItems++;
}

void HashTable::pop(Student student)
{
  int location = hashFunction(student);
  if (structure[location].getRa() != -1)
  {
    structure[location] = Student(-1, " ");
    qttItems--;
  }
}

void HashTable::search(Student &student, bool &search)
{
  int location = hashFunction(student);
  Student aux = structure[location];
  if (student.getRa() != aux.getRa())
  {
    search = false;
  }
  else
  {
    search = true;
    student = aux;
  }
}

void HashTable::print()
{
  cout << "Tabela Hash:\n";
  for (int i = 0; i < maxPositions; i++)
  {
    if (structure[i].getRa() != -1)
    {
      cout << i << ":" << structure[i].getRa() << " ";
      cout << structure[i].getName() << endl;
    }
  }
}
