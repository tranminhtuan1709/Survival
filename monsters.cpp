#include "monsters.h"
#include "game.h"

Monster1::Monster1(SDL_Renderer* render)
{
	loadImage(runFrame, "Image/Monsters/mons1_run_", 13, render);
	loadImage(dieFrame, "Image/Monsters/mons1_die_", 7, render);
}

void randomMonster(MonsterProperties& monster, MonsterOnscreen& defaulMons)
{
	srand((int)time(0));
	monster.currentMonsPos = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
	monster.monSizeW = 60;
	monster.monSizeH = 60;
	monster.currentMonsHP = 300;
	monster.currentMonsSpeed = (rand() % 3) + 1;
	monster.flip = SDL_FLIP_NONE;
	monster.currentMonsFrame = 0;
	monster.delayFrameTime = SDL_GetTicks();
	monster.typeOfMons = "Monster1";
	defaulMons.allMonster.push_back(monster);
}

void chase(MonsterOnscreen& monster, CharacterOnScreen& character, SDL_Renderer* render, Monster1& mons1)
{
	for (int i = 0; i < monster.allMonster.size(); i++)
	{
		if (monster.allMonster[i].currentMonsHP <= 0)
		{
			monster.allMonster.erase(monster.allMonster.begin() + i, monster.allMonster.begin() + i + 1);
			i--;
		}
		else
		{
			if (monster.allMonster[i].currentMonsPos.x + 60 <= character.currentCharPosition.x)
			{
				monster.allMonster[i].currentMonsPos.x += monster.allMonster[i].currentMonsSpeed;
				monster.allMonster[i].flip = SDL_FLIP_NONE;
			}
			if (monster.allMonster[i].currentMonsPos.x >= character.currentCharPosition.x + 50)
			{
				monster.allMonster[i].currentMonsPos.x -= monster.allMonster[i].currentMonsSpeed;
				monster.allMonster[i].flip = SDL_FLIP_HORIZONTAL;
			}
			if (monster.allMonster[i].currentMonsPos.y >= character.currentCharPosition.y + 50)
			{
				monster.allMonster[i].currentMonsPos.y -= monster.allMonster[i].currentMonsSpeed;
			}
			if (monster.allMonster[i].currentMonsPos.y + 60 <= character.currentCharPosition.y)
			{
				monster.allMonster[i].currentMonsPos.y += monster.allMonster[i].currentMonsSpeed;
			}
			if (monster.allMonster[i].typeOfMons == "Monster1")
			{
				SDL_RenderCopyEx(render, mons1.runFrame[monster.allMonster[i].currentMonsFrame], NULL, &monster.allMonster[i].currentMonsPos, 0, NULL, monster.allMonster[i].flip);
				if (cooldown(monster.allMonster[i].delayFrameTime, 20) == true)
				{
					monster.allMonster[i].currentMonsFrame = (monster.allMonster[i].currentMonsFrame + 1) % (int)mons1.runFrame.size();
				}
			}
		}
	}
}

void beAttacked(anemoChar& char1, electroChar& char2, hydroChar& char3, pyroChar& char4, MonsterOnscreen& defaultMons)
{
	for (int i = 0; i < char1.bulletOnScreen.size(); i++)
	{
		for (int j = 0; j < defaultMons.allMonster.size(); j++)
		{
			int a1 = char1.bulletOnScreen[i].currentBulletPos.x;
			int b1 = char1.bulletOnScreen[i].currentBulletPos.y;
			int w1 = char1.bulletOnScreen[i].bulletSizeW;
			int h1 = char1.bulletOnScreen[i].bulletSizeH;

			int a2 = defaultMons.allMonster[j].currentMonsPos.x;
			int b2 = defaultMons.allMonster[j].currentMonsPos.y;
			int w2 = defaultMons.allMonster[j].monSizeW;
			int h2 = defaultMons.allMonster[j].monSizeH;

			if (a1 + w1 >= a2 && a2 + w2 >= a1 && b1 + w1 >= b2 && b2 + w2 >= b1)
			{
				defaultMons.allMonster[j].currentMonsHP -= char1.atk;
				if (char1.bulletOnScreen[i].type == "N" || char1.bulletOnScreen[i].type == "E")
				{
					char1.bulletOnScreen[i].check = false;
				}
			}
		}
	}
	
	for (int i = 0; i < char2.bulletOnScreen.size(); i++)
	{
		for (int j = 0; j < defaultMons.allMonster.size(); j++)
		{
			int a1 = char2.bulletOnScreen[i].currentBulletPos.x;
			int b1 = char2.bulletOnScreen[i].currentBulletPos.y;
			int w1 = char2.bulletOnScreen[i].bulletSizeW;
			int h1 = char2.bulletOnScreen[i].bulletSizeH;

			int a2 = defaultMons.allMonster[j].currentMonsPos.x;
			int b2 = defaultMons.allMonster[j].currentMonsPos.y;
			int w2 = defaultMons.allMonster[j].monSizeW;
			int h2 = defaultMons.allMonster[j].monSizeH;

			if (a1 + w1 >= a2 && a2 + w2 >= a1 && b1 + w1 >= b2 && b2 + w2 >= b1)
			{
				defaultMons.allMonster[j].currentMonsHP -= char2.atk;
				if (char2.bulletOnScreen[i].type == "E")
				{
					char2.bulletOnScreen[i].check = false;
				}
			}
		}
	}

	for (int i = 0; i < char3.bulletOnScreen.size(); i++)
	{
		for (int j = 0; j < defaultMons.allMonster.size(); j++)
		{
			int a1 = char3.bulletOnScreen[i].currentBulletPos.x;
			int b1 = char3.bulletOnScreen[i].currentBulletPos.y;
			int w1 = char3.bulletOnScreen[i].bulletSizeW;
			int h1 = char3.bulletOnScreen[i].bulletSizeH;

			int a2 = defaultMons.allMonster[j].currentMonsPos.x;
			int b2 = defaultMons.allMonster[j].currentMonsPos.y;
			int w2 = defaultMons.allMonster[j].monSizeW;
			int h2 = defaultMons.allMonster[j].monSizeH;

			if (a1 + w1 >= a2 && a2 + w2 >= a1 && b1 + w1 >= b2 && b2 + w2 >= b1)
			{
				defaultMons.allMonster[j].currentMonsHP -= char3.atk;
				if (char3.bulletOnScreen[i].type == "N")
				{
					char3.bulletOnScreen[i].check = false;
				}
			}
		}
	}
}
