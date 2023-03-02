#pragma once

#include <SDL2/SDL_events.h>

class Input final
{
    private:
    SDL_KeyCode p = SDLK_i;
    public:
        void DoInput(const SDL_Event &e);
};
