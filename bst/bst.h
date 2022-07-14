#ifndef _BST_H_
#define _BST_H_

#include <iostream>

template <class T>
class BST {
    private:
      BSTNode <T> *root;
    public:
      BST();
      ~BST();
      bool search(T value);
}

template <class T>
BST<T>::BST(){
    std::cout <<
}

template <class T>
bool BST<T>::search(T value){
    while (p != nullptr){
        if (p->data == value){
            return true;
        }
        else{
            p = (value < p->data ? p->left : p->right);
        }
        return false;
    }
}



#endif //  _BST_H_