#include <iostream>
#include "dynamicStack.h"

using namespace std;

int main() {
  dynamicStack dynamicStack1;
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
      dynamicStack1.push(item);
      break;

    case 2:
        item = dynamicStack1.pop();
        if (!dynamicStack1.isEmpty()) {
          cout << "Elemento removido: " << item << endl;
        }        
        break;
    
    case 3:
      dynamicStack1.print();
      break;
    }
    
  } while(option != 0);

  return 0;
}