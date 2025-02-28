#include <iostream>
#include <cstddef> // NULL
#include "dynamicStack.h"
#include <new>

using namespace std;

  DynamicStack::DynamicStack()
  {
    topNode = NULL;
  }

  DynamicStack::~DynamicStack()
  {
    node* tempNode;
    while (topNode != NULL)
    {
      tempNode = topNode;
      topNode = topNode->next;
      delete tempNode;
    }
    
  }

  bool DynamicStack::isFull() 
  {
    node* newNode;
    try { // Tentar criar um novo nó
      newNode = new node; 
      delete newNode; // Se conseguir, deleta ele
      return false; // E retorna que o isFull é false
    } catch(bad_alloc exception) {
      return true; // Se não conseguir, retorna que o isFull é true
    }
  }

  bool DynamicStack::isEmpty()
  {
    return (topNode == NULL);
  }

  void DynamicStack::push(ItemType item)
  {
    if (isFull())
    {
      cout << "Não é possível inserir porque a pilha está cheia!\n";
    } else
    {
      node* newNode = new node;
      newNode->value = item;
      newNode->next = topNode; // Aponta para o topo antigo
      topNode = newNode; // O topo agora é o novo nó
    }
  
  }

  ItemType DynamicStack::pop()
  {
    if (isEmpty())
    {
      cout << "Não é possível remover porque a pilha está vazia!\n";
      return 0;
    } else
    {
      node* tempNode; // Criação do tempNode para remover ele em vez do topNode
      tempNode = topNode; // Faz a substituição
      ItemType item = topNode->value; // Isso é para o valor removido conseguir ser retornado
      topNode = topNode->next; // Faz a substituição
      delete tempNode; // Deleta o temporário
      return item;
    }
    
  }

  void DynamicStack::print()
  {
    node* tempNode = topNode;
    cout << "Pilha: [ ";
    while (tempNode != NULL) // O tempNode vai imprimindo e passando pro próximo até o próximo ser null (chega no final)
    {
      cout << tempNode->value << " ";
      tempNode = tempNode->next; 
    }
    cout << "]\n";
  }
