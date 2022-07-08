/*
 * Actividad individual 9
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -o main *.cpp
 * Ejecucion:
 *    ./main
 */

#include <iostream>
#include "LinkedList.h"

int main(void)
{
    LinkedList<int> myList;

    for (int i = 0; i < 5; i++)
    {
        myList.addFirst(i);
    }

    std::cout << myList.getSize() << std::endl;
    
    for (int i = 0; i < 5; i++)
    {
        myList.addLast(i);
    }

    return 0;
}
