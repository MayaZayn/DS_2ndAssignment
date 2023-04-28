#include "SLL.h"
#include "SLL.cpp"

LinkedList<int> combineNodesBetweenZeros(LinkedList<int> inputList)
{
    int sum = 0;
    LinkedList<int> outputList;

    for (int i = 0; i < inputList.LinkedListSize(); ++i)
    {
        if (!inputList.isItemAtEqual(0, i))
        {
            sum += inputList.retrieveAt(i);
        }

        else if (inputList.isItemAtEqual(0, i) && sum)
        {
            outputList.insertAtTail(sum);
            sum = 0;
        }
    }
    return outputList;
}

int main()
{
    LinkedList<int> inputList;

    inputList.insertAtTail(0);
    inputList.insertAtTail(3);
    inputList.insertAtTail(4);
    inputList.insertAtTail(5);
    inputList.insertAtTail(0);
    inputList.insertAtTail(6);
    inputList.insertAtTail(7);
    inputList.insertAtTail(0);
    inputList.insertAtTail(8);
    inputList.insertAtTail(9);
    inputList.insertAtTail(0);

    LinkedList<int> combinedList = combineNodesBetweenZeros(inputList);
    combinedList.print();
}
