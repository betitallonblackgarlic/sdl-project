#pragma once

#include <stdint.h>
#include <stddef.h>

class Alloc
{
  protected:
    void *start_;
    void *end_;
    size_t size_;
    Alloc(const size_t size);
    ~Alloc();
    void *GetStart() { return start_; }
    void *GetEnd() { return end_; }
    const size_t GetSize() { return size_; }
    void ExtendAlloc(size_t extendSize);
};
