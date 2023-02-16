#include "window_m.h"

#include <iostream>
#include <stdexcept>

WindowManager::WindowManager()
try
{
    if (SDL_Init(sdl_flags))
    {
        std::cerr << "SDL failed to initialize. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
    window_ =
        SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, dMode_.w, dMode_.h, wFlags_);
    if (!window_)
    {
        std::cerr << "SDL failed to create window. SDL_Error: ";
        throw std::runtime_error(SDL_GetError());
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "Mixer failed to initialize. Mixer_Error: ";
        throw std::runtime_error(Mix_GetError());
    }
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';

    SDL_Quit();
    exit(EXIT_FAILURE);
}

WindowManager::~WindowManager()
{
    SDL_DestroyWindow(window_);
    if (!window_)
    {
        std::cerr << "SDL failed to destroy window. SDL_Error: "
                  << SDL_GetError() << '\n';
    }
    window_ = nullptr;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void WindowManager::Run(RenderManager *r_mgr, TextureManager *t_mgr)
{
    _rend = r_mgr;
    _tex = t_mgr;

    _tex->LoadTextures();
    auto textures = _tex->GetTextures();

    Mix_Music *_music = nullptr;
    Mix_Chunk *_wakkawakka1 = nullptr;
    Mix_Chunk *_wakkawakka2 = nullptr;

    _music = Mix_LoadMUS("assets/game_start.wav");
    if (!_music) { printf("Failed to load music: %s\n", Mix_GetError()); }

    _wakkawakka1 = Mix_LoadWAV("assets/munch_1.wav");
    if (!_wakkawakka1)
    {
        printf("Failed to load wakkawakka1: %s\n", Mix_GetError());
    }

    _wakkawakka2 = Mix_LoadWAV("assets/munch_2.wav");
    if (!_wakkawakka2)
    {
        printf("Failed to load wakkawakka2: %s\n", Mix_GetError());
    }

    Mix_Chunk *_chunks[2];
    _chunks[0] = _wakkawakka2;
    _chunks[1] = _wakkawakka1;

    SDL_Event e;

    int frames_per_second = 60;

    double t = 0.0;
    double dt = 1.0 / frames_per_second;

    double current_time = SDL_GetTicks64() / 1000.0;
    double accumulator = 0.0;

    int frame = 0;

    while (running_)
    {
        double new_time = SDL_GetTicks64() / 1000.0;
        double frame_time = new_time - current_time;

        if (frame_time > 0.25) { frame_time = 0.25; }
        current_time = new_time;

        accumulator += frame_time;

        _rend->PrepareScene();

        while (SDL_PollEvent(&e))
        {
            // TODO: input
            switch (e.type)
            {
                case SDL_QUIT:
                    running_ = false;
                    break;
                case SDL_KEYDOWN:
                    if (!Mix_PlayingMusic()) { Mix_PlayMusic(_music, 1); }
                    else
                    {
                        if (Mix_PausedMusic()) { Mix_ResumeMusic(); }
                        else { (Mix_PauseMusic()); }
                    }
                    break;
                default:
                    break;
            }
        }

        Mix_PlayChannel(-1, _chunks[frame % 2], 0);
        frame++;
        if (frame % 2) { SDL_Delay(100); }
        else { SDL_Delay(150); }

        while (accumulator >= dt)
        {
            // TODO: integration of state
            t += dt;
            accumulator -= dt;
        }

        // const double alpha = accumulator / dt;
        // TODO: interpolation, update, render
        for (auto t : textures) { _rend->Render(t, _d); }
        _rend->DisplayScene();
    }

    Mix_FreeMusic(_music);
}
