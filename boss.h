//#pragma once
//#ifndef boss_h_
//#define boss_h_
//
//#include "AllHeaderFile.h"
//
//class Boss
//{
//public:
//	double HP;
//	double atk;
//	double def;
//	SDL_Rect position;
//	SDL_Rect target[5];
//	SDL_RendererFlip flip;
//	DelayActions delayACT;
//	int attackedSkill[4];
//	bool isAlive;
//	vector <SDL_Texture*> hpFrame;
//	vector <SDL_Texture*> standFrame;
//	vector <SDL_Texture*> runFrame;
//	vector <SDL_Texture*> dieFrame;
//	vector <SDL_Texture*> attackFrame;
//	Boss(SDL_Renderer* render);
//	void resetSkill();
//	void bossStand(SDL_Renderer* render);
//	void bossRun(AllCharacters& characters, SDL_Renderer* render);
//	void bossDie(SDL_Renderer* render);
//	void skill1(AllCharacters& chacracters, AllMonsters& monsters, SDL_Renderer* render);
//	void skill2(AllMonsters& monsters, SDL_Renderer* render);
//	void skill3(AllCharacters& chacracters, AllMonsters& monsters, SDL_Renderer* render);
//	void skill4(AllMonsters& monsters, SDL_Renderer* render);
//	void fight(SDL_Renderer* render);
//	void updateHP(SDL_Renderer* render);
//};
//
//#endif boss_h_