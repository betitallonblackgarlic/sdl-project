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
#include "manager/window/window_m.h"

#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Going to try scoping static window manager to main and maybe write
game loop in global game state, see how that works
Singletons are apparently completely unnecessary in game design so
if I make gamestate globally accessible, should I just make it static?
I think instead of using an assert to completely shut down an instance
if it's already instantiated may be unnecessary. I could use a try/catch
block to prevent the class from instantiating, so I wonder if there's a
real drawback there. Any calls to that instance would therefore be invalid
so making a call to it would probably error if you try calling it after
it fails to initialize. But I might be able to use the try/catch to redirect
it to the first instance
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(const int argc, const char **argv)
{
    if (argc)
    {
        // do arg stuff
    }

    /* TODO: maybe do config stuff for window parameters
    Won't need lazy in that case since the execution order is now linear */

    static WindowManager w_mgr;

    w_mgr.Run();

    return EXIT_SUCCESS;
}
