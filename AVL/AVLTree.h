#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <iostream>
#include "AVLNode.h"

template <class T>
class AVLTree {
  private:
    AVLNode<T> *root;
    AVLNode<T>* insertRecursive(AVLNode<T> *p, T value);
    int height(AVLNode)

  public:
    AVLTree();
    ~AVLTree();
    void clearMemory(AVLNode<T> *p);
    void insert(T value);
    int max(int a, int b);
    


};

template <class T>
AVLTree<T>::AVLTree() {
  std::cout << "---> Creando un arbol AVL vacio: " << this << std::endl;
  root = nullptr;
}
template <class T>
AVLTree<T>::~AVLTree() {
  std::cout << "---> Liberando memoria del arbol AVL: " << this << std::endl;
  clearMemory(root);
}

template<class T>
void AVLTree<T>::clearMemory(AVLNode<T> *p) {
  if (p != NULL) {
    clearMemory(p->left);
    clearMemory(p->right);
    delete p;
    p = NULL;
  }
}

template <class T>
int AVLTree<T>::height(AVLNode<T> *node){
    if (node == nullptr)
      return 0;
    return node->height;
}

template <class T>
int AVLTree<T>::max(int a,b )

template <class T>
int AVLTree<T>::getBalance(Node<T> *node){
  if (node == nullptr) return 0;
  return height(node->left) - height(node->right);
}

template <class T>
AVLNode<T>* AVLTree<T>::insertRecursive(AVLNode<T> *node, T value) {
  // 1. Realizar insercion normal en un BST
  if (node == nullptr) // El AVL esta vacio
    return (new AVLNode<T>(value));
  if (value < node->data)
    node->left = insertRecursive(node->left, value);
  else if (value > node->data)
    node->right = insertRecursive(node->right, value);
  else
    return node;

  // 2. Actualizar height de los ancestros del nodo insertado
  node->height  = 1 + max(height(node->left), height(node->right));

  //3. obtain balancing factor from ancestor node
  //   verify if it is unbalanced
  int balance = getBalance(node);
}

template <class T>
void AVLTree<T>::insert(T value) {
  root = insertRecursive(root, value);
}







#endif // _AVLTREE_H_