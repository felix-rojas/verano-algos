#ifndef _HASH_NODE_H_
#define _HASH_NODE_H_

template <class K, class T>
class HashNode
{
public:
    K key;
    T data;
    HashNode *next;
    HashNode(K newKey, T newData);
};

template <class K, class T>
HashNode<K, T>::HashNode(K newKey, T newData)
{
    key = newKey;
    data = newData; 
    next = NULL;
}

#endif //_HASH_NODE_H_