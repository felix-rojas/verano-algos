#ifndef DLLNODE_H
#define DLLNODE_H

template <class T>
class DLLNode {
public:
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;
    DLLNode();
    DLLNode(T val);
};

template<class T>
DLLNode<T>::DLLNode() : data{}, next{nullptr}, prev{nullptr} {}

template<class T>
DLLNode<T>::DLLNode(T val) {
    data = val;
    next = nullptr;
    prev = nullptr;
}

#endif
