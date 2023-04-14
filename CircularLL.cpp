#include "CircularLL.h"

/// MAKE SURE INDICES ARE RIGHT!!!!! AND SHALL I DELETE SOMETHING AFTER I AM DONE WITH IT TO AVOID MEMORY LEAK??

template<class T>
void CircularLL<T>::insertAtHead(T data) {
    Node* tmp = new Node(data);
    if (!isEmpty()) {
        tmp->next = head;
        head = tmp;
        tail->next = head;
    } else {
        head = tail = tmp;
        /// What should I do here to make it circular if it has only one element (Shall I keep this line)?
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
        /// What should I do here to make it circular if it has only one element (Shall I keep this line)?
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
        throw std::out_of_range("CircularLinkedList is empty");
    }
    if (size == 1) {
        /// Is this how to remove the only element in the list??
        head = tail = nullptr;
    } else {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    size--;
}

template<class T>
void CircularLL<T>::removeAtEnd() {
    if (isEmpty()) {
        throw std::out_of_range("CircularLinkedList is empty");
    }
    if (size == 1) {
        /// Is this how to remove the only element in the list??
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
        ///handle if any index or both is head or tail and consecutive elements!

        //If both aren't head or tail and not consecutive elements
        Node *cur1 = head, *cur2 = head;
        //getting the element before the first index
        for (int i = 0; i < index1 - 1; ++i) {
            cur1 = cur1->next;
        }
        //getting the element before the second index
        for (int i = 0; i < index2 - 1; ++i) {
            cur2 = cur2->next;
        }

        Node *firstPrev = cur1, *el1 = cur1->next, *firstNext = cur1->next->next,
        *secondPrev = cur2, *el2 = cur2->next, *secondNext = cur2->next->next;

        //swapping the elements
        firstPrev->next = el2;
        secondPrev->next = el1;
        el1->next = secondNext;
        el2->next = firstNext;

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