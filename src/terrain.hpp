#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "constant.hpp"
#include "entity.hpp"

enum terrain_color{green_terrain, orange_terrain, pink_terrain};

class Terrain {
public:
    Terrain(terrain_color _color, SDL_Renderer* renderer);
    Terrain() {}

    Entity getBlock();
    Entity getGround();

private:
    SDL_Texture* terrain;
    terrain_color color;
};