#include "PriorityQueue.h"

template<typename T>
void swapElements(T& first, T& second)
{
    T temp;
    temp = first;
    first = second;
    second = temp;
}

template<typename T>
void PriorityQueue<T>::heapUp()
{
    auto pqSize = elements.size();
    auto& last = elements[pqSize - 1];
    int index = (pqSize - 1) / 2;
    while (index >= 0 && last.compareTo(elements[index]) < 0)
    {
        swapElements(elements[index], last);
        index = (index - 1) / 2;
    }
}

template<typename T>
void PriorityQueue<T>::heapDown(int start, int end)
{
    auto pqSize = elements.size();
    auto& first = elements[start];
    auto init = start;
    auto index = start * 2 + 1;
    while (index < end)
    { 
        if (index + 1 < end && elements[index].compareTo(elements[index + 1]) > 0)
        {
            swapElements(elements[index], elements[index + 1]);
        }
        if (elements[index].compareTo(elements[init]) < 0)
        {
            swapElements(elements[index], elements[init]);
        }
        else
        {
            break;
        }
        
        init = index;
        index = init * 2 + 1;
    }
}

template<typename T>
void PriorityQueue<T>::addToPq(T& element)
{
    elements.push_back(element);
    heapUp();
}

template<typename T>
T PriorityQueue<T>::getNextElement()
{
    return elements[0];
}

template<typename T>
void PriorityQueue<T>::removeFromPq()
{
    swapElements(elements[0], elements[elements.size() - 1]);
    elements.pop_back();
    heapDown(0, elements.size() - 1);
}