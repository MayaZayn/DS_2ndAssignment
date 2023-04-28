#include <iostream>
#include "SLL.h"
#include "SLL.cpp"

using namespace std;

template<class T>
LinkedList<T> merge(LinkedList<T> &list1, LinkedList<T> &list2) {
    LinkedList<T> mergedList;
    Node<T> *ptr1 = list1.head, *ptr2 = list2.head;
    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->data < ptr2->data) {
            mergedList.insertAtTail(ptr1->data);
            ptr1 = ptr1->next;
        } else {
            mergedList.insertAtTail(ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != nullptr) {
        mergedList.insertAtTail(ptr1->data);
        ptr1 = ptr1->next;
    }
    while (ptr2 != nullptr) {
        mergedList.insertAtTail(ptr2->data);
        ptr2 = ptr2->next;
    }
    return mergedList;
}

template<class T>
LinkedList<T> mergeKLinkedLists(int k) {
    if (k < 2) {
        cout << "invalid k\n";
        throw exception();
    }

    LinkedList<T> list1, list2;
    cin >> list1 >> list2;
    LinkedList<T> mergedList = merge(list1, list2);
    for (int i = 2; i < k; ++i) {
        LinkedList<T> list3;
        cin >> list3;
        mergedList = merge(mergedList, list3);
    }
    return mergedList;
}

int main() {
    LinkedList<int> merged = mergeKLinkedLists<int>(1);
    merged.print();
    return 0;
}