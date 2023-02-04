#include <stdexcept>

#include "texture.h"

namespace TextureSystem
{

void CreateRect(TextureComponent &t)
{
    t.src_rect_ = SDL_Rect{.x = 50, .y = 50, .w = 100, .h = 100};
}

void CreateTexture(TextureComponent &t, RenderComponent &r, const char *filename)
{
    t.texture_ = IMG_LoadTexture(r.renderer_, filename);
    if (!t.texture_)
    {
        printf("Failed to load texture %s. IMG_Error: ", filename);
        throw std::runtime_error(IMG_GetError());
    }
}

TextureComponent ExtractSprite(TextureComponent &t)
{
    TextureComponent new_texture;
    new_texture.texture_ = t.texture_;
    new_texture.src_rect_ = SDL_Rect{.x = 1, .y = 9 * 9 + 2, .w = 16, .h = 16};    

    return new_texture;
}
} // namespace TextureSystem
