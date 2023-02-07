#pragma once

#include <stddef.h>
#include <iostream>

#include "../components/texture_c.h"

class MemoryManager
{
  private:
  public:
    MemoryManager();
    ~MemoryManager();
};

/**
 * @brief I think I'm going to try to design
 * a class that can be used as a regular stack,
 * a double buffered allocator, and maybe a
 * double-ended bottom-up/top-down allocator
 * using different functions
 *
 * Or maybe I'll create a base and inherit
 * to create the other two
 * It wouldn't be a tangled inheritance mess to
 * *final* the others
 *
 * @tparam T
 */
template <typename T> class StackAllocator
{
  private:
    void *stack_;
    T *top_;

    const size_t size_;

    void IncrementTop();
    T *GetTop() const;
    void DecrementTop();

  public:
    StackAllocator(const size_t size);
    ~StackAllocator();

    inline void *operator new(size_t nbytes);

    inline void operator delete(void *p);

    void Clear()
    {
        top_ = reinterpret_cast<T*>(stack_);
    }

    void Allocate(int num);
    void Deallocate();
};

/**
 * @brief Start with pool because I want to begin with
 * textures, plus probably everything should be AVAILABLE
 * to push onto the stack allocator, or i could do a whole
 * lot of placement new() and try to use the stack allocator
 * for almost everything
 *
 * @tparam T
 */
template <typename T> class PoolAllocator
{
  private:
    PoolAllocator(size_t size);
    ~PoolAllocator();

  public:
};

template <typename T> void *StackAllocator<T>::operator new(size_t nbytes)
{
    T *newObject = GetTop();
    IncrementTop();
    return newObject;
}

template <typename T> void StackAllocator<T>::operator delete(void *p)
{
    if (p)
    {
        if (T* t = GetTop())
        {
            t->dealloc(p);
        }
        else
        {
            free(p);
        }
    }
    DecrementTop();
}

template <typename T> StackAllocator<T>::StackAllocator(const size_t size) : size_(size)
{
    try
    {
        stack_ = aligned_alloc(sizeof(T), size);
        top_ = reinterpret_cast<T*>(stack_);
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
}

template <typename T> StackAllocator<T>::~StackAllocator()
{
    Deallocate();
}

template <typename T> void StackAllocator<T>::Allocate(int num)
{
    TextureComponent *p;
    for (int i = 0 ; i < num ; ++i)
        p = new(top_) TextureComponent();
    p->src_ = SDL_Rect();
}

template <typename T> void StackAllocator<T>::Deallocate()
{
    Clear();
    free(stack_);
    stack_ = nullptr;
}
