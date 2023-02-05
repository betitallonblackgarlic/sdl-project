#include <stdexcept>

#include "texture_s.h"

Sheet operator++(Sheet &s, int)
{
    if (s == Sheet::total_sheets)
    {
        return s;
    }
    else
    {
        s = static_cast<Sheet>(static_cast<int>(s) + 1);
        return s;
    }
}

namespace TextureSystem
{

SDL_Texture *CreateTexture(SDL_Renderer *&r, const char *filename)
{
    SDL_Texture *t = IMG_LoadTexture(r, filename);
    if (!t)
    {
        printf("SDL_image failed to load texture %s. IMG_Error: ", filename);
    }
    return t;
}

void DestroyTexture(TextureComponent &t)
{
    SDL_DestroyTexture(t.texture_);
    if (!t.texture_)
    {
        printf("SDL failed to destroy texture. SDL_Error: %s\n", SDL_GetError());
    }
    t.texture_ = nullptr;
}
} // namespace TextureSystem
