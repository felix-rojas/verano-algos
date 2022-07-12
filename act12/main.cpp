/** 
* Ejemplo que implementa un stack usando una lista ligada 
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
#include "StackLinkedList.h"

int main() {
 std::cout << "Ejemplo de Stack implementado con una lista ligada" << std::endl;

  StackLinkedList<int> miStack;
  std::cout << "numElements: " << miStack.getNumElements() << std::endl;
  // Push
  std::cout << "Push de 5 elementos ..." << std::endl;
  for (int i = 1; i < 6; i++) {
    miStack.push(i);
  }
  std::cout << "numElements: " << miStack.getNumElements() << std::endl;
  miStack.print();
  std::cout << std::endl;

  // Pop
  // getData
  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
  
  std::cout << "numElements: " << miStack.getNumElements() << std::endl;
  miStack.print();
  std::cout << std::endl;
   
  // Top
  try {
    std::cout << "Top(): " << miStack.getTop() << std::endl;
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }

  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
    
  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
    
  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
    
  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
  
  try {
    std::cout << "Pop(): " << std::endl;
    miStack.pop();
  }
  catch (std::out_of_range e) {
    std::cout << "Ocurrio un error: " << e.what() << std::endl;
    std::cout << "No se modifico el stack" << std::endl;
  }
  
  return 0;
}