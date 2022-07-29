#ifndef _QUEUENODE_H_
#define _QUEUENODE_H_

  template <class T>
  class QueueNode { 
  public: 
      T data; 
      QueueNode<T> *next;
      QueueNode();
      QueueNode(T);        
  }; 

  template<class T>
  QueueNode<T>::QueueNode() : data{}, next{nullptr} {}

  template<class T>
  QueueNode<T>::QueueNode(T val){
      data = val;
      next = nullptr;
  }

#endif // _QUEUENODE_H_