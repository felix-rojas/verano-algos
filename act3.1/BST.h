#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <queue>
#include "BSTNode.h"

template <class T> 
class BST {
  private:
    BSTNode<T> *root;
    BSTNode<T>* insertRecursive(BSTNode<T> *p, T value);
    BSTNode<T>* getSuccessor(BSTNode<T> *p);
    BSTNode<T>* deleteRecursive(BSTNode<T> *p, T value);
    void print2D(BSTNode<T> *p, int space);
    void inorderRecursive(BSTNode<T> *p);
    void postOrderRecursive(BSTNode<T> *p);
    void preOrderRecursive(BSTNode<T> *p);
    void levelOrder(BSTNode<T> *t);
    bool printAncestors(BSTNode<T>* root, T value);
    int  getLevel(T data, T level);
    void visit(int);
    
  

  public:
    BST();
    ~BST();
    void clearMemory(BSTNode<T> *p);
    bool search(T value);
    void insert(T value);
    void deleteNode(T value);
    void print();
    void callInorder();
    void callPostOrder();
    void callPreOrder();
    void callLevelOrder();
    void callvisit(int);
    int callheight();
    int whatlevelami(T data);
    BSTNode<T>* getRoot();
    void ancestors(T value);
    int height(BSTNode<T> *root);
};

//o(1)
template <class T>
BST<T>::BST() {
  std::cout << "---> Creando un BinarySearchTree vacio: " <<  this << std::endl;
  root = nullptr;
}

//o(n) llamadas recursivas que recorren todo el árbol
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

// Peor caso es O(n) si está desbalanceado
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
// Peor caso es O(n) si está desbalanceado
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

// Peor caso es O(n) si está desbalanceado
template <class T>
void BST<T>::insert(T value) {
  root = insertRecursive(root, value);
}

// Peor caso es O(n) si está desbalanceado hacia la izquierda
template <class T>
BSTNode<T> * BST<T>::getSuccessor(BSTNode<T> *p) {
  BSTNode<T> *current = p;
  while (current && current->left != nullptr) {
    current = current->left;
  }
  return current;
}

// Peor caso es O(n) si el trayecto recorrido del nodo
// es igual que la altura del BST
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

// O(n) pues recorre todo el árbol
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

// o(n) recorre todo el árbol
template <class T>
void BST<T>::inorderRecursive(BSTNode<T> *p) {
  if (p != nullptr) {
    inorderRecursive(p->left);
    std::cout << p->data << " ";
    inorderRecursive(p->right);
  }
}

// o(n) recorre todo el árbol
template <class T>
void BST<T>::callInorder() {
  inorderRecursive(root);
  std::cout << std::endl;
}

// o(n) recorre todo el árbol
template<class T>
void BST<T>::postOrderRecursive(BSTNode<T> *p){
  if (p != nullptr) {
    postOrderRecursive(p->left);
    postOrderRecursive(p->right);
    std::cout << p->data << " ";
  }
}

// o(n) recorre todo el árbol
template <class T>
void BST<T>::callPostOrder(){
  postOrderRecursive(root);
  std::cout << std::endl;
}

// o(n) recorre todo el árbol
template <class T>
void BST<T>::preOrderRecursive(BSTNode<T> *p){
  if (p != nullptr) {
    std::cout << p->data << " ";
    preOrderRecursive(p->left);
    preOrderRecursive(p->right);
  }
}

template <class T>
void BST<T>::callPreOrder(){
  preOrderRecursive(root);
  std::cout << std::endl;
}


template<class T>
void BST<T>::levelOrder(BSTNode<T> *t) {
    if (t != NULL) {
        std::queue < BSTNode<T>  * > q;
        q.push(t);


        while (!q.empty()) {
            BSTNode<T> *current = q.front();
            std::cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            q.pop();
        }
    }
}


template<class T>
void BST<T>::callLevelOrder(){
    levelOrder(root);
    std::cout << std::endl;
}
template <class T>
BSTNode<T>* BST<T>::getRoot(){
  return root;
}


template<class T>
void BST<T>::visit(int n){

  if (n==1){
    callPreOrder();
}
  if (n==2){
    callInorder();
}
  if (n==3){
    callPostOrder();
}
if (n==4){
    callLevelOrder();
}
  }

template<class T>
void BST<T>::callvisit(int n){
    visit(n);
    std::cout << std::endl;
}


// o(n) si el árbol no está balanceado
// y se pide el elemento de la hoja más distante
template <class T>
int BST<T>::height(BSTNode<T> *root){
 if (root == NULL) {
    return 0;
  } else {
    int ld = height(root->left);
    int rd = height(root->right);
    return (std::max(ld, rd) + 1);
  }
}

// o(1)
template<class T>
int  BST<T>::callheight(){
    BSTNode<T> *root = getRoot();
   int  h = height(root);
   return h;
    std::cout <<  h << std::endl;
}

// o(h) donde h es la altura en la que se encuentra
// el nodo del que queremos saber sus ancestros
template <class T>
bool BST<T>::printAncestors(BSTNode<T>* root, T value)
{
  if (root == NULL)
     return false;
 
  if (root->data == value)
     return true;
  if ( printAncestors(root->left, value) ||
       printAncestors(root->right, value) )
  {
    std::cout << root->data << " ";
    return true;
  }
  return false;
} 

template<class T>
void BST<T>::ancestors(T value){
 BSTNode<T>* root = getRoot();
    std::cout << printAncestors(root,value) << " ";; 
}

// O(h) donde h es la altura del árbol
template<class T>
int BST<T>::getLevel(T data, T level)
{ BSTNode<T>* root = getRoot();
    if (root == NULL)
        return 0;
 
    if (root->data == data)
        return level;
 
    int downlevel
        = getLevel(data, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevel(data, level + 1);
    return downlevel;
}


template<class T>
int BST<T>::whatlevelami(T data)
{
    return getLevel(data, 1);
}
 



#endif // _BST__H_