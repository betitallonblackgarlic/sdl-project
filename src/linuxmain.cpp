/**
 * @file linuxmain.cpp
 * @author Bill Black (william.black@colorado.edu)
 * @brief
 * @version 0.1
 * @date 2023-02-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "manager/render/render_m.h"
#include "manager/texture/texture_m.h"
#include "manager/window/window_m.h"

#include <iostream>

// there's only ever one window or memory manager
// and should only be one of either
// so is this okay to make it a static global? is this a singleton?
// I want to practice different usages and implementations
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Does ECS architecture actually make sense for window and renderer,  *
 * and does it make sense I declared them as global statics            *
 * since there's only supposed to be one of each?                      *
 * they don't really need management or tracking since                 *
 * tthey're always in use so i'm assuming no                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(const int argc, const char **argv)
{
    static WindowManager wnd_mgr;
    static RenderManager rnd_mgr(wnd_mgr.GetWindow());
    static TextureManager tex_mgr(rnd_mgr.GetContext());
    
    if (argc)
    {
        // do arg stuff
    }

    wnd_mgr.Run(&rnd_mgr, &tex_mgr);

    return EXIT_SUCCESS;
}
// maybe add arg handling or whatever to make the main function look like an
// actual function
