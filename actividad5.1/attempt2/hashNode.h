#ifndef _HASH_NODE_H_
#define _HASH_NODE_H_

template <class K, class T>
class HashNode
{
public:
    K key;
    T data;
    HashNode *next;
    HashNode *prev;
    HashNode(K newKey, T newData);
    // K getKey() {return key};
    // T getData() {return data};
    // void setKey(K newKey){key = newKey};
    // void setData(T newData){data = newData};
};

template <class K, class T>
HashNode<K, T>::HashNode(K newKey, T newData)
{
    key = newKey;
    data = newData; 
    next = nullptr;
}

#endif //_HASH_NODE_H_