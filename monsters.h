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

class Boss
{
public:
	vector <SDL_Texture*> standFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> attackFrame;
	SDL_Texture* rock;
	SDL_Texture* lock;
	SDL_Texture* hp1;
	SDL_Texture* hp2;
	SDL_Texture* shield;
	SDL_Texture* avatar;
	SDL_Texture* anemo;
	SDL_Texture* electro;
	SDL_Texture* hydro;
	SDL_Texture* pyro;
	SDL_Rect elemental;
	SDL_Rect position;
	SDL_Rect maxHP;
	SDL_Rect currentHP;
	SDL_Rect shieldPosition;
	SDL_RendererFlip flip;
	bool standing;
	bool attacking;
	bool isAlive;
	int HP;
	int ATK;
	int shieldlValue;
	int previousRandomSkeleton;
	int delayRandomSkeleton;
	Delay delay;
	Boss(SDL_Renderer* render);
};

#endif monsters_h_