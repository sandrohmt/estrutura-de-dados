typedef int ItemType; 

struct node
{
  ItemType value;
  node* next;
};


class dynamicStack
{
private:
node* topNode;

public:
  dynamicStack();  
  ~dynamicStack(); 
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
};