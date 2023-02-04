#pragma once

#include <string>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

struct TextureComponent
{
    SDL_Texture *texture_ = nullptr;
    SDL_Rect src_rect_;
    SDL_Rect dest_rect_;

    int padding_ = 0;
};
