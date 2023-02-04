#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "../components/render_c.h"
#include "../components/window_c.h"
#include "../components/texture_c.h"

namespace RenderSystem
{
void Init(RenderComponent &r, const WindowComponent &w);
void Render(RenderComponent &r, TextureComponent &t);
void Quit(RenderComponent &r);
}; // namespace RenderSystem
