//#include "boss.h"
//
//Boss::Boss(SDL_Renderer* render)
//{
//	HP = 50000;
//	atk = 100;
//	def = 50;
//	position = { SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT / 3, 200, 300 };
//	for (int i = 0; i < 5; i++)
//	{
//		target[i] = { 0, 0, 0, 0 };
//	}
//	flip = SDL_FLIP_NONE;
//	delay.initData(ALLSTATUS, ALLSTATUS, ALLSTATUS, ALLSTATUS, ALLSKILL, ALLSKILL, 1, 1, 5, 5);
//	delay.delayFrameTime[STANDING] = 30;
//	delay.delayFrameTime[RUNNING] = 30;
//	delay.delayFrameTime[DYING] = 30;
//	delay.delayFrameTime[ATTACKING] = 30;
//	delay.delaySkillTime[SKILL_1] = 4000;
//	delay.delaySkillTime[SKILL_2] = 7000;
//	delay.delaySkillTime[SKILL_3] = 10000;
//	delay.delaySkillTime[SKILL_4] = 25000;
//	delay.delayRandomTime[0] = 3000;
//	for (int i = 0; i < 5; i++)
//	{
//		delay.delayLockTargetTime[i] = 1000;
//	}
//	state = STANDING;
//	for (int i = 0; i < ALLSKILL; i++)
//	{
//		attackedSkill[i] = 0;
//	}
//	isAlive = true;
//	loadImage(hpFrame, "Image/Monsters/Boss/hp", 2, render);
//	loadImage(standFrame, "Image/Monsters/Boss/stand", 4, render);
//	loadImage(runFrame, "Image/Monsters/Boss/run", 9, render);
//	loadImage(dieFrame, "Image/Monsters/Boss/die", 5, render);
//	loadImage(attackFrame, "Image/Monsters/Boss/attack", 8, render);
//}
//
//void Boss::resetSkill()
//{
//	if (attackedSkill[SKILL_1] > 5 && attackedSkill[SKILL_2] > 3 && attackedSkill[SKILL_3] > 2 && attackedSkill[SKILL_4] > 1)
//	{
//		for (int i = 0; i < ALLSKILL; i++)
//		{
//			attackedSkill[i] = 0;
//			delay.previousSkillTime[i] = 0;
//		}
//		for (int i = 0; i < 5; i++)
//		{
//			delay.previousLockTargetTime[i] = 0;
//		}
//	}
//}
//
//void Boss::bossStand(SDL_Renderer* render)
//{
//	if (state != STANDING)
//	{
//		return;
//	}
//	if (cooldown(delay.previousFrameTime[STANDING], delay.delayFrameTime[STANDING]) == true)
//	{
//		delay.checkFrame[STANDING] = true;
//	}
//	if (delay.checkFrame[STANDING] == true)
//	{
//		delay.currentFrame[STANDING] = (delay.currentFrame[STANDING] + 1) % (int)standFrame.size();
//		delay.checkFrame[STANDING] = false;
//	}
//	SDL_RenderCopyEx(render, standFrame[delay.currentFrame[STANDING]], NULL, &position, 0, NULL, flip);
//}
//
//void Boss::bossRun(AllCharacters& characters, SDL_Renderer* render)
//{
//	if (state != RUNNING)
//	{
//		return;
//	}
//	if (cooldown(delay.previousFrameTime[RUNNING], delay.delayFrameTime[RUNNING]) == true)
//	{
//		delay.checkFrame[RUNNING] = true;
//		flip == SDL_FLIP_NONE ? position.x = min(position.x + 2, SCREEN_WIDTH - 200) : position.x = max(position.x - 2, 0);
//	}
//	if (delay.checkFrame[RUNNING] == true)
//	{
//		delay.currentFrame[RUNNING] = (delay.currentFrame[RUNNING] + 1) % (int)runFrame.size();
//		delay.checkFrame[RUNNING] = false;
//	}
//	SDL_RenderCopyEx(render, runFrame[delay.currentFrame[RUNNING]], NULL, &position, 0, NULL, flip);
//}
//
//void Boss::bossDie(SDL_Renderer* render)
//{
//	if (state != DYING || isAlive == true)
//	{
//		return;
//	}
//	if (cooldown(delay.previousFrameTime[DYING], delay.delayFrameTime[DYING]) == true)
//	{
//		delay.checkFrame[DYING] = true;
//	}
//	if (delay.checkFrame[DYING] == true)
//	{
//		delay.currentFrame[DYING] = (delay.currentFrame[DYING] + 1) % (int)dieFrame.size();
//		delay.checkFrame[DYING] = false;
//	}
//	SDL_RenderCopyEx(render, dieFrame[delay.currentFrame[DYING]], NULL, &position, 0, NULL, flip);
//}
//
//void Boss::skill1(AllCharacters& chacracters, AllMonsters& monsters, SDL_Renderer* render)
//{
//	if (state != ATTACKING)
//	{
//		return;
//	}
//	if (cooldown(delay.previousSkillTime[SKILL_1], delay.delaySkillTime[SKILL_1]) == true)
//	{
//		
//	}
//}