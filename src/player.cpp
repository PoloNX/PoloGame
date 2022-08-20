#include "player.hpp"

Player::Player(SDL_Renderer* renderer) {
    current_direction = none_direction;
    current_state = idle;
    
    //Set texture
    idle_tex = IMG_LoadTexture(renderer, IDLE_PATH.c_str());
    run_tex = IMG_LoadTexture(renderer, RUN_PATH.c_str());
    jump_tex = IMG_LoadTexture(renderer, JUMP_PATH.c_str());
}

void Player::createEntity() {
    switch(current_state) {
        case idle: 
            player_entity = Entity(Vector2f(player_entity.getPos().x, player_entity.getPos().y), idle_tex, 32, 32, 0, 0, 50, 11);
            break;
        case run:
            player_entity = Entity(Vector2f(player_entity.getPos().x, player_entity.getPos().y), run_tex, 32, 32, 0, 0, 40, 12);
            break;
        case jump:
            player_entity = Entity(Vector2f(player_entity.getPos().x, player_entity.getPos().y), jump_tex, 32, 32, 0, 0);
            break;
    }
}

void Player::movePlayer(Physics& physics) {
    switch (getDirection()) {
    case right:
        physics.moveRight();
        break;
    case left:
        physics.moveLeft();
        break;
    case none_direction:
		physics.resetSpeedX();
		break;
	}
}

bool Player::isJumping(){
    if (player_entity.getPos().y != last_pos.y) {
        last_pos = player_entity.getPos();
        return true;
    }

    last_pos = player_entity.getPos();
    return false;
}

Entity* Player::getPlayer() {
    return &player_entity;
}

void Player::setState(player_state state) {
    current_state = state;
    createEntity();
}

void Player::setDirection(direction direction) {
    current_direction = direction;
}
