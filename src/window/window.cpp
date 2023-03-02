#include "window.h"

#include <iostream>
#include <stdexcept>

Window::Window()
    : _dMode(SDL_DisplayMode{.w = 224 * 3, .h = 288 * 3}), _window(nullptr),
      _title("Window"), _sdlFlags(SDL_INIT_EVERYTHING),
      _wFlags(SDL_WINDOW_SHOWN), _scalar(3), _running(true)
{
    try
    {
        if (SDL_Init(_sdlFlags))
        {
            std::cerr << "SDL failed to initialize. SDL_Error: ";
            throw std::runtime_error(SDL_GetError());
        }
        _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, _dMode.w, _dMode.h,
                                   _wFlags);
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
}

Window::~Window()
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

// moving main loop out of Window class (into GameState class?)


