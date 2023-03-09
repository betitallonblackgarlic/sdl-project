#include "input.h"

#include <assert.h>
#include <exception>
#include <iostream>

Uint8 Input::_head = 0;
Uint8 Input::_tail = 0;

KeyState Input::_state;

void Input::DoInput(const SDL_Event &e, bool &running)
{
    // auto scancode = e.key.keysym.scancode;
    switch (e.type)
    {
        case SDL_QUIT:
            running = false;
            break;
        default:
            try
            {
                // Input::enqueue(e.type, scancode);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
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
