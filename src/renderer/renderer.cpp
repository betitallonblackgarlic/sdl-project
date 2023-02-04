#include <stdexcept>

#include "renderer.h"

namespace RenderSystem
{
void Render(RenderComponent &r, TextureComponent &t)
{
    // do stuff to render like:
    SDL_Rect dest_rect{.x = 100, .y = 100, .w = 16*3, .h = 16*3};
    if (SDL_RenderCopy(r.renderer_, t.texture_, &t.src_rect_, &dest_rect))
    {
        printf("SDL Error: %s\n", SDL_GetError());
    }
    SDL_RenderPresent(r.renderer_);
}

void Init(RenderComponent &r, const WindowComponent &w)
{
    r.renderer_ = SDL_CreateRenderer(w.window_, r.index_, r.rFlags_);

    if (!r.renderer_)
    {
        printf("SDL failed to create window. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_SetRenderDrawColor(r.renderer_, 0, 0, 0, 255))
    {
        printf("SDL failed to set draw color. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
}

void Quit(RenderComponent &r)
{
    SDL_DestroyRenderer(r.renderer_);

    if (!r.renderer_)
    {
        printf("SDL failed to destroy renderer. SDL_Error: ");
        throw std::runtime_error(SDL_GetError());
    }
    r.renderer_ = nullptr;
}
} // namespace RenderSystem
