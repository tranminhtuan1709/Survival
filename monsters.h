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

void randomMonster(MonsterProperties& monster, MonsterOnscreen& defaulMons);
void chase(MonsterOnscreen& monster, CharacterOnScreen& characterOnScreen, SDL_Renderer* render, Monster1& mons1);
void beAttacked(anemoChar& char1, electroChar& char2, hydroChar& char3, pyroChar& char4, MonsterOnscreen& defaultMons);

#endif monsters_h_