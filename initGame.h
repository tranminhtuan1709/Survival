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
	int currentAppTime;
	SDL_Window* window = nullptr;
	SDL_Renderer* pen = nullptr;
	SDL_Texture* welcom_screen = nullptr;
	SDL_Point mouseCoordinate = { 0, 0 };

	Game();
	~Game();
	bool checkInit();
};

class Line
{
public:
	double a;
	double b;
	double alpha;
};

void loadImage(vector <SDL_Texture*>& v, string s, int frameNumber, SDL_Renderer* render);

#endif initGame_h_