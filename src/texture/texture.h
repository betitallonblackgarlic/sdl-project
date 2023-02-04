#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

#include "../components/texture_c.h"
#include "../components/render_c.h"

namespace TextureSystem
{
void CreateRect(TextureComponent &t);
void CreateTexture(TextureComponent &t, RenderComponent &r, const char *filename);
TextureComponent ExtractSprite(TextureComponent &t);
} // namespace TextureSystem