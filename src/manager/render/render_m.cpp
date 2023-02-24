#include "render_m.h"

#include <iostream>
#include <stdexcept>

RenderManager::RenderManager(SDL_Window *window)
{
    try
    {
        _renderer = SDL_CreateRenderer(window, idx, render_flags);
        if (!_renderer) { throw std::runtime_error(SDL_GetError()); }
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    }
    catch (std::exception &e)
    {
        std::cerr << "SDL failed to create rendering context. SDL_Error: ";
        std::cerr << e.what() << '\n';

        throw e;
    }
}

RenderManager::~RenderManager()
{
    SDL_DestroyRenderer(_renderer);
    if (!_renderer)
    {
        std::cerr << "SDL failed to destroy rendering context. Continuing "
                     "shutdown. SDL_Error: "
                  << SDL_GetError() << '\n';
    }
    _renderer = nullptr;
}

void RenderManager::PrepareScene() { SDL_RenderClear(_renderer); }

void RenderManager::DisplayScene() { SDL_RenderPresent(_renderer); }
