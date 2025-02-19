#include <iostream>
#include "stack.h"

using namespace std;

stack::stack()
{
  length = 0;
  structure = new ItemType[max_items];
}

stack::~stack()
{
  delete[] structure;
}

bool stack::isFull()
{
  return (length == max_items);
}

bool stack::isEmpty()
{
  return (length == 0);
}

void stack::push(ItemType item)
{
  if (isFull())
  {
    cout << "Não é possível inserir porque a pilha está cheia!\n";
  }
  else
  {
    structure[length] = item;
    length++;
  }
}

ItemType stack::pop()
{
  if (isEmpty())
  {
    cout << "Não é possível remover porque a pilha está vazia!\n";
    return 0;
  }
  else
  {
    length--;
    return structure[length];
  }
}

void stack::print()
{
  cout << "Pilha: [ ";
  for (int i = 0; i < length; i++)
  {
    cout << structure[i] << " ";
  }
  cout << "]\n";
}

int stack::getLength()
{
  return length;
}