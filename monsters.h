#ifndef monsters_h_
#define monsters_h_

#include "initGame.h"
#include "characters.h"

class Monster1
{
public:
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> dieFrame;
	Monster1(SDL_Renderer* render);
};

void randomMonster(MonsterOnscreen& monster);
void chase(MonsterOnscreen& monster, CharacterOnScreen& characterOnScreen, SDL_Renderer* render, Monster1& mons1);

#endif monsters_h_