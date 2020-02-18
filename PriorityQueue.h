#include <vector>
#include <type_traits>
#include "Comparable.h"

using namespace std;

#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

template<typename T>
void swapElements(T& first, T& second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T,
        typename = std::enable_if<std::is_base_of<Comparable<T>, T>::value>>
class PriorityQueue;

template<typename T>
class PriorityQueue<T>
{
    public:
      void addToPq(T& element)
      {
          elements.push_back(element);
          heapUp();
      }
      T getNextElement() 
      {
          return elements[0];
      }
      void removeFromPq()
      {
          if (!isEmpty())
          {
              swapElements(elements[0], elements[elements.size() - 1]);
              elements.pop_back();
              heapDown(0, elements.size() - 1);
          }
      }
      bool isEmpty()
      {
          return elements.size() == 0;
      }
    private:
      vector<T> elements;
      void heapUp()
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
      void heapDown(int start, int end)
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
};
#endif