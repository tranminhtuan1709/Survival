#include "characters.h"
#include "enum.h"

Character::Character(SDL_Renderer* render, int type)
{
	isAlive = true;
	hpTotal = { 0, 0, 0, 0 };
	hpLeft = { 0, 0, 0, 0 };
	delay.initData(CHARACTER_ALLACTION, CHARACTER_ALLACTION, CHARACTER_ALLACTION, CHARACTER_ALLACTION, CHARACTER_ALLSKILL, CHARACTER_ALLSKILL, 0, 0, 0, 0);
	delay.delayFrameTime[CHARACTER_RUN] = 20;
	delay.delayFrameTime[CHARACTER_DIE] = 40;
	delay.delayFrameTime[CHARACTER_ATTACK] = 20;
	delay.delaySkillTime[CHARACTER_NORMAL] = 0;
	if (type == CHARACTER_1) delay.delaySkillTime[CHARACTER_ELEMENTAL] = 2000, delay.delaySkillTime[CHARACTER_ULTI] = 4000;
	if (type == CHARACTER_2) delay.delaySkillTime[CHARACTER_ELEMENTAL] = 2000, delay.delaySkillTime[CHARACTER_ULTI] = 4000;
	if (type == CHARACTER_3) delay.delaySkillTime[CHARACTER_ELEMENTAL] = 10000, delay.delaySkillTime[CHARACTER_ULTI] = 3000;
	if (type == CHARACTER_4) delay.delaySkillTime[CHARACTER_ELEMENTAL] = 1000, delay.delaySkillTime[CHARACTER_ULTI] = 2000;
	stat = { 0, 0, 0, 0 };
	stat[CHARACTER_HP] = 2000;
	stat[CHARACTER_ATK] = 100;
	stat[CHARACTER_DEF] = 5;
	stat[CHARACTER_SPEED] = 10;
	if (type == CHARACTER_1)
	{
		loadImage(HPFrame, "Image/hp", 2, render);
		loadImage(runFrame, "Image/Characters/AnemoChar/run", 12, render);
		loadImage(attackFrame, "Image/Characters/AnemoChar/attack", 8, render);
		loadImage(dieFrame, "Image/Characters/AnemoChar/die", 5, render);
		loadImage(normalFrame, "Image/Characters/AnemoChar/N", 2, render);
		loadImage(elementalFrame, "Image/Characters/AnemoChar/E", 3, render);
		loadImage(ultiFrame, "Image/Characters/AnemoChar/Q", 5, render);
	}
	if (type == CHARACTER_2)
	{
		loadImage(HPFrame, "Image/hp", 2, render);
		loadImage(runFrame, "Image/Characters/ElectroChar/run", 10, render);
		loadImage(attackFrame, "Image/Characters/ElectroChar/attack", 7, render);
		loadImage(dieFrame, "Image/Characters/ElectroChar/die", 5, render);
		loadImage(normalFrame, "Image/Characters/ElectroChar/N", 4, render);
		loadImage(elementalFrame, "Image/Characters/ElectroChar/E", 9, render);
		loadImage(ultiFrame, "Image/Characters/ElectroChar/Q", 10, render);
	}
	if (type == CHARACTER_3)
	{
		loadImage(HPFrame, "Image/hp", 2, render);
		loadImage(runFrame, "Image/Characters/HydroChar/run", 11, render);
		loadImage(attackFrame, "Image/Characters/HydroChar/attack", 4, render);
		loadImage(dieFrame, "Image/Characters/HydroChar/die", 5, render);
		loadImage(normalFrame, "Image/Characters/HydroChar/N", 4, render);
		loadImage(elementalFrame, "Image/Characters/HydroChar/E", 4, render);
		loadImage(ultiFrame, "Image/Characters/HydroChar/Q", 1, render);
	}
	if (type == CHARACTER_4)
	{
		loadImage(HPFrame, "Image/hp", 2, render);
		loadImage(runFrame, "Image/Characters/PyroChar/run", 6, render);
		loadImage(attackFrame, "Image/Characters/PyroChar/attack", 1, render);
		loadImage(dieFrame, "Image/Characters/PyroChar/die", 5, render);
		loadImage(normalFrame, "Image/Characters/PyroChar/N", 1, render);
		loadImage(elementalFrame, "Image/Characters/PyroChar/E_red", 2, render);
		loadImage(ultiFrame, "Image/Characters/PyroChar/E_blue", 2, render);
	}
}

AllCharacters::AllCharacters(SDL_Renderer* render)
{
	selectedChar = CHARACTER_1;
	currentCharHP = new int(2000);
	shield = false;
	allDied = false;
	baseATK = 10;
	baseDEF = 1;
	timeWhenDie = 0;
	timeAfterDie = 1000;
	position = { 0, 0, CHARACTER_WIDTH, CHARACTER_HEIGHT };
	flip = SDL_FLIP_NONE;
	ghost = IMG_LoadTexture(render, "Image/ghost.png");
	Character char1(render, CHARACTER_1); listOfChar.push_back(char1);
	Character char2(render, CHARACTER_2); listOfChar.push_back(char2);
	Character char3(render, CHARACTER_3); listOfChar.push_back(char3);
	Character char4(render, CHARACTER_4); listOfChar.push_back(char4);
}