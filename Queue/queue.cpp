#include <iostream>
#include "queue.h"

using namespace std;

queue::queue() {
  first = 0;
  last = 0;
  structure = new ItemType[max_items];
} 

queue::~queue() {
  delete [] structure;
} 

bool queue::isFull() {
  return (last - first == max_items);
}

bool queue::isEmpty() {
  return (first == last);
}

void queue::push(ItemType item) {
  if (isFull()) {
    cout << "Não é possível inserir porque a fila está cheia!\n";
  } else {
    structure[last % max_items] = item;
    last++;
  }
  
}

ItemType queue::pop() {
  if (isEmpty()) {
    cout << "Não é possível remover porque a fila está vazia!\n";
    return 0;
  } else {
    first++;
    return structure[(first - 1) % max_items];
  }
}

void queue::print() {
  cout << "Fila: [ ";
  for (int i = first; i < last; i++)
  {
    cout << structure[i % max_items] << " ";
  }
  cout << "]\n";
}
