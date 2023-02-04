#include <stdexcept>

#include "renderer.h"

namespace RenderSystem
{
void Render(RenderComponent &r, TextureComponent &t)
{
    // do stuff to render like:
    SDL_SetRenderDrawColor(r.renderer_, 0, 0, 0, 255);
    SDL_RenderClear(r.renderer_);
    SDL_SetRenderDrawColor(r.renderer_, 255, 0, 0, 255);
    SDL_RenderFillRect(r.renderer_, &t.rect_);
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
