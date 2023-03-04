/**
 * @file game.h
 * @author your name (you@domain.com)
 * @brief I think I'll try using this as the thing
 * that ties all the top-level classes together
 * @version 0.1
 * @date 2023-03-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "../input/input.h"
#include "../window/window.h"

#include <SDL2/SDL_events.h>

class Game final
{
  private:
    SDL_Window *_window;

  protected:
    static bool _running;

    // I can request pretty much every window parameter through SDL
    // so I'm not going to bother passing the entire class
    // I'm just using that for setup parameters
    // potentially from config files if I get that far
  public:
    Game(SDL_Window *w) : _window(w) {}
    ~Game();
    void Run();
    Game(const Game &g) = delete;
    Game operator=(const Game &g) = delete;

    friend class Input;
};
