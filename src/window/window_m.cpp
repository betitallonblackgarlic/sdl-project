#include <iostream>
#include <stdexcept>

#include "window_m.h"

WindowManager::WindowManager()
{
    try
    {
        if (SDL_Init(sdl_flags))
        {
            printf("SDL failed to initialize. SDL_Error: ");
            throw std::runtime_error(SDL_GetError());
        }
        window_c.window_ = SDL_CreateWindow(window_c.wTitle_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            window_c.dMode_.w, window_c.dMode_.h, window_c.wFlags_);
        if (!window_c.window_)
        {
            printf("SDL failed to create window. SDL_Error: ");
            throw std::runtime_error(SDL_GetError());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';

        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

WindowManager::~WindowManager()
{
    SDL_DestroyWindow(window_c.window_);
    if (!window_c.window_)
    {
        printf("SDL failed to destroy window. SDL_Error: %s\n", SDL_GetError());
    }
    window_c.window_ = nullptr;
    SDL_Quit();
}

void WindowManager::Run()
{
    static RenderManager render_mgr(window_c.window_);

    SDL_Event e;

    int frames_per_second = 60;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    while (window_c.running_)
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
                window_c.running_ = false;
                break;
            case SDL_KEYDOWN:
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
