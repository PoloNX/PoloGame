#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <array>

#include "levels/level1.hpp"

class Level {
public:
    Level(SDL_Renderer* renderer);

    std::vector<Entity> loadLevel();
    void nextLevel();

private:
    int level_number = 0;
    int current_level = 0;
    std::vector<std::vector<Entity>> levels;
};