#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;
void GenerateBinaryNumbers(int n){
    queue<string> q;
    q.enqueue("1");
    int i = 1;
    while (i++ <= n)
    {
        q.enqueue(q.First() + "0");
        q.enqueue(q.First() + "1");

        cout << q.First() << ' ';
        q.dequeue();
    }
}
int main(){
    int n =5;
    GenerateBinaryNumbers(n);
}
