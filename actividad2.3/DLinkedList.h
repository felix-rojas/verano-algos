#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include <stdexcept>

#include "DLLNode.h"
#include "StackLinkedList.h"


template <class T>
class DLinkedList {
private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;
    DLLNode<T> *partition(DLLNode<T> *l, DLLNode<T> *h);
    void swap (T &a, T &b);
    void _quickSort(DLLNode<T> *l, DLLNode<T> *h);
    int verificacion(DLLNode<T> *ptr1, DLLNode<T> *ptr2);

public:
    DLinkedList();
    ~DLinkedList();
    int getNumElements();
    void printList();
    void printLastNode();
    void addFirst(T value);
    void addLast(T value);
    bool deleteData(T value);
    bool deleteAt(int position);
    T getData(int position);
    void Iterative_quickSort();

};

template<class T>
DLinkedList<T>::DLinkedList() {
    std::cout << "--->Inicializando Lista" << std::endl;
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template<class T>
DLinkedList<T>::~DLinkedList() {
    std::cout << "--->Destruyendo lista" << std::endl;
    DLLNode<T> *p, *q;
    p = head;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template<class T>
int DLinkedList<T>::getNumElements() {
    return numElements;
}

template<class T>
void DLinkedList<T>::printList() {
    DLLNode<T> *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data.getTexto() << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template<class T>
void DLinkedList<T>::printLastNode() {
    std::cout << tail->data << std::endl;
}

template<class T>
void DLinkedList<T>::addFirst(T value) {
    DLLNode<T> *newDLLNode = new DLLNode<T>(value);
    // Si la lista está vacia
    if (head == nullptr && tail == nullptr) {
        head = newDLLNode;
        tail = newDLLNode;
    }
    else {
        newDLLNode->next = head;
        head->prev = newDLLNode;
        head = newDLLNode;
    }
    numElements++;
}

template<class T>
void DLinkedList<T>::addLast(T value) {
    if (head == nullptr && tail == nullptr) {
        addFirst(value);
    }
    else {
        DLLNode<T> *newDLLNode = new DLLNode<T>(value);
        tail->next = newDLLNode;
        newDLLNode->prev = tail;
        tail = newDLLNode;
        numElements++;
    }
}

template<class T>
bool DLinkedList<T>::deleteData(T value) {
    
    if (head == nullptr && tail == nullptr) {
        return false;
    }
    else {
        DLLNode<T> *p, *q;
        p = head;
        q = nullptr;
        
        while (p != nullptr && p->data != value) {
            q = p;
            p = p->next;
        }
        
        if (p == nullptr)
            return false;
       
        if (p->prev == nullptr) {
            head = p->next;
            if (head != nullptr)
                head->prev = nullptr;
        }
        else if (p->next == nullptr) {
           
            q->next = nullptr;
            tail = q;
        }
        else {
          
            q->next = p->next;
            p->next->prev = q;
        }
        delete p;
        numElements--;
        return true;
    }
}

template<class T>
bool DLinkedList<T>::deleteAt(int position) {
    if (position < 0 || position >= numElements) {
        throw std::out_of_range("Indice fuera de rango");
    }
    else if (position == 0) { 
        DLLNode<T> *p = head;
       
        if (head != nullptr && head->next == nullptr) {
            head = tail = nullptr;
        }
        else {
            head = p->next;
            head->prev = nullptr;
        }
        delete p;
        numElements--;
        return true;
    }
    else { 
        DLLNode<T> *p = head, *q = nullptr;
        int index = 0;
       
        while (index != position) {
            q = p;
            p = p->next;
            index++;
        }
        
        if (p->next == nullptr) {
            q->next = nullptr;
            tail = q;
        }
        else {
            q->next = p->next;
            p->next->prev = q;
        }
        delete p;
        numElements--;
        return true;
    }
}

template<class T>
T DLinkedList<T>::getData(int position) {
    T tmp = {};
    if (position < 0 || position > numElements) {
        throw std::out_of_range("Indice esta fuera de rango");
    }
    else {
        if (position == 0)
            return head->data;
        DLLNode<T> *p = head;
        int index = 0;
        while (p != nullptr) {
            if (index == position)
                return p->data;
            index++;
            p = p->next;
        }
        return tmp;
    }
}


template<class T>
void DLinkedList<T>::swap(T &a, T &b){
    T t = a; a = b; b = t;
};

template<class T>
DLLNode<T> * DLinkedList<T>::partition(DLLNode<T> *l, DLLNode<T> *h) {
    if(h != nullptr && l != h && l != h->next) {
      
        T x = h->data;
        DLLNode<T> *i = l->prev;
        for (DLLNode<T> *j = l; j != h; j = j->next){
            if (j->data <= x){
                i = (i == nullptr)? l : i->next;
                swap((i->data), (j->data));
            }
        }
        i = (i == nullptr)? l : i->next; 
        swap((i->data), (h->data));
        return i;
    }
    else {
        return nullptr;
    }
}

template <class T>
void DLinkedList<T>::_quickSort(DLLNode<T> *l, DLLNode<T> *h){
    if (h != nullptr && l != h && l != h->next){
        DLLNode<T> * p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}


template<class T>
int DLinkedList<T>::verificacion(DLLNode<T> *inicio, DLLNode<T> *fin) {
    int length = -1;
    DLLNode<T> *p = inicio;
    if (inicio != nullptr && fin != nullptr) {
        length = 1;
        while (p != nullptr) {
            if (p == fin)
                break;
            p = p->next;
            length++;
        }
    }
    return length;
}


template <class T>
void DLinkedList<T>::Iterative_quickSort(){
    DLLNode<T> *l, *h;
    l = head;
    h = tail;
   
    StackLinkedList<DLLNode<T>*> stack;
    
    stack.push(l);
    stack.push(h);
   
    while (!stack.isEmpty()) {
        
        h = stack.getTop();
        stack.pop();
        l = stack.getTop();
        stack.pop();
        DLLNode<T> *p = partition(l, h);
        if (p != nullptr) {
          
            if (verificacion(l, p->prev) >= 2) { 
                stack.push(l);
                stack.push(p->prev);

            }
          
            if (verificacion(p->next, h) >= 2) {
                stack.push(p->next);
                stack.push(h);
            }
        }
    }

}



#endif

