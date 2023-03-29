#include "initGame.h"

Game::Game()
{
	currentAppTime = SDL_GetTicks();
	sdlInitResult = SDL_Init(SDL_INIT_EVERYTHING);
	imgInitResult = (IMG_Init(imgInitFlags) & imgInitFlags);
	window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	pen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	welcom_screen = IMG_LoadTexture(pen, "map2.png");
}

Game::~Game()
{
	imgInitFlags = 0;
	sdlInitResult = 0;
	imgInitResult = 0;
	currentAppTime = 0;
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(welcom_screen);
	SDL_DestroyRenderer(pen);
}

void loadImage(vector <SDL_Texture*>& v, string s, int frameNumber, SDL_Renderer* render)
{
	for (int i = 1; i <= frameNumber; i++)
	{
		string path = s + to_string(i) + ".png";
		v.push_back(IMG_LoadTexture(render, path.c_str()));
	}
}

bool Game::checkInit()
{
	if (!imgInitResult)
	{
		cout << "Error in initialize IMG! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (sdlInitResult < 0)
	{
		cout << "Error in initialize SDL! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (window == nullptr)
	{
		cout << "Error in create window! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (pen == nullptr)
	{
		cout << "Error in create renderer! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (welcom_screen == nullptr)
	{
		cout << "Error in create start screen! Error: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}
