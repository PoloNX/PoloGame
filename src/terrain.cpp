#include "terrain.hpp"

Terrain::Terrain(terrain_color _color, SDL_Renderer* renderer) {
    color = _color;
    terrain = IMG_LoadTexture(renderer, TERRAIN.c_str());
}

Entity Terrain::getGround() {
    switch(color) {
        case green_terrain: {
            Entity ground(Vector2f(0, 400 - 32), terrain, 48, 48, 96, 0);
            return ground;
        }
        case orange_terrain: {
            Entity ground(Vector2f(0, 400 - 32), terrain, 32, 32, 96, 0);
            return ground;
        }
        case pink_terrain: {
            Entity ground(Vector2f(0, 400 - 32), terrain, 32, 32, 96, 0);
            return ground;
        }
        default:
            std::cout << "can't return ground" << std::endl;
    }
}

Entity Terrain::getBlock() {
    Entity block(Vector2f(0, 0), terrain, 32, 32, 208, 16);
    return block;
}