#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "entity.hpp"
#include "constant.hpp"

enum background_color{none = -1, blue, brown, gray, green, pink, purple, yellow};

class Background {
public:
    Background(background_color color, SDL_Renderer* renderer);
    Background(){}
    Entity getBackground();

private:
    SDL_Texture* texture;
    std::vector<Entity> background_vector {};
};