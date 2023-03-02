#pragma once

#include <SDL2/SDL_events.h>

#include "../input/input.h"

class Game final
{
  private:
    static bool _running;
  public:
    void Run();
};
