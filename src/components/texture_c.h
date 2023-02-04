#pragma once

#include <string>

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_image.h>

struct TextureComponent
{
    SDL_Texture *texture_ = nullptr;
    SDL_Rect rect_;

    const std::string filename_;
};
