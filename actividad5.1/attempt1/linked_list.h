#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "hash_node.h"

template <class T>
class LinkedList
{
private:
    HashNode<T> *head;
    HashNode<T> *tail; // para hacer accesos e inserciones O(1)
    int key; // la llave compartida de los elementos
    int numElements; // colisiones 

public:
    LinkedList();
    LinkedList(T data, int newKey);
    ~LinkedList();
    void clearData();
    int getNumElements();
    void printList();
    void addFirst(T value);
    void addLast(T value);
    T getData(int position);
    int getKey();
    void setKey(int);
    void updateData(T value, T newValue);
    bool deleteData(T value);
    bool deleteAt(int posicion);
    int findData(T value);
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
LinkedList<T>::LinkedList(T data, int newKey){
    key = newKey;
    addLast(data);
}

template <class T>
LinkedList<T>::~LinkedList()
{
    HashNode<T> *prev, *q;
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
void LinkedList<T>::clearData()
{
    HashNode<T> *prev, *q;
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
    HashNode<T> *ptr = head;
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
    HashNode<T> *newHashNode = new HashNode(value);
    // Si la lista esta vacia if(head == nullptr)
    if (numElements == 0)
    {
        head = newHashNode;
        tail = newHashNode;
    }
    else
    {
        newHashNode->next = head;
        head = newHashNode;
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
        HashNode<T> *newHashNode = new HashNode(value);
        tail->next = newHashNode;
        tail = newHashNode;
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
        HashNode<T> *p = head;
        HashNode<T> *prev = nullptr;
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
        HashNode<T> *p = head;
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
        HashNode<T> *p = head, *q = nullptr;
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
            return head->getValue();
        HashNode<T> *p = head;
        int index = 0;
        while (p != nullptr)
        {
            if (index == position)
                return p->getValue();
            index++;
            p = p->next;
        }
        return {};
    }
}

template <class T>
int LinkedList<T>::getKey()
{
    return key;
}

template <class T>
void LinkedList<T>::setKey(int newKey){
    key = newKey;
}

template <class T>
void LinkedList<T>::updateData(T value, T newValue)
{
    if (numElements > 0)
    {
        HashNode<T> *p = head;
        // buscar value en la lista
        while (p != nullptr && p->data != value)
        {
            p = p->next;
        }
        // si existe value en la lista
        if (p != nullptr)
            p->data = newValue;
        else
            throw std::out_of_range("No existe el valor en la lista");
    }
}

template <class T>
int LinkedList<T>::findData(T value)
{
    if (numElements > 0)
    {
        HashNode<T> *p = head;
        // buscar value en la lista
        while (p != nullptr && p->data != value)
        {
            p = p->next;
        }
        // si existe value en la lista
        if (p != nullptr)
            return p->data;
        else
            throw std::out_of_range("No existe el valor en la lista");
    }
}

#endif // _LINKED_LIST_
