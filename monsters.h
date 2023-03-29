#ifndef monsters_h_
#define monsters_h_

#include "initGame.h"
#include "characters.h"
#include "game.h"

class Monster1
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	void loadData(SDL_Renderer* render);
};

class Monster2
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	void loadData(SDL_Renderer* render);
};

class Monster3
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> attackFrame;
	void loadData(SDL_Renderer* render);
};

class Monster4
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	void loadData(SDL_Renderer* render);
};

class Monster5
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	void loadData(SDL_Renderer* render);
};

class Monster6
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	void loadData(SDL_Renderer* render);
};

class Monster7
{
public:
	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> attackFrame;
	void loadData(SDL_Renderer* render);
};

class MonsterInformation
{
public:
	int HP{};
	int atk{};
	int def{};
	int speed{};
	int monsSizeW{};
	int monsSizeH{};
	int currentFrameHP{};
	int currentFrameRun{};
	int currentFrameDie{};
	int currentFrameAttack{};
	int previousTimeFrameRun{};
	int previousTimeFrameDie{};
	int previousTimeFrameAttack{};
	int step{};
	SDL_RendererFlip flip{};
	SDL_Rect position{};
	string direction{};
	string type{};
};

class AllMonsters
{
public:
	Monster1 mons1;
	Monster2 mons2;
	Monster3 mons3;
	Monster4 mons4;
	Monster5 mons5;
	Monster6 mons6;
	Monster7 mons7;

	int previousRandomTime = SDL_GetTicks();

	vector <MonsterInformation> monsterOnscreen;
	vector <bullet> bulletMonster;

	AllMonsters(SDL_Renderer* render);
};

void randomMonster(AllMonsters& monsters, int monsType);
void chase(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render);
void beAttacked(AllMonsters& monsters, AllCharacters& characters);

#endif monsters_h_