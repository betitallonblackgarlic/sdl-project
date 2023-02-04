#pragma once
/**
 * @file system.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>

#include <SDL2/SDL.h>
#include "../renderer/renderer.h"

namespace WindowSystem
{
void Init(WindowComponent &w);
void Run(WindowComponent &w, RenderComponent &r);
void Quit(WindowComponent &w);
}; // namespace WindowSystem
