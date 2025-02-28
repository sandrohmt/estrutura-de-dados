#ifndef NO_H
#define NO_H

#include <iostream>

using namespace std;

typedef string ItemType;

struct node
{
  ItemType value;
  node *next;
};

#endif