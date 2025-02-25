#include "student.h"

struct node
{
  Student student;
  node *leftChild;
  node *rightChild;
};

class BinarySearchTree
{
private:
  node *root;

public:
  BinarySearchTree();
  ~BinarySearchTree();
  void deleteTree(node *currentNode);
  node *getRoot();
  bool isFull();
  bool isEmpty();
  void push(Student student);
  void pop(Student student);
  void popSearch(Student student, node *&currentNode); // O ponteiro está atribuído por referência porque depois já dá pra saber qual é o ponteiro do pai dele.
  void removeNode(node *&currentNode);
  void getSuccessor(Student &successorStudent, node *temp); // successorStudent é onde a gente vai guardar o aluno que tá no sucessor
  void search(Student &student, bool &search);
  void inOrderPrint(node *currentNode);
  void preOrderPrint(node *currentNode);
  void postOrderPrint(node *currentNode);
};