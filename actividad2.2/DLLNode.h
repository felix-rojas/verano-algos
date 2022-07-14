#ifndef _DLLNODE_H_
#define _DLLNODE_H_

#include<ostream>

template <class T> class DLLNode {
public:
  T data;
  DLLNode<T> *next;
  DLLNode<T> *prev;

  DLLNode();
  DLLNode(T value);
  DLLNode<T>& operator=(const DLLNode<T> &l);
};

template <class T>
DLLNode<T>::DLLNode() : data{}, next{nullptr} , prev{nullptr} {}

template <class T> 
DLLNode<T>::DLLNode(T value) {
  data = value;
  next = nullptr;
  prev = nullptr;
}

#endif // _DLLNODE_H_