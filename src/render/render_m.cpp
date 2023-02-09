#include <iostream>
#include <stdexcept>

#include "render_m.h"

RenderManager::RenderManager(SDL_Window *&w) : window_(w)
{
    try
    {
        renderer_ = SDL_CreateRenderer(window_, idx, render_flags);
        if (!renderer_)
        {
            throw std::runtime_error(SDL_GetError());
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "SDL failed to create rendering context. SDL_Error: ";
        std::cerr << e.what() << '\n';
    }
}

RenderManager::~RenderManager()
{
    SDL_DestroyRenderer(renderer_);
    if (!renderer_)
    {
        std::cerr << "SDL failed to destroy rendering context. Continuing shutdown. SDL_Error: " << SDL_GetError()
                  << '\n';
    }
    renderer_ = nullptr;
}

void RenderManager::Render(TextureComponent &t, DrawComponent &d)
{
    SDL_RenderCopy(renderer_, t.texture_, &t.src_, &d.dest_);
} 

SDL_Renderer *RenderManager::get_context() const
{
    return renderer_;
}
