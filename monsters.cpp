#include "monsters.h"
#include "enum.h"

Monster::Monster(SDL_Renderer* render, int type)
{
	if (type == MONSTER_1)
	{
		loadImage(runFrame, "Image/Monsters/Monster1/mons1_run_", 12, render);
		loadImage(dieFrame, "Image/Monsters/Monster1/mons1_die_", 7, render);
	}
	if (type == MONSTER_2)
	{
		loadImage(runFrame, "Image/Monsters/Monster2/mons2_run_", 8, render);
		loadImage(dieFrame, "Image/Monsters/Monster2/mons2_die_", 4, render);
	}
	if (type == MONSTER_3)
	{
		loadImage(runFrame, "Image/Monsters/Monster3/mons3_run_", 12, render);
		loadImage(dieFrame, "Image/Monsters/Monster3/mons3_die_", 5, render);
		loadImage(attackFrame, "Image/Monsters/Monster3/mons3_attack_", 7, render);
	}
	if (type == MONSTER_4)
	{
		loadImage(runFrame, "Image/Monsters/Monster4/mons4_run_", 4, render);
		loadImage(dieFrame, "Image/Monsters/Monster4/mons4_die_", 5, render);
	}
	if (type == MONSTER_5)
	{
		loadImage(runFrame, "Image/Monsters/Monster5/mons5_run_", 9, render);
		loadImage(dieFrame, "Image/Monsters/Monster5/mons5_die_", 5, render);
	}
	if (type == MONSTER_6)
	{
		loadImage(runFrame, "Image/Monsters/Monster6/mons6_run_", 10, render);
		loadImage(dieFrame, "Image/Monsters/Monster6/mons6_die_", 5, render);
	}
	if (type == MONSTER_7)
	{
		loadImage(runFrame, "Image/Monsters/Monster7/mons7_run_", 7, render);
		loadImage(dieFrame, "Image/Monsters/Monster7/mons7_die_", 5, render);
		loadImage(attackFrame, "Image/Monsters/Monster7/mons7_attack_", 6, render);
	}
	if (type == MONSTER_8)
	{
		loadImage(runFrame, "Image/Monsters/Monster8/frame", 1, render);
	}
}

MonsterInformation::MonsterInformation(int type)
{
	stat = { 0, 0, 0, 0, 0 };
	position = { 0, 0, 0, 0 };
	flip = SDL_FLIP_NONE;
	isChasing = true;
	isAlive = true;
	delay.initData(MONSTER_ALLACTION, MONSTER_ALLACTION, MONSTER_ALLACTION, MONSTER_ALLACTION, 1, 1, 0, 0, 0, 0);
	delay.delayFrameTime[MONSTER_RUN] = 40;
	delay.delayFrameTime[MONSTER_DIE] = 30;
	if (type == MONSTER_5 || type == MONSTER_6 || type == MONSTER_8) delay.delaySkillTime[0] = 5000 + ((rand() + (int)SDL_GetTicks()) % 1000);
	if (type == MONSTER_1) delay.delayFrameTime[MONSTER_ATTACK] = 0, stat[MONSTER_CURRENT_HP] = 500, stat[MONSTER_MAXHP] = 500, stat[MONSTER_ATK] = 4, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 3) + 1;
	if (type == MONSTER_2) delay.delayFrameTime[MONSTER_ATTACK] = 0; stat[MONSTER_CURRENT_HP] = 300, stat[MONSTER_MAXHP] = 300, stat[MONSTER_ATK] = 2, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 2) + 1;
	if (type == MONSTER_3) delay.delayFrameTime[MONSTER_ATTACK] = 60; stat[MONSTER_CURRENT_HP] = 500, stat[MONSTER_MAXHP] = 500, stat[MONSTER_ATK] = 4, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 3) + 1;
	if (type == MONSTER_4) delay.delayFrameTime[MONSTER_ATTACK] = 0; stat[MONSTER_CURRENT_HP] = 500, stat[MONSTER_MAXHP] = 500, stat[MONSTER_ATK] = 2, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = 20;
	if (type == MONSTER_5) delay.delayFrameTime[MONSTER_ATTACK] = 5000; stat[MONSTER_CURRENT_HP] = 600, stat[MONSTER_MAXHP] = 600, stat[MONSTER_ATK] = 4, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 2) + 1;
	if (type == MONSTER_6) delay.delayFrameTime[MONSTER_ATTACK] = 5000; stat[MONSTER_CURRENT_HP] = 600, stat[MONSTER_MAXHP] = 600, stat[MONSTER_ATK] = 2, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = 1;
	if (type == MONSTER_7) delay.delayFrameTime[MONSTER_ATTACK] = 100; stat[MONSTER_CURRENT_HP] = 500, stat[MONSTER_MAXHP] = 500, stat[MONSTER_ATK] = 6, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 2) + 1;
	if (type == MONSTER_8) delay.delayFrameTime[MONSTER_ATTACK] = 6000; stat[MONSTER_CURRENT_HP] = 500, stat[MONSTER_MAXHP] = 500, stat[MONSTER_ATK] = 10, stat[MONSTER_DEF] = 10, stat[MONSTER_SPEED] = (rand() % 3) + 1;
}

AllMonsters::AllMonsters(SDL_Renderer* render)
{
	previousRandomTime = SDL_GetTicks();
	Monster mons1(render, MONSTER_1); listOfMons.push_back(mons1);
	Monster mons2(render, MONSTER_2); listOfMons.push_back(mons2);
	Monster mons3(render, MONSTER_3); listOfMons.push_back(mons3);
	Monster mons4(render, MONSTER_4); listOfMons.push_back(mons4);
	Monster mons5(render, MONSTER_5); listOfMons.push_back(mons5);
	Monster mons6(render, MONSTER_6); listOfMons.push_back(mons6);
	Monster mons7(render, MONSTER_7); listOfMons.push_back(mons7);
	Monster mons8(render, MONSTER_8); listOfMons.push_back(mons8);
	vector <MonsterInformation> temp;
	for (int i = 0; i < ALLMONSTER; i++) monsterOnScreen.push_back(temp);
	bulletMons = IMG_LoadTexture(render, "Image/Monsters/bullet.png");
	hp1 = IMG_LoadTexture(render, "Image/hp1.png");
	hp2 = IMG_LoadTexture(render, "Image/hp2.png");
}