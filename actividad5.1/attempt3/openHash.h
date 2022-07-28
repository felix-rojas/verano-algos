#ifndef _OPENHASH_H_
#define _OPENHASH_H_
// Code is referenced from https://www.geeksforgeeks.org/c-program-hashing-chaining/
// Article/Code was written by https://auth.geeksforgeeks.org/user/shubham_rana_77/articles
// Code was edited by users rajeev0719singh shwetagaur4698 rishavpgl4 vikaspandey1206
// CPP program to implement hashing with chaining

#include <iostream>
#include <list>
#include <iterator>

template <class T, class K>
class Hash
{
    int BucketCount; // No. of buckets

    // Pointer to an array containing buckets
    std::list<T> *table; // list takes O(2n) space in memory BUT insertion/deletion of any point is O(1)

public:
    Hash(T Cubetas); // Constructor
    ~Hash();         // Destructor O(n^2)

    // inserts a keyVal into hash table
    // O(1) constant due to lists insertion time
    void add(T keyVal); 

    // deletes a keyVal from hash table
    // O(n) 
    void remove(K keyVal);

    // finds a keyVal from hash table, returns T
    // O(n*n) if the hash element is at the las position and they all have the same mod
    // Average case is (n + m)
    T find(K keyVal);

    // hash function to map values to keyVal
    // O(1) because it consults already assigned values
    int hashFunction(T value)
    {
        return (value % BucketCount);
    }

    // Average case is (n+m) unless every list
    // has a sublist the size of n, in which case O(n^2) 
    void print();
};

template <class T, class K>
Hash<T, K>::Hash(T cubetas)
{
    this->BucketCount = cubetas;
    table = new std::list<T>[BucketCount];
}

template <class T, class K>
Hash<T, K>::~Hash()
{
    delete[] table; // initialized using new[], call delete[]
}
template <class T, class K>
void Hash<T, K>::add(T value)
{
    int index = hashFunction(value);
    table[index].push_back(value);
}

template <class T, class K>
void Hash<T, K>::remove(K keyVal)
{
    // get the hash index of keyVal
    int index = hashFunction(keyVal);

    // find the keyVal in (index)th list
    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == keyVal)
            break;
    }

    // if keyVal is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

template <class T, class K>
T Hash<T, K>::find(K keyVal)
{
    // get the hash index of keyVal
    int index = hashFunction(keyVal);
    // find the keyVal in (index)th list
    std::list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == keyVal)
            break;
    }
    if (i != table[index].end())
        return index;
    else return -1;
}

// function to display hash table
template <class T, class K>
void Hash<T, K>::print()
{
    for (int i = 0; i < BucketCount; i++)
    {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

#endif // _OPENHASH_H_