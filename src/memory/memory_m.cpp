#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>

#include <stdlib.h>

#include "memory_m.h"

MemoryManager::MemoryManager(size_t size)
{
    heap_ = static_cast<Allocator *>(aligned_alloc(sizeof(char), size * sizeof(char)));
    last_ = heap_ + size;
    systemStack_ = new (heap_) StackAllocator(heap_, 1 << 10);
}

MemoryManager::~MemoryManager()
{

    delete systemStack_;
    heap_ = nullptr;
}

void MemoryManager::Allocate()
{
}

void MemoryManager::Deallocate()
{
}

Allocator::Allocator(void *head, size_t size) : head_(head), tail_(static_cast<char*>(head_) + size)
{
}

Allocator::Allocator(Allocator &a)
{
}

Allocator::~Allocator()
{
    head_ = nullptr;
    tail_ = nullptr;
}

void *Allocator::GetHead() const
{
    return head_;
}

void *Allocator::GetTail() const
{
    return tail_;
}

StackAllocator::StackAllocator(void *head, size_t size) : Allocator(head, size)
{
}
StackAllocator::~StackAllocator()
{
}

template <typename T> class PoolAllocator final : public Allocator
{
};
