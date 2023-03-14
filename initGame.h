#ifndef initGame_h_
#define initGame_h_

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <algorithm>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

const int SCREEN_WIDTH = 1800;
const int SCREEN_HEIGHT = 1000;

class Game
{
public:
	int imgInitFlags = IMG_INIT_PNG;
	int sdlInitResult;
	int imgInitResult;
	SDL_Window* window = nullptr;
	SDL_Renderer* pen = nullptr;
	SDL_Texture* welcom_screen = nullptr;
	SDL_Point mouseCoordinate = { 0, 0 };

	Game();
	~Game();
	bool checkInit();
};

void loadImage(vector <SDL_Texture*>& v, string s, int frameNumber, SDL_Renderer* render);

class CharacterOnScreen
{
public:
	SDL_Rect currentCharPosition;
	string currentCharDirection;
	int currentCharSelected;
	int currentCharHP;
};

class MonsterOnscreen
{
public:
	SDL_Rect currentMonsPos;
	SDL_RendererFlip flip;
	int currentMonsHP;
	int currentMonsSpeed;
	int currentMonsFrame;
	int delayFrameTime;
	string typeOfMons;
	vector <MonsterOnscreen> allMonster;
};

#endif initGame_h_