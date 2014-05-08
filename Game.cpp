/* Game.cpp
Author: Joshua Prendergast */

#include "Game.h"
#include <stdexcept>
#include "Background.h"
#include "Stave.h"

namespace sight {

Game::Game() : window(NULL), renderer(NULL), entities() {
    SDL_Init(SDL_INIT_VIDEO);
    createWindow();
}

Game::~Game() {
    /* Cleanup allocated memory */
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        delete *it;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/* Creates the game window and renderer. */
void Game::createWindow() {
    window = SDL_CreateWindow("sight-reader",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800,
        300,
        SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!window || !renderer) {
        throw std::runtime_error("failed to create window / renderer");
    }
}

void Game::start() {
    /* Register entities */
    // addEntity(new Background(this));
    addEntity(new Stave(this))->setPosition(20, 20);

    mainLoop();
}

void Game::mainLoop() {
    running = true;
    while (running) {
        handleWindowEvents();
        nextFrame();
    }
}

Entity *Game::addEntity(Entity *entity) {
    entities.push_back(entity);
    return entity;
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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    for (auto it = entities.begin(); it != entities.end(); ++it) {
        (*it)->update();
        (*it)->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

}
