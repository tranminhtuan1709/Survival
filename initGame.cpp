#include "initGame.h"

App::App()
{
	currentAppTime = SDL_GetTicks();
	sdlInitResult = SDL_Init(SDL_INIT_EVERYTHING);
	imgInitResult = (IMG_Init(imgInitFlags) & imgInitFlags);
	window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	pen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

App::~App()
{
	imgInitFlags = 0;
	sdlInitResult = 0;
	imgInitResult = 0;
	currentAppTime = 0;
	SDL_DestroyWindow(window);
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

bool App::checkInit()
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
	return true;
}

void Delay::initData(int size1, int size2, int size3, int size4, int size5, int size6, int size7, int size8, int size9, int size10)
{
	for (int i = 0; i < size1; i++) previousFrameTime.push_back((int)SDL_GetTicks());
	for (int i = 0; i < size2; i++) delayFrameTime.push_back(0);
	for (int i = 0; i < size3; i++) currentFrame.push_back(0);
	for (int i = 0; i < size4; i++) checkFrame.push_back(false);
	for (int i = 0; i < size5; i++) previousSkillTime.push_back(0);
	for (int i = 0; i < size6; i++) delaySkillTime.push_back(0);
	for (int i = 0; i < size7; i++) previousRandomTime.push_back(0);
	for (int i = 0; i < size8; i++) delayRandomTime.push_back(0);
	for (int i = 0; i < size9; i++) previousLockTargetTime.push_back(0);
	for (int i = 0; i < size10; i++) delayLockTargetTime.push_back(0);
}
