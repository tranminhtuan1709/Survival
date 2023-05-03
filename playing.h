#pragma once
#ifndef playing_h_
#define playing_h_

#include "initGame.h"
#include "font.h"

class Playing
{
public:
	int earnedScore{};
	int passScore{};
	int beginTime{};
	int remainingTime{};
	int passedTime{};
	vector <int> monsterScore;
	vector <int> skillUnlocked;
	vector <double> hpLeft;
	vector <SDL_Rect> playingPosition;
	vector <vector <SDL_Texture*>> playingFrame;
	void initData(SDL_Renderer* render, Font font);
};

#endif playing_h_
