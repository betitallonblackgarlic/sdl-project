
#include <SDL2/SDL.h>
#include <string>

#include "../render/render_m.h"
#include "../texture/texture_m.h"

/**
 * @brief Core management class that manages the window as well as
 * orchaestration of other top-level managers
 *
 */
class WindowManager final
{
  private:
    const int scalar = 3;
    SDL_DisplayMode dMode_{.w = 224 * scalar, .h = 288 * scalar};
    SDL_Window *window_;

    RenderManager *_rend;
    TextureManager *_tex;

    DrawComponent _d;

    std::string title_ = "Hello!";

    int sdl_flags = SDL_INIT_EVERYTHING;
    int wFlags_;

    bool running_ = true;

  public:
    WindowManager();
    ~WindowManager();
    void Run(RenderManager *r, TextureManager *t);

    SDL_Window *GetWindow() { return window_; }
};
