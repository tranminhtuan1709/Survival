#include "initGame.h"
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
	AllCharacters characters(app.pen);
	AllMonsters monsters(app.pen);
	SDL_Event e{};
	bool quit = false;
	while (quit == false)
	{
		SDL_Delay(15);
		SDL_GetMouseState(&app.mouseCoordinate.x, &app.mouseCoordinate.y);
		SDL_RenderClear(app.pen);
		SDL_PollEvent(&e);
		if (e.key.keysym.sym == SDLK_1) characters.selectedChar = 1;
		if (e.key.keysym.sym == SDLK_2) characters.selectedChar = 2;
		if (e.key.keysym.sym == SDLK_3) characters.selectedChar = 3;
		if (e.key.keysym.sym == SDLK_4) characters.selectedChar = 4;
		run(characters, app.pen, e);
		beAttacked(monsters, characters);
		anemoAttack(characters, app.pen, app.mouseCoordinate, e);
		electroAttack(characters, app.pen, app.mouseCoordinate, e);
		hydroAttack(characters, app.pen, app.mouseCoordinate, e);
		pyroAttack(characters, app.pen, app.mouseCoordinate, e);
		srand((int)time(0));
		randomMonster(monsters, (rand() % 3) + 1);
		chase(monsters, characters, app.pen);
		SDL_RenderPresent(app.pen);
	}
	return 0;
}
