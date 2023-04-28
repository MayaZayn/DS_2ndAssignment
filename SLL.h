#ifndef DATASTRUCTURES_SLL_H
#define DATASTRUCTURES_SLL_H

#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }

};

template<class T>
class LinkedList {
public:
    int size = 0;
    Node<T> *head;
    LinkedList() {head = NULL;}
    void insertAtHead(int val);
    void insertAtTail(int val);
    void insertAt(int val, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retriveAt(int index);
    void replaceAt(int val, int index);
    bool isExist(int val);
    bool isItemAtEqual(int val, int index);
    void swap(int ItemIndex1, int ItemIndex2);
    bool isEmpty();
    int LinkedListSize();
    void clear();
    void print();

    template<class U>
    friend istream& operator>>(istream &in, LinkedList<U> &list);
};

#endif //DATASTRUCTURES_SLL_H
