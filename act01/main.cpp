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
    std::cout << std::endl;

    std::cout << myList.getData(3) << std::endl;
    myList.erase();
    myList.print();
    std::cout << std::endl;

    std::cout << "Elementos en vector: "<< myList.getSize() << std::endl;
    myList.erase();
    myList.erase();
    myList.erase();
    myList.erase();

    return 0;
}