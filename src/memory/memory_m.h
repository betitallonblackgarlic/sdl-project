#pragma once

#include <iostream>
#include <stddef.h>

#include "../components/texture_c.h"

const int MAX_POOLS = 20;
const int MAX_STACKS = 10;

class Allocator
{

  private:
    void *head_;
    void *tail_;

  public:
  Allocator(void *head, size_t size);
  Allocator(Allocator &a);
  ~Allocator();

  void *GetHead() const;
  void *GetTail() const;
};

class MemoryManager final
{
  public:
    size_t size_;
    Allocator *heap_;
    Allocator *last_;
    Allocator *pools_[MAX_POOLS]{nullptr};
    Allocator *stacks_[MAX_STACKS]{nullptr};
    Allocator *systemStack_{nullptr};

  public:
    MemoryManager(size_t size);
    ~MemoryManager();
    void Allocate();
    void Deallocate();
};

class StackAllocator final : public Allocator
{
  public:
    StackAllocator(void *head, size_t size);
    ~StackAllocator();
};
