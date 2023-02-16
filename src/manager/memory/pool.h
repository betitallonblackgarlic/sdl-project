#pragma once

#include <vector>

template <class T>
class Pool
{
  private:
    std::vector<T> _pool;

  public:
    Pool();
    ~Pool();

    void allocate(T t);
    T find(T t);
    void deallocate(T t);
    void clear();
};

template <class T>
Pool<T>::Pool()
{}

template <class T>
Pool<T>::~Pool()
{}

template <class T>
void Pool<T>::allocate(T t)
{
    _pool.push_back(t);
}

template <class T>
T Pool<T>::find(T t)
{
    for (auto &p : _pool)
    {
        if (p == t) { return p; }
    }
}

template <class T>
void Pool<T>::deallocate(T t)
{
    for (auto &p : _pool)
    {
        if (p == t) { _pool.erase(p); }
    }
}

template <class T>
void Pool<T>::clear()
{
    _pool.clear();
}
