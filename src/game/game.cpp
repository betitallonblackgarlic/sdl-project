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
    Uint64 framerate = 30;
    Vec2 prevpos;
    Vec2 pacpos;
    pacpos.x = 16;
    pacpos.y = 16;

    auto start = SDL_GetTicks64();
    double t = 0.0;
    double dt = 1000.0 / framerate;
    double accumulator = 0.0;
    _renderer.Update(pacpos);

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
            Input::DoInput(e, _running);
        }

        while (accumulator >= dt)
        {
            // do integration stuff so updates
            // only happen every 1 / FPSth second
            prevpos = pacpos;
            pacpos.x += 60 * dt / 1000;

            _renderer.Integrate(pacpos, t, dt);
            std::cout << t << '\n';

            t += dt;
            accumulator -= dt;
        }

        _renderer.Update(pacpos);
        _renderer.PrepareScene();
        _renderer.DisplayScene();
    }
}
