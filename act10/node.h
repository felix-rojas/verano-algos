#ifndef _NODE_H 
#define _NODE_H

template <class T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node();
    Node(T value);
};

template <class T>
Node<T>::Node() : data{}, next{nullptr} {}

template <class T>
Node<T>::Node(T value) {
    data = value; 
    next = nullptr; 
}



#endif // _NODE_H