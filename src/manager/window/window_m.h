
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
    const int _scalar = 3;
    
    SDL_DisplayMode _d_mode{.w = 224 * _scalar, .h = 288 * _scalar};
    SDL_Window *_window = nullptr;

    std::string _title = "Window";

    int _sdl_flags = SDL_INIT_EVERYTHING;
    int _w_flags = SDL_WINDOW_SHOWN;

    bool running_ = true;

  public:
    WindowManager();
    ~WindowManager();
    void Run();
};
