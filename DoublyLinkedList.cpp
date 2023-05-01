#include "DoublyLinkedList.h"

template <class elementType>
void DoublyLinkedList<elementType>::insertAtHead(elementType element)
{
    Node<elementType> *newNode = new Node<elementType>;
    newNode->data = element;

    if (head == NULL)
    {
        tail = newNode;
    }
    else
    {
        head->previous = newNode;
        newNode->next = head;
    }
    head = newNode;
    count++;
}

template <class elementType>
void DoublyLinkedList<elementType>::insertAtTail(elementType element)
{
    Node<elementType> *newNode = new Node<elementType>;
    newNode->data = element;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template <class elementType>
void DoublyLinkedList<elementType>::insertAt(elementType element, int index)
{
    if (index < 0 || index > count)
    {
        cout << "Index is out of range." << endl;
        throw exception();
    }

    else if (index == 0)
    {
        insertAtHead(element);
    }

    else if (index == count)
    {
        insertAtTail(element);
    }

    else
    {
        Node<elementType> *newNode = new Node<elementType>;
        Node<elementType> *current = head;
        newNode->data = element;
        count++;

        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }

        newNode->previous = current;
        newNode->next = current->next;
        current->next->previous = newNode;
        current->next = newNode;
    }
}

template <class elementType>
void DoublyLinkedList<elementType>::insertAfter(Node<elementType> *previousNode, elementType element)
{
    if (previousNode == NULL)
    {
        cout << "The previous node cannot be NULL";
        throw exception();
    }

    else if (previousNode == tail)
    {
        insertAtTail(element);
    }

    else
    {
        Node<elementType> *newNode = new Node<elementType>;
        newNode->data = element;

        newNode->previous = previousNode;
        newNode->next = previousNode->next;

        previousNode->next->previous = newNode;
        previousNode->next = newNode;
        count++;
    }
}

template <class elementType>
void DoublyLinkedList<elementType>::removeAtHead()
{
    if (isEmpty())
    {
        cout << "The linked list is empty, no element exists to remove" << endl;
        throw exception();
    }

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        count--;
        return;
    }

    Node<elementType> *nodeToDelete = head;
    head = head->next;
    head->previous = NULL;
    delete nodeToDelete;
    count--;
}

template <class elementType>
void DoublyLinkedList<elementType>::removeAtTail()
{
    if (isEmpty())
    {
        cout << "The linked list is empty, no element exists to remove" << endl;
        throw exception();
    }

    if (head == tail)
    {
        delete tail;
        head = tail = NULL;
        count--;
        return;
    }

    Node<elementType> *nodeToDelete = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete nodeToDelete;
    count--;
}

template <class elementType>
void DoublyLinkedList<elementType>::removeAt(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "The index is out-of-range" << endl;
        throw exception();
    }

    else if (isEmpty())
    {
        cout << "The linked list is empty" << endl;
        throw exception();
    }

    else if (index == 0)
    {
        removeAtHead();
        return;
    }

    else if (index == count - 1)
    {
        removeAtTail();
        return;
    }

    Node<elementType> *current = head, *nodeToDelete;

    for (int i = 1; i < index; ++i)
    {
        current = current->next;
    }

    nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    nodeToDelete->next->previous = current;

    delete nodeToDelete;
    count--;
}

template <class elementType>
elementType DoublyLinkedList<elementType>::retrieveAt(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "The index is out-of-range" << endl;
        throw exception();
    }

    else if (index == 0)
    {
        return head->data;
    }

    else if (index == (count - 1))
    {
        return tail->data;
    }

    else
    {
        Node<elementType> *current = head;
        for (int i = 1; i <= index; ++i)
        {
            current = current->next;
        }
        return current->data;
    }
}

template <class elementType>
void DoublyLinkedList<elementType>::replaceAt(elementType newElement, int index)
{
    if (index < 0 || index >= count)
    {
        cout << "The index is out-of-range" << endl;
        throw exception();
    }

    else if (index == 0)
    {
        head->data = newElement;
    }

    else if (index == count - 1)
    {
        tail->data = newElement;
    }

    else
    {
        Node<elementType> *current = head;
        for (int i = 1; i <= index; ++i)
        {
            current = current->next;
        }
        current->data = newElement;
    }
}

template <class elementType>
bool DoublyLinkedList<elementType>::isExist(elementType element)
{
    Node<elementType> *current = head;

    while (current != NULL)
    {
        if (current->data == element)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

template <class elementType>
bool DoublyLinkedList<elementType>::isItemAtEqual(elementType element, int index)
{
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index out of range");
    }

    Node<elementType> *current = head;
    for (int i = 1; i <= index; ++i)
    {
        current = current->next;
    }
    if (current->data == element)
    {
        return true;
    }
    return false;
}

template <class elementType>
void DoublyLinkedList<elementType>::swap(int firstItemIdx, int secondItemIdx)
{
    if (firstItemIdx < 0 || firstItemIdx >= count || secondItemIdx < 0 || secondItemIdx >= count)
    {
        throw out_of_range("Index out of range");
    }

    if (firstItemIdx == secondItemIdx)
    {
        return;
    }

    if (firstItemIdx > secondItemIdx)
    {
        int temp = firstItemIdx;
        firstItemIdx = secondItemIdx;
        secondItemIdx = temp;
    }

    Node<elementType> *firstItem = head, *secondItem = head;
    for (int i = 1; i <= firstItemIdx; ++i)
    {
        firstItem = firstItem->next;
    }

    for (int i = 1; i <= secondItemIdx; ++i)
    {
        secondItem = secondItem->next;
    }

    if (firstItemIdx == 0)
    {
        head = secondItem;
    }

    else
    {
        firstItem->previous->next = secondItem;
    }

    if (secondItemIdx == count - 1)
    {
        tail = firstItem;
    }
    else
    {
        secondItem->next->previous = firstItem;
    }

    if (secondItemIdx - firstItemIdx == 1)
    {
        firstItem->next = secondItem->next;
        secondItem->previous = firstItem->previous;
        secondItem->next = firstItem;
        firstItem->next->previous = firstItem;
    }

    else
    {
        firstItem->next->previous = secondItem;
        secondItem->previous->next = firstItem;

        Node<elementType> *firstItemPrev = firstItem->previous, *firstItemNext = firstItem->next;
        firstItem->previous = secondItem->previous;
        firstItem->next = secondItem->next;

        secondItem->previous = firstItemPrev;
        secondItem->next = firstItemNext;
    }
}

template <class elementType>
void DoublyLinkedList<elementType>::reverse()
{
    Node<elementType> *current = head;
    Node<elementType> *previous = NULL;
    Node<elementType> *next = current->next;

    while (current != NULL)
    {
        current->next = previous;
        current->previous = next;

        previous = current;
        current = next;
        next = (next != NULL) ? next->next : NULL;
    }
    tail = head;
    head = previous;
}

template <class elementType>
bool DoublyLinkedList<elementType>::isEmpty()
{
    return (count == 0);
}

template <class elementType>
int DoublyLinkedList<elementType>::doubleLinkedListSize()
{
    return count;
}

template <class elementType>
void DoublyLinkedList<elementType>::clear()
{
    Node<elementType> *temp = head;
    while (head != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = NULL;
    count = 0;
}

template <class elementType>
void DoublyLinkedList<elementType>::forwardTraversal()
{
    Node<elementType> *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <class elementType>
void DoublyLinkedList<elementType>::backwardTraversal()
{
    Node<elementType> *current = tail;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->previous;
    }
    cout << endl;
}

template <class elementType>
DoublyLinkedList<elementType>::~DoublyLinkedList()
{
    clear();
}
