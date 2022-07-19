// Alexia Castillo Diaz-A00227250
//  Felix Javier Rojas Gallardo - A01201946

// Compilation g++ -std=c++17 -o main *.cpp
// Compilation for debugging :
//  1.  g++ -std=c++17 -o main *.cpp
//  2.  valgrind --leak-check=full -s ./main

#include <iostream>
#include "priority_queue.h"

int main()
{
  std::cout << "----------------------- \n";
  std::cout << "  Caso 1 de un Heap \n";
  std::cout << "----------------------- \n";
  priority_queue<int> milista(6);
  std::cout << "Empty " << milista.Empty() << std::endl;
  std::cout << "Size " << milista.getNumElements() << std::endl;
  std::cout << "Push:" << std::endl;
  milista.push(2);
  milista.push(3);
  milista.push(1);
  milista.push(6);
  milista.push(5);
  milista.push(4);
  milista.push(7);
  milista.printHeap();
  std::cout << "Empty " << milista.Empty() << std::endl;
  std::cout << "Size: " << milista.getNumElements() << std::endl;
  std::cout << "top: " << milista.top() << std::endl;
  std::cout << "size: " << milista.getNumElements() << std::endl;
  milista.pop();
  std::cout << "Lista después del pop: " << milista.getNumElements() << std::endl;
  milista.printHeap();

  std::cout << "----------------------- \n";
  std::cout << "  Caso 2 de un Heap \n";
  std::cout << "----------------------- \n";
  priority_queue<int> milista2(7);
  std::cout << "Empty " << milista2.Empty() << std::endl;
  std::cout << "Size " << milista2.getNumElements() << std::endl;
  std::cout << "Push:" << std::endl;
  milista2.push(12);
  milista2.push(13);
  milista2.push(11);
  milista2.push(16);
  milista2.push(15);
  milista2.push(14);
  milista2.push(17);
  milista2.printHeap();
  std::cout << "Empty " << milista2.Empty() << std::endl;
  std::cout << "Size: " << milista2.getNumElements() << std::endl;
  milista2.printHeap();
  std::cout << "top: " << milista2.top() << std::endl;
  std::cout << "size: " << milista2.getNumElements() << std::endl;
  milista2.pop();
  std::cout << "Lista después del pop: " << milista2.getNumElements() << std::endl;
  milista2.printHeap();

  std::cout << "----------------------- \n";
  std::cout << "  Caso 3 de un Heap \n";
  std::cout << "----------------------- \n";
  priority_queue<int> milista4(4);
  std::cout << "Empty " << milista4.Empty() << std::endl;
  std::cout << "Size " << milista4.getNumElements() << std::endl;
  std::cout << "Push:" << std::endl;
  milista4.push(2);
  milista4.push(4);
  milista4.push(6);
  milista4.push(8);
  milista4.push(10);
  milista4.printHeap();
  std::cout << "Empty " << milista4.Empty() << std::endl;
  std::cout << "Size: " << milista4.getNumElements() << std::endl;
  milista4.printHeap();
  std::cout << "top: " << milista4.top() << std::endl;
  std::cout << "size: " << milista4.getNumElements() << std::endl;
  milista4.pop();
  std::cout << "Lista después del pop: " << milista4.getNumElements() << std::endl;
  milista4.printHeap();

  std::cout << "----------------------- \n";
  std::cout << "  Caso 4 de un Heap \n";
  std::cout << "----------------------- \n";
  priority_queue<int> milista3(5);
  std::cout << "Empty " << milista3.Empty() << std::endl;
  std::cout << "Size " << milista3.getNumElements() << std::endl;
  std::cout << "Push:" << std::endl;
  milista3.push(120);
  milista3.push(130);
  milista3.push(110);
  milista3.push(160);
  milista3.push(150);
  milista3.printHeap();
  std::cout << "Empty " << milista3.Empty() << std::endl;
  std::cout << "Size: " << milista3.getNumElements() << std::endl;
  milista3.printHeap();
  std::cout << "top: " << milista3.top() << std::endl;
  std::cout << "size: " << milista3.getNumElements() << std::endl;
  milista3.pop();
  std::cout << "Lista después del pop: " << milista3.getNumElements() << std::endl;
  milista3.printHeap();
}
