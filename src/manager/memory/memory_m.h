#pragma once

#include "pool.h"
#include "stack.h"

class MemoryManager
{
  private:
  public:
    MemoryManager();
    ~MemoryManager();
    void alloc();
};
