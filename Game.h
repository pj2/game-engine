/* Game.h
Author: Joshua Prendergast */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Entity.h"
#include "Font.h"
#include <list>

namespace sight {

class Game {
public:
	Game();
	~Game();
	void start();
	void mainLoop();
	Entity *addEntity(Entity *entity);
	SDL_Renderer *getRenderer() const;
	Font *getStdFont();
protected:
	void createWindow();
	void handleWindowEvents();
	void nextFrame();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;
	std::list<Entity *> entities;
	Font *stdFont;
};

}

#endif // GAME_H