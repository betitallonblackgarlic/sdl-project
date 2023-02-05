#include <stdexcept>

#include "render_m.h"

RenderManager::RenderManager(SDL_Window *&w) : window_(w)
{
    render_c.renderer_ = SDL_CreateRenderer(window_, idx, render_flags);
    if (!render_c.renderer_)
    {
        printf("SDL failed to create rendering context. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
}

RenderManager::~RenderManager()
{
    SDL_DestroyRenderer(render_c.renderer_);
    if (!render_c.renderer_)
    {
        printf("SDL failed to destroy rendering context. Continuing shutdown. SDL_Error: %s\n", SDL_GetError());
    }
    render_c.renderer_ = nullptr;
}

void RenderManager::Render()
{
    static TextureManager texture_mgr(render_c.renderer_);
}
