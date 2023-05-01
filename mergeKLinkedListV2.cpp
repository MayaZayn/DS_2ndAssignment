#include <iostream>
#include "SLL.h"
#include "SLL.cpp"
#include <vector>

using namespace std;

template<class T>
Node<T>* merge(Node<T>* ptr1, Node<T>* ptr2) {
    LinkedList<T> mergedList;
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
    return mergedList.head;
}

template<class T>
LinkedList<T> mergeKLinkedLists(vector<Node<int>*> &lists) {
    int k = lists.size();
    if (k < 2) {
        cout << "invalid k\n";
        throw exception();
    }

    Node<T> *merged = merge(lists[0], lists[1]), *tmp;
    for (int i = 2; i < k; ++i) {
        tmp = lists[i];
        merged = merge(merged, tmp);
    }

    LinkedList<int> mergedList;
    while (merged != nullptr) {
        mergedList.insertAtTail(merged->data);
        merged = merged->next;
    }

    return mergedList;
}

int main() {
    LinkedList<int> list1, list2, list3, list4;
    cin >> list1 >> list2 >> list3 >> list4;
    vector<Node<int>*> v;
    v.push_back(list1.head);
    v.push_back(list2.head);
    v.push_back(list3.head);
    v.push_back(list4.head);

    LinkedList<int> merged = mergeKLinkedLists<int>(v);
    merged.print();
    return 0;
}
