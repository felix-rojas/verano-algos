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

    return 0;
}