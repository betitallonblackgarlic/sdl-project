#include <stdexcept>

#include "texture_m.h"

TextureManager::TextureManager(SDL_Renderer *&r) : renderer_(r)
{
    if (IMG_Init(img_flags))
    {
        printf("SDL_image failed to initialize. IMG_Error: ");
        throw std::runtime_error(IMG_GetError());
    }

    pool_ =
        static_cast<TextureComponent *>(aligned_alloc(sizeof(TextureComponent),
        sizeof(TextureComponent) * (static_cast<int>(tex_sheet::TOTAL) + 2)));

    TextureComponent *ptr = pool_;
    for (int i = 0; i < static_cast<int>(Sheet::total_sheets) - 1; ++i)
    {
        ptr->next_ = ptr + sizeof(TextureComponent);
        ptr = ptr->next_;
    }

    ptr = pool_;

    while (ptr)
    {
        ptr = ptr->next_;
    }
}

TextureManager::~TextureManager()
{
    free(pool_);
    pool_ = nullptr;
    IMG_Quit();
}
