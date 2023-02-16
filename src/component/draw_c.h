#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL_rect.h>

#include "component_c.h"

struct DrawComponent : public Component
{
    SDL_Rect dest_;
};

struct PhysicsComponent
{
    glm::vec2 position_;

    float velocity_;
    float acceleration_;
};
