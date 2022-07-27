#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <iostream>
#include "hashNode.h"

template <class K, class T>
class HashMap
{
private:
    static const int max_size = 100;

public:
    HashNode<K,T> **head;
    // constructor
    HashMap();
    ~HashMap() { delete[] head; }
    int getSize() { return max_size; }
    // hash function using mod
    int hashFun(K keyVal);
    // requested functions
    void add(K keyVal, T value);
    T find(K keyVal);
    void remove(K keyVal);
    void print();
};

template <class K, class T>
HashMap<K,T>::HashMap()
{
    head = new HashNode<K,T> *[max_size];
    // o(n) setting all values to null
    for (int i = 0, i < max_size : i++)
    {
        head[i] = nullptr;
    }
}

template <class K, class T>
int HashMap<K,T>::hashFun(K keyVal)
{
    // simple mod function to hash
    return keyVal % max_size;
}

template <class K, class T>
void HashMap<K,T>::add(K keyVal, T newData)
{
    int keyHash = hashFun(keyVal);
    if (head[keyHash] == nullptr)
    {
        head[keyHash] = new HashNode<K,T>(keyVal, newData);
    }
    else
    {
        HashNode<K,T> *tempNode = head[keyHash];
        while (tempNode->next != nullptr)
        {
            tempNode = tempNode->next;
            if (tempNode->key == keyVal)
                tempNode->key = keyVal;
            else
                tempNode->next = new HashNode<K,T>(keyVal, newData);
        }
    }
}

template <class K, class T>
T HashMap<K,T>::find(K keyVal)
{
    int hashKey = hashFun(keyVal);
    // empty linked list
    if (head[hashKey] == nullptr)
        return -1;
    else
    {
        HashNode<K,T> *temp = head[hashKey];
        while (temp != nullptr && temp->key != keyVal)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return -1;
        else
            return temp->data;
    }
}

template <class K, class T>
void HashMap<K,T>::remove(K keyVal)
{
    int hashKey = hashFun(keyVal);
    // empty linked list
    if (head[hashKey] == nullptr)
        std::cerr << "Linked List is Empty" << std::endl;
    else
    {
        HashNode<K,T> *temp = head[hashKey];
        HashNode<K,T> *ptr = nullptr;
        while (temp != nullptr && temp->key != keyVal)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (temp->key == keyVal)
        {
            if (ptr == nullptr)
            {
                HashNode<K,T> *nuevo = temp->next;
                delete temp;
                head[hashKey] = nuevo;
            }
            HashNode<K,T> *nuevo = temp->next;
            delete temp;
            ptr->next = nuevo;
        }
    }
}

template <class K, class T>
void HashMap<K,T>::print()
{
    int i = 0;
    while (i < max_size)
    {
        if (head[i] == nullptr)
            i++;
        else
        {
            HashNode<K,T> *temp = head[i];
            HashNode<K,T> *ptr = nullptr;
            while (temp != nullptr)
            {
                ptr = temp;
                std::cout << "Llave: "<< temp->key 
                << " Valor: "<< temp->data << std::endl;
                temp = temp->next;
            }
        }
    }
}

#endif // _HASH_MAP_H_