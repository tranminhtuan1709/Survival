#include "characters.h"

bullet::bullet()
{
	type = "";
	currentBulletPos = { 0, 0, 0, 0 };
	boom = { 0, 0, 0, 0 };
	damage = 0;
	currentBulletFrame = 0;
	previousFrameTime = SDL_GetTicks();
	step = 0;
	existTime = 0;
	startTime = SDL_GetTicks();
	check = true;
	a = 0;
	b = 0;
	flip = SDL_FLIP_NONE;
	bulletLine.a = 0;
	bulletLine.b = 0;
	bulletLine.alpha = 0;
}

anemoChar::anemoChar()
{
	HP = 1000;
	atk = 3000;
	def = 20;
	speed = 5;

	currentHPFrame = 0;
	currentRunFrame = 0;
	currentDieFrame = 0;
	currentAttackFrame = 0;
	previousFrameTimeRun = 0;
	previousFrameTimeDie = 0;

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks();
	previousFrameTimeDie = SDL_GetTicks();
	previousTimeAttack = SDL_GetTicks();
}

void anemoChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/Characters/AnemoChar/HP", 2, render);
	loadImage(runFrame, "Image/Characters/AnemoChar/run", 12, render);
	loadImage(attackFrame, "Image/Characters/AnemoChar/attack", 8, render);
	loadImage(dieFrame, "Image/Characters/AnemoChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/AnemoChar/N", 2, render);
	loadImage(elementalFrame, "Image/Characters/AnemoChar/E", 3, render);
	loadImage(ultiFrame, "Image/Characters/AnemoChar/Q", 5, render);
}

void anemoChar::updateStat(string type, anemoChar& char1, int& currentHP)
{
	char1.HP = currentHP;
	if (type == "ATK") atk += 50;
	else if (type == "HP") HP += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

electroChar::electroChar()
{
	HP = 1000;
	atk = 3000;
	def = 15;
	speed = 5;

	currentHPFrame = 0;
	currentRunFrame = 0;
	currentDieFrame = 0;
	currentAttackFrame = 0;

	int currentHPFrame = 0;
	int currentRunFrame = 0;
	int currentAttackFrame = 0;
	int currentDieFrame = 0;

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks();
	previousFrameTimeDie = SDL_GetTicks();
	previousTimeAttack = SDL_GetTicks();
}

void electroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/Characters/ElectroChar/HP", 2, render);
	loadImage(runFrame, "Image/Characters/ElectroChar/run", 10, render);
	loadImage(attackFrame, "Image/Characters/ElectroChar/attack", 7, render);
	loadImage(dieFrame, "Image/Characters/ElectroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/ElectroChar/N", 4, render);
	loadImage(elementalFrame, "Image/Characters/ElectroChar/E", 9, render);
	loadImage(ultiFrame, "Image/Characters/ElectroChar/Q", 10, render);
}

void electroChar::updateStat(string type, anemoChar& char1, int& currentHP)
{
	char1.HP = currentHP;
	if (type == "ATK") atk += 50;
	else if (type == "HP") HP += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

hydroChar::hydroChar()
{
	HP = 1000;
	atk = 3000;
	def = 15;
	speed = 5;
	use_E_skill = false;

	currentHPFrame = 0;
	currentRunFrame = 0;
	currentDieFrame = 0;
	currentAttackFrame = 0;

	int currentHPFrame = 0;
	int currentRunFrame = 0;
	int currentAttackFrame = 0;
	int currentDieFrame = 0;

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks();
	previousFrameTimeDie = SDL_GetTicks();
	previousTimeAttack = SDL_GetTicks();
}

void hydroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/Characters/HydroChar/HP", 2, render);
	loadImage(runFrame, "Image/Characters/HydroChar/run", 11, render);
	loadImage(attackFrame, "Image/Characters/HydroChar/attack", 4, render);
	loadImage(dieFrame, "Image/Characters/HydroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/HydroChar/N", 4, render);
	loadImage(elementalFrame, "Image/Characters/HydroChar/E", 4, render);
	loadImage(ultiFrame, "Image/Characters/HydroChar/Q", 1, render);
}

void hydroChar::updateStat(string type, anemoChar& char1, int& currentHP)
{
	char1.HP = currentHP;
	if (type == "ATK") atk += 50;
	else if (type == "HP") HP += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

pyroChar::pyroChar()
{
	HP = 1500;
	atk = 3000;
	def = 20;
	speed = 5;

	currentHPFrame = 0;
	currentRunFrame = 0;
	currentDieFrame = 0;
	currentAttackFrame = 0;

	int currentHPFrame = 0;
	int currentRunFrame = 0;
	int currentAttackFrame = 0;
	int currentDieFrame = 0;

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks();
	previousFrameTimeDie = SDL_GetTicks();
	previousTimeAttack = SDL_GetTicks();
}

void pyroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/Characters/PyroChar/HP", 2, render);
	loadImage(runFrame, "Image/Characters/PyroChar/run", 6, render);
	loadImage(attackFrame, "Image/Characters/PyroChar/attack", 1, render);
	loadImage(dieFrame, "Image/Characters/PyroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/PyroChar/N", 1, render);
	loadImage(elementalFrame, "Image/Characters/PyroChar/E_red", 2, render);
	loadImage(ultiFrame, "Image/Characters/PyroChar/E_blue", 2, render);
}

void pyroChar::updateStat(string type, anemoChar& char1, int& currentHP)
{
	char1.HP = currentHP;
	if (type == "ATK") atk += 50;
	if (type == "HP") HP += 500;
	if (type == "DEF") def += 10;
	if (type == "SPEED") speed += 5;
}

AllCharacters::AllCharacters(SDL_Renderer* render)
{
	char1.loadData(render);
	char2.loadData(render);
	char3.loadData(render);
	char4.loadData(render);
	selectedChar = 1;
	currentCharHP = &char1.HP;
	currentCharPosition = { 0, 0, 50, 50 };
	currentCharDirection = "right";
	shield = false;
}