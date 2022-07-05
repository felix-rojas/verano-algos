/*
 * Algoritmos de ordenamiento parte 3
 * 
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 *
 * Ejecución:
 *  ./main < TestCases/test02.txt
 */

#include <iostream>
#include <vector>
#include <chrono>
#include "mergeSort.h"


using std::cin;
using std::cout;
using std::endl;
using std::vector;

  int main(void)
  {
    int i, tmp, size, flag;
    // Inicio conteo de tiempo de ejecución
    auto startTime = std::chrono::high_resolution_clock::now();
    cin >> size;
    cout << "Size: " << size << endl;
    cin >> flag;
    cout << "Print flag: " << flag << endl;
    // Declaración del
    vector<int> myVector;
    // Lectura de los elementos del arreglo
    for (i = 0; i < size; i++)
    {
      cin >> tmp;
      myVector.push_back(tmp);
    }
    if (flag)
    {
      cout << "Los elementos del vector son: " << endl;
      for (i = 0; i < size; i++)
      {
        cout << myVector[i] << " ";
      }
      cout << endl;
    }
    int comparaciones = 0;
    int intercambios = 0;
    swapSort(myVector, comparaciones, intercambios);
    if (flag)
    {
      cout << "Los elementos del vector ordenado son: " << endl;
      for (i = 0; i < size; i++)
      {
        cout << myVector[i] << " ";
      }
      cout << endl;
    }

    // Termina conteo de tiempo de ejecución
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;

    cout << "Tiempo de ejecución en ms: " << totalTime / std::chrono::milliseconds(1) << endl;
    cout << "Numero de comparaciones: " << comparaciones << endl;
    cout << "Numero de intercambios: " << intercambios << endl;
    return 0;
  }