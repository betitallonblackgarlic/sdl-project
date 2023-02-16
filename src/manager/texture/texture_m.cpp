#include "texture_m.h"

#include <iostream>
#include <stdexcept>

TextureManager::TextureManager(SDL_Renderer *renderer) : _renderer(renderer)
{
    try
    {
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            throw std::runtime_error(IMG_GetError());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

TextureManager::~TextureManager()
{
    for (auto &t : _sheets)
    {
        SDL_DestroyTexture(t->texture);
        t->texture = nullptr;
        delete t;
    }
}

void TextureManager::LoadTextures()
{
    TextureComponent *t = new TextureComponent;
    t->texture = IMG_LoadTexture(_renderer, "assets/sprite_sheet.png");
    if (!t->texture) { printf("SDL ERROR: %s\n", SDL_GetError()); }
    _sheets.push_back(t);
}
