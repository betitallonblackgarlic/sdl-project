#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <vector>

class RenderManager final
{
  private:
    SDL_Renderer *_renderer;

    // initialized here until i find a reason to initialize from an actual
    // variable
    int idx = -1;
    int render_flags = SDL_RENDERER_ACCELERATED;

  public:
    RenderManager(SDL_Window *window);
    ~RenderManager();
    void PrepareScene();
    void DisplayScene();
    SDL_Renderer *GetContext() { return _renderer; }
};
