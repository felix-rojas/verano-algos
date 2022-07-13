#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  int numElements;

public:
  LinkedList();
  ~LinkedList();
  int getNumElements();
  void printList();
  void addFirst(T value);
  void addLast(T value);
  bool deleteData(T value);
  bool deleteAt(int posicion);
  T getData(int position);
  void updateData(T value, T newValue);
  void updateAt(T pos, T newValue);
  int findData(T value);
  void operator=(const LinkedList<T>& other); // se llama asi:  lista1 = lista2
};

template <class T>
LinkedList<T>::LinkedList()
{
  std::cout << "--- Creando una lista vacia --- " << &head << std::endl;
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  std::cout << "--- Liberando memoria de la lista --- " << &head << std::endl;
  Node<T> *prev, *q;
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
int LinkedList<T>::getNumElements()
{
  return numElements;
}

template <class T>
void LinkedList<T>::printList()
{
  Node<T> *ptr = head;
  while (ptr != nullptr)
  {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
}

template <class T>
void LinkedList<T>::addFirst(T value)
{
  // creando un nuevo nodo de la lista
  Node<T> *newNode = new Node<T>(value);
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
  numElements++;
}

template <class T>
void LinkedList<T>::addLast(T value)
{
  // Si la lista esta vacia if(head == nullptr)
  if (numElements == 0)
  {
    addFirst(value);
  }
  else
  {
    // creando un nuevo nodo de la lista
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    tail = newNode;
    numElements++;
  }
}

template <class T>
bool LinkedList<T>::deleteData(T value)
{
  bool estado = false;
  // Si la lista esta vacia
  if (numElements == 0)
  {
    return estado;
  }
  else
  {
    Node<T> *p = head;
    Node<T> *prev = nullptr;
    // buscar value en la lista
    while (p != nullptr && p->data != value)
    {
      prev = p;
      p = p->next;
    }
    // si no existe value en la lista
    if (p == nullptr)
      return estado;
    // Si debe borrarse el primer elemento de la lista
    if (p == head)
    {
      head = p->next;
    }
    else if (p->next == nullptr)
    { // borrar ultimo en la lista
      prev->next = nullptr;
      tail = prev;
    }
    else
    {
      prev->next = p->next;
    }
    delete p;
    numElements--;
    estado = true;
    return estado;
  }
}

template <class T>
bool LinkedList<T>::deleteAt(int position)
{
  if (position < 0 || position >= numElements)
  {
    throw std::out_of_range("Indice fuera de rango");
  }
  else if (position == 0)
  { // Si debe borrarse el primer elemento
    Node<T> *p = head;
    // Si la lista contiene solo un nodo
    if (head != nullptr && head->next == nullptr)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = p->next;
    }
    delete p;
    numElements--;
    return true;
  }
  else
  { // Si la lista contiene mas de un nodo
    Node<T> *p = head, *q = nullptr;
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
    }
    delete p;
    numElements--;
    return true;
  }
}

template <class T>
T LinkedList<T>::getData(int position)
{
  if (position < 0 || position >= numElements)
  {
    throw std::out_of_range("Indice fuera de rango");
  }
  else
  {
    if (position == 0)
      return head->data;
    Node<T> *p = head;
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
void LinkedList<T>::updateData(T value, T newValue)
{
  if (numElements > 0)
  {
    Node<T> *p = head;
    Node<T> *prev = nullptr;
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
void LinkedList<T>::updateAt(T pos, T newValue)
{
   if (pos < 0 || pos >= numElements)
  {
    throw std::out_of_range("Indice fuera de rango");
  }
  else
  {
    if (pos == 0) head->data = newValue;
    Node<T> *p = head;
    int index = 0;
    while (p != nullptr)
    {
      if (index == pos) p->data = newValue;
      index++;
      p = p->next;
    }
  }
}

// findData es O(n) pues tiene que recorrer todos los nodos
template <class T>
int LinkedList<T>::findData(T value)
{
  Node<T> *ptr = head;
  int pos = 0;
  while (ptr->next != nullptr && ptr->data != value)
  {
    pos++;
    ptr = ptr->next;
  }
  if (ptr->data != value)
    return -1;
  else
    return pos;
}

// ! TODO
template <class T>
void LinkedList<T>::operator= (const LinkedList<T>& other)
{
  Node<T> *ptr = head;
  int count = other.numElements;
  while (count > 0)
  {
    other.addLast()
  }
} // se llama asi:  lista1 = lista2

#endif // _LINKEDLIST_H_