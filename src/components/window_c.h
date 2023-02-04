#pragma once

#include <string>

#include <SDL2/SDL_video.h>

struct WindowComponent
{
    SDL_Window *window_ = nullptr;
    SDL_DisplayMode dMode_{.w = 800, .h = 600, .refresh_rate = 60};

    std::string wTitle_ = "Hello!";

    int wFlags_ = SDL_WINDOW_SHOWN;
    int running_ = true;
};