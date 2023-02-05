#pragma once

#include <SDL2/SDL_events.h>

enum class Player
{
    player1,
    player2,
    total_players
};

extern Player operator++(Player &p, int);

struct InputComponent
{
    Player player_;
    const Uint8 *key_state;
};
