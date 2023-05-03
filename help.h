#pragma once
#ifndef help_h_
#define help_h_

#include "initGame.h"
#include "font.h"

class HelpWindow
{
public:
	vector <vector <SDL_Texture*>> helpFrame;
	vector <SDL_Rect> helpPosition;
	int pageNumber{};
	void initData(SDL_Renderer* render, Font& font);
};

#endif help_h_
