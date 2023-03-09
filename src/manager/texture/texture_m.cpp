#include "texture_m.h"

#include <exception>
#include <iostream>

TextureManager::TextureManager()
{
    try
    {
        if (!(IMG_Init(_flags) & _flags))
        {
            throw std::runtime_error(IMG_GetError());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void TextureManager::LoadTextures(SDL_Renderer *renderer)
{
    _texture_sheets = IMG_LoadTexture(renderer, "assets/general_sheet.png");
}
