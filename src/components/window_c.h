#pragma once

#include <string>

#include <SDL2/SDL_video.h>

struct WindowComponent
{
    SDL_DisplayMode dMode_{.w = 224*3, .h = 288*3, .refresh_rate = 60};
    SDL_Window *window_ = nullptr;

    std::string wTitle_ = "Hello!";

    int wFlags_ = 0;
    int running_ = true;
};