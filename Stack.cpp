#include "Stack.h"

template<class T>
void Stack<T>::push(T data) {
    dataList.insertAtHead(data);
    size++;
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        throw std::exception();
    }

    size--;
    T data = dataList.retrieveAt(0);
    dataList.removeAtHead();
    return data;
}

template<class T>
T Stack<T>::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        throw std::exception();
    }
    return dataList.retrieveAt(0);
}

template<class T>
bool Stack<T>::isEmpty() {
    return (stackSize() == 0);
}

template<class T>
void Stack<T>::print() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        throw std::exception();
    }

    dataList.print();
    cout << endl;
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
