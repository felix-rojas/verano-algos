#ifndef _QUEUELINKEDLIST_H  
#define _QUEUELINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "QueueNode.h"

template <class T>
class QueueLinkedList {   
    private:
      QueueNode<T> *front;
      QueueNode<T> *rear;
      int numElements;

    public:
      QueueLinkedList();
      ~QueueLinkedList();
      bool isEmpty();
      int getNumElements();
      void print();
      void enqueue(T value);
      T dequeue();
      T getFront();

};

template<class T>
QueueLinkedList<T>::QueueLinkedList() {
  //std::cout << "--->Creando un queue vacio" << std::endl;
  front = rear = nullptr;
  numElements = 0;
}
  
template<class T>
QueueLinkedList<T>::~QueueLinkedList() {
  //std::cout << "--->Liberando memoria del queue" << std::endl;
  if (!isEmpty()) {
    QueueNode<T> *p, *q;
    p = front;
    while (p != nullptr) {
      q = p->next;
      delete p;
      p = q;
    }
    front = nullptr;
    rear = nullptr;
    numElements = 0;
  }
}

template<class T>
bool QueueLinkedList<T>::isEmpty() {
  return (front == nullptr);
}

template<class T>
int QueueLinkedList<T>::getNumElements() {
  return numElements;
}

template <class T>
void QueueLinkedList<T>::print(){
  QueueNode<T> *ptr = front;
  while (ptr != nullptr) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T>
void QueueLinkedList<T>::enqueue(T value) {
  QueueNode<T> *p = new QueueNode<T>(value);
  numElements++;
  // Si la fila esta vacia
  if (isEmpty()) {
    front = p;
    rear = p;
  }
  else { // La fila ya contiene elementos
    rear->next = p;
    rear = p;
  }
}

template <class T>
T QueueLinkedList<T>::dequeue() {
  if (isEmpty()) {
    throw std::out_of_range("El Queue esta vacio");
  }
  else {
    QueueNode<T> *p = front;
    T value = p->data;
    front = front->next;
    if (front == nullptr)
      rear = nullptr;
    delete p;
    numElements--;
    return value;
  }
}

template<class T>
T QueueLinkedList<T>::getFront() {
  if (!isEmpty()) {
    return front->data;
  }
  else {
    throw std::out_of_range("El Queue esta vacio");
  }
}

#endif //_QUEUELINKEDLIST_H