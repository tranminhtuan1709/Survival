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

void MapGame::display(SDL_Renderer* render, AllCharacters& characters, AllMonsters& monsters)
{
	mapNumber == 1 ? SDL_RenderCopy(render, mapFrame[0], NULL, NULL) : SDL_RenderCopy(render, mapFrame[1], NULL, NULL);
	if (mapNumber == 2)
	{
		for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
		{
			if (monsters.monsterOnScreen[i].type == "green_dinosaur" || monsters.monsterOnScreen[i].type == "mushroom" || monsters.monsterOnScreen[i].type == "red_dinosaur" || monsters.monsterOnScreen[i].type == "pterosaurs")
			{
				monsters.monsterOnScreen.erase(monsters.monsterOnScreen.begin() + i, monsters.monsterOnScreen.begin() + i + 1);
				i--;
			}
		}
		if (monsters.mons8.checkRandom == true)
		{
			MonsterInformation temp1;
			MonsterInformation temp2;
			MonsterInformation temp3;
			MonsterInformation temp4;
			temp1.atk = 10;
			temp2.atk = 10;
			temp3.atk = 10;
			temp4.atk = 10;
			temp1.position = { 0, 200, 100, 60 };
			temp2.position = { 0, 600, 100, 60 };
			temp3.position = { 1700, 400, 100, 60 };
			temp4.position = { 1700, 800, 100, 60 };
			temp3.flip = SDL_FLIP_HORIZONTAL;
			temp4.flip = SDL_FLIP_HORIZONTAL;
			temp1.delayFrameTimeAttack = 5000;
			temp2.delayFrameTimeAttack = 5000;
			temp3.delayFrameTimeAttack = 5000;
			temp4.delayFrameTimeAttack = 5000;
			temp1.type = "canon";
			temp2.type = "canon";
			temp3.type = "canon";
			temp4.type = "canon";
			temp1.HP = 1;
			temp2.HP = 2;
			temp3.HP = 3;
			temp4.HP = 4;
			monsters.monsterOnScreen.push_back(temp1);
			monsters.monsterOnScreen.push_back(temp2);
			monsters.monsterOnScreen.push_back(temp3);
			monsters.monsterOnScreen.push_back(temp4);
			monsters.mons8.checkRandom = false;
		}
	}
	if (mapNumber == 1)
	{
		for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
		{
			if (monsters.monsterOnScreen[i].type == "robot" || monsters.monsterOnScreen[i].type == "machine" || monsters.monsterOnScreen[i].type == "cyborg" || monsters.monsterOnScreen[i].type == "canon")
			{
				monsters.monsterOnScreen.erase(monsters.monsterOnScreen.begin() + i, monsters.monsterOnScreen.begin() + i + 1);
				i--;
			}
		}
	}
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
			if (itemOnScreen[i].type == 1) characters.baseATK = min(characters.baseATK + 30, 300);
			if (itemOnScreen[i].type == 2) characters.baseDEF = min(characters.baseDEF + 3, 50);
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