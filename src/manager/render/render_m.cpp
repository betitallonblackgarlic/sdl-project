#include "render_m.h"

#include <iostream>
#include <stdexcept>

RenderManager::RenderManager(SDL_Window *w) : _window(w)
{
    try
    {
        _renderer = SDL_CreateRenderer(_window, idx, render_flags);
        if (!_renderer) { throw std::runtime_error(SDL_GetError()); }
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    }
    catch (std::exception &e)
    {
        std::cerr << "SDL failed to create rendering context. SDL_Error: ";
        std::cerr << e.what() << '\n';
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

void RenderManager::Render(TextureComponent *t, DrawComponent &d)
{
    if (SDL_RenderCopy(_renderer, t->texture, NULL, NULL))
    {
        printf("SDL ERROR: %s\n", SDL_GetError());
    }
}

void RenderManager::DisplayScene() { SDL_RenderPresent(_renderer); }
