#include "map.h"

Item::Item(SDL_Rect pos, int t, int x)
{
	position = pos;
	type = t;
	previousFrameTime = x;
	angle = 5;
	existTime = 30000;
	startTime = SDL_GetTicks();
}

MapGame::MapGame(SDL_Renderer* render)
{
	loadImage(mapFrame, "Image/Map/map", 2, render);
	loadImage(itemFrame, "Image/Map/item", 3, render);
	//loadImage(otherFrame, "Image/Map/other", 2, render);
	randomItemTime = SDL_GetTicks();
	randomItemType = 0;
	mapNumber = 1;
}

void MapGame::display(SDL_Renderer* render, AllCharacters& characters)
{
	mapNumber == 1 ? SDL_RenderCopy(render, mapFrame[0], NULL, NULL) : SDL_RenderCopy(render, mapFrame[1], NULL, NULL);
	if (cooldown(randomItemTime, 3000) == true)
	{
		srand((int)time(0));
		randomItemType = (rand() + (int)SDL_GetTicks()) % 3;
		SDL_Rect temp = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 50, 50 };
		Item it(temp, randomItemType, 0);
		itemOnScreen.push_back(it);
	}
	for (int i = 0; i < itemOnScreen.size(); i++)
	{
		if (itemOnScreen[i].startTime + itemOnScreen[i].existTime <= (int)SDL_GetTicks())
		{
			itemOnScreen.erase(itemOnScreen.begin() + i, itemOnScreen.begin() + i + 1);
			i--;
		}
		else if (checkCollision(itemOnScreen[i].position, characters.currentCharPosition) == true)
		{
			if (itemOnScreen[i].type == 0) *characters.currentCharHP = min(2000, *characters.currentCharHP + 300);
			if (itemOnScreen[i].type == 1) characters.baseATK += 5;
			if (itemOnScreen[i].type == 2) characters.baseDEF += 10;
			itemOnScreen.erase(itemOnScreen.begin() + i, itemOnScreen.begin() + i + 1);
			i--;
		}
		else
		{
			SDL_RenderCopyEx(render, itemFrame[itemOnScreen[i].type], NULL, &itemOnScreen[i].position, itemOnScreen[i].angle, NULL, SDL_FLIP_NONE);
			if (cooldown(itemOnScreen[i].previousFrameTime, 150) == true)
			{
				itemOnScreen[i].angle = 0 - itemOnScreen[i].angle;
			}
		}
	}
}