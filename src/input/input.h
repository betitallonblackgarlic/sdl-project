#pragma once

#include <SDL2/SDL_events.h>

#include "../components/input_c.h"

namespace InputSystem
{
void DoInput(InputComponent &i);
void GetInput(InputComponent &i);
}; // namespace InputSystem
