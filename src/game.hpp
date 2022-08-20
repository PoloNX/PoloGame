#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "level.hpp"
#include "background.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "terrain.hpp"
#include "physics.hpp"

class Game {
public:
    Game(const std::string &title, const int x, const int y, const int w, const int h);
    ~Game();

    void update();
    void clean();
    void event();
    void render(Entity entity);
    void loadImage(SDL_Texture* &texture, const std::string &path);

    bool isRunning() {return running;}

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;

    SDL_Rect ground;

    SDL_Event events;

    std::vector<SDL_Rect> collision_rects;
    std::vector<Entity> vector_level;

    Entity background_entity;
    Entity ground_entity;
    Entity *player_entity;

    Background background;
    Terrain terrain;
    Player player;
    Physics physics;
};