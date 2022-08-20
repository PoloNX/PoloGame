#include "game.hpp"
#include <iostream>

Game::Game(const std::string &title, const int x, const int y, const int w, const int h) {

    window = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    background = Background(background_color::green, renderer);
    background_entity = background.getBackground();

    terrain = Terrain(terrain_color::green_terrain, renderer);
    ground_entity = terrain.getGround();
    ground = ground_entity.getRect();
    ground.w = 600;
    ground.x = 0;
    collision_rects.push_back(ground);

    player = Player(renderer);
    player.createEntity();
    player_entity = player.getPlayer();

    Level level(renderer);
    vector_level = level.loadLevel();
}

Game::~Game() {

}

void Game::update() {

    SDL_RenderClear(renderer);

    //Render the background
     for(int i = 0; i < 10; ++i) {
         for (int j = 0; j < 7; ++j) {
             render(background_entity);
             background_entity.setPos(64 * i, 64 * j);
         }
         render(background_entity);
         background_entity.setPos(64 * i, 0);
     }

    //Render the ground
     for(int i = 0; i < 15; ++i) {
         render(ground_entity);
         ground_entity.setPos(47 *i, ground_entity.getPos().y);
     }

    //Render the level
     for (auto i : vector_level) {
         render(i);
     }

    //Render the player
     render(*player_entity);

     player_entity->animate();

    //std::cout << "pos x " << player_entity->getPos().x << " " << player_entity->getPos().y << std::endl;
     physics.gravity(*player_entity);
     physics.checkCollision(*player_entity, collision_rects);
     
     if (physics.isJumping()) {
         player.setState(player_state::jump);
     }
     if (!physics.checkCollisionWithLevel(*player_entity, vector_level)) {
		player.setDirection(direction::none_direction);
     } 
	
     player.movePlayer(physics);
	
     SDL_RenderPresent(renderer);
}

void Game::event() {
    SDL_PollEvent(&events);
    switch(events.type) {
        case SDL_QUIT:
            std::cout << "exit requested" << std::endl;
            running = false;
            break;
        case SDL_KEYDOWN:
            switch(events.key.keysym.sym) {
                case SDLK_RIGHT:
                    if (player.getDirection() != direction::right && !physics.isJumping()) {
                        player.setState(player_state::run);
                    }
                    player.setDirection(direction::right);
                    break;
                case SDLK_LEFT:
					if (player.getDirection() != direction::left && !physics.isJumping()) {
						player.setState(player_state::run);
					}
                    player.setDirection(direction::left);
                    break;
                case SDLK_SPACE:
                    if (!physics.isJumping()) {
                        player.setState(player_state::jump);
                        physics.jump();
                    }
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            switch(events.key.keysym.sym) {
                case SDLK_RIGHT:
                    std::cout << "key released" << std::endl;
                    player.setDirection(direction::none_direction);
                    player.setState(player_state::idle);
                    break;
                case SDLK_LEFT:
                    player.setDirection(direction::none_direction);
                    player.setState(player_state::idle);
                    break;
                case SDLK_SPACE:
                    player.setState(player_state::idle);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

}

void Game::render(Entity entity){
    SDL_Rect dst {(int)entity.getPos().x, (int)entity.getPos().y, entity.getCurrentFrame().w, entity.getCurrentFrame().h};
    SDL_Rect src = entity.getCurrentFrame();

    SDL_RenderCopy(renderer, entity.getTex(), &src, &dst);
}

void Game::loadImage(SDL_Texture* &texture, const std::string &path){
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        std::cout << "Aie.. Can't load image ! " << IMG_GetError() << std::endl;
        std::cout << path << std::endl;
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}