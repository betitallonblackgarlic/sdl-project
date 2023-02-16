#pragma once

#include "../../component/draw_c.h"
#include "../../component/texture_c.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <vector>

class RenderManager final
{
  private:
    SDL_Renderer *_renderer;
    SDL_Window *&_window;

    // initialized here until i find a reason to initialize from an actual
    // variable
    int idx = -1;
    int render_flags = SDL_RENDERER_ACCELERATED;

  public:
    RenderManager(SDL_Window *w);
    ~RenderManager();
    void PrepareScene();
    void Render(TextureComponent *t, DrawComponent &d);
    void DisplayScene();
    SDL_Renderer *GetContext() { return _renderer; }
};
