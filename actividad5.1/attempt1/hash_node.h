#ifndef _HASH_NODE_
#define _HASH_NODE_

#include <iostream>

// Code referrenced from https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/

template <class T>
class HashNode
{
private:
    T value;

public:
    HashNode<T> *next;
    HashNode();
    // constructor assigns key and value
    HashNode(T valueData);
    T getValue();
    HashNode<T> getNext();
    void setValue(T valueData);
};
template <class T>
HashNode<T>::HashNode()
{
    next = nullptr;
}
template <class T>
HashNode<T> HashNode<T>::getNext()
{
    return *next;
}
template <class T>
HashNode<T>::HashNode(T valueData)
{
    value = valueData;
    next = nullptr;
}

template <class T>
T HashNode<T>::getValue()
{
    return value;
}

template <class T>
void HashNode<T>::setValue(T valueData)
{
    value = valueData;
}

#endif // _HASH_NODE_
