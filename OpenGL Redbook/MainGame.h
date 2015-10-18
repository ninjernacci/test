#pragma once

#include <SDL.h>


class MainGame 
{
public:
	MainGame();
	~MainGame();

	void run();

	



private:

	void initSystems();
	void processInput();
	void gameLoop();

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
};

