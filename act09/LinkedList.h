/** @file LinkedList.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/*
 ! This linked list code is based on Amit Kumar's code found here:
    https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
*/

/*
 * LinkedList is a class that can accept any data type
 * Only LinkedList is able to instantiate a node
 */

template <class T> 
class LinkedList
{
private:
    Node *head, *tail;
    int size;

public:
    LinkedList()
    {
        head, tail = NULL; // first and last node
        size = 0;          // initial size
    }

    void addFirst(T &data)
    {
        // allocate space for node
        Node *tmp = new Node;
        // access tmp's data and set it to data
        tmp -> data = data;

        // if the head NULL, there is no linked list yet
        if (head == NULL) 
        {
            tmp -> next = NULL;
            head = tmp; 
            tail = tmp;
        }
        // else there is a linked list
        else
        {
            head -> next = tmp;
            head = head -> next; 
        }
    }

    void addLast(T &data)
    {
        // instantiate new Node to a tmp
        Node *tmp = new Node;
        // access tmp's data and set it to data
        tmp->data = data;
        // set tmp's next as NULL, because it's the last
        tmp->next = NULL;

        // if the head NULL, there is no linked list yet
        if (head == NULL) 
        {
            head = tmp; 
            tail = tmp;
        }
        // else there is a linked list
        else
        {
            tail -> next = tmp;
            tail = tail -> next; 
        }
        // increase size of LinkedList
        size++;
    }

    int getSize()
    {
        return size;
    };
};

#endif // LINKEDLIST_H