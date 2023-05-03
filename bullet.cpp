#include "bullet.h"
#include "enum.h"

Bullet::Bullet()
{
	type = "";
	position = { 0, 0, 0, 0 };
	boom = { 0, 0, 0, 0 };
	damage = 0;
	previousFrameTime = SDL_GetTicks(); delayFrameTime = 0; currentFrame = 0; checkFrame = false;
	startTime = SDL_GetTicks();
	existTime = 0;
	checkExist = true;
	alpha = 0;
	rotate = 0;
	d = 0;
	flip = SDL_FLIP_NONE;
}

BulletOnScreen::BulletOnScreen(SDL_Renderer* render)
{
	bullet_mons5 = IMG_LoadTexture(render, "Image/Monsters/bullet_mons5.png");
	bullet_mons8 = IMG_LoadTexture(render, "Image/Monsters/bullet_mons8.png");
	vector <Bullet> temp;
	for (int i = 0; i < 12; i++)
	{
		bulletCharacter.push_back(temp);
	}
}