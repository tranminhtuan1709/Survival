#pragma once
#ifndef bullet_h_
#define bullet_h_

#include "initGame.h"

class Bullet
{
public:
	string type;
	SDL_Rect position;
	SDL_Rect boom;
	double damage;
	int previousFrameTime; int delayFrameTime; int currentFrame; bool checkFrame;
	int startTime; int existTime;
	bool checkExist;
	double alpha;
	double rotate;
	double d;
	SDL_RendererFlip flip;
	Bullet();
};

class BulletOnScreen
{
public:
	SDL_Texture* bullet_mons5;
	SDL_Texture* bullet_mons8;
	vector <vector <Bullet>> bulletCharacter;
	vector <Bullet> bulletMonster;
	BulletOnScreen(SDL_Renderer* render);
};

#endif bullet_h_
