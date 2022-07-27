#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <iostream>
#include <string>
#include <vector>
#include "hashNode.h"

template <class K, class T>
class HashMap
{
private:
    int size;
    std::vector<HashNode<K,T>> index;

public:
    // constructor
    HashMap();
    HashMap(int);
    ~HashMap() { index.clear(); }
    int getSize() { return index.size(); }
    // hash function using mod
    int hashFun(K keyVal);
    // requested functions
    void add(K keyVal, T value);
    T find(K keyVal);
    void remove(K keyVal);
    void print();
};


template <class K, class T>
HashMap<K, T>::HashMap(int number){
    std::vector<HashNode<K,T>> index(number);
    size = number; 
}

template <class K, class T>
HashMap<K, T>::HashMap()
{
    std::vector<HashNode<K,T>> index; 
    size = 10;
}

template <class K, class T>
int HashMap<K, T>::hashFun(K keyVal)
{
    // simple mod function to hash
    return keyVal % size;
}

template <class K, class T>
void HashMap<K, T>::add(K keyVal, T newData)
{
    int keyHash = hashFun(keyVal);
    if (index[keyHash] == NULL)
    {
        index[keyHash] = new HashNode<K, T>(keyVal, newData);
    }
    else
    {
        HashNode<K, T> *tempNode = index[keyHash];
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
            if (tempNode->key == keyVal)
                tempNode->key = keyVal;
            else
                tempNode->next = new HashNode<K, T>(keyVal, newData);
        }
    }
}

template <class K, class T>
T HashMap<K, T>::find(K keyVal)
{
    int hashKey = hashFun(keyVal);
    std::string result;
    // empty linked list
    if (index[hashKey] == NULL)
    {
        result = "No data found"; 
        return result;
    }
    else
    {
        HashNode<K, T> *temp = index[hashKey];
        while (temp != NULL && temp->key != keyVal)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            result = "No data found";
            return result;
        }
        else
            return temp->data;
    }
}

template <class K, class T>
void HashMap<K, T>::remove(K keyVal)
{
    int hashKey = hashFun(keyVal);
    // empty linked list
    if (index[hashKey] == NULL)
        std::cerr << "Linked List is Empty" << std::endl;
    else
    {
        HashNode<K, T> *temp = index[hashKey];
        HashNode<K, T> *ptr = NULL;
        while (temp != NULL && temp->key != keyVal)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (temp->key == keyVal)
        {
            if (ptr == NULL)
            {
                HashNode<K, T> *nuevo = temp->next;
                delete temp;
                index[hashKey] = nuevo;
            }
            HashNode<K, T> *nuevo = temp->next;
            delete temp;
            ptr->next = nuevo;
        }
    }
}

template <class K, class T>
void HashMap<K, T>::print()
{
    int i = 0;
    while (i < size)
    {
        if (index[i] == NULL)
            i++;
        else
        {
            HashNode<K, T> *temp = index[i];
            HashNode<K, T> *ptr = NULL;
            while (temp->next != NULL)
            {
                ptr = temp;
                std::cout << "Llave: " << temp->key
                          << " Valor: " << temp->data << std::endl;
                temp = temp->next;
            }
        }
    }
}

#endif // _HASH_MAP_H_