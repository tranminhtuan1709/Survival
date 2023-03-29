#include "monsters.h"
#include "game.h"

void Monster1::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster1/mons1_run_", 13, render);
	loadImage(dieFrame, "Image/Monsters/Monster1/mons1_die_", 7, render);
}

void Monster2::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster2/mons2_run_", 8, render);
	loadImage(dieFrame, "Image/Monsters/Monster2/mons2_die_", 4, render);
}

void Monster3::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster3/mons3_run_", 12, render);
	loadImage(dieFrame, "Image/Monsters/Monster3/mons3_die_", 5, render);
	loadImage(attackFrame, "Image/Monsters3/Monster3/mons3_attack_", 7, render);
}

void Monster4::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster4/mons4_run_", 4, render);
	loadImage(dieFrame, "Image/Monsters/Monster4/mons4_die_", 5, render);
}

void Monster5::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster5/mons5_run_", 9, render);
	loadImage(dieFrame, "Image/Monsters/Monster5/mons5_die_", 5, render);
}

void Monster6::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster6/mons6_run_", 10, render);
	loadImage(dieFrame, "Image/Monsters/Monster6/mons6_die_", 5, render);
}

void Monster7::loadData(SDL_Renderer* render)
{
	loadImage(hpFrame, "Image/hp", 2, render);
	loadImage(runFrame, "Image/Monsters/Monster7/mons7_run_", 7, render);
	loadImage(dieFrame, "Image/Monsters/Monster7/mons7_die_", 5, render);
	loadImage(attackFrame, "Image/Monsters/Monster7/mons7_attack_", 7, render);
}


AllMonsters::AllMonsters(SDL_Renderer* render)
{
	mons1.loadData(render);
	mons2.loadData(render);
	mons3.loadData(render);
	mons4.loadData(render);
	mons5.loadData(render);
	mons6.loadData(render);
	mons7.loadData(render);
}

void randomMonster(AllMonsters& monsters, int monsType)
{
	if (cooldown(monsters.previousRandomTime, 3000) == false)
	{
		return;
	}
	srand((int)time(0));
	MonsterInformation monsInfor;
	if (monsType == 1)
	{
		monsInfor.HP = 300;
		monsInfor.atk = 20;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 3) + 1;
		monsInfor.monsSizeW = 60;
		monsInfor.monsSizeH = 60;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "green_dinosaur";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 2)
	{
		monsInfor.HP = 300;
		monsInfor.atk = 10;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.monsSizeW = 30;
		monsInfor.monsSizeH = 30;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 30, 30 };
		monsInfor.direction = "right";
		monsInfor.type = "mushroom";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 3)
	{
		monsInfor.HP = 300;
		monsInfor.atk = 40;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 3) + 1;
		monsInfor.monsSizeW = 60;
		monsInfor.monsSizeH = 60;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "red_dinosaur";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 4)
	{
		monsInfor.HP = 300;
		monsInfor.atk = 15;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 4) + 1;
		monsInfor.monsSizeW = 40;
		monsInfor.monsSizeH = 30;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 40, 30 };
		monsInfor.direction = "right";
		monsInfor.type = "pterosaurs";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 5)
	{
		monsInfor.HP = 600;
		monsInfor.atk = 30;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.monsSizeW = 60;
		monsInfor.monsSizeH = 60;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "robot";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 6)
	{
		monsInfor.HP = 600;
		monsInfor.atk = 20;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.monsSizeW = 60;
		monsInfor.monsSizeH = 60;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "machine";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
	if (monsType == 7)
	{
		monsInfor.HP = 600;
		monsInfor.atk = 20;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.monsSizeW = 60;
		monsInfor.monsSizeH = 60;
		monsInfor.currentFrameHP = 0;
		monsInfor.currentFrameRun = 0;
		monsInfor.currentFrameDie = 0;
		monsInfor.currentFrameAttack = 0;
		monsInfor.previousTimeFrameRun = 20;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "soldier";
		monsters.monsterOnscreen.push_back(monsInfor);
	}
}

void chase(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnscreen.size(); i++)
	{
		if (monsters.monsterOnscreen[i].HP <= 0)
		{
			monsters.monsterOnscreen.erase(monsters.monsterOnscreen.begin() + i, monsters.monsterOnscreen.begin() + i + 1);
			i--;
		}
		else if (monsters.monsterOnscreen[i].type == "green_dinosaur" || monsters.monsterOnscreen[i].type == "red_dinosaur" || monsters.monsterOnscreen[i].type == "mushroom")
		{
			if (monsters.monsterOnscreen[i].position.x + 50 <= characters.currentCharPosition.x && cooldown(monsters.monsterOnscreen[i].step, 20) == true)
			{
				monsters.monsterOnscreen[i].position.x += monsters.monsterOnscreen[i].speed;
				monsters.monsterOnscreen[i].flip = SDL_FLIP_NONE;
			}
			if (monsters.monsterOnscreen[i].position.x >= characters.currentCharPosition.x + 50 && cooldown(monsters.monsterOnscreen[i].step, 20) == true)
			{
				monsters.monsterOnscreen[i].position.x -= monsters.monsterOnscreen[i].speed;
				monsters.monsterOnscreen[i].flip = SDL_FLIP_HORIZONTAL;
			}
			if (monsters.monsterOnscreen[i].position.y >= characters.currentCharPosition.y + 50 && cooldown(monsters.monsterOnscreen[i].step, 20) == true)
			{
				monsters.monsterOnscreen[i].position.y -= monsters.monsterOnscreen[i].speed;
			}
			if (monsters.monsterOnscreen[i].position.y + 50 <= characters.currentCharPosition.y && cooldown(monsters.monsterOnscreen[i].step, 20) == true)
			{
				monsters.monsterOnscreen[i].position.y += monsters.monsterOnscreen[i].speed;
			}
			if (monsters.monsterOnscreen[i].type == "green_dinosaur")
			{
				SDL_RenderCopyEx(render, monsters.mons1.runFrame[monsters.monsterOnscreen[i].currentFrameRun], NULL, &monsters.monsterOnscreen[i].position, 0, NULL, monsters.monsterOnscreen[i].flip);
				if (cooldown(monsters.monsterOnscreen[i].previousTimeFrameRun, 20) == true)
				{
					monsters.monsterOnscreen[i].currentFrameRun = (monsters.monsterOnscreen[i].currentFrameRun + 1) % (int)monsters.mons1.runFrame.size();
				}
			}
			if (monsters.monsterOnscreen[i].type == "red_dinosaur")
			{
				SDL_RenderCopyEx(render, monsters.mons3.runFrame[monsters.monsterOnscreen[i].currentFrameRun], NULL, &monsters.monsterOnscreen[i].position, 0, NULL, monsters.monsterOnscreen[i].flip);
				if (cooldown(monsters.monsterOnscreen[i].previousTimeFrameRun, 25) == true)
				{
					monsters.monsterOnscreen[i].currentFrameRun = (monsters.monsterOnscreen[i].currentFrameRun + 1) % (int)monsters.mons3.runFrame.size();
				}
			}
			if (monsters.monsterOnscreen[i].type == "mushroom")
			{
				SDL_RenderCopyEx(render, monsters.mons2.runFrame[monsters.monsterOnscreen[i].currentFrameRun], NULL, &monsters.monsterOnscreen[i].position, 0, NULL, monsters.monsterOnscreen[i].flip);
				if (cooldown(monsters.monsterOnscreen[i].previousTimeFrameRun, 20) == true)
				{
					monsters.monsterOnscreen[i].currentFrameRun = (monsters.monsterOnscreen[i].currentFrameRun + 1) % (int)monsters.mons2.runFrame.size();
				}
			}
		}
	}
}

void beAttacked(AllMonsters& monsters, AllCharacters& characters)
{
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		for (int j = 0; j < monsters.monsterOnscreen.size(); j++)
		{
			
		}
	}
}
