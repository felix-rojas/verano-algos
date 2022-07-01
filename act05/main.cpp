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

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//Eliezer comento aqui xd
int linearSearch(vector<int> nums, int key, int &compara){
  int i = 0;
  while (i < nums.size() && nums[i] != key){
    i++;
    compara++;
  }
  if (i < nums.size()){
    return i;
  } else{
    return -1;
  }
  
}


int main(void) {
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
    for(i = 0; i < size; i++) {
      cin >> tmp;
      myVector.push_back(tmp);
    }
    if (flag) {
      cout << "Los elementos del arreglo son: " << endl;
      for(i = 0; i < size; i++) {
        cout << myVector[i] << " ";
      }
      cout << endl;
    }
    int comparaciones = 0;
 //Eliezer tambien comento aqui
    cout << "Key buscado está en índice: " << linearSearch(myVector, key, comparaciones) << endl;
  // Termina conteo de tiempo de ejecución 
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;

    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;
    cout << "Numero de comparaciones: " << comparaciones << endl;
    return 0;
  }