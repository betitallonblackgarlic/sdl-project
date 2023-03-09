#include "game.h"

#include <iostream>

bool Game::_running = true;

Game::Game(SDL_Window *w) : _window(w), _renderer(w)
{
    _renderer.LoadTextures();
}

Game::~Game()
{
    // do stuff maybe
}

void Game::Run()
{
    SDL_Event e;
    Uint64 framerate = 300;
    glm::vec2 prevPos;
    glm::vec2 currPos;
    double velocity = 5.0 * framerate / 1000.0;
    currPos.x = 16;
    currPos.y = 16;

    auto start = SDL_GetTicks64();
    double t = 0.0;
    double dt = 1000.0 / framerate;
    glm::vec2 pacVelocity{velocity * dt, velocity * dt};
    double accumulator = 0.0;

    _renderer.Update(currPos, prevPos, t);

    while (_running)
    {
        auto end = SDL_GetTicks64();
        auto frame_time = end - start;
        if (frame_time > 10 * dt) { frame_time = 10 * dt; }
        start = end;

        accumulator += frame_time;

        while (SDL_PollEvent(&e))
        {
            // TODO: input
            Input::DoInput(e, currPos, pacVelocity, _running);

            while (accumulator >= dt)
            {
                // do integration stuff so updates
                // only happen every 1 / FPSth second
                prevPos = currPos;

                _renderer.Integrate(pacVelocity, t, dt);

                t += dt;
                accumulator -= dt;
            }
        }

        _renderer.Update(currPos, prevPos, t);
        _renderer.PrepareScene();
        _renderer.DisplayScene();
    }
}
