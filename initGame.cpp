#include "initGame.h"

App::App()
{
	currentAppTime = SDL_GetTicks();
	SDLinitResult = SDL_Init(SDL_INIT_EVERYTHING);
	IMGinitResult = (IMG_Init(IMGinitFlags) & IMGinitFlags);
	TTFinitResult = TTF_Init();
	MIXinitResult = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	pen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool App::checkInit()
{
	if (SDLinitResult < 0)
	{
		cout << "Error in initialize SDL! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (!IMGinitResult)
	{
		cout << "Error in initialize IMG! Error: " << IMG_GetError() << endl;
		return false;
	}
	if (TTFinitResult == -1)
	{
		cout << "Error in initialize TTF! Error: " << TTF_GetError() << endl;
		return false;
	}
	if (MIXinitResult < 0)
	{
		cout << "Error in initialize MIX! Error: " << Mix_GetError() << endl;
		return false;
	}
	if (window == nullptr)
	{
		cout << "Error in create Window! Error: " << SDL_GetError() << endl;
		return false;
	}
	if (pen == nullptr)
	{
		cout << "Error in create Renderer! Error: " << SDL_GetError() << endl;
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

void loadImage(vector <SDL_Texture*>& v, string s, int frameNumber, SDL_Renderer* render)
{
	for (int i = 1; i <= frameNumber; i++)
	{
		string path = s + to_string(i) + ".png";
		v.push_back(IMG_LoadTexture(render, path.c_str()));
	}
}

TTF_Font* loadFont(string path, int size)
{
	return TTF_OpenFont(path.c_str(), size);
}

Mix_Chunk* loadChunk(string path)
{
	return Mix_LoadWAV(path.c_str());
}

Mix_Music* loadMusic(string path)
{
	return Mix_LoadMUS(path.c_str());
}

SDL_Texture* createTextureFromFont(TTF_Font* font, string sentence, SDL_Color color, SDL_Renderer* render)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, sentence.c_str(), color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	return text;
}