#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "entity.hpp"
#include "math.hpp"
class Physics {
public:
    Physics();
    ~Physics();

    void acceleration();

    bool checkCollision(Entity &entity, Entity &other);
    bool checkCollision(Entity &entity, SDL_Rect rect);
    bool checkCollision(Entity &entity, std::vector<SDL_Rect>& vector);
    bool checkCollisionWithLevel(Entity& entity, std::vector<Entity>& entity_level);
    void jump();
    bool isJumping();
    void gravity(Entity &entity);

    void moveRight();
    void moveLeft();
    void resetSpeedX();
    double VOy;
private:
    void speed();
    Vector2f g;
    double t;
    double timestamp;
    double VOx;

};
