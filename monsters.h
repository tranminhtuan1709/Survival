#pragma once
#ifndef monsters_h_
#define monsters_h_

#include "initGame.h"
#include "bullet.h"

class Monster
{
public:
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> attackFrame;
	Monster(SDL_Renderer* render, int type);
};

class MonsterInformation
{
public:
	vector <int> stat;
	SDL_Rect position;
	SDL_RendererFlip flip;
	bool isChasing;
	bool isAlive;
	Delay delay;
	MonsterInformation(int type);
};

class AllMonsters
{
public:
	int previousRandomTime;
	vector <Monster> listOfMons;
	vector <vector <MonsterInformation>> monsterOnScreen;
	SDL_Texture* bulletMons;
	SDL_Texture* hp1;
	SDL_Texture* hp2;
	AllMonsters(SDL_Renderer* render);
};

#endif monsters_h_