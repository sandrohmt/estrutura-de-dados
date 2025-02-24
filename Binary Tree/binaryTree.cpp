#include <iostream>
#include <cstddef>
#include  "binaryTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(); 
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree() 
{

} 

void BinarySearchTree::deleteTree(node* currentNode) 
{

}

node* BinarySearchTree::getRoot() 
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
    node* temp = new No;
    delete temp;
    return false;
  }
  catch(bad_alloc exception)
  {
    return true;
  }
  

}

void BinarySearchTree::push(Student student) 
{

}

ItemType BinarySearchTree::pop(Student student) 
{

}

void BinarySearchTree::search(Student& student, bool& search) 
{

}

void BinarySearchTree::inOrderPrint(node* currentNode) 
{

}

void BinarySearchTree::preOrderPrint(node* currentNode) 
{

}

void BinarySearchTree::postOrderPrint(node* currentNode) 
{

}
