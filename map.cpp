#include "map.h"
#include "enum.h"

Item::Item(SDL_Rect _position, int _startTime, int _existTime, double _angle)
{
	position = _position;
	startTime = _startTime;
	existTime = _existTime;
	previousFrameTime = SDL_GetTicks();
	angle = _angle;
}

MapGame::MapGame(SDL_Renderer* render)
{
	previousRandomItemTime = SDL_GetTicks();
	currentMap = MAP_1;
	loadImage(mapFrame, "Image/Map/map", 2, render);
	loadImage(itemFrame, "Image/Map/item", 3, render);
	vector <Item> temp;
	itemOnScreen = { temp, temp, temp };
	result = "";
}