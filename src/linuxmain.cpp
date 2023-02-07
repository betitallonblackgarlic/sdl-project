/**
 * @file linuxmain.cpp
 * @author Bill Black (william.black@colorado.edu)
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

#include "memory/memory_m.h"
// there's only ever one window, and should only be one window
// so is this okay to make it a static global? is this a singleton?
// I want to practice different usages and implementations
const int MB = 1<<20;
static MemoryManager mgr(30*MB);
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Does ECS architecture actually make sense for window and renderer,  *
 * and does it make sense I declared them as global statics            *
 * since there's only supposed to be one of each?                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(const int argc, const char **argv)
{
    if (argc)
    {
        // do arg stuff
    }

    return EXIT_SUCCESS;
}

// maybe add arg handling or whatever to make the main function look like an actual function
