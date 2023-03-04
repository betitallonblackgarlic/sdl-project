#pragma once
/**
 * @file window.h
 * @author Bill Black (eva.shogouki@gmail.com)
 * @brief You need a window to do literally anything with this
 * stuff so I'm initializing the most fundamental functionality
 * in here on top of creating the window
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <SDL2/SDL.h>
#include <string>

class Window final
{
  private:
    SDL_DisplayMode _dMode;
    SDL_Window *_window;

    std::string _title;

    int _sdlFlags;
    int _wFlags;
    int _scalar;

  public:
  /**
   * @brief Constructor will (hopefully) take more parameters
   * from config files and/or args for things like resolution
   * and maybe flags
   * 
   */
    Window();
    ~Window();

    SDL_Window *GetWindow() { return _window; }

    // It's not a singleton but this just seems like a good idea
    Window(const Window &) = delete;
    Window operator=(const Window &) = delete;
};
