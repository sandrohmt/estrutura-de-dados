#include <iostream>
#include "dynamicQueue.h"
#include <cstddef>
#include <new>

using namespace std;

  DynamicQueue::DynamicQueue()
  {
    front = NULL;
    rear = NULL;
  }

  DynamicQueue::~DynamicQueue()
  {
    node* tempNode;
    while (front != NULL)
    {
      tempNode = front;
      front = front->next;
      delete tempNode;
    }
    rear = NULL;
  }

  bool DynamicQueue::isFull()
  {
    node* tempNode;
    try
    {
      tempNode = new node; // Cria com a função new porque depois da pra desalocar com o delete
      delete tempNode;
      return false;
    }
    catch(bad_alloc exception)
    {
      return true;
    }
  }

  bool DynamicQueue::isEmpty()
  {
    return (front == NULL);
  }

  void DynamicQueue::push(ItemType item)
  {
    if (isFull())
    {
      cout << "Não é possível inserir porque a fila está cheia!\n";
    } else
    {
      node* newNode = new node;
      newNode->value = item;
      newNode->next = NULL; // O elemento inserido sempre terá o next como null
      if (front == NULL) // Se esse for o primeiro elemento a ser inserido
      {
        front = newNode; // O ponteiro front aponta pra ele 
      } else 
      {
        rear->next = newNode;
      }
    rear = newNode;
    }
  }

  ItemType DynamicQueue::pop()
  {
    if (isEmpty())
    {
      cout << "Não é possível remover porque a pilha está vazia!\n";
      return 0;
    } else
    {
      node* tempNode;
      tempNode = front;
      ItemType item = front->value;
      front = front->next;
      if (front == NULL) // Se quando o primeiro andou pro next ele virou NULL, quer dizer que não tem mais próximo, foi removido o último item da fila.
      {
        rear = NULL; // Ai eu faço o último receber NULL, porque quando a fila está vazia o rear também tem que ser NULL.
      }
      delete tempNode;
      return item;
    }
  }

  void DynamicQueue::print()
  {
    node* tempNode = front;
    cout << "Fila: [ ";
    while (tempNode != NULL)
    {
      cout << tempNode->value << " ";
      tempNode = tempNode->next;
    }
    cout << "]\n";
  }