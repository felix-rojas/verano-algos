/*
 * Algoritmos de ordenamiento
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

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// swapsort
void swapSort(vector<int> &vector, int &compara, int &nSwaps)
{
  compara = nSwaps = 0;
  for (int i = 0; i < vector.size(); i++)
  {
    for (int j = i + 1; j < vector.size(); j++)
    {
      compara++;
      if (vector[i] > vector[j])
      {
        std::swap(vector[i], vector[j]);
        nSwaps++;
      }
    }
  }
}

// selectionSort
// Selection sort moves the least amount of elements compared to any other sort
// unfortunately its time will always be n^2 both in best case and worst case
// this is pretty good for moving big files that require lots processing power
void selectionSort(vector<int> &vector, int &compara, int &nSwaps)
{
  compara = nSwaps = 0;
  int minIndex = 0;
  for (int i = 0; i < vector.size() - 1; i++)
  {
    minIndex = i;
    for (int j = i + 1; j < vector.size(); j++)
    {
      compara++;
      if (vector[j] < vector[minIndex])
      {
        minIndex = j;
      }
    }
    std::swap(vector[i], vector[minIndex]);
    nSwaps++;
  }
}

// bubbleSort
// mueve el elemento mas grande hasta arriba

void bubbleSort(vector<int> &vector, int &compara, int &nSwaps) {
  compara = nSwaps = 0;
  for(int i = 0; i < vector.size() - 1; i++) {
    for(int j = 0; j < vector.size() - i - 1; j++) {
      compara++;
      if(vector[j]  > vector[j + 1]) {
        std::swap(vector[j], vector[j + 1]);
        nSwaps++;
      }
    }
  }
}

while (swapped)
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