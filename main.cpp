#include "characters.h"
#include "game.h"

int main(int argc, char* argv[])
{
	Game app;
	if (app.checkInit() == false)
	{
		cout << "Can not open game :(" << endl;
		return 0;
	}
	anemoChar venti(300, 300, app.pen);
	electroChar raiden(300, 300, app.pen);
	hydroChar xingqiu(300, 300, app.pen);
	pyroChar bennet(300, 300, app.pen);

	SDL_Event e{};
	bool quit = false;
	SDL_Rect currentPosition = venti.currentCharPos;
	int select = 1;
	string direct = "right";
	while (quit == false)
	{
		SDL_GetMouseState(&app.mouseCoordinate.x, &app.mouseCoordinate.y);
		SDL_RenderClear(app.pen);
		SDL_PollEvent(&e);
		if (e.key.keysym.sym == SDLK_1)
		{
			select = 1;
		}
		if (e.key.keysym.sym == SDLK_2)
		{
			select = 2;
		}
		if (e.key.keysym.sym == SDLK_3)
		{
			select = 3;
		}
		if (e.key.keysym.sym == SDLK_4)
		{
			select = 4;
		}
		if (select == 1)
		{
			run(venti.runFrame, venti.currentCharFrame, app.pen, e, venti.currentCharPos, venti.speed, currentPosition, direct);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				anemoAttack(venti, "N", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				anemoAttack(venti, "E", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				anemoAttack(venti, "Q", app.pen, app.mouseCoordinate, direct);
			}
		}
		if (select == 2)
		{
			run(raiden.runFrame, raiden.currentCharFrame, app.pen, e, raiden.currentCharPos, raiden.speed, currentPosition, direct);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				electroAttack(raiden, "N", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				electroAttack(raiden, "E", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				electroAttack(raiden, "Q", app.pen, app.mouseCoordinate, direct);
			}
		}
		if (select == 3)
		{
			run(xingqiu.runFrame, xingqiu.currentCharFrame, app.pen, e, xingqiu.currentCharPos, xingqiu.speed, currentPosition, direct);
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_N)
			{
				hydroAttack(xingqiu, "N", app.pen);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				hydroAttack(xingqiu, "E", app.pen);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				hydroAttack(xingqiu, "Q", app.pen);
			}
		}
		if (select == 4)
		{
			run(bennet.runFrame, bennet.currentCharFrame, app.pen, e, bennet.currentCharPos, bennet.speed, currentPosition, direct);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				pyroAttack(bennet, "N", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_E)
			{
				pyroAttack(bennet, "E", app.pen, app.mouseCoordinate, direct);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_Q)
			{
				pyroAttack(bennet, "Q", app.pen, app.mouseCoordinate, direct);
			}
		}
		anemoAttack(venti, "", app.pen, app.mouseCoordinate, direct);
		pyroAttack(bennet, "", app.pen, app.mouseCoordinate, direct);
		electroAttack(raiden, "", app.pen, app.mouseCoordinate, direct);
		hydroAttack(xingqiu, "", app.pen);
		SDL_RenderPresent(app.pen);
	}
	return 0;
}
