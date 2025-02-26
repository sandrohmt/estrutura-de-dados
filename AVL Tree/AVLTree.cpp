#include <iostream>
#include <cstddef>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{
  root = NULL;
}

AVLTree::~AVLTree()
{
  deleteTree(root);
}

void AVLTree::deleteTree(node *currentNode)
{
  if (currentNode != NULL)
  {
    deleteTree(currentNode->leftChild);
    deleteTree(currentNode->rightChild);

    delete currentNode;
  }
}

node *AVLTree::getRoot()
{
  return root;
}

bool AVLTree::isFull()
{
  try
  {
    node *temp = new node;
    delete temp;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

bool AVLTree::isEmpty()
{
  return (root == NULL);
}

void AVLTree::push(Student student)
{
  bool incresead;
  recursivePush(root, student, incresead);
}

void AVLTree::recursivePush(node *&currentNode, Student student, bool &increased)
{
  if (currentNode == NULL)
  {
    currentNode = new node;
    currentNode->rightChild = NULL;
    currentNode->leftChild = NULL;
    currentNode->student = student;
    currentNode->bFactor = 0;
    increased = true;
    return;
  }

  if (student.getRa() < currentNode->student.getRa())
  {
    recursivePush(currentNode->leftChild, student, increased);
    if (increased)
    {
      currentNode->bFactor--;
    }
  }
  else
  {
    recursivePush(currentNode->rightChild, student, increased);
    if (increased)
    {
      currentNode->bFactor++;
    }
  }
  performRotation(currentNode);

  if (increased && currentNode->bFactor == 0)
  {
    increased = false;
  }
}

void AVLTree::pop(Student student)
{
  bool decresead;
  popSearch(student, root, decresead); // Vai fazer uma busca do aluno começando pela raiz
}

void AVLTree::popSearch(Student student, node *&currentNode, bool &decreased)
{
  if (student.getRa() < currentNode->student.getRa())
  {
    popSearch(student, currentNode->leftChild, decreased);
    if (decreased)
    {
      currentNode->bFactor++;
    }
  }
  else if (student.getRa() > currentNode->student.getRa())
  {
    popSearch(student, currentNode->rightChild, decreased);
    if (decreased)
    {
      currentNode->bFactor--;
    }
  }
  else
  {
    removeNode(currentNode, decreased);
  }
  if (currentNode != NULL)
  {
    performRotation(currentNode);
    if (decreased && currentNode->bFactor != 0)
    {
      decreased = false;
    }
  }
}

void AVLTree::removeNode(node *&currentNode, bool &decreased)
{
  node *temp = currentNode;
  if (currentNode->leftChild == NULL)
  {
    currentNode = currentNode->rightChild;
    delete temp;
  }
  else if (currentNode->rightChild == NULL)
  {
    currentNode = currentNode->leftChild;
    delete temp;
  }
  else
  {
    Student successorStudent;
    getSuccessor(successorStudent, currentNode);
    currentNode->student = successorStudent;
    popSearch(successorStudent, currentNode->rightChild, decreased);
    if (decreased)
    {
      currentNode->bFactor--; // Aqui sempre diminui um porque o obter sucessor é sempre o menor valor a direita, se diminui a direita, diminui um o valor de balanceamento.
    }
  }
}

void AVLTree::getSuccessor(Student &successorStudent, node *temp) // Menor valor a direita
{
  temp = temp->rightChild;
  while (temp->leftChild != NULL)
  {
    temp = temp->leftChild;
  }
  successorStudent = temp->student;
}

void AVLTree::search(Student &student, bool &search)
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

void AVLTree::inOrderPrint(node *currentNode)
{
  if (currentNode != NULL)
  {
    inOrderPrint(currentNode->leftChild);

    cout << currentNode->student.getName() << ": ";
    cout << currentNode->student.getRa() << ": " << endl;

    inOrderPrint(currentNode->rightChild);
  }
}

void AVLTree::preOrderPrint(node *currentNode)
{
  if (currentNode != NULL)
  {
    cout << currentNode->student.getName() << ": ";
    cout << currentNode->student.getRa() << ": " << endl;

    preOrderPrint(currentNode->leftChild);
    preOrderPrint(currentNode->rightChild);
  }
}

void AVLTree::postOrderPrint(node *currentNode)
{
  if (currentNode != NULL)
  {
    postOrderPrint(currentNode->leftChild);
    postOrderPrint(currentNode->rightChild);

    cout << currentNode->student.getName() << ": ";
    cout << currentNode->student.getRa() << ": " << endl;
  }
}

void AVLTree::rightRotation(node *&parent)
{
  node *newParent = parent->leftChild;
  parent->leftChild = newParent->rightChild;
  newParent->rightChild = parent;
  parent = newParent;
}

void AVLTree::leftRotation(node *&parent)
{
  node *newParent = parent->rightChild;
  parent->rightChild = newParent->leftChild;
  newParent->leftChild = parent;
  parent = newParent;
}

void AVLTree::rightLeftRotation(node *&parent)
{
  node *child = parent->rightChild;
  rightRotation(child);
  parent->rightChild = child;
  leftRotation(parent);
}

void AVLTree::leftRightRotation(node *&parent)
{
  node *child = parent->leftChild;
  leftRotation(child);
  parent->leftChild = child;
  rightRotation(parent);
}

void AVLTree::performRotation(node *&parent)
{
  node *child;
  node *grandchild; // Caso precise de rotação dupla

  if (parent->bFactor == -2) // Rotaciona para direita
  {

    child = parent->leftChild;

    if (child->bFactor == -1) // Simples para direita
    {
      parent->bFactor = 0;
      child->bFactor = 0;
      rightRotation(parent);
    }
    else if (child->bFactor == 0) // Simples para a direita
    {
      parent->bFactor = -1;
      child->bFactor = -1;
      rightRotation(parent);
    }
    else if (child->bFactor == 1) // Rotação dupla
    {
      grandchild = child->rightChild;
      if (grandchild->bFactor == -1)
      {
        parent->bFactor = 1;
        child->bFactor = 0;
      }
      else if (grandchild->bFactor == 0)
      {
        parent->bFactor = 0;
        child->bFactor = 0;
      }
      else if (grandchild->bFactor == 1)
      {
        parent->bFactor = 0;
        child->bFactor = -1;
      }
      grandchild->bFactor = 0;
      leftRightRotation(parent);
    }
  }
  else if (parent->bFactor == 2) // Rotaciona para esquerda
  {

    child = parent->rightChild;

    if (child->bFactor == 1) // Simples para esquerda
    {
      parent->bFactor = 0;
      child->bFactor = 0;
      leftRotation(parent);
    } else if (child->bFactor == 0) // Simples para esquerda
    {
      parent->bFactor = 1;
      child->bFactor = -1;
      leftRotation(parent);
    } else if (child->bFactor == -1) // Rotação dupla
    {
      grandchild = child->leftChild;

      if (grandchild->bFactor == -1)
      {
        parent->bFactor = 0;
        child->bFactor = 1;
      } else if (grandchild->bFactor == 0)
      {
        parent->bFactor = 0;
        child->bFactor = 0;
      } else if (grandchild->bFactor == 1)
      {
        parent->bFactor = -1;
        child->bFactor = 0;
      }
      grandchild->bFactor = 0;
      rightLeftRotation(parent);
    }
  }
}
