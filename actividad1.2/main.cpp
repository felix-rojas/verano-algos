/*
    Autores:
    - Felix Javier Rojas Gallardo A01201946@tec.mx
    - Alexia Castillo Diaz A00227250@tec.mx
    - Santiago Vargas Ochoa A01782242@tec.mx
 * Algoritmos de busqueda
 *
 * Compilación:
 *  g++ -std=c++17 *.cpp -o main
 *
 * Ejecución:
 *  ./main < test-cases/test01.txt
 *  ./main < test-cases/test02.txt
 *  ./main < test-cases/test03.txt
 *  ./main < test-cases/test04.txt

 Los tests 1 y 2 funcionan
 */

// Librerias
#include <vector>
#include <iostream>
#include <chrono>

// Metodos
#include "ordenaBurbuja.h"
#include "ordenaQuick.h"
#include "ordenaMerge.h"
#include "busquedaBinaria.h"
#include "busquedaSecuencialOrd.h"

// Namespace
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
    // Argumentos
    int size, orderFlag, searchFlag, key, tmp;

    // Variables globales
    // le reasignamos valor 0 en cada llamada
    int swaps, comparaOrden, comparaBusqueda, pos;

    cin >> size;
    cout << "Size: " << size << endl;

    cin >> orderFlag;
    cout << "Order flag: " << orderFlag << endl;

    cin >> searchFlag;
    cout << "Search flag: " << searchFlag << endl;

    cin >> key;
    cout << "Key: " << key << endl;

    // Declaración del vector con los números
    vector<int> myVector;

    // Lectura de los elementos del arreglo
    for (int i = 0; i < size; i++)
    {
        cin >> tmp;
        myVector.push_back(tmp);
    }

    switch (orderFlag)
    {
    // Ordenamiento Burbuja
    case 1:
        // Busqueda secuencial burbuja
        if (searchFlag == 1)
        {
            pos = -1;
            swaps, comparaOrden, comparaBusqueda = 0;
            ordenaBurbuja(myVector, comparaOrden, swaps);
            cout << "Numero de comparaciones: " << comparaOrden << endl;
            cout << "Numero de swaps: " << swaps << endl;

            pos = busquedaSecuencialOrd(myVector, key, comparaBusqueda);
            cout << "Numero de comparaciones: " << comparaBusqueda << endl;
            cout << "Posicion: " << pos << endl;
        }
        // Busqueda binaria Burbuja
        else if (searchFlag == 2)
        {
            pos = -1;
            swaps, comparaOrden, comparaBusqueda = 0;
            ordenaBurbuja(myVector, comparaOrden, swaps);
            cout << "Numero de comparaciones: " << comparaOrden << endl;
            cout << "Numero de swaps: " << swaps << endl;

            pos = busquedaBinaria(myVector, key, comparaBusqueda);
            cout << "Numero de comparaciones: " << comparaBusqueda << endl;
            cout << "Posicion: " << pos << endl;
        }
        break;

    // Ordenamiento Merge
    case 2:
        // Busqueda secuencial Merge
        if (searchFlag == 1)
        {
            pos = -1;
            comparaOrden, comparaBusqueda = 0;
            ordenaMerge(myVector, 0, myVector.size(), comparaOrden);
            cout << "Numero de comparaciones: " << comparaOrden << endl;
            cout << "Numero de swaps: "
                 << "No aplica para merge" << endl;

            pos = busquedaSecuencialOrd(myVector, key, comparaBusqueda);
            cout << "Numero de comparaciones: " << comparaBusqueda << endl;
            cout << "Posicion: " << pos << endl;
        }
        // Busqueda binaria Merge
        else if (searchFlag == 2)
        {
            pos = -1;
            comparaOrden, comparaBusqueda = 0;
            ordenaMerge(myVector, 0, myVector.size(), comparaOrden);
            cout << "Numero de comparaciones: " << comparaOrden << endl;
            cout << "Numero de swaps: "
                 << "No aplica para merge" << endl;

            pos = busquedaBinaria(myVector, key, comparaBusqueda);
            cout << "Numero de comparaciones: " << comparaBusqueda << endl;
            cout << "Posicion: " << pos << endl;
        }
        break;

        // ! Not done yet, uncomment when programming
        // // Ordenamiento Quick
        // case 3:
        //     // Busqueda secuencial Quick
        //     if (searchFlag == 1)
        //     {
        //         /* code */
        //     }
        //     // Busqueda binaria Quick
        //     else if (searchFlag == 2)
        //     {
        //     }
        //     break;

    default:
        cout << "Invalid arguments" << endl;
        break;
    }
}
