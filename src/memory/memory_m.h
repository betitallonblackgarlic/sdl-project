#pragma once

#include <stddef.h>

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

    size_t size_;

  public:
    StackAllocator(size_t size);
    ~StackAllocator();

    inline void *operator new(size_t nbytes);
    inline void operator delete(void *p);
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
