#include "MainGame.h"
#include <iostream>
#include <conio.h>
#include <string>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	_getch();
	SDL_Quit();

}

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;

}


MainGame::~MainGame()
{

}


void MainGame::initSystems()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create the Window
	_window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		fatalError("SDL Window couldn't be created");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		fatalError("SDL_GL context could not be created");
	}

	GLenum error = glewInit();

	if (error != GLEW_OK)
	{
		fatalError("Could not initialize GLEW");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(.0f, .0f, 1.0f, 1.0f);
}

void MainGame::run()
{
	initSystems();

	gameLoop();
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt) == 1)
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
			
		}	
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glEnd();

	SDL_GL_SwapWindow(_window);
}

