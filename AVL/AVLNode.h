#ifndef _AVLNODE_H_
#define _AVLNODE_H_

template <class T>
class AVLNode {
  public:
    T data;
    AVLNode<T> *left;
    AVLNode<T> *right;
    int height;

    AVLNode();
    AVLNode(T value);
};

template <class T>
AVLNode<T>::AVLNode() : data{}, left{nullptr}, right{nullptr}, height{1} {}

template <class T>
AVLNode<T>::AVLNode(T value) {
  data = value;
  left = right = nullptr;
  height = 1;
}

#endif // _AVLNODE_H_