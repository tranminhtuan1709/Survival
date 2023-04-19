#include "menu.h"
#include "enum.h"

Menu::Menu(SDL_Renderer* render)
{
	for (int i = 0; i < MENU_ALL; i++)
	{
		mousePos.push_back(false);
		click.push_back(false);
		state.push_back(false);
		position.push_back({ 0, 0, 0, 0 });
	}
	gameover = IMG_LoadTexture(render, "Image/gameover.png");
	state[MENU_WELCOMSCREEN] = true;
	state[MENU_CLICKTOPLAY_WORD] = true;
	state[MENU_START_BUTTON] = true;
	position[MENU_PAUSE_BUTTON] = { MENU_PAUSE_BUTTON_X, MENU_PAUSE_BUTTON_Y, MENU_PAUSE_BUTTON_WIDTH, MENU_PAUSE_BUTTON_HEIGHT };
	position[MENU_RESUME_BUTTON] = { MENU_RESUME_BUTTON_X, MENU_RESUME_BUTTON_Y, MENU_RESUME_BUTTON_WIDTH, MENU_RESUME_BUTTON_HEIGHT };
	position[MENU_HELP_BUTTON] = { MENU_HELP_BUTTON_X, MENU_HELP_BUTTON_Y, MENU_HELP_BUTTON_WIDTH, MENU_HELP_BUTTON_HEIGHT };
	position[MENU_REPLAY_BUTTON] = { MENU_REPLAY_BUTTON_X, MENU_REPLAY_BUTTON_Y, MENU_REPLAY_BUTTON_WIDTH, MENU_REPLAY_BUTTON_HEIGHT };
	position[MENU_SETTING_BUTTON] = { MENU_SETTING_BUTTON_X, MENU_SETTING_BUTTON_Y, MENU_SETTING_BUTTON_WIDTH, MENU_SETTING_BUTTON_HEIGHT };
	position[MENU_MENU_WORD] = { MENU_MENU_WORD_X, MENU_MENU_WORD_Y, MENU_MENU_WORD_WIDTH, MENU_MENU_WORD_HEIGHT };
	position[MENU_QUIT_WINDOW_BUTTON] = { MENU_QUIT_WINDOW_BUTTON_X, MENU_QUIT_WINDOW_BUTTON_Y, MENU_QUIT_WINDOW_BUTTON_WIDTH, MENU_QUIT_WINDOW_BUTTON_HEIGHT };
	position[MENU_WINDOW] = { MENU_WINDOW_X, MENU_WINDOW_Y, MENU_WINDOW_WIDTH, MENU_WINDOW_HEIGHT };
	position[MENU_WELCOMSCREEN] = { MENU_WELCOMSCREEN_X, MENU_WELCOMSCREEN_Y, MENU_WELCOMSCREEN_WIDTH, MENU_WELCOMSCREEN_HEIGHT };
	position[MENU_START_BUTTON] = { MENU_START_BUTTON_X, MENU_START_BUTTON_Y, MENU_START_BUTTON_WIDTH, MENU_START_BUTTON_HEIGHT };
	position[MENU_CLICKTOPLAY_WORD] = { MENU_CLICKTOPLAY_WORD_X, MENU_CLICKTOPLAY_WORD_Y, MENU_CLICKTOPLAY_WORD_WIDTH, MENU_CLICKTOPLAY_WORD_HEIGHT };
	position[MENU_MAP_WORD] = { MENU_MAP_WORD_X, MENU_MAP_WORD_Y, MENU_MAP_WORD_WIDTH, MENU_MAP_WORD_HEIGHT };
	position[MENU_MAP_IMAGE] = { MENU_MAP_IMAGE_X, MENU_MAP_IMAGE_Y, MENU_MAP_IMAGE_WIDTH, MENU_MAP_IMAGE_HEIGHT };
	position[MENU_ARROW_LEFT] = { MENU_ARROW_LEFT_X, MENU_ARROW_LEFT_Y, MENU_ARROW_LEFT_WIDTH, MENU_ARROW_LEFT_HEIGHT };
	position[MENU_ARROW_RIGHT] = { MENU_ARROW_RIGHT_X, MENU_ARROW_RIGHT_Y, MENU_ARROW_RIGHT_WIDTH, MENU_ARROW_RIGHT_HEIGHT };
	position[MENU_NUMBER_MAP_WORD] = { MENU_NUMBER_MAP_WORD_X, MENU_NUMBER_MAP_WORD_Y, MENU_NUMBER_MAP_WORD_WIDTH, MENU_NUMBER_MAP_WORD_HEIGHT };
	vector <SDL_Texture*> temp;
	for (int i = 0; i < MENU_ALL; i++) frame.push_back(temp);
	loadImage(frame[MENU_PAUSE_BUTTON], "Image/Menu/pause.png", 2, render);
	loadImage(frame[MENU_RESUME_BUTTON], "Image/Menu/resume.png", 2, render);
	loadImage(frame[MENU_HELP_BUTTON], "Image/Menu/help.png", 2, render);
	loadImage(frame[MENU_REPLAY_BUTTON], "Image/Menu/replay.png", 2, render);
	loadImage(frame[MENU_SETTING_BUTTON], "Image/Menu/setting.png", 2, render);
	loadImage(frame[MENU_MENU_WORD], "Image/Menu/menuword.png", 2, render);
	loadImage(frame[MENU_QUIT_WINDOW_BUTTON], "Image/Menu/quitwindow.png", 2, render);
	loadImage(frame[MENU_WINDOW], "Image/Menu/window.png", 2, render);
	loadImage(frame[MENU_WELCOMSCREEN], "Image/Menu/welcomscreen.png", 2, render);
	loadImage(frame[MENU_START_BUTTON], "Image/Menu/start.png", 2, render);
	loadImage(frame[MENU_CLICKTOPLAY_WORD], "Image/Menu/clicktoplayword.png", 2, render);
	loadImage(frame[MENU_MAP_WORD], "Image/Menu/mapword.png", 2, render);
	loadImage(frame[MENU_MAP_IMAGE], "Image/Menu/mapimage.png", 2, render);
	loadImage(frame[MENU_ARROW_LEFT], "Image/Menu/arrowleft.png", 2, render);
	loadImage(frame[MENU_ARROW_RIGHT], "Image/Menu/arrowright.png", 2, render);
	loadImage(frame[MENU_NUMBER_MAP_WORD], "Image/Menu/numbermapword.png", 2, render);
}

void Menu::checkMousePos(SDL_Point& p)
{
	for (int i = 0; i < MENU_ALL; i++)
	{
		if (checkPointInRect(p, position[i]) == true)
		{
			mousePos[i] = true;
		}
		else
		{
			mousePos[i] = false;
		}
	}
}

void Menu::checkClick(SDL_Event& e)
{
	for (int i = 0; i < MENU_ALL; i++)
	{
		if (mousePos[i] == true && e.type == SDL_MOUSEBUTTONDOWN)
		{
			click[i] = true;
		}
		else
		{
			click[i] = false;
		}
	}
}

void Menu::updateMenuStatus()
{
	for (int i = 0; i < MENU_ALL; i++)
	{
		if (click[i] == true)
		{
			state[i] = true;
		}
	}
}

void Menu::display(SDL_Renderer* render)
{
	for (int i = 0; i < MENU_ALL; i++)
	{
		if (state[i] == true)
		{
			if (mousePos[i] == true)
			{
				SDL_RenderCopy(render, frame[i][0], NULL, &position[i]);
			}
			else
			{
				SDL_RenderCopy(render, frame[i][1], NULL, &position[i]);
			}
		}
	}
}

void Menu::play(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, App& app)
{
	SDL_Event e{};
	bool quit = false;
	while (quit == false)
	{
		if (e.type == SDL_QUIT) quit = true;
		SDL_Delay(15);
		SDL_GetMouseState(&app.mouseCoordinate.x, &app.mouseCoordinate.y);
		SDL_RenderClear(app.pen);
		SDL_PollEvent(&e);
		if (pause(characters, monsters, maps, app.pen) == false)
		{
			if (e.key.keysym.sym == SDLK_F1) maps.currentMap = MAP_1;
			if (e.key.keysym.sym == SDLK_F2) maps.currentMap = MAP_2;
			map_RandomItem(maps, app.pen);
			map_Display(maps, characters, app.pen);
			character_Run(characters, app.pen, e);
			character_UpdateHP(characters, app.pen);
			character_Die(characters, app.pen);
			character_PushBullet(characters, bulletOnScreen, e, app.mouseCoordinate);
			character_Fire(characters, bulletOnScreen, app.pen);
			srand((int)time(0));
			monster_Random(monsters, (rand() + (int)SDL_GetTicks()) % ALLMONSTER);
			map_ClearMap(maps, monsters, bulletOnScreen);
			monster_UpdateHP(monsters, app.pen);
			monster_Die(monsters, app.pen);
			monster_Chase(monsters, characters, app.pen);
			monster_Attack(monsters, characters, bulletOnScreen, app.pen);
			monster_BeAttacked(bulletOnScreen, monsters);
		}
		else
		{
			SDL_RenderCopy(app.pen, gameover, NULL, NULL);
		}
		SDL_RenderPresent(app.pen);
	}
}

bool Menu::pause(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, SDL_Renderer* render)
{
	for (int i = 0; i < ALLCHARACTER; i++)
	{
		if (characters.listOfChar[i].isAlive == true)
		{
			return false;
		}
	}
	return true;
}