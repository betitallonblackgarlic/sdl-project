#pragma once
#define MAX_EVENTS 16

#include <SDL2/SDL_events.h>

struct KeyState
{
    Uint8 keyPressed[SDL_NUM_SCANCODES];
    Uint8 keyDown[SDL_NUM_SCANCODES];
    Uint8 keyReleased[SDL_NUM_SCANCODES];

    Uint32 type;
    Uint32 code;
    KeyState() {}
};

class Input final
{
  private:
    // setup keystate arrays for down, active, and up
    static Uint8 _head;
    static Uint8 _tail;

    static KeyState _state;

    static void enqueue(const Uint32 type, SDL_Scancode code);
    static KeyState dequeue(); // this will probably be called
                               // to pass input to other systems

  public:
    static void DoInput(const SDL_Event &e, bool &running);
};
