#include "monsters.h"
#include "game.h"

Monster1::Monster1(SDL_Renderer* render)
{
	loadImage(runFrame, "Image/Monsters/mons1_run_", 13, render);
	loadImage(dieFrame, "Image/Monsters/mons1_die_", 7, render);
}

void randomMonster(MonsterOnscreen& monster)
{
	srand((int)time(0));
	monster.currentMonsPos = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
	monster.currentMonsHP = 200;
	monster.currentMonsSpeed = 1;
	monster.flip = SDL_FLIP_NONE;
	monster.currentMonsFrame = 0;
	monster.delayFrameTime = SDL_GetTicks();
	monster.typeOfMons = "Monster1";
	monster.allMonster.push_back(monster);
}

void chase(MonsterOnscreen& monster, CharacterOnScreen& character, SDL_Renderer* render, Monster1& mons1)
{
	for (int i = 0; i < monster.allMonster.size(); i++)
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
		SDL_Point center_mons = { monster.allMonster[i].currentMonsPos.x + 30, monster.allMonster[i].currentMonsPos.y + 30};
		SDL_Point center_char = { character.currentCharPosition.x + 25, character.currentCharPosition.y + 25};
		if ((center_char.x - center_mons.x) * (center_char.x - center_mons.x) + (center_char.y - center_mons.y) * (center_char.y - center_mons.y) <= 60 * 60)
		{
			character.currentCharHP -= 5;
		}
		if (monster.allMonster[i].currentMonsHP <= 0)
		{
			monster.allMonster.erase(monster.allMonster.begin() + i, monster.allMonster.begin() + i + 1);
			i--;
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
