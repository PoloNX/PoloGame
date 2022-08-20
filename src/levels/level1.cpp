#include "level1.hpp"


std::vector<Entity> returnLevel1(SDL_Renderer* renderer){
    Terrain terrain(green_terrain, renderer);
    
    Entity block;
    block = terrain.getBlock();
    block.setPos(Vector2f(200, 336));

    std::vector<Entity> level;
    level.push_back(block);
	
    block.setPos(Vector2f(200, 336 - block.getHeight() + 1));
    level.push_back(block);
    return level;
}