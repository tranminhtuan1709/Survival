#pragma once
#ifndef menu_h_
#define menu_h_

#include "game.h"

class Menu
{
public:
	vector <bool> mousePos;
	vector <bool> click;
	vector <bool> state;
	vector <SDL_Rect> position;
	vector <vector <SDL_Texture*>> frame;
	SDL_Texture* gameover;
	Menu(SDL_Renderer* render);
	void checkMousePos(SDL_Point& p);
	void checkClick(SDL_Event& e);
	void updateMenuStatus();
	void display(SDL_Renderer* render);
	bool pause(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, SDL_Renderer* render);
	void play(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, App& app);
	void reset(AllCharacters& characters, AllMonsters& monsters, MapGame& maps);
	void start();
	void help();
	void updateGameStatus();
};


#endif menu_h_