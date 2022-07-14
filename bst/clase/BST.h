#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include "BSTNode.h"

template <class T> 
class BST {
  private:
    BSTNode<T> *root;
    BSTNode<T>* insertRecursive(BSTNode<T> *p, T value);
    BSTNode<T>* getSuccessor(BSTNode<T> *p);
    BSTNode<T>* deleteRecursive(BSTNode<T> *p, T value);
    void print2D(BSTNode<T> *p, int space);
    void inorderRecursive(BSTNode <T> *p);
    void preorderRecursive(BSTNode <T> *p);
    void postorderRecursive(BSTNode <T> *p);

  public:
    BST();
    ~BST();
    void clearMemory(BSTNode<T> *p);
    bool search(T value);
    void insert(T value);
    void deleteNode(T value);
    void print();
    void callInorder(); // wrapper
    void callPreorder(); // wrapper
    void callPostorder(); // wrapper
};

template <class T>
BST<T>::BST() {
  std::cout << "---> Creando un BinarySearchTree vacio: " <<  this << std::endl;
  root = nullptr;
}

template <class T>
BST<T>::~BST() {
  std::cout << "---> Liberando memoria del BinarySearchTree: " <<  this << std::endl;
  clearMemory(root);
  root = nullptr;
}

template <class T>
void BST<T>::clearMemory(BSTNode<T> *p) {
  if (p != nullptr) {
    clearMemory(p->left);
    clearMemory(p->right);
    delete p;
    p = nullptr;
  }
}

template <class T>
bool BST<T>::search(T value) {
  BSTNode<T> *p = root;
  while (p != nullptr) {
    if (p->data == value)
      return true;
    else
      p = (value < p->data ? p->left : p->right);
  }
  return false;
}

template <class T>
BSTNode<T>* BST<T>::insertRecursive(BSTNode<T> *p, T value) {
  if (p == nullptr) // El BST esta vacio
    p = new BSTNode<T>(value);
  else if (value < p->data)
    p->left = insertRecursive(p->left, value);
  else if (value > p->data)
    p->right = insertRecursive(p->right, value);
  else
    std::cout << "El elemento " << value << " ya existe en el BST" << std::endl;
  return p;
}

template <class T>
void BST<T>::insert(T value) {
  root = insertRecursive(root, value);
}

template <class T>
BSTNode<T> * BST<T>::getSuccessor(BSTNode<T> *p) {
  BSTNode<T> *current = p;
  while (current && current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <class T>
BSTNode<T>* BST<T>::deleteRecursive(BSTNode<T> *p, T value) {
  BSTNode<T> *current = p;
  // caso base, arbol vacio
  if (p == nullptr)
    return p;
  if (value < p->data)
    p->left = deleteRecursive(p->left, value);
  else if (value > p->data)
    p->right = deleteRecursive(p->right, value);
  else { // Hemos localizado el nodo a borrar (apuntado por p)
    // El nodo a borrar no tiene ningun hijo
    if (p->left == nullptr && p->right == nullptr) {
      delete p;
      p = nullptr;
      return p;
    }
    else if (p->left == nullptr) { // El nodo a borrar solo tiene hijo derecho
      current = p->right;
      delete p;
      p = nullptr;
      return current;
    } 
    else if (p->right == nullptr) { // El nodo a borrar solo tiene hijo izquierdo
      current = p->left;
      delete p;
      p = nullptr;
      return current;
    }
    // El nodo a borrar tiene dos hijos
    current = getSuccessor(p->right);
    p->data = current->data;
    p->right = deleteRecursive(p->right, current->data);
  }
  return p;
}

template <class T>
void BST<T>::deleteNode(T value) {
   root = deleteRecursive(root, value);
}

template <class T>
void BST<T>::print2D(BSTNode<T> *root, int space) {
  // Caso base
  if (root == nullptr)
      return;
  // Incrementa la distancia entre niveles
  space += 5;
  // Procesa hijo derecho
  print2D(root->right, space);
  // Imprime el nodo actual despues de los espacios necesarios
  std::cout << std::endl;
  for (int i = 5; i < space; i++)
      std::cout << " ";
  std::cout << root->data << std::endl;
  // Procesa el hijo izquierdo 
  print2D(root->left, space);
}

template <class T>
void BST<T>::print() {
  print2D(root, 0);
}

template <class T>
void BST<T>::inorderRecursive(BSTNode <T> *p) {
  if (p != nullptr) {
    inorderRecursive(p ->left);
    std::cout << p->data << " ";
    inorderRecursive(p ->right);
  }
}

template <class T>
void BST<T>::callInorder() {
  inorderRecursive(root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::callPreorder() {
  preorderRecursive(root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::callPostorder() {
  postorderRecursive(root);
  std::cout << std::endl;
}

template <class T>
void BST<T>::preorderRecursive(BSTNode <T> *p) {
  if (p != nullptr) {
    std::cout << p->data << " ";
    preorderRecursive(p ->left);
    preorderRecursive(p ->right);
  }
}

template <class T>
void BST<T>::postorderRecursive(BSTNode <T> *p) {
  if (p != nullptr) {
    postorderRecursive(p ->left);
    postorderRecursive(p ->right);
    std::cout << p->data << " ";
  }
}

#endif // _BST__H_
