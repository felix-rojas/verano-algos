/** @file Node.h */
#ifndef NODE_H
#define NODE_H

/*
 * Nodes could be instantiated as a struct which would make everything public.
 * However, since we use private instantiation to encapsulate the nodes
 */

template <class T>
class Node
{
private:
    T data;     // stored data
    Node *next; // mem loc of next node

    // class LinkedList can access and instantiate
    // nodes from LinkedList
    friend class LinkedList;
};

#endif // NODE_H