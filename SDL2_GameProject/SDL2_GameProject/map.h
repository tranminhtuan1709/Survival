#ifndef map_h_
#define map_h_

#include "initGame.h"
#include "monsters.h"
#include "game.h"
#include "characters.h"

class Item
{
public:
	SDL_Rect position;
	int type;
	int previousFrameTime;
	double angle;
	int existTime;
	int startTime;
	Item(SDL_Rect pos, int t, int x);
};

class MapGame
{
public:
	vector <SDL_Texture*> mapFrame;
	vector <SDL_Texture*> itemFrame;
	vector <SDL_Texture*> otherFrame;
	int randomItemTime;
	int randomItemType;
	int mapNumber;
	vector <Item> itemOnScreen;
	MapGame(SDL_Renderer* render);
	void display(SDL_Renderer* render, AllCharacters& characters, AllMonsters& monsters);
};

#endif map_h_