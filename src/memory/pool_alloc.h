#pragma once

#include "alloc.h"

#include <iostream>

template <typename T>
class PoolAlloc : public Alloc
{
  private:
    union State;
    size_t elements_;
    size_t available_;
    State *firstAvailable_;

    union State
    {
        T t;
        State *next;
        explicit State(State *next) { this->next = next; }
    };

  public:
    PoolAlloc(const size_t size);
    ~PoolAlloc();
    void Allocate(T t);
    void Deallocate(T t);
    void Find(T t);
};

template <typename T>
PoolAlloc<T>::PoolAlloc(const size_t size)
    : Alloc(size * sizeof(T)), elements_(size), available_(elements_),
      firstAvailable_(static_cast<State *>(start_))
{
    State *ptr = new (firstAvailable_) State(firstAvailable_ + 1);
    State *end = static_cast<State *>(GetEnd());

    for (; ptr < end - 1; ptr++)
    {
        ptr->next = new (ptr->next) State(ptr->next + 1);
    }
    ptr->next = new (ptr->next) State(nullptr);
}

template <typename T>
PoolAlloc<T>::~PoolAlloc()
{}

template <typename T>
void PoolAlloc<T>::Allocate(T t)
{
    if (!firstAvailable_) { return; } // do "CAN'T ALLOCATE THAT SHIT" stuff
    --available_;
    State *nextAvailable = firstAvailable_->next;
    firstAvailable_->t = t;
    firstAvailable_ = nextAvailable;
}

template <typename T>
void PoolAlloc<T>::Deallocate(T t)
{}

template <typename T>
void PoolAlloc<T>::Find(T t)
{}
