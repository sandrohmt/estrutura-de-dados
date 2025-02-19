typedef int ItemType;
const int max_items = 100;

class queue
{
private:
  int first, last;
  ItemType *structure; 

public:
  queue();  
  ~queue(); 
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
};