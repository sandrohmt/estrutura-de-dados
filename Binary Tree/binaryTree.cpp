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
}

void BinarySearchTree::search(Student &student, bool &search)
{
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
