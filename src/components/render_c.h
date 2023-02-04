#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

struct RenderComponent
{
    SDL_Renderer *renderer_ = nullptr;

    int index_ = -1;
    int rFlags_ = SDL_RENDERER_ACCELERATED;
    int imgFlags_ = IMG_INIT_PNG | IMG_INIT_JPG;
};