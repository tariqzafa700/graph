#include <vector>
#include <type_traits>
#include "Comparable.h"

using namespace std;

#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

template <typename T,
        typename = std::enable_if<std::is_base_of<Comparable<T>, T>::value>>
class PriorityQueue;

template<typename T>
class PriorityQueue<T>
{
    public:
      void addToPq(T& element);
      T getNextElement();
      void removeFromPq();
    private:
      vector<T> elements;
      void heapUp();
      void heapDown(int start, int end);
};
#endif