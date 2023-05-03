#pragma once
#ifndef  font_h_
#define font_h_

#include "initGame.h"

class Font
{
public:
	TTF_Font* villa;
	TTF_Font* zag;
	vector <SDL_Color> allColor;
	vector <SDL_Texture*> text;
	Font(SDL_Renderer* render);
};

#endif font_h_
