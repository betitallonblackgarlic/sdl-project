#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

#include "../components/texture_c.h"

namespace TextureSystem
{
SDL_Texture *CreateTexture(SDL_Renderer *&r, const char *filename);
void DestroyTexture(TextureComponent &t);
} // namespace TextureSystem