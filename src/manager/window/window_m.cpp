#include "window_m.h"

#include <iostream>
#include <stdexcept>

WindowManager::WindowManager()
try
{
    if (SDL_Init(sdl_flags))
    {
        std::cerr << "SDL failed to initialize. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
    window_ =
        SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, dMode_.w, dMode_.h, wFlags_);
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
        std::cerr << "SDL failed to destroy window. SDL_Error: "
                  << SDL_GetError() << '\n';
    }
    window_ = nullptr;
    IMG_Quit();
    SDL_Quit();
}

void WindowManager::Run(RenderManager *r_mgr, TextureManager *t_mgr)
{
    _rend = r_mgr;
    _tex = t_mgr;

    _tex->LoadTextures();
    auto textures = _tex->GetTextures();

    SDL_Event e;

    int frames_per_second = 60;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    int frame = 0;

    while (running_)
    {
        double new_time = SDL_GetTicks64() / 1000.0;
        double frame_time = new_time - current_time;

        if (frame_time > 0.25) { frame_time = 0.25; }
        current_time = new_time;

        accumulator += frame_time;

        _rend->PrepareScene();

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
        for (auto t : textures) { _rend->Render(t, _d); }
        _rend->DisplayScene();
    }
}
