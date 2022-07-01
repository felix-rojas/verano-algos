/*
 * Algoritmos de busqueda
 *
 * Compilación:
 *  g++ -std=c++17 *.cpp -o main
 *
 * Ejecución:
 *  ./main < TestCases/test01.txt
 */

#include <iostream>
#include <vector>
#include <chrono>

#define endl "\n"
using std::cin;
using std::cout;
// using std::endl;
using std::vector;

// Eliezer comento aqui xd
int linearSearch(vector<int> nums, int key)
{
    int i = 0;
    while (i < nums.size() || nums[i])
    {
        i++;
    }

    if (i < nums.size() || nums[i] != key)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int i, tmp, size, key, flag;
    // Inicio conteo de tiempo de ejecución
    auto startTime = std::chrono::high_resolution_clock::now();
    cin >> size;
    cout << "Size: " << size << endl;
    cin >> key;
    cout << "Key: " << key << endl;
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
        cout << "Los elementos del arreglo son: " << endl;
        for (i = 0; i < size; i++)
        {
            cout << myVector[i] << " ";
        }
        cout << endl;
    }
    // Eliezer tambien comento aqui
    cout << "Key buscado está en índice: " << linearSearch(myVector, key);
    return 0;
}