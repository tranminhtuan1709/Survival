#include "game.h"

const Uint8* keyState = SDL_GetKeyboardState(nullptr);

void run(vector <SDL_Texture*> v, int& currentFrame, SDL_Renderer* render, SDL_Event& e, SDL_Rect& position, int speed, SDL_Rect& currentPosition, string& direction)
{
	bool press = false;
	position = currentPosition;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (keyState[SDL_SCANCODE_W])
	{
		press = true;
		position.y = max(0, position.y - speed);
	}
	if (keyState[SDL_SCANCODE_S])
	{
		press = true;
		position.y = min(SCREEN_HEIGHT - 50, position.y + speed);
	}
	if (keyState[SDL_SCANCODE_A])
	{
		press = true;
		direction = "left";
		position.x = max(0, position.x - speed);
	}
	if (keyState[SDL_SCANCODE_D])
	{
		press = true;
		direction = "right";
		position.x = min(SCREEN_WIDTH - 50, position.x + speed);
	}
	if (direction == "left")
	{
		flip = SDL_FLIP_HORIZONTAL;
	}
	SDL_Point center = { position.x, position.y };
	SDL_RenderCopyEx(render, v[currentFrame], NULL, &position, 0, &center, flip);
	if (press == true)
	{
		currentFrame++;
		if (currentFrame == v.size())
		{
			currentFrame = 0;
		}
	}
	currentPosition = position;
	SDL_Delay(15);
}

bool cooldown(int& previousTime, int step)
{
	if (SDL_GetTicks() >= previousTime + step)
	{
		previousTime = SDL_GetTicks();
		return true;
	}
	else
	{
		return false;
	}
}

void anemoAttack(anemoChar& char1, string type, SDL_Renderer* render, SDL_Point dot, string& direction)
{
	SDL_Rect p{};
	if (type == "N" && cooldown(char1.previousTimeN, 100) == true)
	{
		if (char1.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char1.currentCharPos.x + 50, char1.currentCharPos.y + 25, 20, 10 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char1.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char1.currentCharPos.x, char1.currentCharPos.y + 25, 20, 10 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char1.bulletOnScreen.push_back(bull);
		}
	}
	else if (type == "E" && cooldown(char1.previousTimeE, 2000) == true)
	{
		if (char1.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char1.currentCharPos.x + 50, char1.currentCharPos.y + 25, 50, 50 };
			bullet bull(type, p, 0, SDL_GetTicks(), 5);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char1.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char1.currentCharPos.x, char1.currentCharPos.y + 25, 50, 50 };
			bullet bull(type, p, 0, SDL_GetTicks(), 5);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char1.bulletOnScreen.push_back(bull);
		}
	}
	else if (type == "Q" && cooldown(char1.previousTimeQ, 4000) == true)
	{
		if (char1.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char1.currentCharPos.x + 50, char1.currentCharPos.y - 30, 100, 100 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.flip = SDL_FLIP_NONE;
			char1.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char1.currentCharPos.x, char1.currentCharPos.y - 30, 100, 100 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char1.bulletOnScreen.push_back(bull);
		}
	}
	for (int i = 0; i < char1.bulletOnScreen.size(); i++)
	{
		if (char1.bulletOnScreen[i].currentBulletPos.x > SCREEN_WIDTH || char1.bulletOnScreen[i].currentBulletPos.x < 0 || char1.bulletOnScreen[i].currentBulletPos.y < 0 || char1.bulletOnScreen[i].currentBulletPos.y > SCREEN_HEIGHT)
		{
			char1.bulletOnScreen.erase(char1.bulletOnScreen.begin() + i, char1.bulletOnScreen.begin() + i + 1);
			i--;
		}
		else
		{
			if (char1.bulletOnScreen[i].type == "N")
			{
				if (char1.bulletOnScreen[i].flip == SDL_FLIP_HORIZONTAL)
				{
					char1.bulletOnScreen[i].currentBulletPos.x -= 20;
				}
				else
				{
					char1.bulletOnScreen[i].currentBulletPos.x += 20;
				}
				char1.bulletOnScreen[i].currentBulletPos.y = round(char1.bulletOnScreen[i].a * char1.bulletOnScreen[i].currentBulletPos.x + char1.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char1.normalFrame[char1.bulletOnScreen[i].currentBulletFrame], NULL, &char1.bulletOnScreen[i].currentBulletPos, atan(char1.bulletOnScreen[i].a) * (180 / 3.141592654), NULL, char1.bulletOnScreen[i].flip);
				char1.bulletOnScreen[i].currentBulletFrame = (char1.bulletOnScreen[i].currentBulletFrame + 1) % (int) char1.normalFrame.size();
			}
			if (char1.bulletOnScreen[i].type == "E")
			{
				if (cooldown(char1.bulletOnScreen[i].previousTime, char1.bulletOnScreen[i].step) == true)
				{
					if (char1.bulletOnScreen[i].flip == SDL_FLIP_HORIZONTAL)
					{
						char1.bulletOnScreen[i].currentBulletPos.x -= 15;
					}
					else
					{
						char1.bulletOnScreen[i].currentBulletPos.x += 15;
					}
					char1.bulletOnScreen[i].currentBulletPos.y = round(char1.bulletOnScreen[i].a * char1.bulletOnScreen[i].currentBulletPos.x + char1.bulletOnScreen[i].b);
					SDL_RenderCopyEx(render, char1.elementalFrame[char1.bulletOnScreen[i].currentBulletFrame], NULL, &char1.bulletOnScreen[i].currentBulletPos, atan(char1.bulletOnScreen[i].a) * (180 / 3.141592654), NULL, char1.bulletOnScreen[i].flip);
					char1.bulletOnScreen[i].currentBulletFrame = (char1.bulletOnScreen[i].currentBulletFrame + 1) % (int)char1.elementalFrame.size();
				}
			}
			if (char1.bulletOnScreen[i].type == "Q")
			{
				if (cooldown(char1.bulletOnScreen[i].previousTime, char1.bulletOnScreen[i].step) == true)
				{
					if (char1.bulletOnScreen[i].flip == SDL_FLIP_HORIZONTAL)
					{
						char1.bulletOnScreen[i].currentBulletPos.x -= 4;
					}
					else
					{
						char1.bulletOnScreen[i].currentBulletPos.x += 4;
					}
					SDL_RenderCopyEx(render, char1.ultiFrame[char1.bulletOnScreen[i].currentBulletFrame], NULL, &char1.bulletOnScreen[i].currentBulletPos, 0, NULL, char1.bulletOnScreen[i].flip);
					char1.bulletOnScreen[i].currentBulletFrame = (char1.bulletOnScreen[i].currentBulletFrame + 1) % (int)char1.ultiFrame.size();
				}
			}
		}
	}
}

void electroAttack(electroChar& char2, string type, SDL_Renderer* render, SDL_Point dot, string& direction)
{
	SDL_Rect p{};
	if (type == "N" && cooldown(char2.previousTimeN, 100) == true)
	{
		if (char2.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char2.currentCharPos.x + 50, char2.currentCharPos.y + 25, 800, 25 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char2.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char2.currentCharPos.x - 800, char2.currentCharPos.y + 25, 800, 25 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * (char2.currentCharPos.y + 25)) / (1.0 * dot.x - 1.0 * char2.currentCharPos.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char2.bulletOnScreen.push_back(bull);
		}
	}
	else if (type == "E" && cooldown(char2.previousTimeE, 2000) == true)
	{
		if (char2.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char2.currentCharPos.x + 50, char2.currentCharPos.y + 25, 60, 50 };
			bullet bull(type, p, 0, SDL_GetTicks(), 15);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char2.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char2.currentCharPos.x, char2.currentCharPos.y + 25, 60, 50 };
			bullet bull(type, p, 0, SDL_GetTicks(), 15);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char2.bulletOnScreen.push_back(bull);
		}
	}
	else if (type == "Q" && cooldown(char2.previousTimeQ, 4000) == true)
	{
		p = { dot.x, dot.y - 250, 150, 250 };
		bullet b(type, p, 0, SDL_GetTicks(), 100);
		b.startTime = SDL_GetTicks();
		char2.bulletOnScreen.push_back(b);
	}
	for (int i = 0; i < char2.bulletOnScreen.size(); i++)
	{
		if (char2.bulletOnScreen[i].type == "N")
		{
			if (char2.bulletOnScreen[i].currentBulletFrame == char2.normalFrame.size())
			{
				char2.bulletOnScreen.erase(char2.bulletOnScreen.begin() + i, char2.bulletOnScreen.begin() + i + 1);
				i--;
			}
			else if (cooldown(char2.bulletOnScreen[i].previousTime, char2.bulletOnScreen[i].step) == true)
			{
				SDL_Point center{};
				if (char2.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					center = { 0, 0 };
				}
				else
				{
					center = { 800, 25 };
				}
				SDL_RenderCopyEx(render, char2.normalFrame[char2.bulletOnScreen[i].currentBulletFrame], NULL, &char2.bulletOnScreen[i].currentBulletPos, atan(char2.bulletOnScreen[i].a) * (180 / 3.141592654), &center, char2.bulletOnScreen[i].flip);
				char2.bulletOnScreen[i].currentBulletFrame++;
			}
		}
		else if (char2.bulletOnScreen[i].type == "E")
		{
			if (char2.bulletOnScreen[i].currentBulletPos.x > SCREEN_WIDTH || char2.bulletOnScreen[i].currentBulletPos.x < 0 || char2.bulletOnScreen[i].currentBulletPos.y < 0 || char2.bulletOnScreen[i].currentBulletPos.y > SCREEN_HEIGHT)
			{
				char2.bulletOnScreen.erase(char2.bulletOnScreen.begin() + i, char2.bulletOnScreen.begin() + i + 1);
				i--;
			}
			else if (cooldown(char2.bulletOnScreen[i].previousTime, char2.bulletOnScreen[i].step) == true)
			{
				if (char2.bulletOnScreen[i].flip == SDL_FLIP_HORIZONTAL)
				{
					char2.bulletOnScreen[i].currentBulletPos.x -= 15;
				}
				else
				{
					char2.bulletOnScreen[i].currentBulletPos.x += 15;
				}
				char2.bulletOnScreen[i].currentBulletPos.y = round(char2.bulletOnScreen[i].a * char2.bulletOnScreen[i].currentBulletPos.x + char2.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char2.elementalFrame[char2.bulletOnScreen[i].currentBulletFrame], NULL, &char2.bulletOnScreen[i].currentBulletPos, atan(char2.bulletOnScreen[i].a) * (180 / 3.141592654), NULL, char2.bulletOnScreen[i].flip);
				char2.bulletOnScreen[i].currentBulletFrame = (char2.bulletOnScreen[i].currentBulletFrame + 1) % (int) char2.elementalFrame.size();
			}
		}
		else if (char2.bulletOnScreen[i].type == "Q")
		{
			if (cooldown(char2.bulletOnScreen[i].previousTime, char2.bulletOnScreen[i].step) == true)
			{
				char2.bulletOnScreen[i].currentBulletPos.x += 1;
				SDL_RenderCopy(render, char2.ultiFrame[char2.bulletOnScreen[i].currentBulletFrame], NULL, &char2.bulletOnScreen[i].currentBulletPos);
				char2.bulletOnScreen[i].currentBulletFrame = (rand() % (int) char2.ultiFrame.size());
			}
			else if (cooldown(char2.bulletOnScreen[i].startTime, 7000) == true)
			{
				char2.bulletOnScreen.erase(char2.bulletOnScreen.begin() + i, char2.bulletOnScreen.begin() + i + 1);
				i--;
			}
		}
	}
}

void hydroAttack(hydroChar& char3, string type, SDL_Renderer* render, SDL_Point dot, string& direction)
{
	SDL_Rect p1{};
	SDL_Rect p2{};
	SDL_Rect p3{};
	SDL_Rect p4{};
	SDL_Rect p5{};
	SDL_Rect p6{};
	SDL_Rect p7{};
	SDL_Rect p8{};
	if (type == "N" && cooldown(char3.previousTimeN, 100) == true)
	{
		if (char3.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p1 = { char3.currentCharPos.x + 50, char3.currentCharPos.y + 25, 50, 50 };
			bullet bull(type, p1, 0, SDL_GetTicks(), 20);
			bull.a = (1.0 * dot.y - 1.0 * p1.y) / (1.0 * dot.x - 1.0 * p1.x);
			bull.b = (1.0 * dot.x * 1.0 * p1.y - 1.0 * p1.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p1.x);
			bull.flip = SDL_FLIP_NONE;
			char3.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p1 = { char3.currentCharPos.x, char3.currentCharPos.y + 25, 50, 50 };
			bullet bull(type, p1, 0, SDL_GetTicks(), 20);
			bull.a = (1.0 * dot.y - 1.0 * p1.y) / (1.0 * dot.x - 1.0 * p1.x);
			bull.b = (1.0 * dot.x * 1.0 * p1.y - 1.0 * p1.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p1.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char3.bulletOnScreen.push_back(bull);
		}
	}
	else if (type == "E" && cooldown(char3.previousTimeE, 2000) == true)
	{
		bullet bull(type, char3.currentCharPos, 0, SDL_GetTicks(), 0);
		bull.startTime = SDL_GetTicks();
		bull.a = 10;
		char3.bulletOnScreen.push_back(bull);
	}
	else if (type == "Q" && cooldown(char3.previousTimeQ, 4000) == true)
	{
		p1 = { char3.currentCharPos.x + 50, char3.currentCharPos.y + 50, 80, 10 };
		p2 = { char3.currentCharPos.x - 25, char3.currentCharPos.y - 30, 80, 10 };
		p3 = { char3.currentCharPos.x - 100, char3.currentCharPos.y + 50, 80, 10 };
		p4 = { char3.currentCharPos.x - 150, char3.currentCharPos.y + 25, 80, 10 };
		p5 = { char3.currentCharPos.x + 100, char3.currentCharPos.y + 25, 80, 10 };
		p6 = { char3.currentCharPos.x - 100, char3.currentCharPos.y, 80, 10 };
		p7 = { char3.currentCharPos.x + 220, char3.currentCharPos.y, 80, 10 };
		p8 = { char3.currentCharPos.x, char3.currentCharPos.y - 50, 80, 10 };
		bullet b1(type, p1, 0, SDL_GetTicks(), 100);
		bullet b2(type, p2, 0, SDL_GetTicks(), 200);
		bullet b3(type, p3, 0, SDL_GetTicks(), 300);
		bullet b4(type, p4, 0, SDL_GetTicks(), 400);
		bullet b5(type, p5, 0, SDL_GetTicks(), 500);
		bullet b6(type, p6, 0, SDL_GetTicks(), 600);
		bullet b7(type, p7, 0, SDL_GetTicks(), 700);
		bullet b8(type, p8, 0, SDL_GetTicks(), 800);
		if (char3.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			b1.flip = SDL_FLIP_NONE;
			b2.flip = SDL_FLIP_NONE;
			b3.flip = SDL_FLIP_NONE;
			b4.flip = SDL_FLIP_NONE;
			b5.flip = SDL_FLIP_NONE;
			b6.flip = SDL_FLIP_NONE;
			b7.flip = SDL_FLIP_NONE;
			b8.flip = SDL_FLIP_NONE;
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			b1.flip = SDL_FLIP_HORIZONTAL;
			b2.flip = SDL_FLIP_HORIZONTAL;
			b3.flip = SDL_FLIP_HORIZONTAL;
			b4.flip = SDL_FLIP_HORIZONTAL;
			b5.flip = SDL_FLIP_HORIZONTAL;
			b6.flip = SDL_FLIP_HORIZONTAL;
			b7.flip = SDL_FLIP_HORIZONTAL;
			b8.flip = SDL_FLIP_HORIZONTAL;
		}
		char3.bulletOnScreen.push_back(b1);
		char3.bulletOnScreen.push_back(b2);
		char3.bulletOnScreen.push_back(b3);
		char3.bulletOnScreen.push_back(b4);
		char3.bulletOnScreen.push_back(b5);
		char3.bulletOnScreen.push_back(b6);
		char3.bulletOnScreen.push_back(b7);
		char3.bulletOnScreen.push_back(b8);
	}
	for (int i = 0; i < char3.bulletOnScreen.size(); i++)
	{
		if (char3.bulletOnScreen[i].type == "N")
		{
			if (char3.bulletOnScreen[i].currentBulletPos.x > SCREEN_WIDTH || char3.bulletOnScreen[i].currentBulletPos.x < 0 || char3.bulletOnScreen[i].currentBulletPos.y < 0 || char3.bulletOnScreen[i].currentBulletPos.y > SCREEN_HEIGHT)
			{
				char3.bulletOnScreen.erase(char3.bulletOnScreen.begin() + i, char3.bulletOnScreen.begin() + i + 1);
				i--;
			}
			else if (cooldown(char3.bulletOnScreen[i].previousTime, char3.bulletOnScreen[i].step) == true)
			{
				if (char3.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					char3.bulletOnScreen[i].currentBulletPos.x += 20;
				}
				else
				{
					char3.bulletOnScreen[i].currentBulletPos.x -= 20;
				}
				char3.bulletOnScreen[i].currentBulletPos.y = round(char3.bulletOnScreen[i].a * char3.bulletOnScreen[i].currentBulletPos.x + char3.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char3.normalFrame[char3.bulletOnScreen[i].currentBulletFrame], NULL, &char3.bulletOnScreen[i].currentBulletPos, atan(char3.bulletOnScreen[i].a) * (180 / 3.141592654), NULL, char3.bulletOnScreen[i].flip);
				char3.bulletOnScreen[i].currentBulletFrame = (char3.bulletOnScreen[i].currentBulletFrame + 1) % (int) char3.normalFrame.size();
			}
		}
		else if (char3.bulletOnScreen[i].type == "E")
		{
			if (cooldown(char3.bulletOnScreen[i].previousTime, char3.bulletOnScreen[i].step) == true)
			{
				SDL_Rect pos = char3.currentCharPos;
				pos.x -= 100;
				pos.y -= 100;
				pos.w += 200;
				pos.h += 200;
				SDL_RenderCopyEx(render, char3.elementalFrame[char3.bulletOnScreen[i].currentBulletFrame], NULL, &pos, char3.bulletOnScreen[i].a, NULL, SDL_FLIP_NONE);
				char3.bulletOnScreen[i].a += 10;
				char3.bulletOnScreen[i].currentBulletFrame = (char3.bulletOnScreen[i].currentBulletFrame + 1) % (int)char3.elementalFrame.size();
			}
			if (cooldown(char3.bulletOnScreen[i].startTime, 10000) == true)
			{
				char3.bulletOnScreen.erase(char3.bulletOnScreen.begin() + i, char3.bulletOnScreen.begin() + i + 1);
				i--;
			}
			if (char3.use_E_skill == false)
			{
				char3.bulletOnScreen.erase(char3.bulletOnScreen.begin() + i, char3.bulletOnScreen.begin() + i + 1);
				i--;
			}
		}
		else if (char3.bulletOnScreen[i].type == "Q")
		{
			if (char3.bulletOnScreen[i].currentBulletPos.x > SCREEN_WIDTH || char3.bulletOnScreen[i].currentBulletPos.x < 0 || char3.bulletOnScreen[i].currentBulletPos.y < 0 || char3.bulletOnScreen[i].currentBulletPos.y > SCREEN_HEIGHT)
			{
				char3.bulletOnScreen.erase(char3.bulletOnScreen.begin() + i, char3.bulletOnScreen.begin() + i + 1);
				i--;
			}
			else if (cooldown(char3.bulletOnScreen[i].previousTime, char3.bulletOnScreen[i].step) == true)
			{
				if (char3.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					char3.bulletOnScreen[i].currentBulletPos.x += 100;
				}
				else
				{
					char3.bulletOnScreen[i].currentBulletPos.x -= 100;
				}
				SDL_RenderCopyEx(render, char3.ultiFrame[char3.bulletOnScreen[i].currentBulletFrame], NULL, &char3.bulletOnScreen[i].currentBulletPos, 0, NULL, char3.bulletOnScreen[i].flip);
				char3.bulletOnScreen[i].step = 0;
			}
			else
			{
				SDL_RenderCopyEx(render, char3.ultiFrame[char3.bulletOnScreen[i].currentBulletFrame], NULL, &char3.bulletOnScreen[i].currentBulletPos, 0, NULL, char3.bulletOnScreen[i].flip);
			}
		}
	}
}

void pyroAttack(pyroChar& char4, string type, SDL_Renderer* render, SDL_Point dot, string& direction)
{
	SDL_Rect p{};
	if (type == "N" && cooldown(char4.previousTimeN, 50))
	{
		if (char4.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char4.currentCharPos.x + 50, char4.currentCharPos.y + 25, 20, 10 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char4.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char4.currentCharPos.x, char4.currentCharPos.y + 25, 20, 10 };
			bullet bull(type, p, 0, SDL_GetTicks(), 0);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char4.bulletOnScreen.push_back(bull);
		}
	}
	if (type == "E" && cooldown(char4.previousTimeE, 300))
	{
		if (char4.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char4.currentCharPos.x + 50, char4.currentCharPos.y + 25, 40, 20 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char4.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char4.currentCharPos.x, char4.currentCharPos.y + 25, 40, 20 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char4.bulletOnScreen.push_back(bull);
		}
	}
	if (type == "Q" && cooldown(char4.previousTimeQ, 500))
	{
		if (char4.currentCharPos.x <= dot.x)
		{
			if (direction == "left")
			{
				direction = "right";
			}
			p = { char4.currentCharPos.x + 50, char4.currentCharPos.y + 25, 50, 40 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_NONE;
			char4.bulletOnScreen.push_back(bull);
		}
		else
		{
			if (direction == "right")
			{
				direction = "left";
			}
			p = { char4.currentCharPos.x, char4.currentCharPos.y + 25, 50, 40 };
			bullet bull(type, p, 0, SDL_GetTicks(), 10);
			bull.a = (1.0 * dot.y - 1.0 * p.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.b = (1.0 * dot.x * 1.0 * p.y - 1.0 * p.x * 1.0 * dot.y) / (1.0 * dot.x - 1.0 * p.x);
			bull.flip = SDL_FLIP_HORIZONTAL;
			char4.bulletOnScreen.push_back(bull);
		}
	}
	for (int i = 0; i < char4.bulletOnScreen.size(); i++)
	{
		if (char4.bulletOnScreen[i].currentBulletPos.x > SCREEN_WIDTH || char4.bulletOnScreen[i].currentBulletPos.x < 0 || char4.bulletOnScreen[i].currentBulletPos.y < 0 || char4.bulletOnScreen[i].currentBulletPos.y > SCREEN_HEIGHT)
		{
			char4.bulletOnScreen.erase(char4.bulletOnScreen.begin() + i, char4.bulletOnScreen.begin() + i + 1);
			i--;
		}
		else
		{
			if (char4.bulletOnScreen[i].type == "N")
			{
				if (char4.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					char4.bulletOnScreen[i].currentBulletPos.x += 40;
				}
				else
				{
					char4.bulletOnScreen[i].currentBulletPos.x -= 40;
				}
				char4.bulletOnScreen[i].currentBulletPos.y = round(char4.bulletOnScreen[i].a * char4.bulletOnScreen[i].currentBulletPos.x + char4.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char4.normalFrame[char4.bulletOnScreen[i].currentBulletFrame], NULL, &char4.bulletOnScreen[i].currentBulletPos, atan(char4.bulletOnScreen[i].a)* (180 / 3.141592654), NULL, char4.bulletOnScreen[i].flip);
				char4.bulletOnScreen[i].currentBulletFrame = (char4.bulletOnScreen[i].currentBulletFrame + 1) % (int) char4.normalFrame.size();
			}
			else if (char4.bulletOnScreen[i].type == "E")
			{
				if (char4.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					char4.bulletOnScreen[i].currentBulletPos.x += 30;
				}
				else
				{
					char4.bulletOnScreen[i].currentBulletPos.x -= 30;
				}
				char4.bulletOnScreen[i].currentBulletPos.y = round(char4.bulletOnScreen[i].a * char4.bulletOnScreen[i].currentBulletPos.x + char4.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char4.elementalFrame[char4.bulletOnScreen[i].currentBulletFrame], NULL, &char4.bulletOnScreen[i].currentBulletPos, atan(char4.bulletOnScreen[i].a)* (180 / 3.141592654), NULL, char4.bulletOnScreen[i].flip);
				char4.bulletOnScreen[i].currentBulletFrame = (char4.bulletOnScreen[i].currentBulletFrame + 1) % (int)char4.elementalFrame.size();
			}
			else if (char4.bulletOnScreen[i].type == "Q")
			{
				if (char4.bulletOnScreen[i].flip == SDL_FLIP_NONE)
				{
					char4.bulletOnScreen[i].currentBulletPos.x += 30;
				}
				else
				{
					char4.bulletOnScreen[i].currentBulletPos.x -= 30;
				}
				char4.bulletOnScreen[i].currentBulletPos.y = round(char4.bulletOnScreen[i].a * char4.bulletOnScreen[i].currentBulletPos.x + char4.bulletOnScreen[i].b);
				SDL_RenderCopyEx(render, char4.ultiFrame[char4.bulletOnScreen[i].currentBulletFrame], NULL, &char4.bulletOnScreen[i].currentBulletPos, atan(char4.bulletOnScreen[i].a) * (180 / 3.141592654), NULL, char4.bulletOnScreen[i].flip);
				char4.bulletOnScreen[i].currentBulletFrame = (char4.bulletOnScreen[i].currentBulletFrame + 1) % (int)char4.ultiFrame.size();
			}
		}
	}
}
