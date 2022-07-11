#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_

#include "DLLNode.h"
#include <iostream>

template <class T>
class DLinkedList
{
private:
  DLLNode<T> *head;
  DLLNode<T> *tail;
  int numElements;

public:
  DLinkedList();
  ~DLinkedList();
  int getNumElements();
  void printList();
  void addFirst(T value);
  void addLast(T value);
  bool deleteData(T value);
  bool deleteAt(int posicion);
  T getData(int position);
  void updateData(T value, T newValue);
  void updateAt(T value, T newValue);
};

template <class T>
DLinkedList<T>::DLinkedList()
{
  std::cout << "--- Creando una lista vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
  std::cout << "--- Liberando memoria de la lista --- " << &head << std::endl;
  DLLNode<T> *prev, *q;
  prev = head;
  while (prev != nullptr)
  {
    q = prev->next;
    delete prev;
    prev = q;
  }
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T>
int DLinkedList<T>::getNumElements()
{
  return numElements;
}

template <class T>
void DLinkedList<T>::printList()
{
  DLLNode<T> *ptr = head;
  while (ptr != nullptr)
  {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T>
void DLinkedList<T>::addFirst(T value)
{
  // creando un nuevo nodo de la lista
  DLLNode<T> *newDLLNode = new DLLNode<T>(value);
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0)
  {
    head = newDLLNode;
    tail = newDLLNode;
  }
  else
  {
    newDLLNode->next = head;
    head -> prev = newDLLNode;
    head = newDLLNode;

  }
  numElements++;
}

template <class T>
void DLinkedList<T>::addLast(T value)
{
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0)
  {
    addFirst(value);
  }
  else
  {
    // creando un nuevo nodo de la lista
    DLLNode<T> *newDLLNode = new DLLNode<T>(value);
    tail->next = newDLLNode;
    newDLLNode->prev = tail; // update for the DLL 
    tail = newDLLNode;
    numElements++;
  }
}

template <class T>
bool DLinkedList<T>::deleteData(T value)
{
  bool estado = false;
  // Si la lista esta vacia
  if (numElements == 0)
  {
    return estado;
  }
  else
  {
    DLLNode<T> *p = head;
    DLLNode<T> *prev = nullptr;
    // buscar value en la lista
    while (p != nullptr && p -> data != value)
    {
      prev = p;
      p = p -> next;
    }
    // si no existe value en la lista
    if (p == nullptr)
      return estado;
    // Si debe borrarse el primer elemento de la lista
    if (p == head)
    {
      head = p -> next;
      if (head != nullptr)
        head -> prev = nullptr;
    }
    // borrar ultimo en la lista se mantiene igual
    else if (p->next == nullptr)
    { 
      prev->next = nullptr;
      tail = prev; 
    }
    else
    { // cualquier otro elemento
      prev->next = p->next;
      p->next->prev = p->prev; // actualizamos
    }
    delete p;
    numElements--;
    estado = true;
    return estado;
  }
}

template <class T>
bool DLinkedList<T>::deleteAt(int position)
{
  if (position < 0 || position >= numElements)
  {
    throw std::out_of_range("Indice fuera de rango");
  }
  else if (position == 0)
  { // Si debe borrarse el primer elemento
    DLLNode<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = p->next;
      head -> prev = nullptr;
    }
    delete p;
    numElements--;
    return true;
  }
  else
  { // Si la lista contiene mas de un nodo
    DLLNode<T> *p = head, *q = nullptr;
    int index = 0;
    // Se busca el indice del elemento a borrar
    while (index != position)
    {
      q = p;
      p = p->next;
      index++;
    }
    // Si debe borrarse el último elemento
    if (p->next == nullptr)
    {
      q->next = nullptr;
      tail = q;
    }
    else
    { // Cualquier otro elemento en medio de la lista
      q->next = p->next;
      p->next->prev = q; // el next de prev apunta al previo
    }
    delete p;
    numElements--;
    return true;
  }
}

template <class T>
T DLinkedList<T>::getData(int position)
{
  if (position < 0 || position >= numElements)
  {
    throw std::out_of_range("Indice fuera de rango");
  }
  else
  {
    if (position == 0)
      return head->data;
    DLLNode<T> *p = head;
    int index = 0;
    while (p != nullptr)
    {
      if (index == position)
        return p->data;
      index++;
      p = p->next;
    }
    return {};
  }
}

template <class T>
void DLinkedList<T>::updateData(T value, T newValue)
{
  if (numElements > 0)
  {
    DLLNode<T> *p = head;
    DLLNode<T> *prev = nullptr;
    while (p != nullptr && p->data != value)
    {
      prev = p;
      p = p->next;
    }
    if (p != nullptr)
      p->data = newValue;
    else
      throw std::out_of_range("No existe el valor en la lista");
  }
}
template <class T>
void DLinkedList<T>::updateAt(T value, T newValue)
{

}

#endif // _DLINKEDLIST_H_