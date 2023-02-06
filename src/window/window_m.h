#include <string>

#include <SDL2/SDL.h>

/**
 * @brief Core management class that manages the window as well as
 * orchaestration of other top-level managers
 *
 */
class WindowManager final
{
  private:
    int scalar = 4;
    SDL_DisplayMode dMode_{.w = 224 * scalar, .h = 288 * scalar};
    SDL_Window *window_;

    std::string title_;

    int sdl_flags = SDL_INIT_EVERYTHING;
    int wFlags_;

    bool running_ = true;

  public:
    WindowManager();
    ~WindowManager();
    void Run();
};
