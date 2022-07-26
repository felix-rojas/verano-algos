#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include <iostream>
#include <vector>
#include <stdexcept>
#include "hash_node.h"
#include "linked_list.h"

template<class K, class T>
class HashTable {
  private:
    std::vector<LinkedList<T>> tableVector;
    int numElements;
    int maxCapacity; // preferible un numero primo

  public:
    HashTable(int selectedMaxSize);
    int getHashIndex(K keyVal);
    int getSize();
    void print();
    void add(K keyVal, T value);
    int find(K keyVal);
    T getDataAt(int index);
    void remove(K keyVal);
};

template<class K, class T>
HashTable<K, T>::HashTable(int selectedMaxSize) {
  maxCapacity = selectedMaxSize;
  numElements = 0;
  tableVector = std::vector<LinkedList<T>>(maxCapacity);
}

// Hash function recibe una llave
template<class K, class T>
int HashTable<K, T>::getHashIndex(K keyVal) {
  return keyVal % maxCapacity;
}

template<class K, class T>
int HashTable<K, T>::getSize() {
  return numElements;
}

template<class K, class T>
void HashTable<K,T>::print() {
  std::cout << "Content of the hash tableVector: " << std::endl;
  for (int i = 0; i < numElements; i++) {
    tableVector[i].printList();
    // status:  0 empty, 1 used, 2 deleted
    // if (tableVector[i].getNumElements() > 0) // Cell is used
    //   std::cout << "Cell: " << i 
    //   << " Key: " << tableVector[i].getKey() 
    //   << ", Values: " << tableVector[i].printList() 
    //   << ", Overflow.size: " << tableVector.at(i).getNumElements() << std::endl;
  }
}

template<class K, class T>
void HashTable<K,T>::add(K keyVal, T value) {
  if (numElements == maxCapacity) {
    throw std::out_of_range("Hash Table is full");
  }
  // Compute the index of the tableVector using a key and a hash function
  int hashVal = getHashIndex(keyVal); 
  if (tableVector.at(hashVal).get)
  tableVector.at(hashVal) = new LinkedList(value, keyVal);
  // numElements:  0 is empty
  if (list.getNumElements() == 0) { // Cell is free
    list.setKey(keyVal);
    list.addLast(value);
    tableVector[hashVal] = list;
  }
  else { // Cell is already taken
    // Find next free space using quadratic probing
    // https://www.geeksforgeeks.org/quadratic-probing-in-hashing/
    int i = 1;
    int currentHashVal = getHashIndex(hashVal + i * i);
    LinkedList<T> currentList = tableVector[currentHashVal];
    while (currentList.getNumElements() > 0) { // Cell is used
      i++;
      currentHashVal = getHashIndex(hashVal + i * i);
      currentList = tableVector[currentHashVal];
    }
    // A free cell was found
    currentList.setKey(keyVal);
    currentList.addLast(value);
    tableVector[currentHashVal] = currentList;
    tableVector[hashVal] = list;
  }
  numElements++;
}  

template<class K, class T>
int HashTable<K,T>::find(K keyVal) {
  int hashVal = getHashIndex(keyVal); 
  LinkedList<T> list = tableVector[hashVal];
  // numELements:  0 empty
  if (list.getNumElements() > 0) { // Cell is used
    if (list.getKey() == keyVal) {
      return hashVal;
    }
    for (int i = 0; i < list.getNumElements(); i++) {
      int overflowIndex = list.getOverflowAt(i);
      if (tableVector[overflowIndex].getKey() == keyVal) {
        return overflowIndex;
      }
    }
    return -1;
  }
  return -1;
}

template<class K, class T>
T HashTable<K,T>::getDataAt(int index) {
  return tableVector[index].getValue();
}

template<class K, class T>
void HashTable<K,T>::remove(K keyVal) {
  int pos, hashVal;
  pos = find(keyVal);
  if (pos == -1) {
    throw std::invalid_argument("Element does not exist in hash tableVector");
  }
  hashVal = getHashIndex(keyVal);
  if (pos != hashVal) {
    HashNode<T> node = tableVector[hashVal];
    node.removeFromOverflow(pos);
    tableVector[hashVal] = node;
  }
  tableVector[pos].clearData(); 
}


#endif // __HASH_TABLE_H_

