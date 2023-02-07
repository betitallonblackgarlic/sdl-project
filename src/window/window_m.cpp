#include <iostream>
#include <stdexcept>

#include "window_m.h"

#include "../render/render_m.h"
#include "../texture/texture_m.h"
#include "../memory/memory_m.h"

WindowManager::WindowManager()
try
{
    if (SDL_Init(sdl_flags))
    {
        std::cerr << "SDL failed to initialize. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
    window_ =
        SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dMode_.w, dMode_.h, wFlags_);
    if (!window_)
    {
        std::cerr << "SDL failed to create window. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';

    SDL_Quit();
    exit(EXIT_FAILURE);
}

WindowManager::~WindowManager()
{
    SDL_DestroyWindow(window_);
    if (!window_)
    {
        std::cerr << "SDL failed to destroy window. SDL_Error: " << SDL_GetError() << '\n';
    }
    window_ = nullptr;
    SDL_Quit();
}

void WindowManager::Run()
{
    static RenderManager render_mgr(window_);
    static TextureManager texture_mgr(render_mgr.get_context());
    StackAllocator<TextureComponent> textures(sizeof(TextureComponent) * 1000);

    SDL_Event e;

    int frames_per_second = 60;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    textures.Allocate(10);

    while (running_)
    {
        double new_time = SDL_GetTicks64() / 1000.0;
        double frame_time = new_time - current_time;

        if (frame_time > 0.25)
        {
            frame_time = 0.25;
        }
        current_time = new_time;

        accumulator += frame_time;

        while (SDL_PollEvent(&e))
        {
            // TODO: input
            switch (e.type)
            {
            case SDL_QUIT:
                running_ = false;
                break;
            case SDL_KEYDOWN:
                textures.Deallocate();
                break;
            default:
                break;
            }
        }

        while (accumulator >= dt)
        {
            // TODO: integration of state
            t += dt;
            accumulator -= dt;
        }

        // const double alpha = accumulator / dt;
        // TODO: interpolation, update, render
    }
}
