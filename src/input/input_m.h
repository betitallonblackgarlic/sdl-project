#pragma once

#include "input_s.h"

class InputManager final
{
  private:
    InputComponent *pool_;

  public:
    InputManager();
    ~InputManager();
};
