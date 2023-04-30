#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class elementType>
class Node
{
public:
    elementType data;
    Node *next;
    Node *previous;

    Node() : next(NULL), previous(NULL) {}
};

template <class elementType>
class DoublyLinkedList
{
public:
    Node<elementType> *head;
    Node<elementType> *tail;
    int count;
    
    DoublyLinkedList() : head(NULL), tail(NULL), count(0) {}
    void insertAtHead(elementType element);
    void insertAtTail(elementType element);
    void insertAt(elementType element, int index);
    void insertAfter(Node<elementType> *previousNode, elementType element);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    elementType retrieveAt(int index);
    void replaceAt(elementType newElement, int index);
    bool isExist(elementType element);
    bool isItemAtEqual(elementType element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    void reverse();
    bool isEmpty();
    int doubleLinkedListSize();
    void clear();
    void forwardTraversal();
    void backwardTraversal();
    ~DoublyLinkedList();
};

#endif
