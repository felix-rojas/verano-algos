#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> 
#include <map>
#include <set>
#include <queue>
#include "LinkedList.h"
#include "QueueLinkedList.h"

#define INF 0x3f3f3f3f

template <class T>
class Graph {
  private:
    int numNodes;
    int numEdges;
    // Cada nodo tiene un id y un objeto de datos tipo T
    std::map<int, T> nodesInfo;
    // Lista de adyacencia, vector de listas ligadas de pares (vertice, peso)
    std::vector<LinkedList<std::pair<int, int>>> adjList;
    
    void split(std::string line, std::vector<int> &res);
    
  public:
    Graph();
    ~Graph();
    void readGraph(std::istream &input);
    void print();
    void printGraphInfo();
    void BFS(int v);
    void shortestPath(int src);

};

template <class T>
Graph<T>::Graph() {
  numNodes = 0;
  numEdges = 0;
}

template <class T>
Graph<T>::~Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
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
void Graph<T>::readGraph(std::istream &input) {
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
      LinkedList<std::pair<int,int>> tmpList; // Grafos ponderados usamos una lista de pares (nodo, peso)
      adjList[i-1] = tmpList; 
      i++;
      continue;
    }
    std::vector<int> res;
    split(line, res);
    int u = res[0];
    int v = res[1];
    int weight = res[2];    
    // Grafos dirigidos agrega solo la arista (u,v)
    adjList[u].addLast(std::make_pair(v,weight)); // en grafo ponderado guardar pares (nodo, peso)
    i++;
  }
}

template <class T>
void Graph<T>::print(){
  std::cout << "Adjacency List" << std::endl;
  for (int u = 1; u <= numNodes; u++){
    std::cout << "vertex " << u << ": ";
    LLNode<std::pair<int, int>> *ptr = adjList[u].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      std::cout << "{"<< par.first << "," << par.second << "}  ";
      ptr = ptr->next;
    }
    std::cout << std::endl;
  }
}

template <class T>
void Graph<T>::printGraphInfo(){
  std::cout << "Adjacency List" << std::endl;
  for (int u = 1; u <= numNodes; u++) {
    std::cout << "vertex " << u << " (" << nodesInfo[u] << "): ";
    LLNode<std::pair<int,int>> *ptr = adjList[u].getHead();
    while (ptr != nullptr) {
      std::pair<int, int> par = ptr->data;
      std::cout << "{"<< nodesInfo[par.first] << "," << par.second << "}  ";
      ptr = ptr->next;
    }
    std::cout << std::endl;
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

    // Recorremos los vertices vecinos de v
    LLNode<std::pair<int, int>> *ptr = adjList[v].getHead();
    while (ptr != nullptr) {
      std::pair<int,int> par = ptr->data;
      int u = par.first;
      // Verificar si el vecino u ya fue visitado
      bool isInVisited = visited.find(u) != visited.end();
      if (!isInVisited) { // no visitado
        visited.insert(u);
        queue.enqueue(u);
      }
      ptr = ptr->next;
    }      
  }
  std::cout << std::endl;
}



template <class T>
// Prints shortest paths from src to all other vertices
void Graph<T>::shortestPath(int src) {
    
  // Create a priority queue to store vertices that
  // are being preprocessed. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  // pares (distancia, vertice)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    std::vector<int> dist(numNodes+1, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(std::make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty()) {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a
        // vertex
        // Recorremos los vertices vecinos de v
        LLNode<std::pair<int, int>> *ptr = adjList[u].getHead();
        while (ptr != nullptr) {
          std::pair<int,int> par = ptr->data;
          int v = par.first;
          int weight = par.second;
          // If there is shorted path to v through u.
          if (dist[v] > dist[u] + weight) {
              // Updating distance of v
              dist[v] = dist[u] + weight;
              pq.push(std::make_pair(dist[v], v));
          }
          ptr = ptr->next;
        }   
    }
    
    // Print shortest distances stored in dist[]
    std::cout << "Vertex Distance from Source" << std::endl;
    for (int i = 1; i <= numNodes; ++i){ 
      std::cout << "vertice "<< i << ":\t\t" << dist[i] << std::endl; 
    }
    std::cout << std::endl;
}



#endif  // _GRAPH_H_
