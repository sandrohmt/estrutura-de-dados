#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include "node.h"

class DynamicStack
{
private:
  node *topNode;

public:
  DynamicStack();
  ~DynamicStack();
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
};

#endif