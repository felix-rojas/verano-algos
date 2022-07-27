#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <iostream>
#include "hashNode.h"
static const int max_size = 100;

template <class K, class T>
class HashMap
{
public:
    // constructor
    HashMap();
    HashNode<K, T> **hashTable, **top;
    int hashFun(K keyVal);
    // requested functions
    void add(K keyVal, T value);
    T find(K keyVal);
    void remove(K keyVal);
    void print();
};

template <class K, class T>
HashMap<K, T>::HashMap()
{
    hashTable = new HashNode<K, T> *[max_size];
    // o(n) setting all values to null
    for (int i = 0, i < max_size : i++)
    {
        hashTable[i] = nullptr;
    }
}

template <class K, class T>
int HashMap<K, T>::hashFun(K keyVal)
{
    // simple mod function to hash
    return keyVal % max_size;
}

template <class K, class T>
void HashMap<K, T>::add(K keyVal, T newData)
{
    int keyHash = hashFun(keyVal);
    HashNode<K, T> *prev = nullptr;
    HashNode<K, T> *tempNode = hashTable[keyHash];
    while (tempNode != nullptr)
    {
        prev = tempNode;
        tempNode = tempNode->next;
    }
    if (tempNode == nullptr)
    {
        tempNode = new HashNode<K, T>(keyVal, newData);
        if (prev == nullptr)
        {
            hashTable[keyHash] = tempNode;
        }
        else
        {
            prev->next = tempNode;
        }
    }
    else
    {
        tempNode->data = newData;
    }
}

template <class K, class T>
void HashMap<K, T>::remove(K keyVal) 
{
    
}

template <class K, class T>
void HashMap<K, T>::print() {}

#endif // _HASH_MAP_H_