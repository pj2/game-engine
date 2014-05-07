/* Game.cpp
Author: Joshua Prendergast */

#include "Game.h"
#include <stdexcept>

namespace sight {

std::map<std::string, Texture *> Game::textures;

Game::Game() : window(NULL), renderer(NULL), entities() {
    SDL_Init(SDL_INIT_VIDEO);
    createWindow();
}

Game::~Game() {
    /* Cleanup allocated memory */
    for (std::map<std::string, Texture *>::iterator it = textures.begin(); it != textures.end(); ++it) {
        delete it->second;
    }
    for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it) {
        delete *it;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/* Creates the game window and renderer. */
int Game::createWindow() {
    window = SDL_CreateWindow("sight-reader",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        600,
        SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    if (!window || !renderer) {
        throw std::runtime_error("failed to create window / renderer");
    }
}

void Game::mainLoop() {
    running = true;
    while (running) {
        handleWindowEvents();
        nextFrame();
    }
}

void Game::addEntity(Entity *entity) {
    entities.push_back(entity);
}

void Game::handleWindowEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Game::nextFrame() {
    SDL_RenderClear(renderer);

    for (std::list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it) {
        (*it)->update();
        (*it)->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

Texture *Game::loadTexture(SDL_Renderer *renderer, const std::string &filename) {
    if (textures.find(filename) == textures.end()) {
        textures[filename] = new Texture(renderer, filename);
    }
    return textures[filename];
}

}
