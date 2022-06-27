/*
  compilar:
    g++ -std=c++17 -Wall *.cpp

  ejecutar:
    ./a.out
*/

#include <iostream>
#include "ListaTemplate.h"

int main()
{
    std::cout << "Template example!\n";
    ListaTemplate<int> myList;

    myList.insert(15);
    myList.insert(1);
    myList.insert(13);
    myList.insert(14);
    myList.print();

    return 0;
}