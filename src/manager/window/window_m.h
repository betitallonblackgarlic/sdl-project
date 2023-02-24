#pragma once

#include "../render/render_m.h"
#include "../texture/texture_m.h"

#include <SDL2/SDL.h>
#include <string>

/**
 * @brief Core management class that manages the window as well as
 * orchaestration of other top-level managers
 *
 */
class WindowManager final
{
  private:
    SDL_DisplayMode _d_mode;
    SDL_Window *_window;

    std::string _title;

    int _sdl_flags;
    int _w_flags;
    int _scalar;

    bool _running;

  public:
    WindowManager();
    ~WindowManager();

    SDL_Window *GetWindow() { return _window; }

    WindowManager(const WindowManager &) = delete;
    void operator=(const WindowManager &) = delete;

    void Run();
};
