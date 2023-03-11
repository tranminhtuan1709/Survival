#include "characters.h"

bullet::bullet(string s, SDL_Rect pos, int f, int previous, int st)
{
	type = s;
	currentBulletPos = pos;
	currentBulletFrame = f;
	previousTime = previous;
	step = st;
	existTime = 7;
	startTime = 0;
	a = 0;
	b = 0;
	flip = SDL_FLIP_NONE;
}

anemoChar::anemoChar(int x, int y, SDL_Renderer* render)
{
	hp = 1000;
	atk = 150;
	def = 20;
	speed = 10;

	currentCharFrame = 0;
	currentCharPos = { x, y, 50, 50 };

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();

	loadImage(hpFrame, "Image/Characters/AnemoChar/hp", 2, render);
	loadImage(runFrame, "Image/Characters/AnemoChar/run", 12, render);
	loadImage(attackFrame, "Image/Characters/AnemoChar/attack", 8, render);
	loadImage(dieFrame, "Image/Characters/AnemoChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/AnemoChar/N", 2, render);
	loadImage(elementalFrame, "Image/Characters/AnemoChar/E", 3, render);
	loadImage(ultiFrame, "Image/Characters/AnemoChar/Q", 5, render);
}

void anemoChar::updateStat(string type)
{
	if (type == "ATK") atk += 50;
	else if (type == "HP") hp += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

electroChar::electroChar(int x, int y, SDL_Renderer* render)
{
	hp = 1000;
	atk = 150;
	def = 15;
	speed = 15;
	
	currentCharFrame = 0;
	currentCharPos = { x, y, 50, 50 };

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();

	loadImage(hpFrame, "Image/Characters/ElectroChar/hp", 2, render);
	loadImage(runFrame, "Image/Characters/ElectroChar/run", 10, render);
	loadImage(attackFrame, "Image/Characters/ElectroChar/attack", 7, render);
	loadImage(dieFrame, "Image/Characters/ElectroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/ElectroChar/N", 4, render);
	loadImage(elementalFrame, "Image/Characters/ElectroChar/E", 3, render);
	loadImage(ultiFrame, "Image/Characters/ElectroChar/Q", 10, render);
}

void electroChar::updateStat(string type)
{
	if (type == "ATK") atk += 50;
	else if (type == "HP") hp += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

hydroChar::hydroChar(int x, int y, SDL_Renderer* render)
{
	hp = 1000;
	atk = 150;
	def = 15;
	speed = 15;

	currentCharFrame = 0;
	currentCharPos = { x, y, 50, 50 };

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();

	loadImage(hpFrame, "Image/Characters/HydroChar/hp", 2, render);
	loadImage(runFrame, "Image/Characters/HydroChar/run", 11, render);
	loadImage(attackFrame, "Image/Characters/HydroChar/attack", 4, render);
	loadImage(dieFrame, "Image/Characters/HydroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/HydroChar/N", 4, render);
	loadImage(elementalFrame, "Image/Characters/HydroChar/E", 4, render);
	loadImage(ultiFrame, "Image/Characters/HydroChar/Q", 1, render);
}

void hydroChar::updateStat(string type)
{
	if (type == "ATK") atk += 50;
	else if (type == "HP") hp += 500;
	else if (type == "DEF") def += 10;
	else if (type == "SPEED") speed += 5;
}

pyroChar::pyroChar(int x, int y, SDL_Renderer* render)
{
	hp = 1500;
	atk = 90;
	def = 20;
	speed = 15;
	
	currentCharFrame = 0;
	currentCharPos = { x, y, 50, 50 };

	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();

	loadImage(hpFrame, "Image/Characters/PyroChar/hp", 2, render);
	loadImage(runFrame, "Image/Characters/PyroChar/run", 6, render);
	loadImage(attackFrame, "Image/Characters/PyroChar/attack", 1, render);
	loadImage(dieFrame, "Image/Characters/PyroChar/die", 5, render);
	loadImage(normalFrame, "Image/Characters/PyroChar/N", 1, render);
	loadImage(elementalFrame, "Image/Characters/PyroChar/E_red", 2, render);
	loadImage(ultiFrame, "Image/Characters/PyroChar/E_blue", 2, render);
}

void pyroChar::updateStat(string type)
{
	if (type == "ATK") atk += 50;
	if (type == "HP") hp += 500;
	if (type == "DEF") def += 10;
	if (type == "SPEED") speed += 5;
}