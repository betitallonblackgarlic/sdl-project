#include "System.h"

System::System(SDL_DisplayMode disp)
    : window_(nullptr), dmode_(disp), running_(true) {}

System::~System() {
  SDL_DestroyWindow(window_);

  window_ = nullptr;
  SDL_Quit();
}

bool System::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL failed to initialize. SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  if (!(window_ = SDL_CreateWindow("Hello Window", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, dmode_.w, dmode_.h,
                                   SDL_RENDERER_ACCELERATED))) {
    printf("SDL failed to create window. SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void System::Run() {
  SDL_Event e;

  while(running_)
  {
    while(SDL_PollEvent(&e))
    {
      switch(e.type)
      {
        case SDL_WINDOWEVENT_CLOSE:
          running_ = false;
          break;
      }
    }
  }
}
