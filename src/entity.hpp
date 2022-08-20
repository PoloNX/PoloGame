#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "math.hpp"

class Entity {
public:
    Entity(Vector2f _pos, SDL_Texture* _tex, int w, int h, int x = 0, int y = 0);
    Entity(Vector2f _pos, SDL_Texture* _tex, int w, int h, int x, int y, int speed, int frames);
    Entity() {};

    Vector2f& getPos();

    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();

    int getWidth();
    int getHeight();
    SDL_Rect getRect();

    void setPos(Vector2f _pos);
    void setPos(float x, float y);

    void animate();

private:
    Vector2f pos;
    SDL_Texture* tex;
    SDL_Rect currentFrame;

    // Animation
    int frames = 0; 
    int speed = 0;
    bool animated = false;
    void createCurrentFrame(int x, int y, int w, int h);
};