#include <iostream>
#include "dynamicQueue.h"

using namespace std;

int main() {
  dynamicQueue dynamicQueue1;
  ItemType item;
  int option;
  cout << "Programa gerador de fila:\n";

  do {
    cout << "Digite 0 para parar o programa! \n";
    cout << "Digite 1 para inserir um elemento! \n";
    cout << "Digite 2 para remover um elemento! \n";
    cout << "Digite 3 para imprimir a fila! \n";

    cin >> option;

    switch (option) {
      case 1: 
      cout << "Digite o elemento a ser inserido:\n";
      cin >> item;
      dynamicQueue1.push(item);
      break;

    case 2:
        item = dynamicQueue1.pop();
        if (!dynamicQueue1.isEmpty()) {
          cout << "Elemento removido: " << item << endl;
        }        
        break;
    
    case 3:
      dynamicQueue1.print();
      break;
    }
    
  } while(option != 0);

  return 0;
}