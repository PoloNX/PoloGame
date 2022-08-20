#include "entity.hpp"
#include <iostream>

Entity::Entity(Vector2f _pos, SDL_Texture* _tex, int w, int h, int x, int y) {
    pos = _pos;
    tex = _tex;
    currentFrame = {x, y, w, h};
}

Entity::Entity(Vector2f _pos, SDL_Texture* _tex, int w, int h, int x, int y, int speed, int frames) {
    pos = _pos;
    tex = _tex;
    this->speed = speed;
    this->frames = frames;
    animated = true;
    createCurrentFrame(x, y, w, h);
}

Vector2f& Entity::getPos() {
    return pos;
}

void Entity::setPos(Vector2f _pos) {
    pos = _pos;
}

void Entity::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
}

SDL_Texture* Entity::getTex() {
    return tex;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

int Entity::getWidth(){
    return currentFrame.w;
}

int Entity::getHeight(){
    return currentFrame.h;
}

SDL_Rect Entity::getRect(){
    return {(int)pos.x, (int)pos.y, currentFrame.w, currentFrame.h}; 
}

void Entity::animate() {
    createCurrentFrame(currentFrame.x, currentFrame.y, currentFrame.w, currentFrame.h);
}

void Entity::createCurrentFrame(int x, int y, int w, int h){
    if (!animated) {
        currentFrame = {x, y, w, h};
    } 
    else {
        currentFrame.x = currentFrame.w * ((SDL_GetTicks() / speed) % frames);
        currentFrame.y = y;
        currentFrame.w = w;
        currentFrame.h = h;
    }
}