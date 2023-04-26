#include "CircularLL.h"

template<class T>
void CircularLL<T>::insertAtHead(T data) {
    Node* tmp = new Node(data);
    if (!isEmpty()) {
        tmp->next = head;
        head = tmp;
        tail->next = head;
    } else {
        head = tail = tmp;
        tail->next = head;
    }
    size++;
}

template<class T>
void CircularLL<T>::insertAtEnd(T data) {
    Node* tmp = new Node(data);
    if (!isEmpty()) {
        tail->next = tmp;
        tail = tmp;
        tail->next = head;
    } else {
        head = tail = tmp;
        tail->next = head;
    }
    size++;
}

template<class T>
void CircularLL<T>::insertAt(T data, int index) {
    if (index <= size) {
        if (index == 0) {
            insertAtHead(data);
        } else if (index == size) {
                insertAtEnd(data);
        } else {
            Node *tmp = new Node(data), *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            tmp->next = cur->next;
            cur->next = tmp;
            size++;
        }
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
void CircularLL<T>::removeAtHead() {
    if (isEmpty()) {
        std::cout << "CircularLinkedList is empty!" << std::endl;
        throw std::exception();
    }
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* tmp = head;
        head = head->next;
        tail->next = head;
        delete tmp;
    }
    size--;
}

template<class T>
void CircularLL<T>::removeAtEnd() {
    if (isEmpty()) {
        std::cout << "CircularLinkedList is empty!" << std::endl;
        throw std::exception();
    }
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node *cur = head, *tmp;
        for (int i = 0; i < size - 2; ++i) {
            cur = cur->next;
        }
        tmp = tail;
        tail = cur;
        tail->next = head;

        delete tmp;
    }
    size--;
}

template<class T>
void CircularLL<T>::removeAt(int index) {
    if (index < size) {
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtEnd();
        } else {
            Node *tmp, *cur = head;
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
        size--;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
T CircularLL<T>::retrieveAt(int index) {
    if (index < size) {
        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->data;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
void CircularLL<T>::replaceAt(T data, int index) {
    if (index < size) {
        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->data = data;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
bool CircularLL<T>::isExist(T data) {
    Node *cur = head;
    for (int i = 0; i < size; ++i) {
        if (cur->data == data) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

template<class T>
bool CircularLL<T>::isItemAtEqual(T data, int index) {
    if (index < size) {
        Node *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->data == data;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
void CircularLL<T>::swap(int index1, int index2) {
    if (index1 < size && index2 < size) {
        if (index1 == index2) { return; }

        if (index1 > index2) {
            int tmp = index1;
            index1 = index2;
            index2 = tmp;
        }

        Node *firstPrev = head, *secondPrev = head;
        //getting the element before the first index
        for (int i = 0; i < index1 - 1; ++i) {
            firstPrev = firstPrev->next;
        }
        //getting the element before the second index
        for (int i = 0; i < index2 - 1; ++i) {
            secondPrev = secondPrev->next;
        }
        if (index1 == 0)
            firstPrev = tail;

        Node *first = firstPrev->next, *second = secondPrev->next;

        if (first == head) {  // handle if first index is head
            head = second;
        } else if (second == head) {  // handle if second index is head
            head = first;
        }
        if (first == tail) {  // handle if first index is tail
            tail = second;
        } else if (second == tail) {  // handle if second index is tail
            tail = first;
        }

        if (abs(index1 - index2) != 1) {  //If not consecutive elements
            Node *firstNext = first->next, *secondNext = second->next;
            firstPrev->next = second;
            secondPrev->next = first;
            first->next = secondNext;
            second->next = firstNext;
        } else {  //If consecutive elements
            firstPrev->next = second;
            first->next = second->next;
            second->next = first;
        }

        tail->next = head;

    } else {
        throw std::out_of_range("Index out of range");
    }
}

template<class T>
bool CircularLL<T>::isEmpty() {
    return size == 0;
}

template<class T>
void CircularLL<T>::print() {
    Node *cur = head;
    for (int i = 0; i < size; ++i) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}

template<class T>
void CircularLL<T>::clear() {
    while (!isEmpty())
        removeAtEnd();
}

template<class T>
int CircularLL<T>::CircularLLSize() {
    return size;
}

template<class T>
CircularLL<T>::~CircularLL() {
    clear();
}
