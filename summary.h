#pragma once
#ifndef summary_h_
#define summary_h_

#include "initGame.h"
#include "font.h"

class Summary
{
public:
	vector <SDL_Rect> summaryPosition;
	vector <vector <SDL_Texture*>> summaryFrame;
	void initData(SDL_Renderer* render, Font& font);
};

#endif summary_h_