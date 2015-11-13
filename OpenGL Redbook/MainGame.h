#pragma once

#include "Sprite.h"
#include "GLSLProgram.h"
#include <SDL.h>
#include <glew.h>
#include <freeglut.h>


enum class GameState 
{
	PLAY, EXIT
};

class MainGame 
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initSystems();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	GLSLProgram _colorProgram;

	Sprite _sprite;
};

