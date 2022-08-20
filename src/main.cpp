#include <SDL2/SDL.h>
#include <SDL2_framerate.h>
#include "game.hpp"
#include "background.hpp"

void init();

int main(int argc, char* args[]) {
    init();
    FPSmanager framerate;
    SDL_initFramerate(&framerate);
    SDL_setFramerate(&framerate, 60);
    Game game("PoloGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400);
    while(game.isRunning()) {
        game.event();
        game.update();
        SDL_framerateDelay(&framerate);
    }
    std::cout << "exit requested" << std::endl;
    return 0;
}

void init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL_Init successed" << std::endl;
    }
    if (IMG_Init(IMG_INIT_PNG)) {
        std::cout << "IMG_Init sccessed" << std::endl;
    }
}