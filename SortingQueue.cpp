// 3 ways to sort the queue

#include <iostream>
#include <vector>
#include "queue.h"
#include "queue.cpp"

using namespace std;

//template <class T>
//queue<T> sortQueue(queue<T> &q) {
//    vector<int> v;
//    while (!q.isEmpty()) {
//        v.enqueue_back(q.First());
//        q.dequeue();
//    }
//
//    sort(v.begin(), v.end());
//    for (int & i : v) {
//        q.enqueue(i);
//    }
//    return q;
//}

template <class T>
queue<T> sortQueue(queue<T> &q, int sz) {
    int mx = INT_MIN;
    while (sz--) {
        q.enqueue(q.First());
        mx = max(mx, q.First());
        q.dequeue();
    }

    vector<int> v(mx + 1);
    while (!q.isEmpty()) {
        v[q.First()]++;
        q.dequeue();
    }

    for (int i = 0; i < v.size(); ++i) {
        while (v[i]--)
            q.enqueue(i);
    }

    return q;
}

template <class T>
queue<T> sortQueue(queue<T> &q) {
    int sz = q.queueSize();
    for (int i = 0; i < sz; ++i) {
        int mnIndx = 0, mnVal = q.First();
        for (int j = 0; j < sz; ++j) {
            int cur = q.First();
            if (j < sz - i && cur < mnVal) {
                mnVal = q.First();
                mnIndx = j;
            }
            q.dequeue();
            q.enqueue(cur);
        }
        for (int j = 0; j < sz; ++j) {
            if (j != mnIndx) {
                q.enqueue(q.First());
            }
            q.dequeue();
        }
        q.enqueue(mnVal);
    }
    return q;
}

int main() {
    queue<int> q;
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);

    sortQueue(q);
    q.print();

/*--------------------------------------------------------------------------------------------------------------------*/

    q.clear();

    q.enqueue(9);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(1);

    sortQueue(q, q.queueSize());

    while (!q.isEmpty()) {
        cout << q.First() << " ";
        q.dequeue();
    }

    return 0;
}
