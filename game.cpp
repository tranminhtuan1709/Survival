#include "game.h"

const Uint8* keyState = SDL_GetKeyboardState(nullptr);

double checkPointOnLine(SDL_Point p, Line l)
{
	return l.a * p.x - p.y + l.b;
}

void createLine(SDL_Point p1, SDL_Point p2, Line& l)
{
	l.a = (1.0 * p2.y - 1.0 * p1.y) / (1.0 * p2.x - 1.0 * p1.x);
	l.b = (1.0 * p2.x * p1.y - 1.0 * p1.x * p2.y) / (1.0 * p2.x - 1.0 * p1.x);
	l.alpha = atan(l.a) * 180 / 3.141592654;
}

void createRectFromLine(SDL_Point p1, SDL_Point p2, SDL_Rect& rec)
{
	rec.w = abs(p1.x - p2.x);
	rec.y = abs(p1.y - p2.y);
	rec.x = min(p1.x, p2.x);
	rec.y = min(p1.x, p2.y);
}

bool collision_RECTxRECT(SDL_Rect a, SDL_Rect b)
{
	return (a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y) ? true : false;
}

bool collision_RECTxLINE(SDL_Rect rec, SDL_Point p1, SDL_Point p2, Line l)
{
	SDL_Rect temp{};
	createRectFromLine(p1, p2, temp);
	SDL_Point A = { temp.x, temp.y };
	SDL_Point B = { temp.x + temp.w, temp.y };
	SDL_Point C = { temp.x, temp.y + temp.h };
	SDL_Point D = { temp.x + temp.w, temp.y + temp.h };
	if ((checkPointOnLine(A, l) >= 0 && checkPointOnLine(B, l) >= 0 && checkPointOnLine(C, l) >= 0 && checkPointOnLine(D, l) >= 0) || (checkPointOnLine(A, l) <= 0 && checkPointOnLine(B, l) <= 0 && checkPointOnLine(C, l) <= 0 && checkPointOnLine(D, l) <= 0))
	{
		return false;
	}
	else
	{
		return collision_RECTxRECT(temp, rec);
	}
}

void run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e)
{
	bool press = false;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (keyState[SDL_SCANCODE_W])
	{
		press = true;
		if (characters.selectedChar == 1)
		{
			characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char2.speed);
		}
		if (characters.selectedChar == 2)
		{
			characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char2.speed);
		}
		if (characters.selectedChar == 3)
		{
			characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char3.speed);
		}
		if (characters.selectedChar == 4)
		{
			characters.currentCharPosition.y = max(0, characters.currentCharPosition.y - characters.char4.speed);
		}
	}
	if (keyState[SDL_SCANCODE_S])
	{
		press = true;
		if (characters.selectedChar == 1)
		{
			characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char1.speed);
		}
		if (characters.selectedChar == 2)
		{
			characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char2.speed);
		}
		if (characters.selectedChar == 3)
		{
			characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char3.speed);
		}
		if (characters.selectedChar == 4)
		{
			characters.currentCharPosition.y = min(SCREEN_HEIGHT - 50, characters.currentCharPosition.y + characters.char4.speed);
		}
	}
	if (keyState[SDL_SCANCODE_A])
	{
		press = true;
		characters.currentCharDirection = "left";
		if (characters.selectedChar == 1)
		{
			characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char1.speed);
		}
		if (characters.selectedChar == 2)
		{
			characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char2.speed);
		}
		if (characters.selectedChar == 3)
		{
			characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char3.speed);
		}
		if (characters.selectedChar == 4)
		{
			characters.currentCharPosition.x = max(0, characters.currentCharPosition.x - characters.char4.speed);
		}
	}
	if (keyState[SDL_SCANCODE_D])
	{
		press = true;
		characters.currentCharDirection = "right";
		if (characters.selectedChar == 1)
		{
			characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char1.speed);
		}
		if (characters.selectedChar == 2)
		{
			characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char2.speed);
		}
		if (characters.selectedChar == 3)
		{
			characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char3.speed);
		}
		if (characters.selectedChar == 4)
		{
			characters.currentCharPosition.x = min(SCREEN_WIDTH - 50, characters.currentCharPosition.x + characters.char4.speed);
		}
	}
	if (characters.currentCharDirection == "left")
	{
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (characters.selectedChar == 1)
	{
		SDL_RenderCopyEx(render, characters.char1.runFrame[characters.char1.currentRunFrame], NULL, &characters.currentCharPosition, 0, NULL, flip);
	}
	if (characters.selectedChar == 2)
	{
		SDL_RenderCopyEx(render, characters.char2.runFrame[characters.char2.currentRunFrame], NULL, &characters.currentCharPosition, 0, NULL, flip);
	}
	if (characters.selectedChar == 3)
	{
		SDL_RenderCopyEx(render, characters.char3.runFrame[characters.char3.currentRunFrame], NULL, &characters.currentCharPosition, 0, NULL, flip);
	}
	if (characters.selectedChar == 4)
	{
		SDL_RenderCopyEx(render, characters.char4.runFrame[characters.char4.currentRunFrame], NULL, &characters.currentCharPosition, 0, NULL, flip);
	}
	if (press == true)
	{
		if (characters.selectedChar == 1 && cooldown(characters.char1.previousFrameTimeRun, 35) == true)
		{
			characters.char1.currentRunFrame = (characters.char1.currentRunFrame + 1) % (int)(characters.char1.runFrame.size());
		}
		if (characters.selectedChar == 2 && cooldown(characters.char2.previousFrameTimeRun, 35) == true)
		{
			characters.char2.currentRunFrame = (characters.char2.currentRunFrame + 1) % (int)(characters.char2.runFrame.size());
		}
		if (characters.selectedChar == 3 && cooldown(characters.char3.previousFrameTimeRun, 35) == true)
		{
			characters.char3.currentRunFrame = (characters.char3.currentRunFrame + 1) % (int)(characters.char3.runFrame.size());
		}
		if (characters.selectedChar == 4 && cooldown(characters.char4.previousFrameTimeRun, 35) == true)
		{
			characters.char4.currentRunFrame = (characters.char4.currentRunFrame + 1) % (int)(characters.char4.runFrame.size());
		}
	}
}

bool cooldown(int& previousFrameTime, int step)
{
	if ((int)SDL_GetTicks() >= previousFrameTime + step)
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
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].currentBulletPos.x > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y > SCREEN_HEIGHT || characters.bulletCharacter[i].check == false)
		{
			characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
			i--;
		}
		else
		{
			if (characters.bulletCharacter[i].type == "N1")
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_HORIZONTAL)
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 20;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x += 20;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char1.normalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char1.normalFrame.size();
			}
			if (characters.bulletCharacter[i].type == "E1")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
				{
					if (characters.bulletCharacter[i].flip == SDL_FLIP_HORIZONTAL)
					{
						characters.bulletCharacter[i].currentBulletPos.x -= 15;
					}
					else
					{
						characters.bulletCharacter[i].currentBulletPos.x += 15;
					}
					characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
					SDL_RenderCopyEx(render, characters.char1.elementalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
					characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char1.elementalFrame.size();
				}
			}
			if (characters.bulletCharacter[i].type == "Q1")
			{
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
				{
					if (characters.bulletCharacter[i].flip == SDL_FLIP_HORIZONTAL)
					{
						characters.bulletCharacter[i].currentBulletPos.x -= 4;
					}
					else
					{
						characters.bulletCharacter[i].currentBulletPos.x += 4;
					}
					SDL_RenderCopyEx(render, characters.char1.ultiFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
					characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char1.ultiFrame.size();
				}
			}
		}
	}
	if (characters.selectedChar != 1)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char1.previousTimeN, 500) == true)
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "N1";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 20, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "N1";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 20, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char1.previousTimeE, 2000) == true)
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "E1";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 50 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk * 3 / 2;
			bull.step = 5;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "E1";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 50 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk * 3 / 2;
			bull.step = 5;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	else if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char1.previousTimeQ, 4000) == true)
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection== "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "Q1";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 100, 100 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk * 2;
			bull.step = 10;
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "Q1";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 100, 100 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char1.atk * 2;
			bull.step = 10;
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
}

void electroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].type == "N2")
		{
			if (characters.bulletCharacter[i].currentBulletPos.x > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y > SCREEN_HEIGHT || characters.bulletCharacter[i].check == false)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 25;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 25;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char2.normalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char2.normalFrame.size();
			}
		}
		else if (characters.bulletCharacter[i].type == "E2")
		{
			if (characters.bulletCharacter[i].currentBulletFrame > 7)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else if ((int)SDL_GetTicks() <= characters.bulletCharacter[i].startTime + characters.bulletCharacter[i].existTime)
			{
				SDL_RenderCopy(render, characters.char2.elementalFrame[characters.bulletCharacter[i].step], NULL, &characters.bulletCharacter[i].currentBulletPos);
				if (cooldown(characters.bulletCharacter[i].previousFrameTime, 100) == true)
				{
					characters.bulletCharacter[i].step = (characters.bulletCharacter[i].step + 1) % 2;
				}
			}
			else if (cooldown(characters.bulletCharacter[i].previousFrameTime, 30) == true)
			{
				SDL_RenderCopy(render, characters.char2.elementalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].boom);
				characters.bulletCharacter[i].currentBulletFrame++;
			}
		}
		else if (characters.bulletCharacter[i].type == "Q2")
		{
			if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
			{
				characters.bulletCharacter[i].currentBulletPos.x += 1;
				SDL_RenderCopy(render, characters.char2.ultiFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos);
				characters.bulletCharacter[i].currentBulletFrame = ((rand() + SDL_GetTicks()) % (int)characters.char2.ultiFrame.size());
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
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char2.previousTimeN, 500) == true)
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "N2";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 60, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char2.atk * 2 / 3;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "N2";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 60, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char2.atk * 2 / 3;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char2.previousTimeE, 3000) == true)
	{
		bullet bull;
		bull.type = "E2";
		bull.currentBulletPos = { dot.x, dot.y, 50, 50 };
		bull.boom = { dot.x - 125, dot.y - 125, 300, 300 };
		bull.startTime = SDL_GetTicks();
		bull.existTime = 2000;
		bull.currentBulletFrame = 2;
		bull.damage = characters.char2.atk * 2;
		characters.bulletCharacter.push_back(bull);
	}
	else if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char2.previousTimeQ, 4000) == true)
	{
		bullet bull;
		bull.type = "Q2";
		bull.currentBulletPos = { dot.x, dot.y - 250, 150, 250 };
		bull.step = 40;
		bull.damage = characters.char2.atk * 2 / 3;
		bull.startTime = SDL_GetTicks();
		bull.existTime = 7000;
		characters.bulletCharacter.push_back(bull);
	}
}

void hydroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e)
{
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].type == "N3")
		{
			if (characters.bulletCharacter[i].currentBulletPos.x > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y > SCREEN_HEIGHT || characters.bulletCharacter[i].check == false)
			{
				characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
				i--;
			}
			else if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 20;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 20;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char3.normalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char3.normalFrame.size();
			}
		}
		else if (characters.bulletCharacter[i].type == "E3")
		{
			if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
			{
				SDL_Rect pos = characters.currentCharPosition;
				pos.x -= 100;
				pos.y -= 100;
				pos.w += 200;
				pos.h += 200;
				SDL_RenderCopyEx(render, characters.char3.elementalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &pos, characters.bulletCharacter[i].bulletLine.a, NULL, SDL_FLIP_NONE);
				characters.bulletCharacter[i].bulletLine.a += 10;
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char3.elementalFrame.size();
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
			else if (cooldown(characters.bulletCharacter[i].previousFrameTime, characters.bulletCharacter[i].step) == true)
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 100;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 100;
				}
				SDL_RenderCopyEx(render, characters.char3.ultiFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].step = 0;
			}
			else
			{
				SDL_RenderCopyEx(render, characters.char3.ultiFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, 0, NULL, characters.bulletCharacter[i].flip);
			}
		}
	}

	if (characters.selectedChar != 3)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char3.previousTimeN, 500) == true)
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "N3";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 50 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char3.atk;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.step = 20;
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "N3";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 50 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char3.atk;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.step = 20;
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	else if (keyState[SDL_SCANCODE_E] && cooldown(characters.char3.previousTimeE, 2000) == true)
	{
		bullet bull;
		bull.type = "E3";
		bull.currentBulletPos = characters.currentCharPosition;
		bull.previousFrameTime = SDL_GetTicks();
		bull.existTime = 10000;
		bull.startTime = SDL_GetTicks();
		bull.a = 10;
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
		bull1.step = 100;
		bull2.step = 200;
		bull3.step = 300;
		bull4.step = 400;
		bull5.step = 500;
		bull6.step = 600;
		bull7.step = 700;
		bull8.step = 800;
		bull1.damage = characters.char3.atk * 3 / 2;
		bull2.damage = characters.char3.atk * 3 / 2;
		bull3.damage = characters.char3.atk * 3 / 2;
		bull4.damage = characters.char3.atk * 3 / 2;
		bull5.damage = characters.char3.atk * 3 / 2;
		bull6.damage = characters.char3.atk * 3 / 2;
		bull7.damage = characters.char3.atk * 3 / 2;
		bull8.damage = characters.char3.atk * 3 / 2;
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bull1.flip = SDL_FLIP_NONE;
			bull2.flip = SDL_FLIP_NONE;
			bull3.flip = SDL_FLIP_NONE;
			bull4.flip = SDL_FLIP_NONE;
			bull5.flip = SDL_FLIP_NONE;
			bull6.flip = SDL_FLIP_NONE;
			bull7.flip = SDL_FLIP_NONE;
			bull8.flip = SDL_FLIP_NONE;
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
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
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		if (characters.bulletCharacter[i].currentBulletPos.x > SCREEN_WIDTH || characters.bulletCharacter[i].currentBulletPos.x < 0 || characters.bulletCharacter[i].currentBulletPos.y < 0 || characters.bulletCharacter[i].currentBulletPos.y > SCREEN_HEIGHT || characters.bulletCharacter[i].check == false)
		{
			characters.bulletCharacter.erase(characters.bulletCharacter.begin() + i, characters.bulletCharacter.begin() + i + 1);
			i--;
		}
		else
		{
			if (characters.bulletCharacter[i].type == "N4")
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 40;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 40;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char4.normalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char4.normalFrame.size();
			}
			else if (characters.bulletCharacter[i].type == "E4")
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 30;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 30;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char4.elementalFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char4.elementalFrame.size();
			}
			else if (characters.bulletCharacter[i].type == "Q4")
			{
				if (characters.bulletCharacter[i].flip == SDL_FLIP_NONE)
				{
					characters.bulletCharacter[i].currentBulletPos.x += 30;
				}
				else
				{
					characters.bulletCharacter[i].currentBulletPos.x -= 30;
				}
				characters.bulletCharacter[i].currentBulletPos.y = (int)round(characters.bulletCharacter[i].bulletLine.a * characters.bulletCharacter[i].currentBulletPos.x + characters.bulletCharacter[i].bulletLine.b);
				SDL_RenderCopyEx(render, characters.char4.ultiFrame[characters.bulletCharacter[i].currentBulletFrame], NULL, &characters.bulletCharacter[i].currentBulletPos, characters.bulletCharacter[i].bulletLine.alpha, NULL, characters.bulletCharacter[i].flip);
				characters.bulletCharacter[i].currentBulletFrame = (characters.bulletCharacter[i].currentBulletFrame + 1) % (int)characters.char4.ultiFrame.size();
			}
		}
	}

	if (characters.selectedChar != 4)
	{
		return;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && cooldown(characters.char4.previousTimeN, 500))
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{	
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "N4";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 20, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "N4";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 20, 10 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	if (keyState[SDL_SCANCODE_E] && cooldown(characters.char4.previousTimeE, 300))
	{
		if (characters.currentCharPosition.x <= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "E4";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 40, 20 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk * 3 / 2;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "E4";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 40, 20 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk * 3 / 2;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
	if (keyState[SDL_SCANCODE_Q] && cooldown(characters.char4.previousTimeQ, 500))
	{
		if (characters.currentCharPosition.x<= dot.x)
		{
			if (characters.currentCharDirection == "left")
			{
				characters.currentCharDirection = "right";
			}
			bullet bull;
			bull.type = "Q4";
			bull.currentBulletPos = { characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25, 50, 40 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk * 2;
			bull.step = 10;
			createLine({ characters.currentCharPosition.x + 50, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_NONE;
			characters.bulletCharacter.push_back(bull);
		}
		else
		{
			if (characters.currentCharDirection == "right")
			{
				characters.currentCharDirection = "left";
			}
			bullet bull;
			bull.type = "Q4";
			bull.currentBulletPos = { characters.currentCharPosition.x, characters.currentCharPosition.y + 25, 50, 40 };
			bull.previousFrameTime = SDL_GetTicks();
			bull.damage = characters.char4.atk * 2;
			bull.step = 10;
			createLine({ characters.currentCharPosition.x, characters.currentCharPosition.y + 25 }, dot, bull.bulletLine);
			bull.flip = SDL_FLIP_HORIZONTAL;
			characters.bulletCharacter.push_back(bull);
		}
	}
}