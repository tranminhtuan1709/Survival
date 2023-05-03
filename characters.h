#pragma once
#ifndef characters_h_
#define characters_h_

#include "initGame.h"

class Character
{
public:
	bool isAlive;
	SDL_Rect hpTotal;
	SDL_Rect hpLeft;
	Delay delay;
	vector <int> stat;
	vector <SDL_Texture*> HPFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;
	Character(SDL_Renderer* render, int type);
};

class AllCharacters
{
public:
	int selectedChar;
	int* currentCharHP;
	bool shield;
	bool allDied;
	double baseATK;
	double baseDEF;
	int timeWhenDie;
	int timeAfterDie;
	SDL_Rect position;
	SDL_RendererFlip flip;
	SDL_Texture* ghost;
	vector <Character> listOfChar;
	AllCharacters(SDL_Renderer* render);
};

#endif characters_h_