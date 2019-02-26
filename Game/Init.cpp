#include "pch.h"

#include "Main.h"

bool App::Init() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "ERROR: " << SDL_GetError() << "\n";
		return false;
	}

	Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);
	if (Window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	Generator();

	renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	background = LoadImage("D:/Projects/University/Game/Pictures/background.bmp", renderer);
	if (background == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}

	if (Hero.OnLoad("D:/Projects/University/Game/Pictures/yoshi.bmp", renderer, EntityWidht, EntityHeight, 8) == false) {
		return false;
	}

	Hero.X = 0, Hero.Y = -15;

	App::Game_Map.OnLoad("D:/Projects/University/Game/Maps/1.map", renderer);

	return true;
}