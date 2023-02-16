#pragma once

#include "../../component/texture_c.h"

#include <vector>

class TextureManager
{
  private:
    std::vector<TextureComponent *> _sheets;

    SDL_Renderer *&_renderer;

  public:
    TextureManager(SDL_Renderer *renderer);
    ~TextureManager();

    void LoadTextures();
    std::vector<TextureComponent *> &GetTextures() { return _sheets; }

};
