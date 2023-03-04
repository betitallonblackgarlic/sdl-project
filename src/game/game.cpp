#include "game.h"

bool Game::_running = true;

Game::~Game()
{
    // do stuff maybe
}

void Game::Run()
{
    SDL_Event e;

    while (_running)
    {
        // prepareScene();
        while (SDL_PollEvent(&e))
        {
            // TODO: input
            Input::DoInput(e, _running);
        }
        // update();
        // presentScene();
    }
}

