#include <stdexcept>

#include "texture.h"

namespace TextureSystem
{

void CreateRect(TextureComponent &t)
{
    t.rect_ = SDL_Rect{.x = 50, .y = 50, .w = 100, .h = 100};
}

void CreateTexture(TextureComponent &t, const RenderComponent &r)
{
    t.texture_ = IMG_LoadTexture(r.renderer_, t.filename_.c_str());
    if (!t.texture_)
    {
        printf("Failed to load texture %s. IMG_Error: ", t.filename_.c_str());
        throw std::runtime_error(IMG_GetError());
    }
}
} // namespace TextureSystem
