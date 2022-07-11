/** 
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
**/

#include <iostream>
#include "LinkedList.h"

int main() {
  std::cout << "Ejemplo de listas ligadas\n";
  
  LinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  // addFirst
  std::cout << "Agregando 5 elementos al frente..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // addLast
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 10; i < 15; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // deleteData
  std::cout << "Delete 5: " << std::endl;
  miLista.deleteData(5);
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete 14: " << std::endl;
  miLista.deleteData(14);
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete 10: " << std::endl;
  miLista.deleteData(10);
  miLista.printList();
  std::cout << std::endl;

  // deleteAt puede lanzar una excepcion 
  std::cout << "Delete at 0: " << std::endl;
  try {
    miLista.deleteAt(0);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete at 3: " << std::endl;
  try {
    miLista.deleteAt(3);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  miLista.printList();
  std::cout << std::endl;
  std::cout << "Delete at 4: " << std::endl;
  try {
    miLista.deleteAt(4);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  // getData puede lanzar una excepcion 
  std::cout << "getData at 0: " << std::endl;
  try {
    std::cout << miLista.getData(0) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  std::cout << "getData at 3: " << std::endl;
  try {
    std::cout << miLista.getData(3) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  std::cout << "getData at 1: " << std::endl;
  try {
    std::cout << miLista.getData(1) << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

   // updateData puede lanzar una excepcion 
  std::cout << "updateData(3, 33): " << std::endl;
  try {
    miLista.updateData(3, 33);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "updateData(12, 1212): " << std::endl;
  try {
    miLista.updateData(12, 1212);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;
  std::cout << "updateData(2, 22): " << std::endl;
  try {
    miLista.updateData(2, 22);
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl << "No se modifico la lista" << std::endl;
  }  
  miLista.printList();
  std::cout << std::endl; 
 
  return 0;
}