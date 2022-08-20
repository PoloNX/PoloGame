#include "physics.hpp"
#include <iostream>

Physics::Physics() {
    g = Vector2f(0.f, 320.f);
    timestamp = SDL_GetTicks();
    t = (SDL_GetTicks() - timestamp) / 1000.f;
    VOx = 0;
    VOy = 0; 
}

Physics::~Physics() {

}

void Physics::gravity(Entity &entity) {
    t = (SDL_GetTicks()- timestamp) / 1000;
    timestamp = SDL_GetTicks();

    speed();

    entity.setPos(entity.getPos().x + VOx * t, entity.getPos().y + VOy * t);

}

void Physics::speed() {
    VOy = VOy + g.y * t;
    VOx = VOx + g.x * t;
}

void Physics::jump() {
    VOy = -225;
}

void Physics::moveRight() {
    VOx = 100;
}

void Physics::moveLeft() {
	VOx = -100;
}

void Physics::resetSpeedX() {
    VOx = 0;
}

bool Physics::isJumping() {
    if (VOy < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Physics::checkCollision(Entity &entity, Entity &other) {
    if (entity.getPos().x + entity.getWidth() > other.getPos().x && entity.getPos().x < other.getPos().x + other.getWidth()) {
        if (entity.getPos().y + entity.getHeight() > other.getPos().y && entity.getPos().y < other.getPos().y + other.getHeight()) {
            return true;
        }
    }
}

bool Physics::checkCollision(Entity& entity, std::vector<SDL_Rect>& vector_entity) {
    for (int i = 0; i < vector_entity.size(); i++) {
        if (entity.getPos().x + entity.getWidth() > vector_entity[i].x && entity.getPos().x < vector_entity[i].x + vector_entity[i].w) {
            if (entity.getPos().y + entity.getHeight() > vector_entity[i].y && entity.getPos().y < vector_entity[i].y + vector_entity[i].h) {
                entity.setPos(entity.getPos().x, vector_entity[i].y - entity.getHeight());
            }
        }
    }
    if (entity.getPos().y < 0) {
        entity.setPos(entity.getPos().x, 0);
    }
    if (entity.getPos().y > 336) {
        entity.setPos(entity.getPos().x, 336);
        VOy = 0;
    }
    if (entity.getPos().x > 600 - entity.getWidth()) {
        entity.setPos(600 - entity.getWidth(), entity.getPos().y);
    }
    if (entity.getPos().x < 0) {
        entity.setPos(0, entity.getPos().y);
    }
    return false;
}

bool Physics::checkCollision(Entity &entity, SDL_Rect rect) {
    if (entity.getPos().x + entity.getWidth() > rect.x && entity.getPos().x < rect.x + rect.w) {
        if (entity.getPos().y + entity.getHeight() > rect.y && entity.getPos().y < rect.y + rect.h) {
            return true;
        }
    }
}

bool Physics::checkCollisionWithLevel(Entity& entity, std::vector<Entity>& entity_level) {
    for (int i = 0; i < entity_level.size(); i++) {
		SDL_Rect rect = entity_level[i].getRect();
        if (entity.getPos().x + entity.getWidth() > rect.x && entity.getPos().x < rect.x + rect.w) {
            if (entity.getPos().y + entity.getHeight() > rect.y && entity.getPos().y < rect.y + rect.h) {
				std::cout << "pos x : " << rect.x << " pos y : " << rect.y << std::endl;
                return true;
            }
        }
	}
    return false;
}

