#include <iostream>
#include <cstddef>
#include "binaryTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree();
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::deleteTree(node *currentNode)
{
}

node *BinarySearchTree::getRoot()
{
  return root;
}

bool BinarySearchTree::isFull()
{
  return (root == NULL);
}

bool BinarySearchTree::isEmpty()
{
  try
  {
    node *temp = new No;
    delete temp;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

void BinarySearchTree::push(Student student)
{
  if (isFull())
  {
    cout << "A árvore está cheia!\n" cout << "Não foi possível inserir este elemento!\n"
  }
  else
  {
    node *newNode = new No;
    newNode->student = student;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    if (root == NULL)
    {
      root = newNode;
    }
    else
    {
      node *temp = root;
      while (temp != NULL)
      {
        if (student.getRa() < temp->student.getRa())
        {
          if (temp->leftChild == NULL)
          {
            temp->leftChild = newNode;
            break;
          }
          else
          {
            temp = temp->leftChild;
          }
        }
        else
        {
          if (temp->rightChild == NULL)
          {
            temp->rightChild = newNode;
            break;
          }
          else
          {
            temp = temp->rightChild;
          }
        }
      }
    }
  }
}

ItemType BinarySearchTree::pop(Student student)
{
  popSearch(student, root); // Vai fazer uma busca do aluno começando pela raiz
}

void BinarySearchTree::popSearch(Student student, node *&currentNode)
{
  if (student.getRa() < currentNode->student.getRa())
  {
    popSearch(student, currentNode->leftChild);
  }
  else if (student.getRa() > currentNode->student.getRa())
  {
    popSearch(student, currentNode->rightChild);
  }
  else
  {
    removeNode(currentNode);
  }
}

void BinarySearchTree::removeNode(node *&currentNode)
{
  node *temp = currentNode;
  if (currentNode->leftChild == NULL)
  {
    currentNode = currentNode->rightChild; // Se ele não tiver filhos o currentNode vira NULL, então também funciona pra esse caso
    delete temp;
  }
  else if (currentNode->rightChild == NULL)
  {
    currentNode = currentNode->leftChild;
    delete temp;
  }
  else
  {
    Student successorStudent; // O Student é enviado vazio porque dentro da função ele recebe um valor, o currentNode serve para obter o sucessor dele''
    getSuccessor(successorStudent, currentNode); // A gente quer saber o sucessor do nó atual, que é o nó que a gente quer remover
    currentNode->student = successorStudent; // Apenas o valor do aluno é trocado, aqui é onde acontece a substituição
    popSearch(successorStudent, currentNode->rightChild); // A busca aqui começa a partir da direita do successorStudent, porque se começar pela raiz vai encontrar ele e remover a cópia errada. Depois da substituição, você remove a cópia.
  }
}

void BinarySearchTree::getSuccessor(Student &successorStudent, node *temp) // Menor valor a direita
{
  temp = temp->rightChild;
  while (temp->leftChild != NULL)
  {
    temp = temp->leftChild;
  }
  successorStudent =  temp->student;
}

void BinarySearchTree::search(Student &student, bool &search)
{
  search = false;
  node *currentNode = root;
  while (currentNode != NULL)
  {
    if (student.getRa() < currentNode->student.getRa())
    {
      currentNode = currentNode->leftChild;
    }
    else if (student.getRa() > currentNode->student.getRa())
    {
      currentNode = currentNode->rightChild;
    }
    else
    {
      search = true;
      student = currentNode->student;
      break;
    }
  }
}

void BinarySearchTree::inOrderPrint(node *currentNode)
{
}

void BinarySearchTree::preOrderPrint(node *currentNode)
{
}

void BinarySearchTree::postOrderPrint(node *currentNode)
{
}
