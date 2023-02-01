#include <SDL2/SDL.h>
/**
 * @brief Initializes SDL systems and main loop
 *
 */
class System {
private:
  SDL_Window *window_;
  SDL_DisplayMode dmode_;

  bool running_;

public:
  System(SDL_DisplayMode disp = SDL_DisplayMode{.w = 800, .h = 600, .refresh_rate = 0, .driverdata = 0});
  ~System();

  bool Init();
  void Run();
};
