#pragma once
#ifndef map_h_
#define map_h_

#include "initGame.h"

class Item
{
public:
	SDL_Rect position;
	int startTime;
	int existTime;
	int previousFrameTime;
	double angle;
	Item(SDL_Rect _position, int _startTime, int _existTime, double _angle);
};

class MapGame
{
public:
	int previousRandomItemTime;
	int currentMap;
	string result;
	vector <SDL_Texture*> mapFrame;
	vector <SDL_Texture*> itemFrame;
	vector <vector <Item>> itemOnScreen;
	MapGame(SDL_Renderer* render);
};

#endif map_h_