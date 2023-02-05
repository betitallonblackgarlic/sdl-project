#include <string>

#include <SDL2/SDL.h>

#include "../components/window_c.h"
#include "../render/render_m.h"
#include "../input/input_m.h"

/**
 * @brief Core management class that manages the window as well as
 * orchaestration of other top-level managers
 *
 */
class WindowManager final
{
  private:
    WindowComponent window_c;
    InputManager input_mgr;
    
    int sdl_flags = SDL_INIT_EVERYTHING;

  public:
    WindowManager();
    ~WindowManager();
    void Run();
};
