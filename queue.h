#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#define SIZE 10000
#include <iostream>
using namespace std;
template <class T>
class queue {
private:
    int first, last, size;
    T arr[SIZE];
public:
    queue() { first = last = -1, size = 0; }
    bool isFull();
    void enqueue(T val);
    T dequeue();
    T First();
    int queueSize();
    bool isEmpty();
    void clear();
    void print();
};
#endif //QUEUE_QUEUE_H
