#include "game.h"

const Uint8* keyState = SDL_GetKeyboardState(nullptr);

void calculateAlpha(bullet& bull, SDL_Point p1, SDL_Point p2, int flip)
{
	flip == 0 ? bull.alpha = atan((1.0 * p2.y - 1.0 * p1.y) / (1.0 * p2.x - 1.0 * p1.x)) : bull.alpha = atan((1.0 * p2.y - 1.0 * p1.y) / (1.0 * p2.x - 1.0 * p1.x)) - 3.141592654;
}

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	return (a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y) ? true : false;
}

void run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e)
{
	bool press = false;
	characterDie(characters, render);
	if (characters.selectedChar == 1 && characters.char1.isAlive == true)
	{
		characters.currentCharHP = &characters.char1.HP;
		if (cooldown(characters.char1.previousFrameTimeRun, characters.char1.delayFrameTimeRun) == true)
		{
			if (keyState[SDL_SCANCODE_W])
			{
				press = true;
				characters.char1.checkFrameRun = true;
				characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char1.speed);
			}
			if (keyState[SDL_SCANCODE_S])
			{
				press = true;
				characters.char1.checkFrameRun = true;
				characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char1.speed);
			}
			if (keyState[SDL_SCANCODE_A])
			{
				press = true;
				characters.flip = SDL_FLIP_HORIZONTAL;
				characters.char1.checkFrameRun = true;
				characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char1.speed);
			}
			if (keyState[SDL_SCANCODE_D])
			{
				press = true;
				characters.flip = SDL_FLIP_NONE;
				characters.char1.checkFrameRun = true;
				characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char1.speed);
			}
		}
		if (characters.char1.checkFrameRun == true)
		{
			characters.char1.currentFrameRun = (characters.char1.currentFrameRun + 1) % (int)(characters.char1.runFrame.size());
			characters.char1.checkFrameRun = false;
		}
		SDL_RenderCopyEx(render, characters.char1.runFrame[characters.char1.currentFrameRun], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
	}
	if (characters.selectedChar == 2 && characters.char2.isAlive == true)
	{
		characters.currentCharHP = &characters.char2.HP;
		if (cooldown(characters.char2.previousFrameTimeRun, characters.char2.delayFrameTimeRun) == true)
		{
			if (keyState[SDL_SCANCODE_W])
			{
				press = true;
				characters.char2.checkFrameRun = true;
				characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char2.speed);
			}
			if (keyState[SDL_SCANCODE_S])
			{
				press = true;
				characters.char2.checkFrameRun = true;
				characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char2.speed);
			}
			if (keyState[SDL_SCANCODE_A])
			{
				press = true;
				characters.flip = SDL_FLIP_HORIZONTAL;
				characters.char2.checkFrameRun = true;
				characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char2.speed);
			}
			if (keyState[SDL_SCANCODE_D])
			{
				press = true;
				characters.flip = SDL_FLIP_NONE;
				characters.char2.checkFrameRun = true;
				characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char2.speed);
			}
		}
		if (characters.char2.checkFrameRun == true)
		{
			characters.char2.currentFrameRun = (characters.char2.currentFrameRun + 2) % (int)(characters.char2.runFrame.size());
			characters.char2.checkFrameRun = false;
		}
		SDL_RenderCopyEx(render, characters.char2.runFrame[characters.char2.currentFrameRun], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
	}
	if (characters.selectedChar == 3 && characters.char3.isAlive == true)
	{
		characters.currentCharHP = &characters.char3.HP;
		if (cooldown(characters.char3.previousFrameTimeRun, characters.char3.delayFrameTimeRun) == true)
		{
			if (keyState[SDL_SCANCODE_W])
			{
				press = true;
				characters.char3.checkFrameRun = true;
				characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char3.speed);
			}
			if (keyState[SDL_SCANCODE_S])
			{
				press = true;
				characters.char3.checkFrameRun = true;
				characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char3.speed);
			}
			if (keyState[SDL_SCANCODE_A])
			{
				press = true;
				characters.flip = SDL_FLIP_HORIZONTAL;
				characters.char3.checkFrameRun = true;
				characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char3.speed);
			}
			if (keyState[SDL_SCANCODE_D])
			{
				press = true;
				characters.flip = SDL_FLIP_NONE;
				characters.char3.checkFrameRun = true;
				characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char3.speed);
			}
		}
		if (characters.char3.checkFrameRun == true)
		{
			characters.char3.currentFrameRun = (characters.char3.currentFrameRun + 3) % (int)(characters.char3.runFrame.size());
			characters.char3.checkFrameRun = false;
		}
		SDL_RenderCopyEx(render, characters.char3.runFrame[characters.char3.currentFrameRun], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
	}
	if (characters.selectedChar == 4 && characters.char4.isAlive == true)
	{
		characters.currentCharHP = &characters.char4.HP;
		if (cooldown(characters.char4.previousFrameTimeRun, characters.char4.delayFrameTimeRun) == true)
		{
			if (keyState[SDL_SCANCODE_W])
			{
				press = true;
				characters.char4.checkFrameRun = true;
				characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char4.speed);
			}
			if (keyState[SDL_SCANCODE_S])
			{
				press = true;
				characters.char4.checkFrameRun = true;
				characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char4.speed);
			}
			if (keyState[SDL_SCANCODE_A])
			{
				press = true;
				characters.flip = SDL_FLIP_HORIZONTAL;
				characters.char4.checkFrameRun = true;
				characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char4.speed);
			}
			if (keyState[SDL_SCANCODE_D])
			{
				press = true;
				characters.flip = SDL_FLIP_NONE;
				characters.char4.checkFrameRun = true;
				characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char4.speed);
			}
		}
		if (characters.char4.checkFrameRun == true)
		{
			characters.char4.currentFrameRun = (characters.char4.currentFrameRun + 4) % (int)(characters.char4.runFrame.size());
			characters.char4.checkFrameRun = false;
		}
		SDL_RenderCopyEx(render, characters.char4.runFrame[characters.char4.currentFrameRun], NULL, &characters.currentCharPosition, 0, NULL, characters.flip);
	}

}
bool cooldown(int& previousFrameTime, int delayFrameTime)
{
	if ((int)SDL_GetTicks() >= previousFrameTime + delayFrameTime)
	{
		previousFrameTime = SDL_GetTicks();
		return true;
	}
	else
	{
		return false;
	}
}

void anemoAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	if (characters.char1.isAlive == false)
	{
		return;
	}
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].currentBulletPos.w > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y + characters.bulletCharacter[i].currentBulletPos.h > SCREEN_HEIGHT || characters.bulletCharacter[i].checkExist == false)
		{
			characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
			i--;
		}
		else
		{
			if (characters.bulletCharacter[i].type == "N1")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char1.normalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char1.normalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
			if (characters.bulletCharacter[i].type == "E1")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char1.elementalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char1.elementalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
			if (characters.bulletCharacter[i].type == "Q1")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					if (characters.bulletCharacter[i].flip == SDL_FLIP_HORIZONTAL)
					{
						characters.bulletCharacter[i].currentBulletPos.x -= 4;
					}
					else
					{
						characters.bulletCharacter[i].currentBulletPos.x += 4;
					}
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char1.ultiFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char1.ultiFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
			}
		}
	}
	if (characters.selectedChar != 1)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char1.previousTimeN, 0) == true)
	{
		bullet bull;
		bull.type = "N1";
		bull.damage = characters.char1.atk + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip == SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 20, 10 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 20, 10 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char1.previousTimeE, 1000) == true)
	{
		bullet bull;
		bull.type = "E1";
		bull.damage = characters.char1.atk * 3 / 2 + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip == SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 50 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 50 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char1.previousTimeQ, 4000) == true)
	{
		bullet bull;
		bull.type = "Q1";
		bull.damage = characters.char1.atk * 2 + characters.baseATK;
		bull.delayFrameTime = 10;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 100, 100 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 100, 100 };
		}
		characters.bulletCharacter.push_back(bull);
	}
}

void electroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	if (characters.char2.isAlive == false)
	{
		return;
	}
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].type == "N2")
		{
			if (characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].currentBulletPos.w > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y + characters.bulletCharacter[i].currentBulletPos.h > SCREEN_HEIGHT || characters.bulletCharacter[i].checkExist == false)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char2.normalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char2.normalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
		}
		else if (characters.bulletCharacter[i].type == "E2")
		{
			if (characters.bulletCharacter[i].currentFrame > 7)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else
			{
				if ((int)SDL_GetTicks() <= characters.bulletCharacter[i].startTime + characters.bulletCharacter[i].existTime)
				{
					SDL_RenderCopy(render, characters.char2.elementalFrame[characters.bulletCharacter[i].delayFrameTime], NULL, &characters.bulletCharacter[i].currentBulletPos);
					if (cooldown(characters.bulletCharacter[i].previousFrameTime, 100) == true)
					{
						characters.bulletCharacter[i].delayFrameTime = (characters.bulletCharacter[i].delayFrameTime + 1) % 2;
					}
				}
				else if (cooldown(characters.bulletCharacter[i].previousFrameTime, 30) == true)
				{
					SDL_RenderCopy(render, characters.char2.elementalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].boom);
					characters.bulletCharacter[i].currentFrame++;
				}
			}
		}
		else if (characters.bulletCharacter[i].type == "Q2")
		{
			if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
			{
				characters.bulletCharacter[i].currentBulletPos.x += 1;
				SDL_RenderCopy(render, characters.char2.ultiFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos);
				characters.bulletCharacter[i].currentFrame = ((rand() + SDL_GetTicks()) % (int)characters.char2.ultiFrame.size());
			}
			if ((int)SDL_GetTicks() >= characters.bulletCharacter[i].startTime + characters.bulletCharacter[i].existTime)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
		}
	}
	if (characters.selectedChar != 2)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char2.previousTimeN, 0) == true)
	{
		bullet bull;
		bull.type = "N2";
		bull.damage = characters.char2.atk * 2 / 3 + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 60, 10 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 60, 10 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char2.previousTimeE, 2000) == true)
	{
		bullet bull;
		bull.type = "E2";
		bull.currentBulletPos = { dot.x, dot.y, 50, 50 };
		bull.boom = { dot.x - 125, dot.y - 125, 300, 300 };
		bull.existTime = 2000;
		bull.currentFrame = 2;
		bull.damage = characters.char2.atk * 2 + characters.baseATK;
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char2.previousTimeQ, 4000) == true)
	{
		bullet bull;
		bull.type = "Q2";
		bull.currentBulletPos = { dot.x, dot.y - 250, 150, 250 };
		bull.delayFrameTime = 40;
		bull.damage = characters.char2.atk * 2 / 3 + characters.baseATK;
		bull.existTime = 7000;
		characters.bulletCharacter.push_back(bull);
	}
}

void hydroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	if (characters.char3.isAlive == false)
	{
		return;
	}
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].type == "N3")
		{
			if (characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].currentBulletPos.w > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y + characters.bulletCharacter[i].currentBulletPos.h > SCREEN_HEIGHT || characters.bulletCharacter[i].checkExist == false)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char3.normalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char3.normalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
		}
		else if (characters.bulletCharacter[i].type == "E3")
		{
			if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
			{
				SDL_Rect pos = characters.currentCharPosition;
				pos.x -= 100;
				pos.y -= 100;
				pos.w += 200;
				pos.h += 200;
				SDL_RenderCopyEx(render, characters.char3.elementalFrame[characters.bulletCharacter[i].currentFrame], NULL, &pos, characters.bulletCharacter[i].alpha, NULL, SDL_FLIP_NONE);
				characters.bulletCharacter[i].alpha += 10;
				characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char3.elementalFrame.size();
			}
			if (cooldown(characters.bulletCharacter[i].startTime, characters.bulletCharacter[i].existTime) == true)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
		}
		else if (characters.bulletCharacter[i].type == "Q3")
		{
			if (characters.bulletCharacter[i].currentBulletPos.x > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y > SCREEN_HEIGHT)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 100;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 100;
				}
				SDL_RenderCopyEx(render, characters.char3.ultiFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].delayFrameTime = 0;
			}
			else
			{
				SDL_RenderCopyEx(render, characters.char3.ultiFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
			}
		}
	}
	if (characters.selectedChar != 3)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char3.previousTimeN, 0) == true)
	{
		bullet bull;
		bull.type = "N3";
		bull.damage = characters.char3.atk + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 50 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 50 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char3.previousTimeE, 10000) == true)
	{
		bullet bull;
		bull.type = "E3";
		bull.currentBulletPos = characters.currentCharPosition;
		bull.existTime = 10000;
		bull.alpha = 10;
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char3.previousTimeQ, 4000) == true)
	{
		bullet bull1;
		bullet bull2;
		bullet bull3;
		bullet bull4;
		bullet bull5;
		bullet bull6;
		bullet bull7;
		bullet bull8;
		bull1.type = "Q3";
		bull2.type = "Q3";
		bull3.type = "Q3";
		bull4.type = "Q3";
		bull5.type = "Q3";
		bull6.type = "Q3";
		bull7.type = "Q3";
		bull8.type = "Q3";
		bull1.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 50, 80, 10 };
		bull2.currentBulletPos = { characters.currentCharPosition.x - 25, characters.currentCharPosition.y - 30, 80, 10 };
		bull3.currentBulletPos = { characters.currentCharPosition.x - 100, characters.currentCharPosition.y + 50, 80, 10 };
		bull4.currentBulletPos = { characters.currentCharPosition.x - 150, characters.currentCharPosition.y + 25, 80, 10 };
		bull5.currentBulletPos = { characters.currentCharPosition.x + 100, characters.currentCharPosition.y + 25, 80, 10 };
		bull6.currentBulletPos = { characters.currentCharPosition.x - 100, characters.currentCharPosition.y, 80, 10 };
		bull7.currentBulletPos = { characters.currentCharPosition.x + 220, characters.currentCharPosition.y, 80, 10 };
		bull8.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y - 50, 80, 10 };
		bull1.delayFrameTime = 100;
		bull2.delayFrameTime = 200;
		bull3.delayFrameTime = 300;
		bull4.delayFrameTime = 400;
		bull5.delayFrameTime = 500;
		bull6.delayFrameTime = 600;
		bull7.delayFrameTime = 700;
		bull8.delayFrameTime = 800;
		bull1.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull2.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull3.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull4.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull5.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull6.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull7.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		bull8.damage = characters.char3.atk * 3 / 2 + characters.baseATK;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull1.flip = SDL_FLIP_HORIZONTAL;
			bull2.flip = SDL_FLIP_HORIZONTAL;
			bull3.flip = SDL_FLIP_HORIZONTAL;
			bull4.flip = SDL_FLIP_HORIZONTAL;
			bull5.flip = SDL_FLIP_HORIZONTAL;
			bull6.flip = SDL_FLIP_HORIZONTAL;
			bull7.flip = SDL_FLIP_HORIZONTAL;
			bull8.flip = SDL_FLIP_HORIZONTAL;
		}
		characters.bulletCharacter.push_back(bull1);
		characters.bulletCharacter.push_back(bull2);
		characters.bulletCharacter.push_back(bull3);
		characters.bulletCharacter.push_back(bull4);
		characters.bulletCharacter.push_back(bull5);
		characters.bulletCharacter.push_back(bull6);
		characters.bulletCharacter.push_back(bull7);
		characters.bulletCharacter.push_back(bull8);
	}
}

void pyroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	if (characters.char4.isAlive == false)
	{
		return;
	}
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].currentBulletPos.w > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y + characters.bulletCharacter[i].currentBulletPos.h > SCREEN_HEIGHT || characters.bulletCharacter[i].checkExist == false)
		{
			characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
			i--;
		}
		else
		{
			if (characters.bulletCharacter[i].type == "N4")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char4.normalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char4.normalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
			else if (characters.bulletCharacter[i].type == "E4")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char4.elementalFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char4.elementalFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
			else if (characters.bulletCharacter[i].type == "Q4")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].delayFrameTime) == true)
				{
					characters.bulletCharacter[i].checkFrame = true;
					characters.bulletCharacter[i].currentBulletPos.x += (int)(characters.bulletCharacter[i].d * cos(characters.bulletCharacter[i].alpha));
					characters.bulletCharacter[i].currentBulletPos.y += (int)(characters.bulletCharacter[i].d * sin(characters.bulletCharacter[i].alpha));
				}
				if (characters.bulletCharacter[i].checkFrame == true)
				{
					characters.bulletCharacter[i].currentFrame = (characters.bulletCharacter[i].currentFrame + 1) % (int)characters.char4.ultiFrame.size();
					characters.bulletCharacter[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, characters.char4.ultiFrame[characters.bulletCharacter[i].currentFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
			}
		}
	}
	if (characters.selectedChar != 4)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char4.previousTimeN, 0))
	{
		bullet bull;
		bull.type = "N4";
		bull.damage = characters.char4.atk + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 20, 10 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 20, 10 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	if (keyState[SDL_SCANCODE_E] && cooldown(characters.char4.previousTimeE, 300))
	{
		bullet bull;
		bull.type = "E4";
		bull.damage = characters.char4.atk * 3 / 2 + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 20;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 40, 20 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 40, 20 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
	if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char4.previousTimeQ, 500))
	{
		bullet bull;
		bull.type = "Q4";
		bull.damage = characters.char4.atk * 2 + characters.baseATK;
		bull.delayFrameTime = 10;
		bull.d = 15;
		if (characters.currentCharPosition.x <= dot.x)
		{
			characters.flip = SDL_FLIP_NONE;
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 40 };
		}
		else
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			bull.flip = SDL_FLIP_HORIZONTAL;
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 40 };
		}
		calculateAlpha(bull, { bull.currentBulletPos.x, bull.currentBulletPos.y }, dot, bull.flip);
		characters.bulletCharacter.push_back(bull);
	}
}