#include "game.h"

bool Game::_running = true;

void Game::Run()
{
    SDL_Event e;

    while (_running)
    {
        while (SDL_PollEvent(&e))
        {
            // TODO: input
            switch (e.type)
            {
                case SDL_QUIT:
                    _running = false;
                    break;
                case SDL_KEYDOWN:
                    // handle keydown
                    break;
                case SDL_KEYUP:
                    // handle keyup
                    break;
                // do mouse stuff eventually
                default:
                    break;
            }
        }
    }
}