#include "queue.h"

template<class T>
void queue<T>::enqueue(T val) {
    if(!isFull()) {
        if (first == -1) {
            first = 0;
        }
        arr[++last] = val;
        size++;
    } else {
        cout << "The queue is full!" << endl;
        throw exception();
    }
}

template<class T>
T queue<T>::dequeue() {
    T tmp;
    tmp = arr[first];
    if(isEmpty()){
        cout << "The queue is empty!" << endl;
        throw exception();
    } else {
        if (first >= last) {
            first = last = -1;
        } else {
            first++;
        }
        size--;
    }
    return (tmp);
}

template<class T>
T queue<T>::First() {
    T tmp = arr[first];
    return (tmp);
}

template<class T>
bool queue<T>::isEmpty() {
    if(first == -1)
        return true;
    else
        return false;
}

template<class T>
int queue<T>::queueSize() {
    return size;
}

template<class T>
void queue<T>::clear() {
    first = last = -1;
}

template<class T>
void queue<T>::print() {
    if(isEmpty()){
        cout << "The queue is empty!" << endl;
        throw exception();
    } else {
        for(int i = first; i <= last; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template<class T>
bool queue<T>::isFull() {
    if (first == 0 && last == SIZE - 1 || first == last + 1)
        return true;
    else
        return false;
}
