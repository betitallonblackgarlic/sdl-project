#include <iostream>
#include <stdexcept>

#include "texture_m.h"

TextureManager::TextureManager(SDL_Renderer *r) : renderer_(r)
{
    try
    {
        if (!(IMG_Init(img_flags) && img_flags))
        {
            throw std::runtime_error(IMG_GetError());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "SDL_image failed to initialize. IMG_Error: ";
        std::cerr << e.what() << '\n';
    }
}

TextureManager::~TextureManager()
{
    IMG_Quit();
}
