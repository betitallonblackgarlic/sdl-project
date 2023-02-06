#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "../texture/texture_m.h"

class RenderManager final
{
  private:
    SDL_Renderer *renderer_;
    SDL_Window *&window_;

    // initialized here until i find a reason to initialize from an actual variable
    int idx = -1;
    int render_flags = SDL_RENDERER_ACCELERATED;

  public:
    RenderManager(SDL_Window *&w);
    ~RenderManager();
    SDL_Renderer *get_context() const;
};
