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
	void mainLoop();
	void addEntity(Entity *entity);
	static Texture *loadTexture(SDL_Renderer *renderer, const std::string &filename);
protected:
	int createWindow();
	void handleWindowEvents();
	void nextFrame();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool running;
	std::list<Entity *> entities;
	static std::map<std::string, Texture *> textures;
};

}

#endif // GAME_H