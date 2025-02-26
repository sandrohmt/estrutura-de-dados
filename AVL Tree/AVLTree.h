#include "student.h"

struct node
{
  Student student;
  node *leftChild;
  node *rightChild;

  int bFactor; 
};

class AVLTree
{
private:
  node *root;

public:
  AVLTree();
  ~AVLTree();
  void deleteTree(node *currentNode);
  node *getRoot();
  bool isFull();
  bool isEmpty();
  void push(Student student);
  void recursivePush(node*& currentNode, Student student,  bool& increased);
  void pop(Student student);
  void popSearch(Student student, node *&currentNode, bool& decreased); 
  void removeNode(node *&currentNode, bool& decreased);
  void getSuccessor(Student &successorStudent, node *temp); 
  void search(Student &student, bool &search);
  void inOrderPrint(node *currentNode);
  void preOrderPrint(node *currentNode);
  void postOrderPrint(node *currentNode);
  void rightRotation(node*& tree);
  void leftRotation(node*& tree);
  void rightLeftRotation(node*& tree);
  void leftRightRotation(node*& tree);
  void performRotation(node*& tree);
};