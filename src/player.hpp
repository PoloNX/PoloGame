#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "constant.hpp"
#include "entity.hpp"
#include "physics.hpp"

enum player_state {idle, jump, run};
enum direction {none_direction = -1, right, left};

class Player {
public: 
    Player(SDL_Renderer* renderer);
    Player() {}

    void setDirection(direction direction);
    void setState(player_state direction);
    void createEntity();

    bool isJumping();
    void movePlayer(Physics& physics);

    direction getDirection() {return current_direction;}
    player_state getState() {return current_state;}
    Entity* getPlayer();
private:
    Entity player_entity;
    player_state current_state = idle;
    direction current_direction = none_direction;

    Vector2f last_pos;

    SDL_Texture* idle_tex;
    SDL_Texture* jump_tex;
    SDL_Texture* run_tex;
};