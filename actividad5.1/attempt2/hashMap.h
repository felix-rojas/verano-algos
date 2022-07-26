#include <iostream>
static const int max_size = 100;

template <class K, class T>
class HashNode
{
private:
    K key;
    T data;

public:
    HashNode *next;
    HashNode *prev;
    HashNode(K newKey, T newData);
    K getKey(){return key};
    T getData(){return data};
};

template <class K, class T>
HashNode<K, T>::HashNode(K newKey, T newData)
{
    this->key = newKey;
    this->data = newData this->next = nullptr;
}

template <class K, class T>
class HashMap
{
public:
    HashNode<K, T>::HashNode **hashTable, **top;
    void makeTable();
    T find(K keyVal);
    void remove();
    void print();
};

template <class K, class T>
void HashMap<K,T>::makeTable()
{
    hashTable = new HashNode *[max_size];
    // o(n) setting all to null
    for (int i = 0, i < max_size : i++)
    {
        hashTable[i] = NULL;
    }
}