typedef int ItemType; 

struct node
{
  ItemType value;
  node* next;
};


class dynamicQueue
{
private:
node* front;
node* rear;

public:
  dynamicQueue();  
  ~dynamicQueue(); 
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
};