#pragma once
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

const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 800;

class App
{
public:
	int imgInitFlags = IMG_INIT_PNG;
	int sdlInitResult;
	int imgInitResult;
	int currentAppTime;
	SDL_Window* window = nullptr;
	SDL_Renderer* pen = nullptr;
	SDL_Point mouseCoordinate = { 0, 0 };
	App();
	~App();
	bool checkInit();
};

class Delay
{
public:
	vector <int> previousFrameTime;
	vector <int> delayFrameTime;
	vector <int> currentFrame;
	vector <bool> checkFrame;
	vector <int> previousSkillTime;
	vector <int> delaySkillTime;
	vector <int> previousRandomTime;
	vector <int> delayRandomTime;
	vector <int> previousLockTargetTime;
	vector <int> delayLockTargetTime;
	void initData(int size1, int size2, int size3, int size4, int size5, int size6, int size7, int size8, int size9, int size10);
};

void loadImage(vector <SDL_Texture*>& v, string s, int frameNumber, SDL_Renderer* render);

#endif initGame_h_