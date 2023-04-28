#include "ArrayList.h"

template <class elementType>
void ArrayList<elementType>::insert(elementType element)
{
    if (isFull())
    {
        cout << "The array is full, cannot insert an element..." << endl;
    }

    else
    {
        list[currentLength++] = element;
    }
}

template <class elementType>
void ArrayList<elementType>::insertAt(elementType element, int index)
{
    if (index < 0 || index > currentLength)
    {
        cout << "Index is out of range. " << endl;
        return;
    }

    else if (isFull())
    {
        cout << "The array is full. Please remove an element before inserting a new one." << endl;
        return;
    }

    if (index == currentLength)
    {
        list[currentLength] = element;
    }
    else
    {
        for (int i = currentLength; i > index; --i)
        {
            list[i] = list[i - 1];
        }
        list[index] = element;
    }
    currentLength++;
}

template <class elementType>
elementType ArrayList<elementType>::retrieveAt(int index)
{
    if (index < 0 || index >= currentLength)
    {
        cout << "Index is out of range." << endl;
    }
    else
    {
        return list[index];
    }
}

template <class elementType>
void ArrayList<elementType>::removeAt(int index)
{
    if (index < 0 || index >= currentLength)
    {
        cout << "Index is out of range. " << endl;
    }
    else
    {
        currentLength--;
        for (int i = index; i < currentLength; ++i)
        {
            list[i] = list[i + 1];
        }
    }
}

template <class elementType>
void ArrayList<elementType>::replaceAt(elementType newElement, int index)
{
    if (index < 0 || index >= currentLength)
    {
        cout << "Index is out of range. " << endl;
    }
    else
    {
        list[index] = newElement;
    }
}

template <class elementType>
bool ArrayList<elementType>::isItemAtEqual(elementType element, int index)
{
    if (index < 0 || index >= currentLength)
    {
        cout << "Index is out of range. " << endl;
    }
    else
    {
        return (list[index] == element);
    }
}

template <class elementType>
bool ArrayList<elementType>::isEmpty()
{
    return (currentLength == 0);
}

template <class elementType>
bool ArrayList<elementType>::isFull()
{
    return (maxSize == currentLength);
}

template <class elementType>
int ArrayList<elementType>::listSize()
{
    return currentLength;
}

template <class elementType>
int ArrayList<elementType>::maxListSize()
{
    return maxSize;
}

template <class elementType>
void ArrayList<elementType>::clear()
{
    currentLength = 0;
}

template <class elementType>
void ArrayList<elementType>::print()
{
    for (int i = 0; i < currentLength; ++i)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
