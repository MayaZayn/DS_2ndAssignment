#include "SLL.h"

template<class T>
void LinkedList<T>::insertAtHead(int val) {
    Node<T> *newNode = new Node<T>;
    if (head == NULL) {
        head = newNode;
        newNode->data = val;
        newNode->next = NULL;
        size++;
        return;
    }
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    size++;
}

template<class T>
void LinkedList<T>::insertAtTail(int val) {
    Node<T> *newNode = new Node<T>;
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node<T> *ptr;
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAt(int val, int index) {
    Node<T> *newNode = new Node<T>;
    newNode->data = val;
    newNode->next = NULL;
    if (index < 0 or index > size + 1) {
        cout << "invalid index\n";
    } else if (index == 0) {
        newNode->next = head;
        head = newNode;
        size++;
    } else {
        Node<T> *tmp = head;
        while (--index > 0) {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
        size++;
    }

}

template<class T>
void LinkedList<T>::removeAtHead() {
    head = head->next;
    size--;
}

template<class T>
void LinkedList<T>::removeAtTail() {
    Node<T> *ptr = head->next;
    if (head == NULL) {
        std::cout << "Error, the linked list is empty.\n";
    }
    while (ptr->next != NULL) {
        head = head->next;
        ptr = ptr->next;
    }
    head->next = NULL;
    size--;
    delete ptr;
}

template<class T>
void LinkedList<T>::removeAt(int index) {
    Node<T> *q = head;
    Node<T> *ptr = head->next;
    int cnt = 0;
    if (index < 0 or index > size - 1) {
        cout << "Wrong index.\n";
        return;
    }
    while (ptr != NULL) {
        if ((index - cnt) == 1) {
            q->next = ptr->next;
        }
        q = q->next;
        ptr = q->next;
        cnt++;
    }
    size--;
}

template<class T>

T LinkedList<T>::retriveAt(int index) {
    Node<T> *ptr = head;
    int cnt = 0;
    int tmp = ptr->data;
    if (index < 0 or index > size - 1) {
        cout << "Wrong index.\n";
        return;
    }
    while (ptr != NULL) {
        if (cnt == index) {
            cout << "The value in this index is: " << ptr->data << std::endl;
            //return tmp;
        }
        ptr = ptr->next;
        cnt++;
    }
    return tmp;
}


template<class T>
void LinkedList<T>::replaceAt(int val, int index) {
    Node<T> *ptr = head;
    int cnt = 0;
    while (ptr != NULL) {
        if (cnt == index) {
            ptr->data = val;
        }
        ptr = ptr->next;
        cnt++;
    }
    if (cnt < index or index < 0 or index > size - 1) {
        cout << "Wrong index.\n";
    }
}

template<class T>
bool LinkedList<T>::isExist(int val) {
    while (head != NULL) {
        if (head->data == val) {
            cout << "The value is existing in the list.\n";
            return true;
        }
        head = head->next;
    }
    cout << "The value is not existing in the list.\n";
    return false;
}

template<class T>

bool LinkedList<T>::isItemAtEqual(int val, int index) {
    Node<T> *ptr = head;
    int cnt = 0;
    if (index > size - 1 or index < 0) {
        cout << "Wrong index.\n";
    }
    while (ptr != NULL) {
        if (cnt == index) {
            if (ptr->data == val) {
                cout << "Yes, this value is equal to the value in the index given.\n";
                return true;
            } else {
                cout << "Yes, this value is not equal to the value in the index given.\n";
                return false;
            }
        }
        ptr = ptr->next;
        cnt++;
    }
    return false;
}

template<class T>
void LinkedList<T>::swap(int ItemIndex1, int ItemIndex2) {
    if (ItemIndex1 == ItemIndex2) {
        return;
    }
    Node<T> *prev1 = NULL, *curr1 = head;
    while (curr1 && curr1->data != ItemIndex1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    Node<T> *prev2 = NULL, *curr2 = head;
    while (curr2 && curr2->data != ItemIndex2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if (curr1 == NULL && curr2 == NULL) {
        return;
    }
    if (prev1 != NULL) {
        prev1->next = curr2;
    } else {
        head = curr2;
    }
    if (prev2 != NULL) {
        prev2->next = curr1;
    } else {
        head = curr1;
    }
    Node<T> *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    if (head == NULL) {
        cout << "The linked list is empty.\n";
        return true;
    } else {
        cout << "The linked list is not empty.\n";
        return false;
    }
}

template<class T>
int LinkedList<T>::LinkedListSize() {
    int counter = 0;
    while (head != NULL) {
        counter++;
        head = head->next;
    }
    cout << "the linked list size is:" << counter;
    return counter;
}

template<class T>
void LinkedList<T>::clear() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        removeAtTail();
        ptr = ptr->next;
    }
}

template<class T>
void LinkedList<T>::print() {
    Node<T> *current;
    current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

template<class T>
istream &operator>>(istream &in, LinkedList<T> &list) {
    int n;
    cout << "Enter the size of the linked list:\n";
    in >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        in >> data;
        list.insertAtTail(data);
    }
    return in;
}




