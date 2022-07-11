/*@file LinkedList.h */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

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
};

template <class T>
LinkedList<T>::LinkedList()
{
    std::cout << "Creating empty list" << std::endl;
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

// ! TODO
template <class T>
LinkedList<T>::~LinkedList()
{
    std::cout << "Liberando memoria" << std::endl;
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
void LinkedList<T>::addFirst(T value){
    Node<T> *ptr;
    ptr = new Node<T>();
    if (numElements == 0){
        tail = ptr;
        head = ptr;
    } else{
        ptr -> next = head;
        head = ptr;
    }
    numElements++;
}

#endif // _LINKEDLIST_H