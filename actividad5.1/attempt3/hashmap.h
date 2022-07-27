#ifndef _MyHashMap_H_
#define _MyHashMap_H_

#include "LinkedList.h"
#include <forward_list>  
// consumes less memory than a list and only goes forward
// only issue is when there are too many collissions

template <class T, class K>
class OpenHash
{
private:
    int maxCapacity;
    std::forward_list<LinkedList<T, K>*> hashTable;

public:
    OpenHash(int size);
    OpenHash();
    ~OpenHash();
    int getHashIndex(K keyVal);
    void add(K keyVal, T value);
    // int find(K keyVal);
    // T getDataAt(int index);
    // void remove(K keyVal);
};

// Hash function recibe una llave
template <class T, class K>
int OpenHash<T, K>::getHashIndex(K keyVal) {
  return keyVal % maxCapacity;
}

template <class T, class K>
OpenHash<T, K>::OpenHash(int size)
{
    std::forward_list<LinkedList<T, K>> hashTable(size);
}

template <class T, class K>
OpenHash<T, K>::~OpenHash()
{
    hashTable.clear();
}

template <class T, class K>
void OpenHash<T, K>::add(K keyVal, T value);


// template <class T, class K>
// int OpenHash<T, K>::find(K keyVal);


// template <class T, class K>
// T OpenHash<T, K>::getDataAt(int index);


// template <class T, class K>
// void OpenHash<T, K>::remove(K keyVal);

#endif // _MyHashMap_H_