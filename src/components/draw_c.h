#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL_rect.h>

struct DrawComponent
{
    SDL_Rect dest_;
};

struct PhysicsComponent : public DrawComponent
{
    glm::vec2 position_;

    float velocity_;
    float acceleration_;
};
