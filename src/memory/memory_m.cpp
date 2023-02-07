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

template <typename T> void StackAllocator<T>::IncrementTop()
{
    top_++;
}

template <typename T> T *StackAllocator<T>::GetTop() const
{
    return top_;
}

template <typename T> void StackAllocator<T>::DecrementTop()
{
    top_--;
}

template <typename T> PoolAllocator<T>::PoolAllocator(size_t size)
{
}

template <typename T> PoolAllocator<T>::~PoolAllocator()
{
}
