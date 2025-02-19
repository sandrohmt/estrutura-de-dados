typedef int ItemType; // Para facilitar a tipagem, caso a seja necessário mudar o tipo dos exemplos
const int max_items = 100;

class stack
{
private:
  int length;
  ItemType *structure; // Vetor

public:
  stack();  // construtora
  ~stack(); // destrutora
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
  int getLength();
};