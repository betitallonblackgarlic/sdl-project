#pragma once

#include <SDL2/SDL_events.h>

#include "component_c.h"

enum class Player
{
    player1,
    player2,
    total_players
};

struct InputComponent : public Component
{
    Player player_;
    const Uint8 *key_state;
};
