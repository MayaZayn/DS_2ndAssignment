#include "Stack.h"
#include "Stack.cpp"
#include "CircularLL.h"
#include "CircularLL.cpp"

int main() {
    //LinkedList based Stack (STL)
//    Stack<int> s;
//    s.push(3);
//    s.push(4);
//    s.push(5);
//    s.push(6);
//    s.push(7);
//    s.pop();
//    std::cout << s.top() << std::endl;
//    s.print();
//    s.clear();
//    std::cout << s.stackSize() << std::endl;
//    std::cout << s.top() << std::endl;

    //Circular LinkedList
    CircularLL<int> c;
    c.insertAtHead(1);
    c.insertAtHead(2);
    c.insertAtHead(3);
    c.insertAtHead(4);
    c.insertAtEnd(5);
    c.insertAtEnd(6);
    c.insertAtEnd(7);
    c.insertAt(8, 0);
    c.insertAt(9, 8);
    c.insertAt(10, 2);
//    c.print();
//    std::cout << std::endl;
    c.removeAt(4);
    c.removeAtEnd();
    c.removeAtHead();
//    std::cout << c.retrieveAt(3) << std::endl;
    c.replaceAt(18, 1);
    c.print();
    std::cout << std::endl;
//    std::cout << c.isExist(9) << '\n';
//    std::cout << c.isItemAtEqual(6, 4) << '\n';

    c.swap(2, 3);
    c.print();

//    c.clear();
//    std::cout << c.isEmpty() << std::endl;
//    std::cout << c.CircularLLSize() << std::endl;

    return 0;
}