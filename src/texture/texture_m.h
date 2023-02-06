#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "texture_s.h"

using namespace TextureSystem;

class TextureManager final
{
  private:
    enum class tex_sheet
    {
        EVERYTHING,
        MAP,
        GENERAL,
        ATTRACT_HUD,
        TOTAL
    };
    // texture arrays
    SDL_Renderer *&renderer_;

    int img_flags = IMG_INIT_PNG;


  public:
    TextureManager(SDL_Renderer *r);
    ~TextureManager();
};
