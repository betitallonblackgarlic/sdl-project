#include <SDL2/SDL.h>
#include <stdio.h>

#include "system/System.h"

int main(const int argc, const char **argv) {
  System game;

  if (!game.Init()) {
    return -1;
  }

  game.Run();
  
  return 0;
}