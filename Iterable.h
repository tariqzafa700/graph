#ifndef __ITERABLE_H__
#define __ITERABLE_H__

template<typename T>
class Iterable
{
    public:
        Iterable(T begin, T end) : _begin(begin), _end(end)
        { }
    
    private:
        T _begin;
        T _end;
};

template<class T>
Iterable<T> make_iterable(T begin, T end)
{
    return Iterable<T>(begin, end);
}

#endif