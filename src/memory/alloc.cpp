#include "alloc.h"

#include <stdlib.h>
#include <iostream>

Alloc::Alloc(const size_t size) : size_(size)
{
    start_ = aligned_alloc(8, size_);
    end_ =
        reinterpret_cast<void *>(reinterpret_cast<size_t>(start_) + size_);
}

Alloc::~Alloc() { free(start_); }

void Alloc::ExtendAlloc(size_t extendSize)
{
    size_ += extendSize;
    start_ = realloc(start_, size_);
    end_ =
        reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(start_) + size_);
}
