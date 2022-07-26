/** 
* Ejemplo que implementa dos representaciones de Grafos
* (Matriz de adyacencia y Lista de adyacencia) y el recorrido BFS
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main < graph01.txt
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < graph01.txt
**/

#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::cout << "Ejemplo de grafos (representaciones)!" << std::endl;
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph<std::string> g1;
  g1.readGraph(true, inputInfo);
  g1.print();
  std::cout << std::endl;
  //g1.printGraphInfo();
  g1.BFS(1);
  
  // Regresa a linea cero el archivo de entrada
  inputInfo.clear();
  inputInfo.seekg(0);

  std::cout << std::endl;
  // Construye un grafo a partir de la consola usando
  // representacion de Matriz de adyacencia
  Graph<std::string> g2;
  g2.readGraph(false, inputInfo);
  g2.print();
  std::cout << std::endl;
  //g2.printGraphInfo();
  g2.BFS(1);

  
  return 0;
} 