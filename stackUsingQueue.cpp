#include "queue.h"
#include "queue.cpp"

template <class T>
class Stack
{
private:
    queue<T> q;

public:
    void push(T element);
    T pop();
};

template <class T>
void Stack<T>::push(T element)
{
    if (q.isFull())
    {
        cout << "The stack is full!" << endl;
        throw exception();
    }
    q.enqueue(element);
}

template <class T>
T Stack<T>::pop()
{
    if (q.isEmpty())
    {
        cout << "The stack is empty!" << endl;
        throw exception();
    }

    int count = 0;
    while (count < q.queueSize() - 1)
    {
        q.enqueue(q.dequeue());
        count++;
    }
    return q.dequeue();
}

int main()
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}
