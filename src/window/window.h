#pragma once

#include <SDL2/SDL.h>
#include <string>

/**
 * @brief Core management class that manages the window as well as
 * orchaestration of other top-level managers
 *
 */
class Window final
{
  private:
    SDL_DisplayMode _dMode;
    SDL_Window *_window;

    std::string _title;

    int _sdlFlags;
    int _wFlags;
    int _scalar;

    bool _running;

  public:
    Window();
    ~Window();

    SDL_Window *GetWindow() { return _window; }

    Window(const Window &) = delete;
    void operator=(const Window &) = delete;
};
