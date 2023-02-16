#pragma once

#include <SDL2/SDL_image.h>

#include "component_c.h"

struct TextureComponent : Component
{
    SDL_Texture *texture = nullptr;
    SDL_Rect src;
};
