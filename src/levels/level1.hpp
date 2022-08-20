#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "../constant.hpp"
#include "../entity.hpp"
#include "../terrain.hpp"

std::vector<Entity> returnLevel1(SDL_Renderer* renderer);
