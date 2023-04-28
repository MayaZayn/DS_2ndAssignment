#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
using namespace std;

template <class elementType>
class ArrayList
{
protected:
    int maxSize;
    int currentLength;
    elementType *list;

public:
    ArrayList(int maxSize = 50) : maxSize(maxSize < 0 ? 50 : maxSize), currentLength(0), list(new elementType[maxSize]) {}
    void insert(elementType element);
    void insertAt(elementType element, int index);
    elementType retrieveAt(int index);
    void removeAt(int index);
    void replaceAt(elementType newElement, int index);
    bool isItemAtEqual(elementType element, int index);
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void clear();
    void print();
};
#endif