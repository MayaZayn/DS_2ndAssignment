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
    }
    size++;
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
    Node<T> *tmp = head;
    Node<T> *ptr = head->next;
    if (tmp == NULL) {
        std::cout << "Error, the linked list is empty.\n";
    }
    while (ptr->next != NULL) {
        tmp = tmp->next;
        ptr = ptr->next;
    }
    tmp->next = NULL;
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
    if (index == 0)
    {
        removeAtHead();
        return;
    }
    while (ptr != NULL) {
        if ((index - cnt) == 1) {
            q->next = ptr->next;
            break;
        }
        q = q->next;
        ptr = q->next;
        cnt++;
    }
    size--;
}

template<class T>

T LinkedList<T>::retrieveAt(int index) {
    Node<T> *ptr = head;
    int cnt = 0;
    int tmp = ptr->data;
    if (index < 0 or index > size - 1) {
        cout << "Wrong index.\n";
        throw exception();
    }
    while (cnt < index) {
        ptr = ptr->next;
        tmp = ptr->data;
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
            cout << "The value exists in the list.\n";
            return true;
        }
        head = head->next;
    }
    cout << "The value does not exist in the list.\n";
    return false;
}

template<class T>

bool LinkedList<T>::isItemAtEqual(int val, int index) {
    Node<T> *ptr = head;
    int cnt = 0;
    if (index > size - 1 or index < 0) {
        throw out_of_range("Invalid index.");
    }
    while (ptr != NULL) {
        if (cnt == index) {
            if (ptr->data == val) {
//                 cout << "Yes, this value is equal to the value in the index given.\n";
                return true;
            } else {
//                 cout << "No, this value is not equal to the value in the index given.\n";
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
    Node<T> *tmp = head;
    while (tmp->next!=NULL){
        tmp = tmp->next;
    }
    if (ItemIndex1 == ItemIndex2) {
        return;
    }
    Node<T> *prevfirst = head, *prevsecond = head;
    for(int i=0;i<ItemIndex1-1;++i){
        prevfirst = prevfirst->next;
    }
    for (int i = 0; i < ItemIndex2-1; ++i) {
        prevsecond = prevsecond->next;
    }
    Node<T> *first=prevfirst->next, *second = prevsecond->next;
    if (ItemIndex1 == 0){
        first = head;
        prevfirst = 0;
        head = second;
    }
    if (ItemIndex2 == 0){
        second = head;
        prevsecond = 0;
        head = first;
    }

    if(first==tmp){
        tmp = second;
    }
    else if(second == tmp){
        tmp = first;
    }

    if(abs(ItemIndex1-ItemIndex2) == 1){
        if(prevfirst)
            prevfirst->next = second;
        first->next = second->next;
        second->next =first ;
    }
    else {
        Node<T> *tmpf = first->next;
        if(prevfirst)
            prevfirst->next = second;
        if(prevsecond)
            prevsecond->next = first;
        first->next = second->next;
        second->next = tmpf;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    if (head == NULL) {
//        cout << "The linked list is empty.\n";
        return true;
    } else {
//        cout << "The linked list is not empty.\n";
        return false;
    }
}

template<class T>
int LinkedList<T>::LinkedListSize() {
    return size;
}

template<class T>
void LinkedList<T>::clear() {
    Node<T> *ptr = head;
    while (ptr != NULL) {
        removeAtHead();
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
