#include "background.hpp"

Background::Background(background_color color, SDL_Renderer *renderer) {
    switch(color) {
        case blue:
            texture = IMG_LoadTexture(renderer, BLUE_BACKGROUND.c_str());
            break;
        case brown:
            
            break;
        case gray:
            
            break;
        case green:
            texture = IMG_LoadTexture(renderer, GREEN_BACKGROUND.c_str());
            break;
        case pink:
           
            break;
        case purple:
           
            break;
        case yellow:
          
            break;
        default:   
            std::cout << "Can't load background texture" << std::endl;
            break;
    }
}

Entity Background::getBackground() {
    Entity background_entity(Vector2f(0, 0), texture, 64, 64);
    return background_entity;
}