#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "texture_s.h"

class TextureManager final
{
  private:
  // eventually make this scripted stuff so the thing
  // doesn't have to be recompiled all the time and can
  // be used as an engine
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
    TextureComponent *pool_;

    int img_flags = IMG_INIT_PNG;


  public:
    TextureManager(SDL_Renderer *r);
    ~TextureManager();
    void Initialize();
};
