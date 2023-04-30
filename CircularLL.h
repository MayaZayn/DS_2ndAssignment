#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include <iostream>

template<class T>
class CircularLL {
private:
    struct Node {
        T data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        explicit Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    CircularLL() : size(0) {head = tail = nullptr;}
    ~CircularLL();
    void insertAtHead(T data);
    void insertAtEnd(T data);
    void insertAt(T data, int index);
    void removeAtHead();
    void removeAtEnd();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T data, int index);
    bool isExist(T data);
    bool isItemAtEqual(T data, int index);
    void swap(int index1, int index2);
    bool isEmpty();
    void print();
    void clear();
    int CircularLLSize();
};

#endif //CIRCULARLL_H
