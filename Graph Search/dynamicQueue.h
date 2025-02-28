#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

#include "node.h"

class DynamicQueue
{
private:
  node *front;
  node *rear;

public:
  DynamicQueue();
  ~DynamicQueue();
  bool isFull();
  bool isEmpty();
  void push(ItemType item);
  ItemType pop();
  void print();
};

#endif