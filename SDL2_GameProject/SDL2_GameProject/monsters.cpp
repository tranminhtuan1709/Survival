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
	loadImage(attackFrame, "Image/Monsters/Monster3/mons3_attack_", 7, render);
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
	loadImage(attackFrame, "Image/Monsters/Monster7/mons7_attack_", 6, render);
}

void Monster8::loadData(SDL_Renderer* render)
{
	loadImage(frame, "Image/Monsters/Monster8/frame", 2, render);
	checkRandom = true;
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
	mons8.loadData(render);
	bulletMons = IMG_LoadTexture(render, "Image/Monsters/bullet.png");
	hp1 = IMG_LoadTexture(render, "Image/hp1.png");
	hp2 = IMG_LoadTexture(render, "Image/hp2.png");
}

MonsterInformation::MonsterInformation()
{
	HP = 0;
	atk = 0;
	def = 0;
	speed = 0;
	startTime = SDL_GetTicks();
	existTime = 0;
	currentFrameHP = 0;
	numberFrameDie = 0;
	previousFrameTimeRun = SDL_GetTicks(); delayFrameTimeRun = 10; currentFrameRun = 0;
	previousFrameTimeDie = SDL_GetTicks(); delayFrameTimeDie = 10; currentFrameDie = 0;
	previousFrameTimeAttack = SDL_GetTicks(); delayFrameTimeAttack = 10; currentFrameAttack = 0;
	flip = SDL_FLIP_NONE;
	position = { 0, 0, 0, 0 };
	direction = "right";
	type = "";
	checkFrame = false;
	isChasing = true;
	isAlive = true;
}

void randomMonster(AllMonsters& monsters, int monsType)
{
	if (cooldown(monsters.previousRandomTime, 300) == false)
	{
		return;
	}
	srand((int)time(0));
	MonsterInformation monsInfor;
	if (monsType == 1)
	{
		monsInfor.HP = 500;
		monsInfor.maxHP = 500;
		monsInfor.atk = 4;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 3) + 1;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "green_dinosaur";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.numberFrameDie = monsters.mons1.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 2)
	{
		monsInfor.HP = 300;
		monsInfor.maxHP = 300;
		monsInfor.atk = 2;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 30, 30 };
		monsInfor.direction = "right";
		monsInfor.type = "mushroom";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.numberFrameDie = monsters.mons2.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 3)
	{
		monsInfor.HP = 500;
		monsInfor.maxHP = 500;
		monsInfor.atk = 4;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 3) + 1;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "red_dinosaur";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.delayFrameTimeAttack = 60;
		monsInfor.numberFrameDie = monsters.mons3.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 4)
	{
		monsInfor.HP = 500;
		monsInfor.maxHP = 500;
		monsInfor.atk = 2;
		monsInfor.def = 10;
		monsInfor.speed = 20;
		int temp = (rand() + (int)SDL_GetTicks()) % 2;
		temp == 1 ? monsInfor.position = { 0, (rand() + (int)SDL_GetTicks()) % (SCREEN_HEIGHT - 30), 40, 30 } : monsInfor.position = { 1760, (rand() + (int)SDL_GetTicks()) % (SCREEN_HEIGHT - 30), 40, 30 };
		monsInfor.position.x == 0 ? monsInfor.flip = SDL_FLIP_NONE : monsInfor.flip = SDL_FLIP_HORIZONTAL;
		monsInfor.type = "pterosaurs";
		monsInfor.delayFrameTimeRun = 30;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.numberFrameDie = monsters.mons4.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 5)
	{
		monsInfor.HP = 600;
		monsInfor.maxHP = 600;
		monsInfor.atk = 4;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.flip = SDL_FLIP_NONE;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "robot";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.delayFrameTimeAttack = 2000;
		monsInfor.numberFrameDie = monsters.mons5.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 6)
	{
		monsInfor.HP = 600;
		monsInfor.maxHP = 600;
		monsInfor.atk = 2;
		monsInfor.def = 10;
		monsInfor.speed = 1;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "machine";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.delayFrameTimeAttack = 4000;
		monsInfor.numberFrameDie = monsters.mons6.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
	if (monsType == 7)
	{
		monsInfor.HP = 500;
		monsInfor.maxHP = 500;
		monsInfor.atk = 6;
		monsInfor.def = 10;
		monsInfor.speed = (rand() % 2) + 1;
		monsInfor.position = { (rand() + (int)SDL_GetTicks()) % SCREEN_WIDTH, (rand() + (int)SDL_GetTicks()) % SCREEN_HEIGHT, 60, 60 };
		monsInfor.direction = "right";
		monsInfor.type = "cyborg";
		monsInfor.delayFrameTimeRun = 40;
		monsInfor.delayFrameTimeDie = 30;
		monsInfor.delayFrameTimeAttack = 100;
		monsInfor.numberFrameDie = monsters.mons7.dieFrame.size() - 1;
		monsters.monsterOnScreen.push_back(monsInfor);
	}
}

void chase(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (monsters.monsterOnScreen[i].isAlive == false)
		{
			continue;
		}
		if (monsters.monsterOnScreen[i].position.x < 0 || monsters.monsterOnScreen[i].position.x + monsters.monsterOnScreen[i].position.w > SCREEN_WIDTH || monsters.monsterOnScreen[i].position.y <= 0 || monsters.monsterOnScreen[i].position.y >= SCREEN_HEIGHT)
		{
			monsters.monsterOnScreen.erase(monsters.monsterOnScreen.begin() + i, monsters.monsterOnScreen.begin() + i + 1);
			i--;
		}
		else if (monsters.monsterOnScreen[i].isChasing == true)
		{
			if (monsters.monsterOnScreen[i].type != "pterosaurs")
			{
				if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeRun, monsters.monsterOnScreen[i].delayFrameTimeRun) == true)
				{
					monsters.monsterOnScreen[i].checkFrame = true;
					if (monsters.monsterOnScreen[i].position.x + monsters.monsterOnScreen[i].position.w <= characters.currentCharPosition.x)
					{
						monsters.monsterOnScreen[i].position.x += monsters.monsterOnScreen[i].speed;
						monsters.monsterOnScreen[i].flip = SDL_FLIP_NONE;
					}
					if (monsters.monsterOnScreen[i].position.x >= characters.currentCharPosition.x + characters.currentCharPosition.w)
					{
						monsters.monsterOnScreen[i].position.x -= monsters.monsterOnScreen[i].speed;
						monsters.monsterOnScreen[i].flip = SDL_FLIP_HORIZONTAL;
					}
					if (monsters.monsterOnScreen[i].position.y >= characters.currentCharPosition.y + characters.currentCharPosition.h)
					{
						monsters.monsterOnScreen[i].position.y -= monsters.monsterOnScreen[i].speed;
					}
					if (monsters.monsterOnScreen[i].position.y + monsters.monsterOnScreen[i].position.h <= characters.currentCharPosition.y)
					{
						monsters.monsterOnScreen[i].position.y += monsters.monsterOnScreen[i].speed;
					}
				}
				if (monsters.monsterOnScreen[i].type == "green_dinosaur")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons1.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons1.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
				if (monsters.monsterOnScreen[i].type == "red_dinosaur")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons3.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons3.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
				if (monsters.monsterOnScreen[i].type == "mushroom")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons2.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons2.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
				if (monsters.monsterOnScreen[i].type == "cyborg")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons7.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons7.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
				if (monsters.monsterOnScreen[i].type == "robot")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons5.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons5.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
				if (monsters.monsterOnScreen[i].type == "machine")
				{
					if (monsters.monsterOnScreen[i].checkFrame == true)
					{
						monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons6.runFrame.size();
						monsters.monsterOnScreen[i].checkFrame = false;
					}
					SDL_RenderCopyEx(render, monsters.mons6.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
			}
			if (monsters.monsterOnScreen[i].type == "pterosaurs")
			{
				if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeRun, monsters.monsterOnScreen[i].delayFrameTimeRun) == true)
				{
					monsters.monsterOnScreen[i].checkFrame = true;
					if (monsters.monsterOnScreen[i].flip == SDL_FLIP_NONE)
					{
						monsters.monsterOnScreen[i].position.x += monsters.monsterOnScreen[i].speed;
					}
					else
					{
						monsters.monsterOnScreen[i].position.x -= monsters.monsterOnScreen[i].speed;
					}
				}
				if (monsters.monsterOnScreen[i].checkFrame == true)
				{
					monsters.monsterOnScreen[i].currentFrameRun = (monsters.monsterOnScreen[i].currentFrameRun + 1) % (int)monsters.mons4.runFrame.size();
					monsters.monsterOnScreen[i].checkFrame = false;
				}
				SDL_RenderCopyEx(render, monsters.mons4.runFrame[monsters.monsterOnScreen[i].currentFrameRun], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
			}
			if (monsters.monsterOnScreen[i].type == "canon")
			{
				SDL_RenderCopyEx(render, monsters.mons8.frame[0], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeAttack, monsters.monsterOnScreen[i].delayFrameTimeAttack) == true)
				{
					bullet bull1;
					bullet bull2;
					bullet bull3;
					bullet bull4;
					bull1.damage = monsters.monsterOnScreen[i].atk; bull1.type = "canon";
					bull2.damage = monsters.monsterOnScreen[i].atk; bull2.type = "canon";
					bull3.damage = monsters.monsterOnScreen[i].atk; bull3.type = "canon";
					bull4.damage = monsters.monsterOnScreen[i].atk; bull4.type = "canon";
					bull1.currentBulletPos = { 100, 220, 30, 20 };
					bull2.currentBulletPos = { 100, 620, 30, 20 };
					bull3.currentBulletPos = { 1700, 420, 30, 20 }; bull3.flip = SDL_FLIP_HORIZONTAL;
					bull4.currentBulletPos = { 1700, 820, 30, 20 }; bull4.flip = SDL_FLIP_HORIZONTAL;
					monsters.bulletMonster.push_back(bull1);
					monsters.bulletMonster.push_back(bull2);
					monsters.bulletMonster.push_back(bull3);
					monsters.bulletMonster.push_back(bull4);
				}
			}
		}
	}
}

void beAttacked(AllMonsters& monsters, AllCharacters& characters)
{
	for (int i = 0; i < characters.bulletCharacter.size(); i++)
	{
		for (int j = 0; j < monsters.monsterOnScreen.size(); j++)
		{
			if (monsters.monsterOnScreen[j].type != "canon" && monsters.monsterOnScreen[j].isAlive == true)
			{
				if (characters.bulletCharacter[i].type == "N1" || characters.bulletCharacter[i].type == "N2" || characters.bulletCharacter[i].type == "N3" || characters.bulletCharacter[i].type == "N4" || characters.bulletCharacter[i].type == "E1" || characters.bulletCharacter[i].type == "E4")
				{
					if (checkCollision(characters.bulletCharacter[i].currentBulletPos, monsters.monsterOnScreen[j].position) == true)
					{
						characters.bulletCharacter[i].checkExist = false;
						monsters.monsterOnScreen[j].HP -= characters.bulletCharacter[i].damage;
					}
				}
				if (characters.bulletCharacter[i].type == "Q1" || characters.bulletCharacter[i].type == "Q2" || characters.bulletCharacter[i].type == "Q3" || characters.bulletCharacter[i].type == "Q4")
				{
					if (checkCollision(characters.bulletCharacter[i].currentBulletPos, monsters.monsterOnScreen[j].position) == true)
					{
						monsters.monsterOnScreen[j].HP -= characters.bulletCharacter[i].damage;
					}
				}
				if (characters.bulletCharacter[i].type == "E2")
				{
					if (characters.bulletCharacter[i].startTime + characters.bulletCharacter[i].existTime <= (int)SDL_GetTicks() && checkCollision(characters.bulletCharacter[i].boom, monsters.monsterOnScreen[j].position) == true)
					{
						monsters.monsterOnScreen[j].HP -= characters.bulletCharacter[i].damage;
					}
				}
			}
		}
	}
}

void attack(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (monsters.monsterOnScreen[i].isAlive == false)
		{
			continue;
		}
		if (monsters.monsterOnScreen[i].type == "red_dinosaur")
		{
			if (checkCollision(monsters.monsterOnScreen[i].position, characters.currentCharPosition) == true)
			{
				monsters.monsterOnScreen[i].isChasing = false;
				monsters.monsterOnScreen[i].checkFrame = false;
				*characters.currentCharHP -= (int)(1.0 * monsters.monsterOnScreen[i].atk * 1.0 * (100 - characters.baseDEF) / 100);
			}
			if (monsters.monsterOnScreen[i].isChasing == false)
			{
				if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeAttack, monsters.monsterOnScreen[i].delayFrameTimeAttack) == true)
				{
					monsters.monsterOnScreen[i].currentFrameAttack++;
				}
				if (monsters.monsterOnScreen[i].currentFrameAttack >= (int)monsters.mons3.attackFrame.size())
				{
					monsters.monsterOnScreen[i].isChasing = true;
					monsters.monsterOnScreen[i].currentFrameAttack = 0;
				}
				else
				{
					SDL_RenderCopyEx(render, monsters.mons3.attackFrame[monsters.monsterOnScreen[i].currentFrameAttack], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
			}
		}
		if (monsters.monsterOnScreen[i].type == "cyborg")
		{
			if (checkCollision(monsters.monsterOnScreen[i].position, characters.currentCharPosition) == true)
			{
				monsters.monsterOnScreen[i].isChasing = false;
				monsters.monsterOnScreen[i].checkFrame = false;
				*characters.currentCharHP -= (int)(1.0 * monsters.monsterOnScreen[i].atk * 1.0 * (100 - characters.baseDEF) / 100);
			}
			if (monsters.monsterOnScreen[i].isChasing == false)
			{
				if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeAttack, monsters.monsterOnScreen[i].delayFrameTimeAttack) == true)
				{
					monsters.monsterOnScreen[i].currentFrameAttack++;
				}
				if (monsters.monsterOnScreen[i].currentFrameAttack >= (int)monsters.mons7.attackFrame.size())
				{
					monsters.monsterOnScreen[i].isChasing = true;
					monsters.monsterOnScreen[i].currentFrameAttack = 0;
				}
				else
				{
					SDL_RenderCopyEx(render, monsters.mons7.attackFrame[monsters.monsterOnScreen[i].currentFrameAttack], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				}
			}
		}
		if (monsters.monsterOnScreen[i].type == "green_dinosaur" || monsters.monsterOnScreen[i].type == "mushroom" || monsters.monsterOnScreen[i].type == "pterosaurs")
		{
			if (checkCollision(monsters.monsterOnScreen[i].position, characters.currentCharPosition) == true)
			{
				*characters.currentCharHP -= (int)(1.0 * monsters.monsterOnScreen[i].atk * 1.0 * (100 - characters.baseDEF) / 100);
			}
		}
		if (monsters.monsterOnScreen[i].type == "machine" || monsters.monsterOnScreen[i].type == "robot")
		{
			if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeAttack, monsters.monsterOnScreen[i].delayFrameTimeAttack) == true)
			{
				bullet bull;
				bull.damage = monsters.monsterOnScreen[i].atk;
				if (monsters.monsterOnScreen[i].flip == SDL_FLIP_NONE)
				{
					bull.currentBulletPos = { monsters.monsterOnScreen[i].position.x + monsters.monsterOnScreen[i].position.w, monsters.monsterOnScreen[i].position.y + monsters.monsterOnScreen[i].position.h / 2, 20, 10 };
				}
				else
				{
					bull.flip = SDL_FLIP_HORIZONTAL;
					bull.currentBulletPos = { monsters.monsterOnScreen[i].position.x, monsters.monsterOnScreen[i].position.y + monsters.monsterOnScreen[i].position.h / 2, 20, 10 };
				}
				monsters.bulletMonster.push_back(bull);
			}
		}
	}
	for (int i = 0; i < monsters.bulletMonster.size(); i++)
	{
		if (monsters.bulletMonster[i].currentBulletPos.x + monsters.bulletMonster[i].currentBulletPos.w > SCREEN_WIDTH || monsters.bulletMonster[i].currentBulletPos.x < 0 || monsters.bulletMonster[i].currentBulletPos.y + monsters.bulletMonster[i].currentBulletPos.h > SCREEN_HEIGHT || monsters.bulletMonster[i].currentBulletPos.y < 0 || monsters.bulletMonster[i].checkExist == false)
		{
			monsters.bulletMonster.erase(monsters.bulletMonster.begin() + i, monsters.bulletMonster.begin() + i + 1);
			i--;
		}
		else
		{
			if (monsters.bulletMonster[i].type == "canon")
			{
				SDL_RenderCopyEx(render, monsters.mons8.frame[1], NULL, &monsters.bulletMonster[i].currentBulletPos, 0, NULL, monsters.bulletMonster[i].flip);
			}
			else
			{	
				SDL_RenderCopyEx(render, monsters.bulletMons, NULL, &monsters.bulletMonster[i].currentBulletPos, 0, NULL, monsters.bulletMonster[i].flip);
			}
			if (monsters.bulletMonster[i].flip == SDL_FLIP_NONE)
			{
				monsters.bulletMonster[i].currentBulletPos.x += 7;
			}
			else
			{
				monsters.bulletMonster[i].currentBulletPos.x -= 7;
			}
			if (checkCollision(monsters.bulletMonster[i].currentBulletPos, characters.currentCharPosition) == true)
			{
				monsters.bulletMonster[i].checkExist = false;
				*characters.currentCharHP -= (int)(1.0 * monsters.bulletMonster[i].damage * 1.0 * (100 - characters.baseDEF) / 100);
			}
		}
	}
}

void updateHPMonsters(AllMonsters& monsters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (monsters.monsterOnScreen[i].type != "canon")
		{
			int percentHP{};
			if (monsters.monsterOnScreen[i].HP <= 0)
			{
				percentHP = 0;
			}
			else
			{
				percentHP = (int)monsters.monsterOnScreen[i].HP * 100 / monsters.monsterOnScreen[i].maxHP;
			}
			SDL_Rect total = { monsters.monsterOnScreen[i].position.x, monsters.monsterOnScreen[i].position.y - 10, monsters.monsterOnScreen[i].position.w, 5 };
			SDL_Rect left = { monsters.monsterOnScreen[i].position.x, monsters.monsterOnScreen[i].position.y - 10, (int)(monsters.monsterOnScreen[i].position.w * percentHP / 100), 5 };
			SDL_RenderCopy(render, monsters.hp1, NULL, &total);
			SDL_RenderCopy(render, monsters.hp2, NULL, &left);
		}
	}
}

void monsterDie(AllMonsters& monsters, SDL_Renderer* render)
{
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (monsters.monsterOnScreen[i].HP <= 0)
		{
			monsters.monsterOnScreen[i].isAlive = false;
		}
	}
	for (int i = 0; i < monsters.monsterOnScreen.size(); i++)
	{
		if (monsters.monsterOnScreen[i].isAlive == false)
		{
			monsters.monsterOnScreen[i].checkFrame = false;
			if (cooldown(monsters.monsterOnScreen[i].previousFrameTimeDie, monsters.monsterOnScreen[i].delayFrameTimeDie) == true)
			{
				monsters.monsterOnScreen[i].checkFrame = true;
			}
			if (monsters.monsterOnScreen[i].checkFrame == true)
			{
				monsters.monsterOnScreen[i].currentFrameDie++;
				monsters.monsterOnScreen[i].checkFrame = false;
			}
			if (monsters.monsterOnScreen[i].currentFrameDie > monsters.monsterOnScreen[i].numberFrameDie)
			{
				monsters.monsterOnScreen.erase(monsters.monsterOnScreen.begin() + i, monsters.monsterOnScreen.begin() + i + 1);
				i--;
			}
			else
			{
				if (monsters.monsterOnScreen[i].type == "green_dinosaur") SDL_RenderCopyEx(render, monsters.mons1.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "mushroom") SDL_RenderCopyEx(render, monsters.mons2.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "red_dinosaur") SDL_RenderCopyEx(render, monsters.mons3.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "pterosaurs") SDL_RenderCopyEx(render, monsters.mons4.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "robot") SDL_RenderCopyEx(render, monsters.mons5.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "machine") SDL_RenderCopyEx(render, monsters.mons6.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
				if (monsters.monsterOnScreen[i].type == "cyborg") SDL_RenderCopyEx(render, monsters.mons7.dieFrame[monsters.monsterOnScreen[i].currentFrameDie], NULL, &monsters.monsterOnScreen[i].position, 0, NULL, monsters.monsterOnScreen[i].flip);
			}
		}
	}
}