#include <iostream>
#include <stdexcept>

#include "window.h"
#include "../renderer/renderer.h"
#include "../texture/texture.h"

namespace WindowSystem
{
void Init(WindowComponent &w)
{
    w.window_ = SDL_CreateWindow(w.wTitle_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w.dMode_.w,
                                 w.dMode_.h, w.wFlags_);
    if (!w.window_)
    {
        printf("SDL failed to create window. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
}

void Run(WindowComponent &w, RenderComponent &r)
{
    SDL_Event e;

    TextureComponent tex;
    
    TextureSystem::CreateRect(tex);

    int frames_per_second = 60;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    while (w.running_)
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
                w.running_ = false;
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
        RenderSystem::Render(r, tex);
    }
}

void Quit(WindowComponent &w)
{
    SDL_DestroyWindow(w.window_);
    if (!w.window_)
    {
        printf("SDL failed to destroy window. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
    w.window_ = nullptr;
}
} // namespace WindowSystem
