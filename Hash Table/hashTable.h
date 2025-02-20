#include "Student.h"

class HashTable
{
private:
  int hashFunction(Student student);
  int maxItems;
  int maxPositions;
  int qttItems;
  Student *structure;

public:
  HashTable(int arraySize, int max);
  ~HashTable();
  bool isFull();
  int getLength();
  void push(Student student);
  void pop(Student student);
  void search(Student &student, bool &search); // O & significa parâmetro por referência, porque só será inserido o RA do student.
  void print();
};