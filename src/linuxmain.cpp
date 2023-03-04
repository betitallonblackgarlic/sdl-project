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
#include "window/window.h"
#include "game/game.h"

#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
discontinuing a "window manager" and just setting it up as a basic
system while removing all other game-related functionality
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(const int argc, const char **argv)
{
    if (argc)
    {
        // do arg stuff
    }

    // TODO: maybe do config stuff for window parameters
    // Won't need lazy initialization if instantiating statics in main
    // Screw singleton, I don't need access to any of this stuff anywhere
    // and where I do, it's easily passable

    static Window window;
    static Game game(window.GetWindow());

    game.Run();
    

    return EXIT_SUCCESS;
}
