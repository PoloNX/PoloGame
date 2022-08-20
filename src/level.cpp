#include "level.hpp"

Level::Level(SDL_Renderer *renderer) {
    level_number = 1;
    current_level = 1;
    levels.push_back(returnLevel1(renderer));
}

std::vector<Entity> Level::loadLevel() {
    switch(current_level) {
        case 1:
            return levels[0];
            break;
    }
}

void Level::nextLevel() {
    current_level++;
}
