#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class MaxHeap
{
private:
    std::vector<T> data;
    // max capacity as control
    int maxCapacity;
    int numElements;
    //aux methods
    int parent(int i);
    int left(int i);
    int right(int i);

public:
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getCapacity();
    int getNumElements();
    void print();
    void push(T key);
    // ! TODO
    T top();
    void pop();
};

// zero based 
template <class T>
int MaxHeap<T>::parent(int i){
    return (i-1)/2;
}

// zero based 
template <class T>
int MaxHeap<T>::left(int i){
    return (2*i + 1);
}

// zero based 
template <class T>
int MaxHeap<T>::right(int i){
    return (2*i + 2);
}

template <class T>
MaxHeap<T>::MaxHeap(int capacity)
{
    std::cout << "Generating new empty heap" << std::endl;
    numElements = 0;
    maxCapacity = capacity;
    data.resize(maxCapacity);
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
    std::cout << "Releasing memory" << std::endl;
    numElements = 0;
    maxCapacity = 0;
    data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty()
{
    return (numElements == 0);
}

template <class T>
int MaxHeap<T>::getCapacity()
{
    return maxCapacity;
}

template <class T>
int MaxHeap<T>::getNumElements()
{
    return numElements;
}

template <class T>
void MaxHeap<T>::print()
{
    std::cout << "This maxheap contains: " << std::endl;
    for (int i = 0; i < numElements; i++)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << std::endl;
}

template <class T>
void MaxHeap<T>::push(T key) {
    if (numElements==maxCapacity){
        throw std::out_of_range("Overflow: key cannot be inserted");
    }
    //Insert the key at the end
    int i = numElements;
    data[i] = key;
    numElements++;
    // Repair the maxHeap

    while (i != 0 && data[parent(i)] < data [i]){
        std:swap(data[i], data[parent(i)])
        i = parent(i);
    }
    
}

// ! TODO
template <class T>
T MaxHeap<T>::top(){
}

// ! TODO
template <class T>
void MaxHeap<T>::pop(){
}

#endif // _MAXHEAP_H_