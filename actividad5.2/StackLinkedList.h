#ifndef _STACKLINKEDLIST_H_
#define _STACKLINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "StackNode.h"

template <class T>
class StackLinkedList {
  private: 
    StackNode<T> *front;
    int numElements;

  public:
    StackLinkedList();
    ~StackLinkedList();
    int getNumElements();
    void print();
    bool isEmpty();
    void push(T value);
    void pop();
    T getTop();
};

template<class T>
StackLinkedList<T>::StackLinkedList() {
  //std::cout << "---> Creando un stack vacio" << std::endl;
  front = nullptr;
  numElements = 0;
}

template<class T>
StackLinkedList<T>::~StackLinkedList() {
  //std::cout << "---> Liberando la memoria del stack" << std::endl;
  StackNode<T> *p, *q;
  p = front;
  while(p != nullptr) {
    q = p->next;
    delete p;
    p = q;
  }
  front = nullptr;
  numElements = 0;
}

template<class T>
int StackLinkedList<T>::getNumElements() {
  return numElements;
}

template<class T>
void StackLinkedList<T>::print() {
  StackNode<T> *p;
  p = front;
  while (p != nullptr) {
    std::cout << p->data << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

template<class T>
bool StackLinkedList<T>::isEmpty() {
  return numElements == 0;
}

template<class T>
void StackLinkedList<T>::push(T value){
  StackNode<T> *newNode = new StackNode<T>(value);
  newNode->next = front;
  front = newNode;
  numElements++;
}

template<class T>
void StackLinkedList<T>::pop(){
  if (!isEmpty()){
    StackNode<T> *p  = front;
    front = p->next;
    delete p;
    numElements--;
  } else {
    throw std::out_of_range("El Stack esta vacio");
  }
}

template<class T>
T StackLinkedList<T>::getTop(){
  if (!isEmpty()){
    return front->data;
  } else{
    throw std::out_of_range("El Stack esta vacio");
  }
}

#endif // _STACKLINKEDLIST_H_