#include "characters.h"
#include "game.h"
#include "monsters.h"

int main(int argc, char* argv[])
{
	Game app;
	if (app.checkInit() == false)
	{
		cout << "Can not open game :(" << endl;
		return 0;
	}
	CharacterOnScreen defaultChar;
	anemoChar venti(300, 300, app.pen);
	electroChar raiden(300, 300, app.pen);
	hydroChar xingqiu(300, 300, app.pen);
	pyroChar bennet(300, 300, app.pen);
	
	MonsterOnscreen defaulMons;
	Monster1 dinosaur(app.pen);
	int time = SDL_GetTicks();

	SDL_Event e{};
	bool quit = false;
	defaultChar.currentCharPosition = venti.currentCharPos;
	defaultChar.currentCharSelected = 1;
	defaultChar.currentCharDirection = "right";
	defaultChar.currentCharHP = venti.hp;
	while (quit == false)
	{
		SDL_Delay(15);
		SDL_GetMouseState(&app.mouseCoordinate.x, &app.mouseCoordinate.y);
		SDL_RenderClear(app.pen);
		SDL_PollEvent(&e);
		if (e.key.keysym.sym == SDLK_1)
		{
			defaultChar.currentCharSelected = 1;
		}
		if (e.key.keysym.sym == SDLK_2)
		{
			defaultChar.currentCharSelected = 2;
		}
		if (e.key.keysym.sym == SDLK_3)
		{
			defaultChar.currentCharSelected = 3;
		}
		if (e.key.keysym.sym == SDLK_4)
		{
			defaultChar.currentCharSelected = 4;
		}
		if (defaultChar.currentCharSelected == 1)
		{
			xingqiu.use_E_skill = false;
			run(venti.runFrame, venti.currentCharFrame, app.pen, e, venti.currentCharPos, venti.speed, defaultChar.currentCharPosition, defaultChar.currentCharDirection);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				anemoAttack(venti, "N", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				anemoAttack(venti, "E", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				anemoAttack(venti, "Q", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
		}
		if (defaultChar.currentCharSelected == 2)
		{
			xingqiu.use_E_skill = false;
			run(raiden.runFrame, raiden.currentCharFrame, app.pen, e, raiden.currentCharPos, raiden.speed, defaultChar.currentCharPosition, defaultChar.currentCharDirection);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				electroAttack(raiden, "N", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				electroAttack(raiden, "E", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				electroAttack(raiden, "Q", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
		}
		if (defaultChar.currentCharSelected == 3)
		{
			run(xingqiu.runFrame, xingqiu.currentCharFrame, app.pen, e, xingqiu.currentCharPos, xingqiu.speed, defaultChar.currentCharPosition, defaultChar.currentCharDirection);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				hydroAttack(xingqiu, "N", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				xingqiu.use_E_skill = true;
				hydroAttack(xingqiu, "E", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				hydroAttack(xingqiu, "Q", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
		}
		if (defaultChar.currentCharSelected == 4)
		{
			xingqiu.use_E_skill = false;
			run(bennet.runFrame, bennet.currentCharFrame, app.pen, e, bennet.currentCharPos, bennet.speed, defaultChar.currentCharPosition, defaultChar.currentCharDirection);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				pyroAttack(bennet, "N", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				pyroAttack(bennet, "E", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				pyroAttack(bennet, "Q", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
			}
		}

		anemoAttack(venti, "", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
		electroAttack(raiden, "", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
		hydroAttack(xingqiu, "", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);
		pyroAttack(bennet, "", app.pen, app.mouseCoordinate, defaultChar.currentCharDirection, defaulMons);


		if (cooldown(time, 5000) == true)
		{
			randomMonster(defaulMons);
		}
		if (defaulMons.allMonster.size() != 0)
		{
			chase(defaulMons, defaultChar, app.pen, dinosaur);
		}

		SDL_RenderPresent(app.pen);
	}
	return 0;
}
