#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> 
#include <map>
#include <set>
#include "LinkedList.h"
#include "QueueLinkedList.h"

template <class T>
class Graph {
  private:
    int numNodes;
    int numEdges;
    bool representation;  // true Lista de adyacencia;  false Matriz de adyacencia
    // Cada nodo tiene un id y un objeto de datos tipo T
    std::map<int, T> nodesInfo;
    // Lista de adyacencia (vector de listas ligadas)
    std::vector<LinkedList<int>> adjList;
    // Matriz de adyacencia (vector de vectores)
    std::vector<std::vector<int>> adjMatrix;

    void loadGraphList(std::istream &input);
    void loadGraphMatrix(std::istream &input);
    void split(std::string line, std::vector<int> &res);
    
  public:
    Graph();
    ~Graph();
    void readGraph(bool representa, std::istream &input);
    void print();
    void printGraphInfo();
    void BFS(int v);
    

};

template <class T>
Graph<T>::Graph() {
  numNodes = 0;
  numEdges = 0;
  representation = true;
}

template <class T>
Graph<T>::~Graph() {
  if (representation) {
    adjList.clear();
  }
  else {
    adjMatrix.clear();
  }
  numNodes = 0;
  numEdges = 0;
  representation = true;
}

template <class T>
void Graph<T>::readGraph(bool representa, std::istream &input) {
  representation = representa;
  // Lista de adyacencia
  if (representation) {
    loadGraphList(input);
  }
  else {  // Matriz de adyacencia
    loadGraphMatrix(input);
  } 
}

template <class T>
void Graph<T>::split(std::string line, std::vector<int> &res) {
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos) {
      res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
      lastPos = strPos + 1;
      strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}


template <class T>
void Graph<T>::loadGraphList(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignorar primera linea de texto
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];
      // Reservar memoria para los renglones 
      // de la lista de adyacencia (renglon 0 no utilizado) 
      adjList.resize(numNodes+1);
      i++;
      continue; 
    }
    if (i > 1 && i < numNodes+2) {  // Para cada nodo lee su informacion
      T data = line; // ATENCION: convertir al tipo de dato adecuado
      nodesInfo.insert(std::make_pair(i-1, data));  // map <key, data> con los nodos indexados 
      // Declara una lista vacia para cada renglon y la almacena en el vector
      LinkedList<int> tmpList; // Para grafos ponderados usar lista de pares (nodo, peso)
      adjList[i-1] = tmpList; 
      i++;
      continue;
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    // Grafos no dirigidos agrega aristas (u,v) y (v,u)       
    adjList[u].addLast(v); // en grafo ponderado guardar pares (nodo, peso)
    adjList[v].addLast(u);
    i++;
  }
}

template <class T>
void Graph<T>::loadGraphMatrix(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignorar primera linea de texto
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> res;
      split(line, res);
      numNodes = res[0];
      numEdges = res[2];
      // Reservar memoria para los renglones 
      // de la matriz de adyacencia (renglon 0 no utilizado) 
      adjMatrix.resize(numNodes+1);
      i++;
      continue; 
    }
    if (i > 1 && i < numNodes+2) {  // Para cada nodo lee su informacion
      T data = line; // ATENCION: convertir al tipo de dato adecuado
      nodesInfo.insert(std::make_pair(i-1, data));  // map <key, data> con los nodos indexados 
      // Declara un vector vacio para cada renglon y la almacena en el vector de adjMatrix 
      std::vector<int> tmpVector(numNodes+1, 0); // Para grafos ponderados usar vector de pares (nodo, peso)
      adjMatrix[i-1] = tmpVector; 
      i++;
      continue;
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    // Grafos no dirigidos agrega aristas (u,v) y (v,u)       
    adjMatrix[u][v] = 1; // en grafo ponderado guardar el peso
    adjMatrix[v][u] = 1;
    i++;
  }
}

template <class T>
void Graph<T>::print(){
  if (representation) {
    std::cout << "Adjacency List" << std::endl;
    for (int u = 1; u <= numNodes; u++){
      std::cout << "vertex " << u << ": ";
      LLNode<int> *ptr = adjList[u].getHead();
      while (ptr != nullptr) {
        int v = ptr->data;
        std::cout << v << "  ";
        ptr = ptr->next;
      }
      std::cout << std::endl;
    }
  }
  else {
    std::cout << "Adjacency Matrix" << std::endl;
    for (int u = 1; u <= numNodes; u++){
      std::cout << "vertex " << u << ": ";
      for (int v = 1; v <= numNodes; v++) {
        std::cout << adjMatrix[u][v] << " ";
      }
      std::cout << std::endl;
    }    
  }
}

template <class T>
void Graph<T>::printGraphInfo(){
  if (representation) {
    std::cout << "Adjacency List" << std::endl;
    for (int u = 1; u <= numNodes; u++){
      std::cout << "vertex " << u << " (" << nodesInfo[u] << "): ";
      LLNode<int> *ptr = adjList[u].getHead();
      while (ptr != nullptr) {
        int v = ptr->data;
        std::cout << nodesInfo[v] << "  ";
        ptr = ptr->next;
      }
      std::cout << std::endl;
    }
  }
  else { 
    std::cout << "Adjacency Matrix" << std::endl;
    for (int u = 1; u <= numNodes; u++){
      std::cout << "vertex " << u << " (" << nodesInfo[u] << "): ";
      for (int v = 1; v <= numNodes; v++) {
        if (adjMatrix[u][v] > 0)
          std::cout << nodesInfo[v] << "  ";
        else
          std::cout << 0 << "  ";
      }
      std::cout << std::endl;
    }    
  }
}

template <class T>
void Graph<T>::BFS(int v) {
  // Declarar un set del STL de c++ (elementos unicos y ordenados)
  std::set<int> visited;
  // Crear un queue
  QueueLinkedList<int> queue;
  // Marcar al vertice actual v como visitado y meterlo en el queue
  visited.insert(v);
  queue.enqueue(v);
  std::cout << "Recorrido BFS" << std::endl;
  while (!queue.isEmpty()) {
    // Extraer un vertice del queue
    v = queue.dequeue();
    std::cout << v << " ";
    // Obtener los vecinos del vertice v
    // Si estos no han sido visitados marcarlos como visitados
    // y los metemos en el queue
    if (representation) { // Lista de adyacencia
      // Recorremos los vertices vecinos de v
      LLNode<int> *ptr = adjList[v].getHead();
      while (ptr != nullptr) {
        int u = ptr->data;
        // Verificar si el vecino u ya fue visitado
        bool isInVisited = visited.find(u) != visited.end();
        if (!isInVisited) { // no visitado
          visited.insert(u);
          queue.enqueue(u);
        }
        ptr = ptr->next;
      }      
    }
    else { // Matriz de adyacencia
      // Recorremos los vertices vecinos de v
      for (int u = 1; u <= numNodes; u++) {
        int c = adjMatrix[v][u];
        if (c != 0) {
          // Verificar si el vecino u ya fue visitado
          bool isInVisited = visited.find(u) != visited.end();
          if (!isInVisited) { // no visitado
            visited.insert(u);
            queue.enqueue(u);
          }  
        }
      }
    }
  }
  std::cout << std::endl;
}







#endif  // _GRAPH_H_
