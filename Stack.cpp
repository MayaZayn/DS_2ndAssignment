#include "Stack.h"

template<class T>
void Stack<T>::push(T data) {
    dataList.push_front(data);
    size++;
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }

    size--;
    T data = dataList.front();
    dataList.pop_front();
    return data;
}

template<class T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return dataList.front();
}

template<class T>
bool Stack<T>::isEmpty() {
    return (stackSize() == 0);
}

template<class T>
void Stack<T>::print() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }

    for (auto & item : dataList) {
        std::cout << item << " ";
    }
}

template<class T>
void Stack<T>::clear() {
    dataList.clear();
    size = 0;
}

template<class T>
int Stack<T>::stackSize() {
    return size;
}