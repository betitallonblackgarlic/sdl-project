#pragma once

#include <SDL2/SDL_image.h>

class TextureManager
{
  private:
    enum Sheets
    {
        GENERAL,
        TOTAL
    };
    
    SDL_Texture *_texture_sheets;
    int _flags = IMG_INIT_PNG | IMG_INIT_JPG;

  public:
    TextureManager();
    void LoadTextures(SDL_Renderer *renderer);
};
