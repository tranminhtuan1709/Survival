#include "game.h"
#include "enum.h"

const Uint8* keyState = SDL_GetKeyboardState(nullptr);

double calculateAlpha(SDL_Point p1, SDL_Point p2, int flip)
{
	return flip == SDL_FLIP_NONE ? atan((1.0 * p2.y - 1.0 * p1.y) / (1.0 * p2.x - 1.0 * p1.x)) : atan((1.0 * p2.y - 1.0 * p1.y) / (1.0 * p2.x - 1.0 * p1.x)) - 3.141592654;
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

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
	return (a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y) ? true : false;
}

bool checkOutOfScreen(SDL_Rect& pos)
{
	if (pos.x + pos.w > SCREEN_WIDTH || pos.x < 0 || pos.y + pos.h > SCREEN_HEIGHT || pos.y < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool checkPointInRect(SDL_Point p, SDL_Rect rec)
{
	return (p.x >= rec.x) && (p.x <= rec.x + rec.w) && (p.y >= rec.y) && (p.y <= rec.y + rec.h) ? true : false;
}

SDL_Rect randomPositionOnScreen(int sizeW, int sizeH)
{
	return { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, sizeW, sizeH };
}

string milisecondsToMinutes(int milisecond)
{
	int seconds = milisecond / 1000;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	string res = "0" + to_string(minutes) + ":" + to_string(seconds);
	if (seconds < 10) res.insert(res.end() - 1, '0');
	return res;
}

void character_Run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e)
{
	if (e.key.keysym.sym == SDLK_1) characters.selectedChar = CHARACTER_1;
	if (e.key.keysym.sym == SDLK_2) characters.selectedChar = CHARACTER_2;
	if (e.key.keysym.sym == SDLK_3) characters.selectedChar = CHARACTER_3;
	if (e.key.keysym.sym == SDLK_4) characters.selectedChar = CHARACTER_4;
	characters.currentCharHP = &characters.listOfChar[characters.selectedChar].stat[CHARACTER_HP];
	if (characters.listOfChar[characters.selectedChar].isAlive == false)
	{
		return;
	}
	if (cooldown(characters.listOfChar[characters.selectedChar].delay.previousFrameTime[CHARACTER_RUN], characters.listOfChar[characters.selectedChar].delay.delayFrameTime[CHARACTER_RUN]) == true)
	{
		if (keyState[SDL_SCANCODE_W])
		{
			characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] = true;
			characters.position.y = max(0, characters.position.y - characters.listOfChar[characters.selectedChar].stat[CHARACTER_SPEED]);
		}
		if (keyState[SDL_SCANCODE_S])
		{
			characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] = true;
			characters.position.y = min(SCREEN_HEIGHT - CHARACTER_HEIGHT, characters.position.y + characters.listOfChar[characters.selectedChar].stat[CHARACTER_SPEED]);
		}
		if (keyState[SDL_SCANCODE_A])
		{
			characters.flip = SDL_FLIP_HORIZONTAL;
			characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] = true;
			characters.position.x = max(0, characters.position.x - characters.listOfChar[characters.selectedChar].stat[CHARACTER_SPEED]);
		}
		if (keyState[SDL_SCANCODE_D])
		{
			characters.flip = SDL_FLIP_NONE;
			characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] = true;
			characters.position.x = min(SCREEN_WIDTH - CHARACTER_WIDTH, characters.position.x + characters.listOfChar[characters.selectedChar].stat[CHARACTER_SPEED]);
		}
	}
	if (characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] == true)
	{
		characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_RUN] = false;
		characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_RUN] = (characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_RUN] + 1) % (int)characters.listOfChar[characters.selectedChar].runFrame.size();
	}
	SDL_RenderCopyEx(render, characters.listOfChar[characters.selectedChar].runFrame[characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_RUN]], NULL, &characters.position, 0, NULL, characters.flip);
}

void character_Die(AllCharacters& characters, SDL_Renderer* render)
{
	if (characters.listOfChar[characters.selectedChar].stat[CHARACTER_HP] <= 0)
	{
		characters.listOfChar[characters.selectedChar].isAlive = false;
	}
	else
	{
		return;
	}
	if (characters.timeWhenDie == 0) characters.timeWhenDie = SDL_GetTicks();
	if (cooldown(characters.listOfChar[characters.selectedChar].delay.previousFrameTime[CHARACTER_DIE], characters.listOfChar[characters.selectedChar].delay.delayFrameTime[CHARACTER_DIE]) == true)
	{
		characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_DIE] = true;
	}
	if (characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_DIE] == true)
	{
		characters.listOfChar[characters.selectedChar].delay.checkFrame[CHARACTER_DIE] = false;
		characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_DIE]++;
	}
	if (characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_DIE] >= (int)characters.listOfChar[characters.selectedChar].dieFrame.size())
	{
		SDL_RenderCopy(render, characters.ghost, NULL, &characters.position);
		if (cooldown(characters.timeWhenDie, characters.timeAfterDie) == true)
		{
			characters.timeWhenDie = 0;
			if (characters.listOfChar[CHARACTER_1].isAlive == true) characters.selectedChar = CHARACTER_1;
			if (characters.listOfChar[CHARACTER_2].isAlive == true) characters.selectedChar = CHARACTER_2;
			if (characters.listOfChar[CHARACTER_3].isAlive == true) characters.selectedChar = CHARACTER_3;
			if (characters.listOfChar[CHARACTER_4].isAlive == true) characters.selectedChar = CHARACTER_4;
		}
	}
	else
	{
		SDL_RenderCopyEx(render, characters.listOfChar[characters.selectedChar].dieFrame[characters.listOfChar[characters.selectedChar].delay.currentFrame[CHARACTER_DIE]], NULL, &characters.position, 0, NULL, characters.flip);
	}
	if (characters.listOfChar[CHARACTER_1].isAlive == false && characters.listOfChar[CHARACTER_2].isAlive == false && characters.listOfChar[CHARACTER_3].isAlive == false && characters.listOfChar[CHARACTER_4].isAlive == false)
	{
		characters.allDied = true;
	}
}

void character_PushBullet(AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Event& e, SDL_Point dot)
{
	if (characters.listOfChar[characters.selectedChar].isAlive == false) return;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (characters.selectedChar == CHARACTER_1)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, N1_WIDTH, N1_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, N1_WIDTH, N1_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_1].stat[CHARACTER_ATK];
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ bull.position.x, bull.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[N1].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_2)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, N2_WIDTH, N2_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, N2_WIDTH, N2_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_2].stat[CHARACTER_ATK];
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[N2].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_3)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, N3_WIDTH, N3_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, N3_WIDTH, N3_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_3].stat[CHARACTER_ATK];
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[N3].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_4)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, N4_WIDTH, N4_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, N4_WIDTH, N4_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_4].stat[CHARACTER_ATK];
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[N4].push_back(bull);
		}
	}
	if (keyState[SDL_SCANCODE_E])
	{
		if (characters.selectedChar == CHARACTER_1 && cooldown(characters.listOfChar[CHARACTER_1].delay.previousSkillTime[CHARACTER_ELEMENTAL], characters.listOfChar[CHARACTER_1].delay.delaySkillTime[CHARACTER_ELEMENTAL]) == true)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, E1_WIDTH, E1_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, E1_WIDTH, E1_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_1].stat[CHARACTER_ATK] * 3.0 / 2;
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[E1].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_2 && cooldown(characters.listOfChar[CHARACTER_2].delay.previousSkillTime[CHARACTER_ELEMENTAL], characters.listOfChar[CHARACTER_2].delay.delaySkillTime[CHARACTER_ELEMENTAL]) == true)
		{
			Bullet bull;
			bull.position = { dot.x, dot.y, E2_WIDTH, E2_HEIGHT };
			bull.boom = { dot.x - 125, dot.y - 125, 300, 300 };
			bull.damage = characters.listOfChar[CHARACTER_2].stat[CHARACTER_ATK] * 2;
			bull.existTime = 2000;
			bull.delayFrameTime = 2;
			bulletOnScreen.bulletCharacter[E2].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_3 && cooldown(characters.listOfChar[CHARACTER_3].delay.previousSkillTime[CHARACTER_ELEMENTAL], characters.listOfChar[CHARACTER_3].delay.delaySkillTime[CHARACTER_ELEMENTAL]) == true)
		{
			Bullet bull;
			bull.position = characters.position;
			characters.shield = true;
			bull.delayFrameTime = 10;
			bull.existTime = 10000;
			bull.alpha = 10;
			bulletOnScreen.bulletCharacter[E3].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_4 && cooldown(characters.listOfChar[CHARACTER_4].delay.previousSkillTime[CHARACTER_ELEMENTAL], characters.listOfChar[CHARACTER_4].delay.delaySkillTime[CHARACTER_ELEMENTAL]) == true)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, E4_WIDTH, E4_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, E4_WIDTH, E4_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_4].stat[CHARACTER_ATK] * 2;
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 20;
			bulletOnScreen.bulletCharacter[E4].push_back(bull);
		}
	}
	if (keyState[SDL_SCANCODE_Q])
	{
		if (characters.selectedChar == CHARACTER_1 && cooldown(characters.listOfChar[CHARACTER_1].delay.previousSkillTime[CHARACTER_ULTI], characters.listOfChar[CHARACTER_1].delay.delaySkillTime[CHARACTER_ULTI]) == true)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, Q1_WIDTH, Q1_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, Q1_WIDTH, Q1_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_1].stat[CHARACTER_ATK] * 2;
			bull.delayFrameTime = 10;
			bull.d = 4;
			bulletOnScreen.bulletCharacter[Q1].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_2 && cooldown(characters.listOfChar[CHARACTER_2].delay.previousSkillTime[CHARACTER_ULTI], characters.listOfChar[CHARACTER_2].delay.delaySkillTime[CHARACTER_ULTI]) == true)
		{
			Bullet bull;
			bull.position = { dot.x, dot.y - 250, Q2_WIDTH, Q2_HEIGHT };
			bull.damage = characters.listOfChar[CHARACTER_2].stat[CHARACTER_ATK] * 3.0 / 2;
			bull.delayFrameTime = 40;
			bull.existTime = 7000;
			bull.d = 1;
			bulletOnScreen.bulletCharacter[Q2].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_3 && cooldown(characters.listOfChar[CHARACTER_3].delay.previousSkillTime[CHARACTER_ULTI], characters.listOfChar[CHARACTER_3].delay.delaySkillTime[CHARACTER_ULTI]) == true)
		{
			Bullet bull;
			if (characters.flip == SDL_FLIP_HORIZONTAL)
			{
				bull.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_3].stat[CHARACTER_ATK] * 3.0 / 2;
			bull.d = 100;
			bull.delayFrameTime = 100; bull.position = { characters.position.x + 50, characters.position.y + 50, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 200; bull.position = { characters.position.x - 25, characters.position.y - 30, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 300; bull.position = { characters.position.x - 100, characters.position.y + 50, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 400; bull.position = { characters.position.x - 150, characters.position.y + 25, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 500; bull.position = { characters.position.x + 100, characters.position.y + 25, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 600; bull.position = { characters.position.x - 100, characters.position.y, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 700; bull.position = { characters.position.x + 220, characters.position.y - 50, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
			bull.delayFrameTime = 800; bull.position = { characters.position.x, characters.position.y - 50, Q3_WIDTH, Q3_HEIGHT }; bulletOnScreen.bulletCharacter[Q3].push_back(bull);
		}
		if (characters.selectedChar == CHARACTER_4 && cooldown(characters.listOfChar[CHARACTER_4].delay.previousSkillTime[CHARACTER_ULTI], characters.listOfChar[CHARACTER_4].delay.delaySkillTime[CHARACTER_ULTI]) == true)
		{
			Bullet bull;
			if (characters.position.x <= dot.x)
			{
				bull.position = { characters.position.x + 50, characters.position.y + 25, Q4_WIDTH, Q4_HEIGHT };
				characters.flip = SDL_FLIP_NONE;
			}
			else
			{
				bull.position = { characters.position.x, characters.position.y + 25, Q4_WIDTH, Q4_HEIGHT };
				bull.flip = SDL_FLIP_HORIZONTAL;
				characters.flip = SDL_FLIP_HORIZONTAL;
			}
			bull.damage = characters.listOfChar[CHARACTER_4].stat[CHARACTER_ATK] * 3;
			bull.delayFrameTime = 10;
			bull.alpha = calculateAlpha({ characters.position.x, characters.position.y }, dot, bull.flip);
			bull.d = 15;
			bulletOnScreen.bulletCharacter[Q4].push_back(bull);
		}
	}
}

void character_Fire(AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Renderer* render)
{
	for (int i = 0; i < bulletOnScreen.bulletCharacter.size(); i++)
	{
		if (i == N1 || i == N2 || i == N3 || i == N4 || i == E1 || i == E4 || i == Q4)
		{
			for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
			{
				if (checkOutOfScreen(bulletOnScreen.bulletCharacter[i][j].position) == false || (bulletOnScreen.bulletCharacter[i][j].checkExist == false && i != Q4))
				{
					bulletOnScreen.bulletCharacter[i].erase(bulletOnScreen.bulletCharacter[i].begin() + j, bulletOnScreen.bulletCharacter[i].begin() + j + 1);
					j--;
				}
				else
				{
					if (cooldown(bulletOnScreen.bulletCharacter[i][j].previousFrameTime, bulletOnScreen.bulletCharacter[i][j].delayFrameTime) == true)
					{
						bulletOnScreen.bulletCharacter[i][j].checkFrame = true;
						bulletOnScreen.bulletCharacter[i][j].position.x += (int)(bulletOnScreen.bulletCharacter[i][j].d * cos(bulletOnScreen.bulletCharacter[i][j].alpha));
						bulletOnScreen.bulletCharacter[i][j].position.y += (int)(bulletOnScreen.bulletCharacter[i][j].d * sin(bulletOnScreen.bulletCharacter[i][j].alpha));
					}
					if (bulletOnScreen.bulletCharacter[i][j].checkFrame == true)
					{
						bulletOnScreen.bulletCharacter[i][j].checkFrame = false;
						if (i == N1) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_1].normalFrame.size();
						if (i == N2) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_2].normalFrame.size();
						if (i == N3) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_3].normalFrame.size();
						if (i == N4) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_4].normalFrame.size();
						if (i == E1) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_1].elementalFrame.size();
						if (i == E4) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_4].elementalFrame.size();
						if (i == Q4) bulletOnScreen.bulletCharacter[i][j].currentFrame = (bulletOnScreen.bulletCharacter[i][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_4].ultiFrame.size();
					}
					if (i == N1) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_1].normalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == N2) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_2].normalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == N3) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_3].normalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == N4) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_4].normalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == E1) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_1].elementalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == E4) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_4].elementalFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
					if (i == Q4) SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_4].ultiFrame[bulletOnScreen.bulletCharacter[i][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[i][j].position, bulletOnScreen.bulletCharacter[i][j].alpha * 180 / 3.141592654, NULL, SDL_FLIP_NONE);
				}
			}
		}
	}
	for (int j = 0; j < bulletOnScreen.bulletCharacter[E2].size(); j++)
	{
		if (bulletOnScreen.bulletCharacter[E2][j].delayFrameTime >= (int)characters.listOfChar[CHARACTER_2].elementalFrame.size())
		{
			bulletOnScreen.bulletCharacter[E2].erase(bulletOnScreen.bulletCharacter[E2].begin() + j, bulletOnScreen.bulletCharacter[E2].begin() + j + 1);
			j--;
		}
		else
		{
			if ((int)SDL_GetTicks() <= bulletOnScreen.bulletCharacter[E2][j].startTime + bulletOnScreen.bulletCharacter[E2][j].existTime)
			{
				SDL_RenderCopy(render, characters.listOfChar[CHARACTER_2].elementalFrame[bulletOnScreen.bulletCharacter[E2][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[E2][j].position);
				if (cooldown(bulletOnScreen.bulletCharacter[E2][j].previousFrameTime, 100) == true)
				{
					bulletOnScreen.bulletCharacter[E2][j].currentFrame = (bulletOnScreen.bulletCharacter[E2][j].currentFrame + 1) % 2;
				}
			}
			else if (cooldown(bulletOnScreen.bulletCharacter[E2][j].previousFrameTime, 30) == true)
			{
				SDL_RenderCopy(render, characters.listOfChar[CHARACTER_2].elementalFrame[bulletOnScreen.bulletCharacter[E2][j].delayFrameTime], NULL, &bulletOnScreen.bulletCharacter[E2][j].boom);
				bulletOnScreen.bulletCharacter[E2][j].delayFrameTime++;
			}
		}
	}
	for (int j = 0; j < bulletOnScreen.bulletCharacter[E3].size(); j++)
	{
		if (cooldown(bulletOnScreen.bulletCharacter[E3][j].startTime, bulletOnScreen.bulletCharacter[E3][j].existTime) == true)
		{
			bulletOnScreen.bulletCharacter[E3].erase(bulletOnScreen.bulletCharacter[E3].begin() + j, bulletOnScreen.bulletCharacter[E3].begin() + j + 1);
			j--;
			characters.shield = false;
		}
		else if (cooldown(bulletOnScreen.bulletCharacter[E3][j].previousFrameTime, bulletOnScreen.bulletCharacter[E3][j].delayFrameTime) == true)
		{
			SDL_Rect pos = characters.position;
			pos.x -= 100;
			pos.y -= 100;
			pos.w += 200;
			pos.h += 200;
			SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_3].elementalFrame[bulletOnScreen.bulletCharacter[E3][j].currentFrame], NULL, &pos, bulletOnScreen.bulletCharacter[E3][j].alpha, NULL, SDL_FLIP_NONE);
			bulletOnScreen.bulletCharacter[E3][j].alpha += 10;
			bulletOnScreen.bulletCharacter[E3][j].currentFrame = (bulletOnScreen.bulletCharacter[E3][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_3].elementalFrame.size();
		}
	}
	for (int j = 0; j < bulletOnScreen.bulletCharacter[Q1].size(); j++)
	{
		if (checkOutOfScreen(bulletOnScreen.bulletCharacter[Q1][j].position) == false)
		{
			bulletOnScreen.bulletCharacter[Q1].erase(bulletOnScreen.bulletCharacter[Q1].begin() + j, bulletOnScreen.bulletCharacter[Q1].begin() + j + 1);
			j--;
		}
		else
		{
			if (cooldown(bulletOnScreen.bulletCharacter[Q1][j].previousFrameTime, bulletOnScreen.bulletCharacter[Q1][j].delayFrameTime) == true)
			{
				bulletOnScreen.bulletCharacter[Q1][j].checkFrame = true;
				bulletOnScreen.bulletCharacter[Q1][j].flip == SDL_FLIP_NONE ? bulletOnScreen.bulletCharacter[Q1][j].position.x += (int)bulletOnScreen.bulletCharacter[Q1][j].d : bulletOnScreen.bulletCharacter[Q1][j].position.x -= (int)bulletOnScreen.bulletCharacter[Q1][j].d;
			}
			if (bulletOnScreen.bulletCharacter[Q1][j].checkFrame == true)
			{
				bulletOnScreen.bulletCharacter[Q1][j].checkFrame = false;
				bulletOnScreen.bulletCharacter[Q1][j].currentFrame = (bulletOnScreen.bulletCharacter[Q1][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_1].ultiFrame.size();
			}
			SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_1].ultiFrame[bulletOnScreen.bulletCharacter[Q1][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[Q1][j].position, 0, NULL, bulletOnScreen.bulletCharacter[Q1][j].flip);
		}
	}
	for (int j = 0; j < bulletOnScreen.bulletCharacter[Q2].size(); j++)
	{
		if ((int)SDL_GetTicks() >= bulletOnScreen.bulletCharacter[Q2][j].startTime + bulletOnScreen.bulletCharacter[Q2][j].existTime)
		{
			bulletOnScreen.bulletCharacter[Q2].erase(bulletOnScreen.bulletCharacter[Q2].begin() + j, bulletOnScreen.bulletCharacter[Q2].begin() + j + 1);
			j--;
		}
		else if (cooldown(bulletOnScreen.bulletCharacter[Q2][j].previousFrameTime, bulletOnScreen.bulletCharacter[Q2][j].delayFrameTime) == true)
		{
			bulletOnScreen.bulletCharacter[Q2][j].position.x += (int)bulletOnScreen.bulletCharacter[Q2][j].d;
			SDL_RenderCopy(render, characters.listOfChar[CHARACTER_2].ultiFrame[bulletOnScreen.bulletCharacter[Q2][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[Q2][j].position);
			bulletOnScreen.bulletCharacter[Q2][j].currentFrame = (bulletOnScreen.bulletCharacter[Q2][j].currentFrame + 1) % (int)characters.listOfChar[CHARACTER_2].ultiFrame.size();
		}
	}
	for (int j = 0; j < bulletOnScreen.bulletCharacter[Q3].size(); j++)
	{
		if (checkOutOfScreen(bulletOnScreen.bulletCharacter[Q3][j].position) == false)
		{
			bulletOnScreen.bulletCharacter[Q3].erase(bulletOnScreen.bulletCharacter[Q3].begin() + j, bulletOnScreen.bulletCharacter[Q3].begin() + j + 1);
			j--;
		}
		else if (cooldown(bulletOnScreen.bulletCharacter[Q3][j].previousFrameTime, bulletOnScreen.bulletCharacter[Q3][j].delayFrameTime) == true)
		{
			bulletOnScreen.bulletCharacter[Q3][j].flip == SDL_FLIP_NONE ? bulletOnScreen.bulletCharacter[Q3][j].position.x += (int)bulletOnScreen.bulletCharacter[Q3][j].d : bulletOnScreen.bulletCharacter[Q3][j].position.x -= (int)bulletOnScreen.bulletCharacter[Q3][j].d;
			SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_3].ultiFrame[bulletOnScreen.bulletCharacter[Q3][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[Q3][j].position, 0, NULL, bulletOnScreen.bulletCharacter[Q3][j].flip);
			bulletOnScreen.bulletCharacter[Q3][j].delayFrameTime = 0;
		}
		else
		{
			SDL_RenderCopyEx(render, characters.listOfChar[CHARACTER_3].ultiFrame[bulletOnScreen.bulletCharacter[Q3][j].currentFrame], NULL, &bulletOnScreen.bulletCharacter[Q3][j].position, 0, NULL, bulletOnScreen.bulletCharacter[Q3][j].flip);
		}
	}
}

void character_UpdateHP(AllCharacters& characters, SDL_Renderer* render)
{
	for (int i = 0; i < characters.listOfChar.size(); i++)
	{
		int percentHP{};
		characters.listOfChar[i].stat[CHARACTER_HP] <= 0 ? percentHP = 0 : percentHP = characters.listOfChar[i].stat[CHARACTER_HP] * 100 / 2000;
		characters.listOfChar[i].hpTotal = { characters.position.x, characters.position.y - 20, 50, 10 };
		characters.listOfChar[i].hpLeft = { characters.position.x, characters.position.y - 20, (int)(percentHP * 50 / 100), 10 };
		SDL_RenderCopy(render, characters.listOfChar[characters.selectedChar].HPFrame[0], NULL, &characters.listOfChar[characters.selectedChar].hpTotal);
		SDL_RenderCopy(render, characters.listOfChar[characters.selectedChar].HPFrame[1], NULL, &characters.listOfChar[characters.selectedChar].hpLeft);
	}
}

void monster_Random(AllMonsters& monsters, int type)
{
	if (cooldown(monsters.previousRandomTime, 300) == false)
	{
		return;
	}
	srand((int)time(0));
	MonsterInformation monsInfor(type);
	if (type == MONSTER_1) monsInfor.position = randomPositionOnScreen(MONSTER_1_WIDTH, MONSTER_1_HEIGHT), monsters.monsterOnScreen[MONSTER_1].push_back(monsInfor);
	if (type == MONSTER_2) monsInfor.position = randomPositionOnScreen(MONSTER_2_WIDTH, MONSTER_2_HEIGHT), monsters.monsterOnScreen[MONSTER_2].push_back(monsInfor);
	if (type == MONSTER_3) monsInfor.position = randomPositionOnScreen(MONSTER_3_WIDTH, MONSTER_3_HEIGHT), monsters.monsterOnScreen[MONSTER_3].push_back(monsInfor);
	if (type == MONSTER_4)
	{
		int temp = (rand() + (int)SDL_GetTicks()) % 2;
		if (temp == 1)
		{
			monsInfor.position = { 0, (rand() + (int)SDL_GetTicks()) % (SCREEN_HEIGHT - MONSTER_4_HEIGHT), MONSTER_4_WIDTH, MONSTER_4_HEIGHT };
		}
		else
		{
			monsInfor.position = { SCREEN_WIDTH - MONSTER_4_WIDTH, (rand() + (int)SDL_GetTicks()) % (SCREEN_HEIGHT - MONSTER_4_HEIGHT), MONSTER_4_WIDTH, MONSTER_4_HEIGHT };
			monsInfor.flip = SDL_FLIP_HORIZONTAL;
		}
		monsters.monsterOnScreen[MONSTER_4].push_back(monsInfor);
	}
	if (type == MONSTER_5) monsInfor.position = randomPositionOnScreen(MONSTER_5_WIDTH, MONSTER_5_HEIGHT), monsters.monsterOnScreen[MONSTER_5].push_back(monsInfor);
	if (type == MONSTER_6) monsInfor.position = randomPositionOnScreen(MONSTER_6_WIDTH, MONSTER_6_HEIGHT), monsters.monsterOnScreen[MONSTER_6].push_back(monsInfor);
	if (type == MONSTER_7) monsInfor.position = randomPositionOnScreen(MONSTER_7_WIDTH, MONSTER_7_HEIGHT), monsters.monsterOnScreen[MONSTER_7].push_back(monsInfor);
	if (type == MONSTER_8 && monsters.monsterOnScreen[MONSTER_8].empty() == true)
	{
		monsInfor.position = { 0, 160, 100, 60 }; monsInfor.stat[MONSTER_CURRENT_HP] = 1; monsters.monsterOnScreen[MONSTER_8].push_back(monsInfor);
		monsInfor.position = { 0, 480, 100, 60 }; monsInfor.stat[MONSTER_CURRENT_HP] = 2; monsters.monsterOnScreen[MONSTER_8].push_back(monsInfor);
		monsInfor.position = { 1300, 320, 100, 60 }; monsInfor.stat[MONSTER_CURRENT_HP] = 3; monsInfor.flip = SDL_FLIP_HORIZONTAL; monsters.monsterOnScreen[MONSTER_8].push_back(monsInfor);
		monsInfor.position = { 1300, 640, 100, 60 }; monsInfor.stat[MONSTER_CURRENT_HP] = 4; monsInfor.flip = SDL_FLIP_HORIZONTAL; monsters.monsterOnScreen[MONSTER_8].push_back(monsInfor);
	}
	if (type == MONSTER_9) monsInfor.position = randomPositionOnScreen(MONSTER_9_WIDTH, MONSTER_9_HEIGHT), monsters.monsterOnScreen[MONSTER_9].push_back(monsInfor);
}

void monster_Chase(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (i != MONSTER_4 && i != MONSTER_8)
		{
			for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
			{
				if (monsters.monsterOnScreen[i][j].isChasing == true && monsters.monsterOnScreen[i][j].isAlive == true)
				{
					if (cooldown(monsters.monsterOnScreen[i][j].delay.previousFrameTime[MONSTER_RUN], monsters.monsterOnScreen[i][j].delay.delayFrameTime[MONSTER_RUN]) == true)
					{
						monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_RUN] = true;
						if (monsters.monsterOnScreen[i][j].position.x + monsters.monsterOnScreen[i][j].position.w <= characters.position.x)
						{
							monsters.monsterOnScreen[i][j].position.x += monsters.monsterOnScreen[i][j].stat[MONSTER_SPEED];
							monsters.monsterOnScreen[i][j].flip = SDL_FLIP_NONE;
						}
						if (monsters.monsterOnScreen[i][j].position.x >= characters.position.x + characters.position.w)
						{
							monsters.monsterOnScreen[i][j].position.x -= monsters.monsterOnScreen[i][j].stat[MONSTER_SPEED];
							monsters.monsterOnScreen[i][j].flip = SDL_FLIP_HORIZONTAL;
						}
						if (monsters.monsterOnScreen[i][j].position.y >= characters.position.y + characters.position.h)
						{
							monsters.monsterOnScreen[i][j].position.y -= monsters.monsterOnScreen[i][j].stat[MONSTER_SPEED];
						}
						if (monsters.monsterOnScreen[i][j].position.y + monsters.monsterOnScreen[i][j].position.h <= characters.position.y)
						{
							monsters.monsterOnScreen[i][j].position.y += monsters.monsterOnScreen[i][j].stat[MONSTER_SPEED];
						}
					}
					if (monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_RUN] == true)
					{
						monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_RUN] = false;
						monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_RUN] = (monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_RUN] + 1) % (int)monsters.listOfMons[i].runFrame.size();
					}
					SDL_RenderCopyEx(render, monsters.listOfMons[i].runFrame[monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_RUN]], NULL, &monsters.monsterOnScreen[i][j].position, 0, NULL, monsters.monsterOnScreen[i][j].flip);
				}
			}
		}
	}
	for (int j = 0; j < monsters.monsterOnScreen[MONSTER_4].size(); j++)
	{
		if (checkOutOfScreen(monsters.monsterOnScreen[MONSTER_4][j].position) == true)
		{
			monsters.monsterOnScreen[MONSTER_4].erase(monsters.monsterOnScreen[MONSTER_4].begin() + j, monsters.monsterOnScreen[MONSTER_4].begin() + j + 1);
			j--;
		}
		else if (monsters.monsterOnScreen[MONSTER_4][j].isAlive == true)
		{
			if (cooldown(monsters.monsterOnScreen[MONSTER_4][j].delay.previousFrameTime[MONSTER_RUN], monsters.monsterOnScreen[MONSTER_4][j].delay.delayFrameTime[MONSTER_4]) == true)
			{
				monsters.monsterOnScreen[MONSTER_4][j].delay.checkFrame[MONSTER_RUN] = true;
				if (monsters.monsterOnScreen[MONSTER_4][j].flip = SDL_FLIP_NONE)monsters.monsterOnScreen[MONSTER_4][j].position.x += monsters.monsterOnScreen[MONSTER_4][j].stat[MONSTER_SPEED];
				else monsters.monsterOnScreen[MONSTER_4][j].position.x -= monsters.monsterOnScreen[MONSTER_4][j].stat[MONSTER_SPEED];
			}
			if (monsters.monsterOnScreen[MONSTER_4][j].delay.checkFrame[MONSTER_RUN] == true)
			{
				monsters.monsterOnScreen[MONSTER_4][j].delay.checkFrame[MONSTER_RUN] = false;
				monsters.monsterOnScreen[MONSTER_4][j].delay.currentFrame[MONSTER_RUN] = (monsters.monsterOnScreen[MONSTER_4][j].delay.currentFrame[MONSTER_RUN] + 1) % (int)monsters.listOfMons[MONSTER_4].runFrame.size();
			}
			SDL_RenderCopyEx(render, monsters.listOfMons[MONSTER_4].runFrame[monsters.monsterOnScreen[MONSTER_4][j].delay.currentFrame[MONSTER_RUN]], NULL, &monsters.monsterOnScreen[MONSTER_4][j].position, 0, NULL, monsters.monsterOnScreen[MONSTER_4][j].flip);
		}
	}
	for (int j = 0; j < monsters.monsterOnScreen[MONSTER_8].size(); j++)
	{
		SDL_RenderCopyEx(render, monsters.listOfMons[MONSTER_8].runFrame[0], NULL, &monsters.monsterOnScreen[MONSTER_8][j].position, 0, NULL, monsters.monsterOnScreen[MONSTER_8][j].flip);
	}
}

void monster_BeAttacked(BulletOnScreen& bulletOnScreen, AllMonsters& monsters)
{
	for (int i = 0; i < bulletOnScreen.bulletCharacter.size(); i++)
	{
		for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
		{
			for (int k = 0; k < monsters.monsterOnScreen.size(); k++)
			{
				for (int t = 0; t < monsters.monsterOnScreen[k].size(); t++)
				{
					if (monsters.monsterOnScreen[k][t].isAlive == true)
					{
						if (i == E2 && (bulletOnScreen.bulletCharacter[i][j].startTime + bulletOnScreen.bulletCharacter[i][j].existTime <= (int)SDL_GetTicks()) && checkCollision(monsters.monsterOnScreen[k][t].position, bulletOnScreen.bulletCharacter[i][j].boom) == true)
						{
							monsters.monsterOnScreen[k][t].stat[MONSTER_CURRENT_HP] -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
						}
						else if (checkCollision(monsters.monsterOnScreen[k][t].position, bulletOnScreen.bulletCharacter[i][j].position) == true && i != E2)
						{
							monsters.monsterOnScreen[k][t].stat[MONSTER_CURRENT_HP] -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
							bulletOnScreen.bulletCharacter[i][j].checkExist = false;
						}
					}
				}
			}
		}
	}
}

void monster_Attack(AllMonsters& monsters, AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (i == MONSTER_1 || i == MONSTER_2 || i == MONSTER_3 || i == MONSTER_4 || i == MONSTER_7 || i == MONSTER_9)
		{
			for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
			{
				if (monsters.monsterOnScreen[i][j].isAlive == true)
				{
					if (checkCollision(monsters.monsterOnScreen[i][j].position, characters.position) == true)
					{
						if (i == MONSTER_3 || i == MONSTER_7 || i == MONSTER_9) monsters.monsterOnScreen[i][j].isChasing = false;
						monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_RUN] = false;
						if (characters.shield == false) *characters.currentCharHP -= (int)(monsters.monsterOnScreen[i][j].stat[MONSTER_ATK] - characters.baseDEF);
					}
					if (monsters.monsterOnScreen[i][j].isChasing == false && (i == MONSTER_3 || i == MONSTER_7 || i == MONSTER_9))
					{
						if (cooldown(monsters.monsterOnScreen[i][j].delay.previousFrameTime[MONSTER_ATTACK], monsters.monsterOnScreen[i][j].delay.delayFrameTime[MONSTER_ATTACK]) == true)
						{
							monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_ATTACK]++;
						}
						if (monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_ATTACK] >= (int)monsters.listOfMons[i].dieFrame.size())
						{
							monsters.monsterOnScreen[i][j].isChasing = true;
							monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_ATTACK] = 0;
						}
						else
						{
							SDL_RenderCopyEx(render, monsters.listOfMons[i].attackFrame[monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_ATTACK]], NULL, &monsters.monsterOnScreen[i][j].position, 0, NULL, monsters.monsterOnScreen[i][j].flip);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (i == MONSTER_5 || i == MONSTER_6)
		{
			for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
			{
				if (monsters.monsterOnScreen[i][j].isAlive == true)
				{
					if (cooldown(monsters.monsterOnScreen[i][j].delay.previousSkillTime[0], monsters.monsterOnScreen[i][j].delay.delaySkillTime[0]) == true)
					{
						Bullet bull;
						bull.damage = monsters.monsterOnScreen[i][j].stat[MONSTER_ATK];
						if (monsters.monsterOnScreen[i][j].position.x <= characters.position.x)
						{
							bull.position = { monsters.monsterOnScreen[i][j].position.x + monsters.monsterOnScreen[i][j].position.w,monsters.monsterOnScreen[i][j].position.y + monsters.monsterOnScreen[i][j].position.h / 2, MONSTER_5_BULLET_WIDTH, MONSTER_5_BULLET_HEIGHT };
						}
						else
						{
							bull.position = { monsters.monsterOnScreen[i][j].position.x,monsters.monsterOnScreen[i][j].position.y + monsters.monsterOnScreen[i][j].position.h / 2, MONSTER_5_BULLET_WIDTH, MONSTER_5_BULLET_HEIGHT };
							bull.flip = SDL_FLIP_HORIZONTAL;
						}
						bulletOnScreen.bulletMonster.push_back(bull);
					}
				}
			}
		}
	}
	for (int j = 0; j < monsters.monsterOnScreen[MONSTER_8].size(); j++)
	{
		if (cooldown(monsters.monsterOnScreen[MONSTER_8][j].delay.previousSkillTime[0], monsters.monsterOnScreen[MONSTER_8][j].delay.delaySkillTime[0]) == true)
		{
			Bullet bull;
			bull.damage = monsters.monsterOnScreen[MONSTER_8][j].stat[MONSTER_ATK];
			if (monsters.monsterOnScreen[MONSTER_8][j].stat[MONSTER_CURRENT_HP] == 1) bull.position = { monsters.monsterOnScreen[MONSTER_8][j].position.x + MONSTER_8_WIDTH,monsters.monsterOnScreen[MONSTER_8][j].position.y + MONSTER_8_HEIGHT / 2, MONSTER_8_BULLET_WIDTH, MONSTER_8_BULLET_HEIGHT }, bulletOnScreen.bulletMonster.push_back(bull);
			if (monsters.monsterOnScreen[MONSTER_8][j].stat[MONSTER_CURRENT_HP] == 2) bull.position = { monsters.monsterOnScreen[MONSTER_8][j].position.x + MONSTER_8_WIDTH,monsters.monsterOnScreen[MONSTER_8][j].position.y + MONSTER_8_HEIGHT / 2, MONSTER_8_BULLET_WIDTH, MONSTER_8_BULLET_HEIGHT }, bulletOnScreen.bulletMonster.push_back(bull);
			if (monsters.monsterOnScreen[MONSTER_8][j].stat[MONSTER_CURRENT_HP] == 3) bull.position = { monsters.monsterOnScreen[MONSTER_8][j].position.x,monsters.monsterOnScreen[MONSTER_8][j].position.y + MONSTER_8_HEIGHT / 2, MONSTER_8_BULLET_WIDTH, MONSTER_8_BULLET_HEIGHT }, monsters.monsterOnScreen[MONSTER_8][j].flip = SDL_FLIP_HORIZONTAL, bulletOnScreen.bulletMonster.push_back(bull);
			if (monsters.monsterOnScreen[MONSTER_8][j].stat[MONSTER_CURRENT_HP] == 4) bull.position = { monsters.monsterOnScreen[MONSTER_8][j].position.x,monsters.monsterOnScreen[MONSTER_8][j].position.y + MONSTER_8_HEIGHT / 2, MONSTER_8_BULLET_WIDTH, MONSTER_8_BULLET_HEIGHT }, monsters.monsterOnScreen[MONSTER_8][j].flip = SDL_FLIP_HORIZONTAL, bulletOnScreen.bulletMonster.push_back(bull);
		}
	}
	for (int i = 0; i < bulletOnScreen.bulletMonster.size(); i++)
	{
		if (bulletOnScreen.bulletMonster[i].type != "") continue;
		if (checkOutOfScreen(bulletOnScreen.bulletMonster[i].position) == false || bulletOnScreen.bulletMonster[i].checkExist == false)
		{
			bulletOnScreen.bulletMonster.erase(bulletOnScreen.bulletMonster.begin() + i, bulletOnScreen.bulletMonster.begin() + i + 1);
			i--;
		}
		else
		{
			if (bulletOnScreen.bulletMonster[i].flip == SDL_FLIP_NONE) bulletOnScreen.bulletMonster[i].position.x += 7;
			else bulletOnScreen.bulletMonster[i].position.x -= 7;
			if (bulletOnScreen.bulletMonster[i].position.w == MONSTER_5_BULLET_WIDTH) SDL_RenderCopyEx(render, bulletOnScreen.bullet_mons5, NULL, &bulletOnScreen.bulletMonster[i].position, 0, NULL, bulletOnScreen.bulletMonster[i].flip);
			if (bulletOnScreen.bulletMonster[i].position.w == MONSTER_8_BULLET_WIDTH) SDL_RenderCopyEx(render, bulletOnScreen.bullet_mons8, NULL, &bulletOnScreen.bulletMonster[i].position, 0, NULL, bulletOnScreen.bulletMonster[i].flip);
			if (checkCollision(characters.position, bulletOnScreen.bulletMonster[i].position) == true)
			{
				bulletOnScreen.bulletMonster[i].checkExist = false;
				if (characters.shield == false) *characters.currentCharHP -= (int)(1.0 * bulletOnScreen.bulletMonster[i].damage * (100 - characters.baseATK) / 100);
			}
		}
	}
}

void monster_Die(AllMonsters& monsters, SDL_Renderer* render, vector <int>& scoreOfMonster, int& currentScore)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
		{
			if (monsters.monsterOnScreen[i][j].stat[MONSTER_CURRENT_HP] <= 0 && i != MONSTER_8)
			{
				monsters.monsterOnScreen[i][j].isAlive = false;
			}
		}
	}
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
		{
			if (monsters.monsterOnScreen[i][j].isAlive == false)
			{
				monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_DIE] = false;
				if (cooldown(monsters.monsterOnScreen[i][j].delay.previousFrameTime[MONSTER_DIE], monsters.monsterOnScreen[i][j].delay.delayFrameTime[MONSTER_DIE]) == true)
				{
					monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_DIE] = true;
				}
				if (monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_DIE] == true)
				{
					monsters.monsterOnScreen[i][j].delay.checkFrame[MONSTER_DIE] = false;
					monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_DIE]++;
				}
				if (monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_DIE] >= (int)monsters.listOfMons[i].dieFrame.size())
				{
					monsters.monsterOnScreen[i].erase(monsters.monsterOnScreen[i].begin() + j, monsters.monsterOnScreen[i].begin() + j + 1);
					currentScore += scoreOfMonster[i];
					j--;
				}
				else
				{
					SDL_RenderCopyEx(render, monsters.listOfMons[i].dieFrame[monsters.monsterOnScreen[i][j].delay.currentFrame[MONSTER_DIE]], NULL, &monsters.monsterOnScreen[i][j].position, 0, NULL, monsters.monsterOnScreen[i][j].flip);
				}
			}
		}
	}
}

void monster_UpdateHP(AllMonsters& monsters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		for (int j = 0; j < monsters.monsterOnScreen[i].size(); j++)
		{
			int percentHP;
			monsters.monsterOnScreen[i][j].stat[MONSTER_CURRENT_HP] <= 0 ? percentHP = 0 : percentHP = (int)(monsters.monsterOnScreen[i][j].stat[MONSTER_CURRENT_HP] * 100 / monsters.monsterOnScreen[i][j].stat[MONSTER_MAXHP]);
			SDL_Rect total = { monsters.monsterOnScreen[i][j].position.x, monsters.monsterOnScreen[i][j].position.y - 10,monsters.monsterOnScreen[i][j].position.w, 5 };
			SDL_Rect left = { monsters.monsterOnScreen[i][j].position.x, monsters.monsterOnScreen[i][j].position.y - 10, (int)(monsters.monsterOnScreen[i][j].position.w * percentHP / 100), 5 };
			SDL_RenderCopy(render, monsters.hp1, NULL, &total);
			SDL_RenderCopy(render, monsters.hp2, NULL, &left);
		}
	}
}

void map_Display(MapGame& maps, AllCharacters& characters, SDL_Renderer* render)
{
	SDL_RenderCopy(render, maps.mapFrame[maps.currentMap], NULL, NULL);
	for (int i = 0; i < maps.itemOnScreen.size(); i++)
	{
		for (int j = 0; j < maps.itemOnScreen[i].size(); j++)
		{
			if (maps.itemOnScreen[i][j].startTime + maps.itemOnScreen[i][j].existTime <= (int)SDL_GetTicks())
			{
				maps.itemOnScreen[i].erase(maps.itemOnScreen[i].begin() + j, maps.itemOnScreen[i].begin() + j + 1);
				j--;
			}
			else if (checkCollision(maps.itemOnScreen[i][j].position, characters.position) == true)
			{
				if (i == ITEM_HEAL) *characters.currentCharHP = min(2000, *characters.currentCharHP + 300);
				if (i == ITEM_ATK) characters.baseATK = min(600.0, characters.baseATK + 50);
				if (i == ITEM_DEF) characters.baseDEF = min(50.0, characters.baseDEF + 3);
				maps.itemOnScreen[i].erase(maps.itemOnScreen[i].begin() + j, maps.itemOnScreen[i].begin() + j + 1);
				j--;
			}
			else
			{
				SDL_RenderCopyEx(render, maps.itemFrame[i], NULL, &maps.itemOnScreen[i][j].position, maps.itemOnScreen[i][j].angle, NULL, SDL_FLIP_NONE);
				if (cooldown(maps.itemOnScreen[i][j].previousFrameTime, 150) == true)
				{
					maps.itemOnScreen[i][j].angle = 0 - maps.itemOnScreen[i][j].angle;
				}
			}
		}
	}
}

void map_RandomItem(MapGame& maps, SDL_Renderer* render)
{
	if (cooldown(maps.previousRandomItemTime, 3000) == true)
	{
		srand((int)time(0));
		Item item(randomPositionOnScreen(ITEM_WIDTH, ITEM_HEIGHT), (int)SDL_GetTicks(), 15000, 5);
		int randomType = (rand() + (int)SDL_GetTicks()) % ALLITEM;
		maps.itemOnScreen[randomType].push_back(item);
	}
}

void map_ClearMap(MapGame& maps, AllMonsters& monsters, BulletOnScreen& bulletOnScreen)
{
	if (maps.currentMap == MAP_1)
	{
		monsters.monsterOnScreen[MONSTER_5].clear();
		monsters.monsterOnScreen[MONSTER_6].clear();
		monsters.monsterOnScreen[MONSTER_7].clear();
		monsters.monsterOnScreen[MONSTER_8].clear();
		bulletOnScreen.bulletMonster.clear();
	}
	else
	{
		monsters.monsterOnScreen[MONSTER_1].clear();
		monsters.monsterOnScreen[MONSTER_2].clear();
		monsters.monsterOnScreen[MONSTER_3].clear();
		monsters.monsterOnScreen[MONSTER_4].clear();
	}
}

void boss_Stand(Boss& boss, SDL_Renderer* render)
{
	if (boss.isAlive == false || boss.standing == false) return;
	if (cooldown(boss.delay.previousFrameTime[BOSS_STAND], boss.delay.delayFrameTime[BOSS_STAND]) == true)
	{
		boss.delay.checkFrame[BOSS_STAND] = true;
	}
	if (boss.delay.checkFrame[BOSS_STAND] == true)
	{
		boss.delay.checkFrame[BOSS_STAND] = false;
		boss.delay.currentFrame[BOSS_STAND] = (boss.delay.currentFrame[BOSS_STAND] + 1) % (int)boss.standFrame.size();
	}
	SDL_RenderCopyEx(render, boss.standFrame[boss.delay.currentFrame[BOSS_STAND]], NULL, &boss.position, 0, NULL, boss.flip);
}

void boss_Attack(Boss& boss, SDL_Renderer* render)
{
	if (boss.isAlive == false || boss.attacking == false) return;
	if (cooldown(boss.delay.previousFrameTime[BOSS_ATTACK], boss.delay.delayFrameTime[BOSS_ATTACK]) == true)
	{
		boss.delay.checkFrame[BOSS_ATTACK] = true;
	}
	if (boss.delay.checkFrame[BOSS_ATTACK] == true)
	{
		boss.delay.checkFrame[BOSS_ATTACK] = false;
		boss.delay.currentFrame[BOSS_ATTACK]++;
	}
	if (boss.delay.currentFrame[BOSS_ATTACK] >= (int)boss.attackFrame.size())
	{
		boss.standing = true;
		boss.attacking = false;
		boss.delay.currentFrame[BOSS_ATTACK] = 0;
	}
	else
	{
		SDL_RenderCopyEx(render, boss.attackFrame[boss.delay.currentFrame[BOSS_ATTACK]], NULL, &boss.position, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
}

void boss_Die(Boss& boss, SDL_Renderer* render)
{
	if (boss.HP <= 0) boss.isAlive = false;
	if (boss.isAlive == true) return;
	if (cooldown(boss.delay.previousFrameTime[BOSS_DIE], boss.delay.delayFrameTime[BOSS_DIE]) == true)
	{
		boss.delay.checkFrame[BOSS_DIE] = true;
	}
	if (boss.delay.checkFrame[BOSS_DIE] == true)
	{
		boss.delay.checkFrame[BOSS_DIE] = false;
		boss.delay.currentFrame[BOSS_DIE]++;
	}
	if (boss.delay.currentFrame[BOSS_DIE] >= (int)boss.dieFrame.size()) return;
	SDL_RenderCopyEx(render, boss.dieFrame[boss.delay.currentFrame[BOSS_DIE]], NULL, &boss.position, 0, NULL, SDL_FLIP_HORIZONTAL);
}

void boss_pushRock(BulletOnScreen& bulletOnScreen, Boss& boss, AllCharacters& characters, int type)
{
	if (boss.isAlive == false) return;
	if (type == BOSS_SKILL1 && cooldown(boss.delay.previousSkillTime[BOSS_SKILL1], boss.delay.delaySkillTime[BOSS_SKILL1]) == true)
	{
		boss.standing = false;
		boss.attacking = true;
		Bullet bull;
		bull.type = "boss skill 1";
		bull.position = { boss.position.x - 50, boss.position.y + 50, 50, 50 };
		bull.damage = boss.ATK;
		bull.delayFrameTime = 50;
		bull.d = 10;
		bull.flip = SDL_FLIP_HORIZONTAL;
		bull.alpha = 0 - 5 * 3.141592654 / 6; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 7 * 3.141592654 / 6; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 3.151592654; bulletOnScreen.bulletMonster.push_back(bull);
	}
	if (type == BOSS_SKILL2 && cooldown(boss.delay.previousSkillTime[BOSS_SKILL2], boss.delay.delaySkillTime[BOSS_SKILL2]) == true)
	{
		boss.standing = false;
		boss.attacking = true;
		Bullet bull;
		bull.type = "boss skill 2";
		bull.position = { boss.position.x - 50, boss.position.y + 50, 50, 50 };
		bull.boom = { characters.position.x - 20, characters.position.y - 20, 90, 90 };
		bull.damage = 1.0 * boss.ATK * 3 / 2;
		bull.delayFrameTime = 20;
		bull.flip = SDL_FLIP_HORIZONTAL;
		bull.d = 20;
		bull.alpha = calculateAlpha({ bull.position.x, bull.position.y }, { characters.position.x, characters.position.y }, bull.flip);
		bulletOnScreen.bulletMonster.push_back(bull);
	}
	if (type == BOSS_SKILL3 && cooldown(boss.delay.previousSkillTime[BOSS_SKILL3], boss.delay.delaySkillTime[BOSS_SKILL3]) == true)
	{
		boss.standing = false;
		boss.attacking = true;
		Bullet bull;
		bull.type = "boss skill 3";
		bull.position = { boss.position.x + 50, boss.position.y + 50, 50, 50 };
		bull.damage = boss.ATK;
		bull.delayFrameTime = 50;
		bull.d = 10;
		bull.flip = SDL_FLIP_HORIZONTAL;
		bull.alpha = 0 - 3.141582654 / 2; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 7 * 3.141582654 / 12; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 2 * 3.141582654 / 3; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 3 * 3.141582654 / 4; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 5 * 3.141582654 / 6; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 11 * 3.141582654 / 12; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 3.141582654; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 13 * 3.141582654 / 12; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 7 * 3.141582654 / 6; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 5 * 3.141582654 / 4; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 4 * 3.141582654 / 3; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 17 * 3.141582654 / 12; bulletOnScreen.bulletMonster.push_back(bull);
		bull.alpha = 0 - 3 * 3.141582654 / 2; bulletOnScreen.bulletMonster.push_back(bull);
	}
	if (type == BOSS_SKILL4 && cooldown(boss.delay.previousSkillTime[BOSS_SKILL4], boss.delay.delaySkillTime[BOSS_SKILL4]) == true)
	{
		boss.standing = false;
		boss.attacking = true;
		Bullet bull;
		bull.type = "boss skill 4";
		bull.position = { 0, 0, 50, 50 };
		srand((int)time(0));
		bull.damage = boss.ATK;
		bull.delayFrameTime = 50;
		bull.d = 10;
		bulletOnScreen.bulletMonster.push_back(bull);
		for (int i = 1; i <= 30; i++)
		{
			bull.position.x = (rand() + (int)SDL_GetTicks()) % (SCREEN_WIDTH - 50);
			bull.startTime = ((rand() + (int)SDL_GetTicks()) % 7000) + (int)SDL_GetTicks();
			bulletOnScreen.bulletMonster.push_back(bull);
		}
	}
}

void boss_RandomSkeleton(AllMonsters& monsters, Boss& boss)
{
	if (cooldown(boss.previousRandomSkeleton, boss.delayRandomSkeleton) == true && boss.isAlive == true) monster_Random(monsters, MONSTER_9);
}

void boss_Fire(BulletOnScreen& bulletOnScreen, Boss& boss, SDL_Renderer* render)
{
	if (boss.isAlive == false) return;
	for (int i = 0; i < bulletOnScreen.bulletMonster.size(); i++)
	{
		if (bulletOnScreen.bulletMonster[i].type == "boss skill 1" || bulletOnScreen.bulletMonster[i].type == "boss skill 3")
		{
			if (checkOutOfScreen(bulletOnScreen.bulletMonster[i].position) == false)
			{
				bulletOnScreen.bulletMonster.erase(bulletOnScreen.bulletMonster.begin() + i, bulletOnScreen.bulletMonster.begin() + i + 1);
				i--;
			}
			else
			{
				if (cooldown(bulletOnScreen.bulletMonster[i].previousFrameTime, bulletOnScreen.bulletMonster[i].delayFrameTime) == true)
				{
					bulletOnScreen.bulletMonster[i].checkFrame = true;
					bulletOnScreen.bulletMonster[i].position.x += (int)(bulletOnScreen.bulletMonster[i].d * cos(bulletOnScreen.bulletMonster[i].alpha));
					bulletOnScreen.bulletMonster[i].position.y += (int)(bulletOnScreen.bulletMonster[i].d * sin(bulletOnScreen.bulletMonster[i].alpha));
				}
				if (bulletOnScreen.bulletMonster[i].checkFrame == true)
				{
					bulletOnScreen.bulletMonster[i].rotate += 15;
					bulletOnScreen.bulletMonster[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, boss.rock, NULL, &bulletOnScreen.bulletMonster[i].position, bulletOnScreen.bulletMonster[i].rotate, NULL, SDL_FLIP_NONE);
			}
		}
		else if (bulletOnScreen.bulletMonster[i].type == "boss skill 2")
		{
			SDL_RenderCopy(render, boss.lock, NULL, &bulletOnScreen.bulletMonster[i].boom);
			if (checkCollision(bulletOnScreen.bulletMonster[i].position, bulletOnScreen.bulletMonster[i].boom) == true)
			{
				bulletOnScreen.bulletMonster.erase(bulletOnScreen.bulletMonster.begin() + i, bulletOnScreen.bulletMonster.begin() + i + 1);
				i--;
			}
			else
			{
				if (cooldown(bulletOnScreen.bulletMonster[i].previousFrameTime, bulletOnScreen.bulletMonster[i].delayFrameTime) == true)
				{
					bulletOnScreen.bulletMonster[i].checkFrame = true;
				}
				if (bulletOnScreen.bulletMonster[i].checkFrame == true)
				{
					bulletOnScreen.bulletMonster[i].checkFrame = false;
					bulletOnScreen.bulletMonster[i].position.x += (int)(bulletOnScreen.bulletMonster[i].d * cos(bulletOnScreen.bulletMonster[i].alpha));
					bulletOnScreen.bulletMonster[i].position.y += (int)(bulletOnScreen.bulletMonster[i].d * sin(bulletOnScreen.bulletMonster[i].alpha));
				}
				SDL_RenderCopyEx(render, boss.rock, NULL, &bulletOnScreen.bulletMonster[i].position, bulletOnScreen.bulletMonster[i].rotate, NULL, SDL_FLIP_NONE);
			}
		}
		else if (bulletOnScreen.bulletMonster[i].type == "boss skill 4")
		{
			if (checkOutOfScreen(bulletOnScreen.bulletMonster[i].position) == false)
			{
				bulletOnScreen.bulletMonster.erase(bulletOnScreen.bulletMonster.begin() + i, bulletOnScreen.bulletMonster.begin() + i + 1);
				i--;
			}
			else
			{
				if ((int)SDL_GetTicks() >= bulletOnScreen.bulletMonster[i].startTime)
				{
					if (cooldown(bulletOnScreen.bulletMonster[i].previousFrameTime, bulletOnScreen.bulletMonster[i].delayFrameTime) == true)
					{
						bulletOnScreen.bulletMonster[i].checkFrame = true;
					}
					if (bulletOnScreen.bulletMonster[i].checkFrame == true)
					{
						bulletOnScreen.bulletMonster[i].checkFrame = false;
						bulletOnScreen.bulletMonster[i].position.y += (int)bulletOnScreen.bulletMonster[i].d;
					}
					SDL_RenderCopy(render, boss.rock, NULL, &bulletOnScreen.bulletMonster[i].position);
				}
			}
		}
	}
}

void boss_UpdateHP(Boss& boss, SDL_Renderer* render)
{
	if (boss.isAlive == false) return;
	int percentHP{};
	int percentShield{};
	if (boss.HP <= 0) percentHP = 0;
	else percentHP = (int)(boss.HP * 100 / 20000);
	if (boss.shieldlValue <= 0) percentShield = 0;
	else percentShield = (int)(boss.shieldlValue * 100 / 12000);
	boss.currentHP.w = (int)(percentHP * boss.maxHP.w / 100);
	boss.shieldPosition.w = (int)(percentShield * 800 / 100);
	SDL_RenderCopy(render, boss.hp1, NULL, &boss.maxHP);
	SDL_RenderCopy(render, boss.hp2, NULL, &boss.currentHP);
	SDL_RenderCopy(render, boss.shield, NULL, &boss.shieldPosition);
}

void boss_BeAttack(Boss& boss, BulletOnScreen& bulletOnScreen, SDL_Renderer* render)
{
	if (boss.isAlive == false) return;
	if (boss.shieldlValue >= 0)
	{
		SDL_RenderCopy(render, boss.anemo, NULL, &boss.elemental);
		if (boss.shieldlValue >= 9000)
		{
			for (int i = N1; i <= Q1; i++)
			{
				for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
				{
					if (checkCollision(boss.position, bulletOnScreen.bulletCharacter[i][j].position) == true)
					{
						boss.shieldlValue -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
					}
				}
			}
		}
		if (boss.shieldlValue >= 6000)
		{
			SDL_RenderCopy(render, boss.electro, NULL, &boss.elemental);
			for (int i = N2; i <= Q2; i++)
			{
				for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
				{
					if (checkCollision(boss.position, bulletOnScreen.bulletCharacter[i][j].position) == true)
					{
						boss.shieldlValue -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
					}
				}
			}
		}
		if (boss.shieldlValue >= 3000)
		{
			SDL_RenderCopy(render, boss.hydro, NULL, &boss.elemental);
			for (int i = N3; i <= Q3; i++)
			{
				for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
				{
					if (checkCollision(boss.position, bulletOnScreen.bulletCharacter[i][j].position) == true)
					{
						boss.shieldlValue -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
					}
				}
			}
		}
		if (boss.shieldlValue >= 0)
		{
			SDL_RenderCopy(render, boss.pyro, NULL, &boss.elemental);
			for (int i = N4; i <= Q4; i++)
			{
				for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
				{
					if (checkCollision(boss.position, bulletOnScreen.bulletCharacter[i][j].position) == true)
					{
						boss.shieldlValue -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < bulletOnScreen.bulletCharacter.size(); i++)
		{
			for (int j = 0; j < bulletOnScreen.bulletCharacter[i].size(); j++)
			{
				if (checkCollision(bulletOnScreen.bulletCharacter[i][j].position, boss.position) == true)
				{
					boss.HP -= (int)bulletOnScreen.bulletCharacter[i][j].damage;
				}
			}
		}
	}
}

void boss_InflicDamage(AllCharacters& characters, BulletOnScreen& bulletOnScreen, Boss& boss)
{
	if (boss.isAlive == false) return;
	for (int i = 0; i < bulletOnScreen.bulletMonster.size(); i++)
	{
		if (checkCollision(characters.position, bulletOnScreen.bulletMonster[i].position) == true)
		{
			if (characters.shield == false) *characters.currentCharHP -= (int)bulletOnScreen.bulletMonster[i].damage;
		}
	}
}