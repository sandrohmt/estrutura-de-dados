struct node
{
  Student student;
  node* leftChild;
  node* rightChild;
};


class BinarySearchTree
{
private:
node* root;

public:
  BinarySearchTree();  
  ~BinarySearchTree(); 
  void deleteTree(node* currentNode);
  node* getRoot();
  bool isFull();
  bool isEmpty();
  void push(Student student);
  ItemType pop(Student student);
  void search(Student& student, bool& search)
  void inOrderPrint(node* currentNode);
  void preOrderPrint(node* currentNode);
  void postOrderPrint(node* currentNode);
};