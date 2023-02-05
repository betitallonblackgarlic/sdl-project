#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "../components/render_c.h"
#include "../components/window_c.h"
#include "../texture/texture_m.h"

class RenderManager final
{
  private:
    RenderComponent render_c;
    SDL_Window *&window_;

    // initialized here until i find a reason to initialize from an actual variable
    int idx = -1;
    int render_flags = SDL_RENDERER_ACCELERATED;

  public:
    RenderManager(SDL_Window *&w);
    ~RenderManager();
    void Render();
};
