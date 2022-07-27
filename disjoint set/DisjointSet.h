#ifndef _DISJOINT_SET_H_
#define _DISJOINT_SET_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>


template <class T> 
class DisjointSet {
  private:
    // universo de elementos
    std::vector<T> universe;
    // padre de cada elemento <índice del elemento, elemento padre>
    std::unordered_map<int, T> parent;
    // altura de cada arbol <índice del elemento, altura de cada árbol>
    std::unordered_map<int, int> rank;
    // indices de cada objeto del universo <objeto, índice>
    std::map<T, int> index;
    // maximo numero de elementos en el universo
    int maxCapacity;

  public:
    DisjointSet();
    DisjointSet(std::vector<T> &objects);
    ~DisjointSet();
    int getMaxCapacity();
    void print();
    T find(T elemento);
    void unionSets(T rootX, T rootY);

};

template <class T> 
DisjointSet<T>::DisjointSet() {
  maxCapacity = 0;
}

template <class T> 
DisjointSet<T>::DisjointSet(std::vector<T> &objects) {
  universe = std::vector<T> (objects.begin(), objects.end());
  int j = 0;
  typename std::vector<T>::iterator it;
  for (it = objects.begin(); it != objects.end(); it++) {
    index.insert({*it, j});
    parent[j] = *it;
    rank[j] = 0;
    j++;
  }
  maxCapacity = objects.size();
}

template <class T> 
DisjointSet<T>::~DisjointSet() {
  index.clear();
  parent.clear();
  universe.clear();
  rank.clear();
  maxCapacity = 0;
}

template <class T> 
int DisjointSet<T>::getMaxCapacity() {
  return maxCapacity;
}

template <class T> 
void DisjointSet<T>::print() {
  std::cout << "Subsets: " << std::endl;
  typename std::vector<T>::iterator it;
  for (it = universe.begin(); it != universe.end(); it++) {
    std::cout << "Element: " << *it << " parent: " << find(*it) << " rank: " << rank[index[*it]] << std::endl;
  }
}
  
template <class T> 
T DisjointSet<T>::find(T elemento) {
  // Si element no es la raiz de su arbol
  if (parent[index[elemento]] != elemento) {
    // path compression
    parent[index[elemento]] = find(parent[index[elemento]]);
  }
  return parent[index[elemento]];
}

template <class T> 
void DisjointSet<T>::unionSets(T rootX, T rootY) {
  // localizamos la raiz de los subconjuntos a los que pertenece X y Y
  T x = find(rootX);
  T y = find(rootY);
  if (x == y)
    return;
  if (rank[index[x]] > rank[index[y]]) {
    parent[index[y]] = x;
  } else if (rank[index[x]] < rank[index[y]]) { 
    parent[index[x]] = y;
  } else { // si son iguales, incrementamos altura de alguno
    parent[index[x]] = y;
    rank[index[y]]++; //incremento de altura
  }
}
  

#endif // _DISJOINT_SET_H_

