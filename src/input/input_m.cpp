#include <malloc.h>
#include <stdint.h>

#include <iostream>

#include "input_m.h"

InputManager::InputManager()
{
    pool_ = static_cast<InputComponent *>(
        aligned_alloc(sizeof(InputComponent), static_cast<int>(Player::total_players) * sizeof(InputComponent)));

    InputComponent *ptr = pool_;

    ptr = pool_;

    Player p = Player::player1;

    while (ptr < (pool_ + static_cast<int>(Player::total_players) * sizeof(InputComponent)))
    {
        InputSystem::CreateInput(ptr, p);
        ptr += sizeof(InputComponent);
        p++;
    }
}

InputManager::~InputManager()
{
    free(pool_);
    pool_ = nullptr;
}
