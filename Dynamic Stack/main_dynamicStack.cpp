#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  stack stack1;
  ItemType item;
  int option;
  cout << "Programa gerador de pilha:\n";

  do {
    cout << "Digite 0 para parar o programa! \n";
    cout << "Digite 1 para inserir um elemento! \n";
    cout << "Digite 2 para remover um elemento! \n";
    cout << "Digite 3 para imprimir a pilha! \n";

    cin >> option;

    switch (option) {
      case 1: 
      cout << "Digite o elemento a ser inserido:\n";
      cin >> item;
      stack1.push(item);
      break;

    case 2:
        item = stack1.pop();
        if (!stack1.isEmpty()) {
          cout << "Elemento removido: " << item << endl;
        }        
        break;
    
    case 3:
      stack1.print();
      break;
    }
    
  } while(option != 0);

  return 0;
}