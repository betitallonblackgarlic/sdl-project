/**
 * @file linuxmain.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <exception>
#include <iostream>

#include "renderer/renderer_s.h"
#include "texture/texture_s.h"
#include "window/window_s.h"

static WindowComponent window;
static RenderComponent renderer;
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

    // no need for custom exceptions, functions can have different problems
    // so for simplicity they print internally and throw std::runtime_error(SDL_Error())
    try
    {
        if (SDL_Init(SDL_INIT_EVERYTHING))
        {
            printf("SDL failed to initialize. SDL_Error: ");
            throw std::runtime_error(SDL_GetError());
        }
        if (!(IMG_Init(renderer.imgFlags_) && renderer.imgFlags_))
        {
            printf("Failed to initialize SDL_image. IMG_Error: ");
            throw std::runtime_error(IMG_GetError());
        }
        WindowSystem::Init(window);
        RenderSystem::Init(renderer, window);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';

        return EXIT_FAILURE;
    }

    // do update and render stuff
    WindowSystem::Run(window, renderer);

    try
    {
        RenderSystem::Quit(renderer);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        WindowSystem::Quit(window);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}
