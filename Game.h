/* Game.h
Author: Joshua Prendergast */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Entity.h"
#include <list>

namespace sight {

class Game {
public:
	Game();
	~Game();
	void start();
	void mainLoop();
	Entity *addEntity(Entity *entity);
	SDL_Renderer *getRenderer() const { return renderer; };
protected:
	void createWindow();
	void handleWindowEvents();
	void nextFrame();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;
	std::list<Entity *> entities;
};

}

#endif // GAME_H