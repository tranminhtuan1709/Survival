#include "characters.h"
#include "game.h"

bullet::bullet()
{
	type = "";
	currentBulletPos = { 0, 0, 0, 0 };
	boom = { 0, 0, 0, 0 };
	damage = 0;
	currentFrame = 0;
	previousFrameTime = SDL_GetTicks(); delayFrameTime = 0; currentFrame = 0; checkFrame = false;
	startTime = SDL_GetTicks();
	existTime = 0;
	checkExist = true;
	flip = SDL_FLIP_NONE;
	alpha = 0;
	d = 0;
}

anemoChar::anemoChar()
{
	isAlive = true;
	HP = 2000;
	atk = 100;
	def = 10;
	speed = 10;
	currentFrameHP = 0;
	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks(); delayFrameTimeRun = 20; currentFrameRun = 0; checkFrameRun = false;
	previousFrameTimeDie = SDL_GetTicks(); delayFrameTimeDie = 40; currentFrameDie = 0; checkFrameDie = false;
	previousFrameTimeAttack = SDL_GetTicks(); delayFrameTimeAttack = 20; currentFrameAttack = 0; checkFrameAttack = false;
}

void anemoChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/hp", 2, render);
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
	isAlive = true;
	HP = 2000;
	atk = 100;
	def = 10;
	speed = 10;
	currentFrameHP = 0;
	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks(); delayFrameTimeRun = 20; currentFrameRun = 0; checkFrameRun = false;
	previousFrameTimeDie = SDL_GetTicks(); delayFrameTimeDie = 40; currentFrameDie = 0; checkFrameDie = false;
	previousFrameTimeAttack = SDL_GetTicks(); delayFrameTimeAttack = 20; currentFrameAttack = 0; checkFrameAttack = false;
}

void electroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/hp", 2, render);
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
	isAlive = true;
	HP = 2000;
	atk = 100;
	def = 10;
	speed = 10;
	currentFrameHP = 0;
	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks(); delayFrameTimeRun = 20; currentFrameRun = 0; checkFrameRun = false;
	previousFrameTimeDie = SDL_GetTicks(); delayFrameTimeDie = 40; currentFrameDie = 0; checkFrameDie = false;
	previousFrameTimeAttack = SDL_GetTicks(); delayFrameTimeAttack = 20; currentFrameAttack = 0; checkFrameAttack = false;
}

void hydroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/hp", 2, render);
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
	isAlive = true;
	HP = 2000;
	atk = 100;
	def = 10;
	speed = 10;
	currentFrameHP = 0;
	previousTimeN = SDL_GetTicks();
	previousTimeE = SDL_GetTicks();
	previousTimeQ = SDL_GetTicks();
	previousFrameTimeRun = SDL_GetTicks(); delayFrameTimeRun = 20; currentFrameRun = 0; checkFrameRun = false;
	previousFrameTimeDie = SDL_GetTicks(); delayFrameTimeDie = 40; currentFrameDie = 0; checkFrameDie = false;
	previousFrameTimeAttack = SDL_GetTicks(); delayFrameTimeAttack = 20; currentFrameAttack = 0; checkFrameAttack = false;
}

void pyroChar::loadData(SDL_Renderer* render)
{
	loadImage(HPFrame, "Image/hp", 2, render);
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
	baseATK = 10;
	baseDEF = 10;
	shield = false;
	allDied = IMG_LoadTexture(render, "Image/ghost.png");
	flip = SDL_FLIP_NONE;
}

void updateHPCharacters(AllCharacters& characters, SDL_Renderer* render)
{
	if (characters.selectedChar == 1)
	{
		int percentHP{};
		if (characters.char1.HP <= 0)
		{
			percentHP = 0;
		}
		else
		{
			percentHP = (characters.char1.HP) * 100 / 2000;
		}
		SDL_Rect total = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, 60, 10 };
		SDL_Rect left = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, (int)(60 * percentHP / 100), 10 };
		SDL_RenderCopy(render, characters.char1.HPFrame[0], NULL, &total);
		SDL_RenderCopy(render, characters.char1.HPFrame[1], NULL, &left);
	}
	if (characters.selectedChar == 2)
	{
		int percentHP{};
		if (characters.char2.HP <= 0)
		{
			percentHP = 0;
		}
		else
		{
			percentHP = (characters.char2.HP) * 100 / 2000;
		}
		SDL_Rect total = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, 60, 10 };
		SDL_Rect left = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, (int)(60 * percentHP / 100), 10 };
		SDL_RenderCopy(render, characters.char2.HPFrame[0], NULL, &total);
		SDL_RenderCopy(render, characters.char2.HPFrame[1], NULL, &left);
	}
	if (characters.selectedChar == 3)
	{
		int percentHP{};
		if (characters.char3.HP <= 0)
		{
			percentHP = 0;
		}
		else
		{
			percentHP = (characters.char3.HP) * 100 / 2000;
		}
		SDL_Rect total = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, 60, 10 };
		SDL_Rect left = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, (int)(60 * percentHP / 100), 10 };
		SDL_RenderCopy(render, characters.char3.HPFrame[0], NULL, &total);
		SDL_RenderCopy(render, characters.char3.HPFrame[1], NULL, &left);
	}
	if (characters.selectedChar == 4)
	{
		int percentHP{};
		if (characters.char4.HP <= 0)
		{
			percentHP = 0;
		}
		else
		{
			percentHP = (characters.char4.HP) * 100 / 2000;
		}
		SDL_Rect total = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, 60, 10 };
		SDL_Rect left = { characters.currentCharPosition.x, characters.currentCharPosition.y - 20, (int)(60 * percentHP / 100), 10 };
		SDL_RenderCopy(render, characters.char4.HPFrame[0], NULL, &total);
		SDL_RenderCopy(render, characters.char4.HPFrame[1], NULL, &left);
	}
}
void characterDie(AllCharacters& characters, SDL_Renderer* render)
{
	if (characters.selectedChar == 1 && characters.char1.HP <= 0)
	{
		characters.char1.isAlive = false;
		if (cooldown(characters.char1.previousFrameTimeDie, characters.char1.delayFrameTimeAttack) == true)
		{
			characters.char1.checkFrameDie = true;
		}
		if (characters.char1.checkFrameDie == true)
		{
			characters.char1.currentFrameDie++;
			characters.char1.checkFrameDie = false;
		}
		if (characters.char1.currentFrameDie >= characters.char1.dieFrame.size())
		{
			SDL_RenderCopy(render, characters.allDied, NULL, &characters.currentCharPosition);
		}
		else
		{
			SDL_RenderCopyEx(render, characters.char1.dieFrame[characters.char1.currentFrameDie], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
		}
	}
	if (characters.selectedChar == 2 && characters.char2.HP <= 0)
	{
		characters.char2.isAlive = false;
		if (cooldown(characters.char2.previousFrameTimeDie, characters.char2.delayFrameTimeAttack) == true)
		{
			characters.char2.checkFrameDie = true;
		}
		if (characters.char2.checkFrameDie == true)
		{
			characters.char2.currentFrameDie++;
			characters.char2.checkFrameDie = false;
		}
		if (characters.char2.currentFrameDie >= characters.char2.dieFrame.size())
		{
			SDL_RenderCopy(render, characters.allDied, NULL, &characters.currentCharPosition);
		}
		else
		{
			SDL_RenderCopyEx(render, characters.char2.dieFrame[characters.char2.currentFrameDie], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
		}
	}
	if (characters.selectedChar == 3 && characters.char3.HP <= 0)
	{
		characters.char3.isAlive = false;
		if (cooldown(characters.char3.previousFrameTimeDie, characters.char3.delayFrameTimeAttack) == true)
		{
			characters.char3.checkFrameDie = true;
		}
		if (characters.char3.checkFrameDie == true)
		{
			characters.char3.currentFrameDie++;
			characters.char3.checkFrameDie = false;
		}
		if (characters.char3.currentFrameDie >= characters.char3.dieFrame.size())
		{
			SDL_RenderCopy(render, characters.allDied, NULL, &characters.currentCharPosition);
		}
		else
		{
			SDL_RenderCopyEx(render, characters.char3.dieFrame[characters.char3.currentFrameDie], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
		}
	}
	if (characters.selectedChar == 4 && characters.char4.HP <= 0)
	{
		characters.char4.isAlive = false;
		if (cooldown(characters.char4.previousFrameTimeDie, characters.char4.delayFrameTimeAttack) == true)
		{
			characters.char4.checkFrameDie = true;
		}
		if (characters.char4.checkFrameDie == true)
		{
			characters.char4.currentFrameDie++;
			characters.char4.checkFrameDie = false;
		}
		if (characters.char4.currentFrameDie >= characters.char4.dieFrame.size())
		{
			SDL_RenderCopy(render, characters.allDied, NULL, &characters.currentCharPosition);
		}
		else
		{
			SDL_RenderCopyEx(render, characters.char4.dieFrame[characters.char4.currentFrameDie], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
		}
	}
}