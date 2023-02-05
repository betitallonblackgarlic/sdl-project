#include <iostream>

#include "input_s.h"

Player operator++(Player &p, int)
{
    if (p == Player::total_players)
    {
        return p;
    }
    else
    {
        p = static_cast<Player>(static_cast<int>(p) + 1);
        return p;
    }
}

namespace InputSystem
{
void CreateInput(InputComponent *&i, Player p)
{
    i->key_state = SDL_GetKeyboardState(NULL);
    i->player_ = p;
}


} // namespace InputSystem
