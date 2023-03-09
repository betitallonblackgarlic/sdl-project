#include "input.h"

#include <assert.h>
#include <exception>
#include <iostream>

Uint8 Input::_head = 0;
Uint8 Input::_tail = 0;

KeyState Input::_state;

void Input::DoInput(const SDL_Event &e, glm::vec2 &currPos, glm::vec2 &velocity,
                    bool &running)
{
    auto key = e.key.keysym.sym;
    switch (e.type)
    {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (key)
            {
                case SDLK_DOWN:
                    velocity.y = 2;
                    velocity.x = 0;
                    currPos.y += velocity.y;
                    break;
                case SDLK_UP:
                    velocity.y = -2;
                    velocity.x = 0;
                    currPos.y += velocity.y;
                    break;
                case SDLK_LEFT:
                    velocity.x = -2;
                    velocity.y = 0;
                    currPos.x += velocity.x;
                    break;
                case SDLK_RIGHT:
                    velocity.x = 2;
                    velocity.y = 0;
                    currPos.x += velocity.x;
                    break;
            }
            break;
    }
}

// void Input::enqueue(const Uint32 type, const SDL_Scancode code)
// {
//     if ((_tail + 1) % MAX_EVENTS == _head)
//     {
//         throw std::logic_error("queue full");
//     }

//     _state._keyreleased[code] = 0; // reset released keys every frame

//     switch (type)
//     {
//         case SDL_KEYDOWN:
//             // reset pressed key if key already down
//             _state._keypressed[code] = !_state._keydown[code];
//             // set key to down which will set keypressed to 0
//             // until keydown is toggled by release
//             _state._keydown[code] = 1;
//             break;
//         case SDL_KEYUP:
//             _state._keyreleased[code] = 1;
//             _state._keydown[code] = 0;

//             break;
//     }
// }

// KeyState Input::dequeue()
// {
//     if (_head == _tail) { throw std::logic_error("queue empty"); }
//     _head = (_head + 1) % MAX_EVENTS;

//     return _state;
// }
