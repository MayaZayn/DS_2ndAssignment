#ifndef STACK_H
#define STACK_H

#include "SLL.h"
#include "SLL.cpp"
#include <iostream>

template<class T>
class Stack {
private:
    LinkedList<T> dataList;
    int size;
public:
    Stack() : size(0) {}
    void push(T data);
    T pop();
    T top();
    bool isEmpty();
    void print();
    void clear();
    int stackSize();
};

#endif //STACK_H
