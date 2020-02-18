#ifndef __COMPARABLE_H__
#define __COMPARABLE_H__
template<typename T>
class Comparable
{
    public:
      virtual int compareTo(T& other) = 0;
};
#endif