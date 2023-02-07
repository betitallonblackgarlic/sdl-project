#include <exception>
#include <iostream>
#include <stdexcept>

#include <stdlib.h>

#include "memory_m.h"

MemoryManager::MemoryManager()
{
}

MemoryManager::~MemoryManager()
{
}

template <typename T> StackAllocator<T>::StackAllocator(size_t size)
try
{
    stack_ = aligned_alloc(sizeof(T), size);
    top_ = reinterpret_cast<T>(stack_);
    if (!stack_)
    {
        throw std::runtime_error("bad thing happened and memory couldn't allocate");
    }
}
catch (std::runtime_error &e)
{
    free(stack_);
    std::cerr << e.what() << '\n';
}

template <typename T> StackAllocator<T>::~StackAllocator()
{
    free(stack_);
    stack_ = nullptr;
}

template <typename T> void *StackAllocator<T>::operator new(size_t nbytes)
{
    T *newObject = top_;
    top_ += nbytes;
    return newObject;
}

template <typename T> void StackAllocator<T>::operator delete(void *p)
{
    top_ -= sizeof(T);
}

template <typename T> PoolAllocator<T>::PoolAllocator(size_t size)
{
}

template <typename T> PoolAllocator<T>::~PoolAllocator()
{
}
