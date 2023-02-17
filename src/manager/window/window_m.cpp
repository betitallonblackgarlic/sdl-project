#include "window_m.h"

#include <iostream>
#include <stdexcept>

WindowManager::WindowManager()
try
{
    if (SDL_Init(_sdl_flags))
    {
        std::cerr << "SDL failed to initialize. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, _d_mode.w, _d_mode.h,
                               _w_flags);
    if (!_window)
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
    SDL_DestroyWindow(_window);
    if (!_window)
    {
        std::cerr << "SDL failed to destroy window. SDL_Error: "
                  << SDL_GetError() << '\n';
    }
    _window = nullptr;
    SDL_Quit();
}

void WindowManager::Run()
{
    SDL_Event e;

    double frames_per_second = 60.0;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    while (running_)
    {
        double new_time = SDL_GetTicks64() / 1000.0;
        double frame_time = new_time - current_time;

        if (frame_time > 0.25) { frame_time = 0.25; }
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
