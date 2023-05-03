#include "menu.h"
#include "enum.h"

Menu::Menu(SDL_Renderer* render, Font& font)
{
	paymentWindow.initData(render, font);
	helpWindow.initData(render, font);
	playingWindow.initData(render, font);
	summaryWindow.initData(render, font);
	appState.push(STATE_START);
	vector <SDL_Texture*> tempText;
	for (int i = 0; i < ALLMENU; i++)
	{
		menuFrame.push_back(tempText);
		menuPosition.push_back({ 0, 0, 0, 0 });
	}
	menuPosition[MENU_SETTING_BUTTON] = { MENU_SETTING_BUTTON_X, MENU_SETTING_BUTTON_Y, MENU_SETTING_BUTTON_WIDTH, MENU_SETTING_BUTTON_HEIGHT };
	menuPosition[MENU_RESUME_BUTTON] = { MENU_RESUME_BUTTON_X, MENU_RESUME_BUTTON_Y, MENU_RESUME_BUTTON_WIDTH, MENU_RESUME_BUTTON_HEIGHT };
	menuPosition[MENU_HELP_BUTTON] = { MENU_HELP_BUTTON_X, MENU_HELP_BUTTON_Y, MENU_HELP_BUTTON_WIDTH, MENU_HELP_BUTTON_HEIGHT };
	menuPosition[MENU_REPLAY_BUTTON] = { MENU_REPLAY_BUTTON_X, MENU_REPLAY_BUTTON_Y, MENU_REPLAY_BUTTON_WIDTH, MENU_REPLAY_BUTTON_HEIGHT };
	menuPosition[MENU_MUSIC_BUTTON] = { MENU_MUSIC_BUTTON_X, MENU_MUSIC_BUTTON_Y, MENU_MUSIC_BUTTON_WIDTH, MENU_MUSIC_BUTTON_HEIGHT };
	menuPosition[MENU_HOME_BUTTON] = { MENU_HOME_BUTTON_X, MENU_HOME_BUTTON_Y, MENU_HOME_BUTTON_WIDTH, MENU_HOME_BUTTON_HEIGHT };
	menuPosition[MENU_PAY_BUTTON] = { MENU_PAY_BUTTON_X, MENU_PAY_BUTTON_Y, MENU_PAY_BUTTON_WIDTH, MENU_PAY_BUTTON_HEIGHT };
	menuPosition[MENU_MENU_WORD] = { MENU_MENU_WORD_X, MENU_MENU_WORD_Y, MENU_MENU_WORD_WIDTH, MENU_MENU_WORD_HEIGHT };
	menuPosition[MENU_QUIT_WINDOW_BUTTON] = { MENU_QUIT_WINDOW_BUTTON_X, MENU_QUIT_WINDOW_BUTTON_Y, MENU_QUIT_WINDOW_BUTTON_WIDTH, MENU_QUIT_WINDOW_BUTTON_HEIGHT };
	menuPosition[MENU_WINDOW] = { MENU_WINDOW_X, MENU_WINDOW_Y, MENU_WINDOW_WIDTH, MENU_WINDOW_HEIGHT };
	menuPosition[MENU_WELCOMSCREEN] = { MENU_WELCOMSCREEN_X, MENU_WELCOMSCREEN_Y, MENU_WELCOMSCREEN_WIDTH, MENU_WELCOMSCREEN_HEIGHT };
	menuPosition[MENU_SURVIVOR] = { MENU_SURVIVOR_X, MENU_SURVIVOR_Y, MENU_SURVIVOR_WIDTH, MENU_SURVIVOR_HEIGHT };
	menuPosition[MENU_START_BUTTON] = { MENU_START_BUTTON_X, MENU_START_BUTTON_Y, MENU_START_BUTTON_WIDTH, MENU_START_BUTTON_HEIGHT };
	menuPosition[MENU_CLICKTOPLAY_WORD] = { MENU_CLICKTOPLAY_WORD_X, MENU_CLICKTOPLAY_WORD_Y, MENU_CLICKTOPLAY_WORD_WIDTH, MENU_CLICKTOPLAY_WORD_HEIGHT };
	menuPosition[MENU_MAP_WORD] = { MENU_MAP_WORD_X, MENU_MAP_WORD_Y, MENU_MAP_WORD_WIDTH, MENU_MAP_WORD_HEIGHT };
	menuPosition[MENU_MAP_IMAGE] = { MENU_MAP_IMAGE_X, MENU_MAP_IMAGE_Y, MENU_MAP_IMAGE_WIDTH, MENU_MAP_IMAGE_HEIGHT };
	menuPosition[MENU_NUMBER_MAP_WORD] = { MENU_NUMBER_MAP_WORD_X, MENU_NUMBER_MAP_WORD_Y, MENU_NUMBER_MAP_WORD_WIDTH, MENU_NUMBER_MAP_WORD_HEIGHT };
	menuPosition[MENU_ARROW_LEFT] = { MENU_ARROW_LEFT_X, MENU_ARROW_LEFT_Y, MENU_ARROW_LEFT_WIDTH, MENU_ARROW_LEFT_HEIGHT };
	menuPosition[MENU_ARROW_RIGHT] = { MENU_ARROW_RIGHT_X, MENU_ARROW_RIGHT_Y, MENU_ARROW_RIGHT_WIDTH, MENU_ARROW_RIGHT_HEIGHT };
	menuPosition[MENU_PLAY_BUTTON] = { MENU_PLAY_BUTTON_X, MENU_PLAY_BUTTON_Y, MENU_PLAY_BUTTON_WIDTH, MENU_PLAY_BUTTON_HEIGHT };
	menuPosition[MENU_NEXT_BUTTON] = { MENU_NEXT_BUTTON_X, MENU_NEXT_BUTTON_Y, MENU_NEXT_BUTTON_WIDTH, MENU_NEXT_BUTTON_HEIGHT };
	menuPosition[MENU_BACK_BUTTON] = { MENU_BACK_BUTTON_X, MENU_BACK_BUTTON_Y, MENU_BACK_BUTTON_WIDTH, MENU_BACK_BUTTON_HEIGHT };
	loadImage(menuFrame[MENU_SETTING_BUTTON], "Image/Menu/setting", 2, render);
	loadImage(menuFrame[MENU_RESUME_BUTTON], "Image/Menu/resume", 2, render);
	loadImage(menuFrame[MENU_HELP_BUTTON], "Image/Menu/help", 2, render);
	loadImage(menuFrame[MENU_REPLAY_BUTTON], "Image/Menu/replay", 2, render);
	loadImage(menuFrame[MENU_MUSIC_BUTTON], "Image/Menu/music", 3, render);
	loadImage(menuFrame[MENU_HOME_BUTTON], "Image/Menu/home", 2, render);
	loadImage(menuFrame[MENU_PAY_BUTTON], "Image/Menu/payment", 2, render);
	menuFrame[MENU_MENU_WORD].push_back(font.text[FONT_MENU]);
	loadImage(menuFrame[MENU_QUIT_WINDOW_BUTTON], "Image/Menu/quit", 2, render);
	loadImage(menuFrame[MENU_WINDOW], "Image/Menu/window", 1, render);
	loadImage(menuFrame[MENU_WELCOMSCREEN], "Image/Menu/welcomscreen", 1, render);
	loadImage(menuFrame[MENU_SURVIVOR], "Image/Menu/survivor", 1, render);
	loadImage(menuFrame[MENU_START_BUTTON], "Image/Menu/startbutton", 2, render);
	menuFrame[MENU_CLICKTOPLAY_WORD].push_back(font.text[FONT_CLIKTOPLAY]);
	menuFrame[MENU_MAP_WORD].push_back(font.text[FONT_MAP]);
	loadImage(menuFrame[MENU_MAP_IMAGE], "Image/Menu/mapimage", 3, render);
	menuFrame[MENU_NUMBER_MAP_WORD].push_back(font.text[FONT_MAP1]);
	menuFrame[MENU_NUMBER_MAP_WORD].push_back(font.text[FONT_MAP2]);
	menuFrame[MENU_NUMBER_MAP_WORD].push_back(font.text[FONT_MAPBOSS]);
	loadImage(menuFrame[MENU_ARROW_LEFT], "Image/Menu/arrowleft", 2, render);
	loadImage(menuFrame[MENU_ARROW_RIGHT], "Image/Menu/arrowright", 2, render);
	loadImage(menuFrame[MENU_PLAY_BUTTON], "Image/Menu/play", 2, render);
	loadImage(menuFrame[MENU_NEXT_BUTTON], "Image/Menu/next", 2, render);
	loadImage(menuFrame[MENU_BACK_BUTTON], "Image/Menu/back", 2, render);
	mapNumber = 1;
}

void Menu::handleStartScreen(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font)
{
	if (appState.top() != STATE_START) return;
	SDL_RenderCopy(render, menuFrame[MENU_WELCOMSCREEN][0], NULL, &menuPosition[MENU_WELCOMSCREEN]);
	SDL_RenderCopy(render, menuFrame[MENU_SURVIVOR][0], NULL, &menuPosition[MENU_SURVIVOR]);
	SDL_RenderCopy(render, menuFrame[MENU_CLICKTOPLAY_WORD][0], NULL, &menuPosition[MENU_CLICKTOPLAY_WORD]);
	SDL_RenderCopy(render, menuFrame[MENU_START_BUTTON][0], NULL, &menuPosition[MENU_START_BUTTON]);
	if (checkPointInRect(p, menuPosition[MENU_START_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_START_BUTTON][1], NULL, &menuPosition[MENU_START_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.push(STATE_LAYOUT);
		}
	}
}

void Menu::handleLayoutScreen(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font, AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen)
{
	if (appState.top() != STATE_LAYOUT) return;
	if (e.key.keysym.sym == SDLK_m)
	{
		appState.push(STATE_SETTING);
		return;
	}
	SDL_RenderCopy(render, menuFrame[MENU_MAP_WORD][0], NULL, &menuPosition[MENU_MAP_WORD]);
	SDL_RenderCopy(render, menuFrame[MENU_PLAY_BUTTON][0], NULL, &menuPosition[MENU_PLAY_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_SETTING_BUTTON][0], NULL, &menuPosition[MENU_SETTING_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_ARROW_LEFT][0], NULL, &menuPosition[MENU_ARROW_LEFT]);
	SDL_RenderCopy(render, menuFrame[MENU_ARROW_RIGHT][0], NULL, &menuPosition[MENU_ARROW_RIGHT]);
	SDL_Rect temp = { 20, 720, 100, 50 };
	SDL_RenderCopy(render, menuFrame[MENU_BACK_BUTTON][0], NULL, &temp);
	if (checkPointInRect(p, menuPosition[MENU_SETTING_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_SETTING_BUTTON][1], NULL, &menuPosition[MENU_SETTING_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.push(STATE_SETTING);
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_PLAY_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_PLAY_BUTTON][1], NULL, &menuPosition[MENU_PLAY_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
			appState.push(STATE_MAP1);
		}
	}
	if (checkPointInRect(p, temp) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_BACK_BUTTON][1], NULL, &temp);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			return;
		}
	}
	if (mapNumber == 1)
	{
		SDL_RenderCopy(render, menuFrame[MENU_MAP_IMAGE][0], NULL, &menuPosition[MENU_MAP_IMAGE]);
		SDL_RenderCopy(render, menuFrame[MENU_NUMBER_MAP_WORD][0], NULL, &menuPosition[MENU_NUMBER_MAP_WORD]);
		if (checkPointInRect(p, menuPosition[MENU_ARROW_RIGHT]) == true)
		{
			SDL_RenderCopy(render, menuFrame[MENU_ARROW_RIGHT][1], NULL, &menuPosition[MENU_ARROW_RIGHT]);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				mapNumber = 2;
			}
		}
	}
	else if (mapNumber == 2)
	{
		SDL_RenderCopy(render, menuFrame[MENU_MAP_IMAGE][1], NULL, &menuPosition[MENU_MAP_IMAGE]);
		SDL_RenderCopy(render, menuFrame[MENU_NUMBER_MAP_WORD][1], NULL, &menuPosition[MENU_NUMBER_MAP_WORD]);
		if (checkPointInRect(p, menuPosition[MENU_ARROW_LEFT]) == true)
		{
			SDL_RenderCopy(render, menuFrame[MENU_ARROW_LEFT][1], NULL, &menuPosition[MENU_ARROW_LEFT]);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				mapNumber = 1;
			}
		}
		if (checkPointInRect(p, menuPosition[MENU_ARROW_RIGHT]) == true)
		{
			SDL_RenderCopy(render, menuFrame[MENU_ARROW_RIGHT][1], NULL, &menuPosition[MENU_ARROW_RIGHT]);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				mapNumber = 3;
			}
		}
	}
	else if (mapNumber == 3)
	{
		SDL_RenderCopy(render, menuFrame[MENU_MAP_IMAGE][2], NULL, &menuPosition[MENU_MAP_IMAGE]);
		SDL_RenderCopy(render, menuFrame[MENU_NUMBER_MAP_WORD][2], NULL, &menuPosition[MENU_NUMBER_MAP_WORD]);
		if (checkPointInRect(p, menuPosition[MENU_ARROW_LEFT]) == true)
		{
			SDL_RenderCopy(render, menuFrame[MENU_ARROW_LEFT][1], NULL, &menuPosition[MENU_ARROW_LEFT]);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				mapNumber = 2;
			}
		}
	}
}

void Menu::handleMenuSetting(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font, AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen)
{
	if (appState.top() != STATE_SETTING) return;
	if (e.key.keysym.sym == SDLK_ESCAPE)
	{
		appState.pop();
		return;
	}
	SDL_RenderCopy(render, menuFrame[MENU_WINDOW][0], NULL, &menuPosition[MENU_WINDOW]);
	SDL_RenderCopy(render, menuFrame[MENU_RESUME_BUTTON][0], NULL, &menuPosition[MENU_RESUME_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_REPLAY_BUTTON][0], NULL, &menuPosition[MENU_REPLAY_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_HOME_BUTTON][0], NULL, &menuPosition[MENU_HOME_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_MUSIC_BUTTON][0], NULL, &menuPosition[MENU_MUSIC_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_PAY_BUTTON][0], NULL, &menuPosition[MENU_PAY_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_HELP_BUTTON][0], NULL, &menuPosition[MENU_HELP_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_QUIT_WINDOW_BUTTON][0], NULL, &menuPosition[MENU_QUIT_WINDOW_BUTTON]);
	if (checkPointInRect(p, menuPosition[MENU_RESUME_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_RESUME_BUTTON][1], NULL, &menuPosition[MENU_RESUME_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_REPLAY_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_REPLAY_BUTTON][1], NULL, &menuPosition[MENU_REPLAY_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_HOME_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_HOME_BUTTON][1], NULL, &menuPosition[MENU_HOME_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			while (appState.top() != STATE_LAYOUT)
			{
				appState.pop();
			}
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
			maps.currentMap = MAP_1;
			return;
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_MUSIC_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_MUSIC_BUTTON][1], NULL, &menuPosition[MENU_MUSIC_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.push(STATE_MUSIC);
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_PAY_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_PAY_BUTTON][1], NULL, &menuPosition[MENU_PAY_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.push(STATE_PAY);
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_HELP_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_HELP_BUTTON][1], NULL, &menuPosition[MENU_HELP_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.push(STATE_HELP);
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_QUIT_WINDOW_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_QUIT_WINDOW_BUTTON][1], NULL, &menuPosition[MENU_QUIT_WINDOW_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			return;
		}
	}
}

void Menu::handleHelpWindow(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font)
{
	if (appState.top() != STATE_HELP) return;
	SDL_RenderCopy(render, menuFrame[MENU_QUIT_WINDOW_BUTTON][0], NULL, &menuPosition[MENU_SETTING_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_BACK_BUTTON][0], NULL, &menuPosition[MENU_BACK_BUTTON]);
	SDL_RenderCopy(render, menuFrame[MENU_NEXT_BUTTON][0], NULL, &menuPosition[MENU_NEXT_BUTTON]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT1][0], NULL, &helpWindow.helpPosition[HELP_DOT1]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT2][0], NULL, &helpWindow.helpPosition[HELP_DOT2]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT3][0], NULL, &helpWindow.helpPosition[HELP_DOT3]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT4][0], NULL, &helpWindow.helpPosition[HELP_DOT4]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT5][0], NULL, &helpWindow.helpPosition[HELP_DOT5]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT6][0], NULL, &helpWindow.helpPosition[HELP_DOT6]);
	SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT7][0], NULL, &helpWindow.helpPosition[HELP_DOT7]);
	if (helpWindow.pageNumber == 1)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "Rule !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 100, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT1][1], NULL, &helpWindow.helpPosition[HELP_DOT1]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_RULE1][0], NULL, &helpWindow.helpPosition[HELP_RULE1]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (helpWindow.pageNumber == 2)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "Rule !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 100, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT2][1], NULL, &helpWindow.helpPosition[HELP_DOT2]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_RULE2][0], NULL, &helpWindow.helpPosition[HELP_RULE2]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (helpWindow.pageNumber == 3)
	{
		SDL_Texture* text1 = createTextureFromFont(font.villa, "HOW TO PLAY ?", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 200, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT3][1], NULL, &helpWindow.helpPosition[HELP_DOT3]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_HOWTOPLAY][0], NULL, &helpWindow.helpPosition[HELP_HOWTOPLAY]);
		SDL_RenderCopy(render, text1, NULL, &rec);
	}
	if (helpWindow.pageNumber == 4)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "SKILL CHARACTER 1 !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 350, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT4][1], NULL, &helpWindow.helpPosition[HELP_DOT4]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_SKILL_CHAR1][0], NULL, &helpWindow.helpPosition[HELP_SKILL_CHAR1]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (helpWindow.pageNumber == 5)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "SKILL CHARACTER 2 !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 350, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT5][1], NULL, &helpWindow.helpPosition[HELP_DOT5]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_SKILL_CHAR2][0], NULL, &helpWindow.helpPosition[HELP_SKILL_CHAR2]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (helpWindow.pageNumber == 6)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "SKILL CHARACTER 3 !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 350, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT6][1], NULL, &helpWindow.helpPosition[HELP_DOT6]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_SKILL_CHAR3][0], NULL, &helpWindow.helpPosition[HELP_SKILL_CHAR3]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (helpWindow.pageNumber == 7)
	{
		SDL_Texture* text = createTextureFromFont(font.villa, "SKILL CHARACTER 4 !", font.allColor[COLOR_WHITE], render);
		SDL_Rect rec = { 50, 20, 350, 50 };
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_DOT7][1], NULL, &helpWindow.helpPosition[HELP_DOT7]);
		SDL_RenderCopy(render, helpWindow.helpFrame[HELP_SKILL_CHAR4][0], NULL, &helpWindow.helpPosition[HELP_SKILL_CHAR4]);
		SDL_RenderCopy(render, text, NULL, &rec);
	}
	if (checkPointInRect(p, menuPosition[MENU_BACK_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_BACK_BUTTON][1], NULL, &menuPosition[MENU_BACK_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			helpWindow.pageNumber == 1 ? helpWindow.pageNumber = 1 : helpWindow.pageNumber--;
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_NEXT_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_NEXT_BUTTON][1], NULL, &menuPosition[MENU_NEXT_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			helpWindow.pageNumber == 7 ? helpWindow.pageNumber = 7 : helpWindow.pageNumber++;
		}
	}
	if (checkPointInRect(p, menuPosition[MENU_SETTING_BUTTON]) == true)
	{
		SDL_RenderCopy(render, menuFrame[MENU_QUIT_WINDOW_BUTTON][1], NULL, &menuPosition[MENU_SETTING_BUTTON]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			return;
		}
	}
}

void Menu::handlePaymentWindow(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font)
{
	if (appState.top() != STATE_PAY) return;
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_WINDOW][0], NULL, &paymentWindow.paymentPosition[PAY_WINDOW]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_QUITWINDOW][0], NULL, &paymentWindow.paymentPosition[PAY_QUITWINDOW]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_TITLE][0], NULL, &paymentWindow.paymentPosition[PAY_TITLE]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_QR][0], NULL, &paymentWindow.paymentPosition[PAY_QR]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_NAME][0], NULL, &paymentWindow.paymentPosition[PAY_BOX_NAME]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_VALUE][0], NULL, &paymentWindow.paymentPosition[PAY_BOX_VALUE]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_ENTER_NAME][0], NULL, &paymentWindow.paymentPosition[PAY_ENTER_NAME]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_ENTER_VALUE][0], NULL, &paymentWindow.paymentPosition[PAY_ENTER_VALUE]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_CHOOSE_BANK][0], NULL, &paymentWindow.paymentPosition[PAY_CHOOSE_BANK]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_OK][0], NULL, &paymentWindow.paymentPosition[PAY_OK]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_SALE][0], NULL, &paymentWindow.paymentPosition[PAY_SALE]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BIDV][0], NULL, &paymentWindow.paymentPosition[PAY_BIDV]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_MOMO][0], NULL, &paymentWindow.paymentPosition[PAY_MOMO]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_TPBANK][0], NULL, &paymentWindow.paymentPosition[PAY_TPBANK]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_VIETTELPAY][0], NULL, &paymentWindow.paymentPosition[PAY_VIETTELPAY]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_CIRCLE1][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE1]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_CIRCLE2][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE2]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_CIRCLE3][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE3]);
	SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_CIRCLE4][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE4]);
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_QUITWINDOW]) == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_QUITWINDOW][1], NULL, &paymentWindow.paymentPosition[PAY_QUITWINDOW]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			return;
		}
	}
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_BOX_NAME]) == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_NAME][1], NULL, &paymentWindow.paymentPosition[PAY_BOX_NAME]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.checkInputName = true;
		}
	}
	else
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.checkInputName = false;
		}
	}
	if (paymentWindow.checkInputName == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_NAME][1], NULL, &paymentWindow.paymentPosition[PAY_BOX_NAME]);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym != SDLK_BACKSPACE && paymentWindow.fullName.size() <= 40)
		{
			paymentWindow.fullName += char(e.key.keysym.sym);
			paymentWindow.paymentPosition[PAY_NAME_WORD].w += 15;
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && paymentWindow.fullName.size() != 0)
		{
			paymentWindow.fullName.erase(paymentWindow.fullName.size() - 1, 1);
			paymentWindow.paymentPosition[PAY_NAME_WORD].w = max(paymentWindow.paymentPosition[PAY_NAME_WORD].w - 15, 0);
		}
	}
	SDL_RenderCopy(render, createTextureFromFont(font.zag, paymentWindow.fullName, font.allColor[COLOR_BLACK], render), NULL, &paymentWindow.paymentPosition[PAY_NAME_WORD]);
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_BOX_VALUE]) == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_VALUE][1], NULL, &paymentWindow.paymentPosition[PAY_BOX_VALUE]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.checkInputValue = true;
		}
	}
	else
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.checkInputValue = false;
		}
	}
	if (paymentWindow.checkInputValue == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_VALUE][1], NULL, &paymentWindow.paymentPosition[PAY_BOX_VALUE]);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym != SDLK_BACKSPACE && paymentWindow.value.size() <= 40)
		{
			paymentWindow.value += char(e.key.keysym.sym);
			paymentWindow.paymentPosition[PAY_VALUE_WORD].w += 15;
			paymentWindow.checkUpdateThanksSentence = false;
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && paymentWindow.value.size() != 0)
		{
			paymentWindow.value.erase(paymentWindow.value.size() - 1, 1);
			paymentWindow.paymentPosition[PAY_VALUE_WORD].w = max(paymentWindow.paymentPosition[PAY_VALUE_WORD].w - 15, 0);
			paymentWindow.checkUpdateThanksSentence = false;
		}
	}
	SDL_RenderCopy(render, createTextureFromFont(font.zag, paymentWindow.value, font.allColor[COLOR_BLACK], render), NULL, &paymentWindow.paymentPosition[PAY_VALUE_WORD]);
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_BIDV]) == true)
	{
		SDL_Rect temp = { paymentWindow.paymentPosition[PAY_BIDV].x - 10, paymentWindow.paymentPosition[PAY_BIDV].y - 10, paymentWindow.paymentPosition[PAY_BIDV].w + 20, paymentWindow.paymentPosition[PAY_BIDV].h + 20 };
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BIDV][0], NULL, &temp);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.bank = PAY_BIDV;
		}
	}
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_MOMO]) == true)
	{
		SDL_Rect temp = { paymentWindow.paymentPosition[PAY_MOMO].x - 10, paymentWindow.paymentPosition[PAY_MOMO].y - 10, paymentWindow.paymentPosition[PAY_MOMO].w + 20, paymentWindow.paymentPosition[PAY_MOMO].h + 20 };
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_MOMO][0], NULL, &temp);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.bank = PAY_MOMO;
		}
	}
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_TPBANK]) == true)
	{
		SDL_Rect temp = { paymentWindow.paymentPosition[PAY_TPBANK].x - 10, paymentWindow.paymentPosition[PAY_TPBANK].y - 10, paymentWindow.paymentPosition[PAY_TPBANK].w + 20, paymentWindow.paymentPosition[PAY_TPBANK].h + 20 };
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_TPBANK][0], NULL, &temp);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.bank = PAY_TPBANK;
		}
	}
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_VIETTELPAY]) == true)
	{
		SDL_Rect temp = { paymentWindow.paymentPosition[PAY_VIETTELPAY].x - 10, paymentWindow.paymentPosition[PAY_VIETTELPAY].y - 10, paymentWindow.paymentPosition[PAY_VIETTELPAY].w + 20, paymentWindow.paymentPosition[PAY_VIETTELPAY].h + 20 };
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_VIETTELPAY][0], NULL, &temp);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.bank = PAY_VIETTELPAY;
		}
	}

	if (paymentWindow.bank == PAY_BIDV)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_GREENTICK][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE1]);
	}
	if (paymentWindow.bank == PAY_MOMO)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_GREENTICK][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE2]);
	}
	if (paymentWindow.bank == PAY_TPBANK)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_GREENTICK][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE3]);
	}
	if (paymentWindow.bank == PAY_VIETTELPAY)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_GREENTICK][0], NULL, &paymentWindow.paymentPosition[PAY_CIRCLE4]);
	}
	if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_OK]) == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_OK][1], NULL, &paymentWindow.paymentPosition[PAY_OK]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			paymentWindow.checkPay = true;
		}
	}
	if (paymentWindow.checkPay == true)
	{
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_BOX_NAME][0], NULL, &paymentWindow.paymentPosition[PAY_BOX_RESULT]);
		SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_QUITRESULT][0], NULL, &paymentWindow.paymentPosition[PAY_QUITRESULT]);
		if (paymentWindow.checkUpdateThanksSentence == false)
		{
			paymentWindow.thanksSentence = "Thanks you for supporting me \"";
			paymentWindow.thanksSentence += paymentWindow.value;
			while (paymentWindow.thanksSentence.size() > 50)
			{
				paymentWindow.thanksSentence.erase(paymentWindow.thanksSentence.size() - 1, 1);
				paymentWindow.checkOutOfRange = true;
			}
			if (paymentWindow.checkOutOfRange == true)
			{
				paymentWindow.thanksSentence += "...\"";
			}
			else
			{
				paymentWindow.thanksSentence += "\"";
			}
			paymentWindow.paymentPosition[PAY_RESULT_WORD].w = (int)paymentWindow.thanksSentence.size() * 15;
			paymentWindow.checkUpdateThanksSentence = true;
		}
		SDL_RenderCopy(render, createTextureFromFont(font.zag, paymentWindow.thanksSentence, font.allColor[COLOR_BLACK], render), NULL, &paymentWindow.paymentPosition[PAY_RESULT_WORD]);
		if (checkPointInRect(p, paymentWindow.paymentPosition[PAY_QUITRESULT]) == true)
		{
			SDL_RenderCopy(render, paymentWindow.paymentFrame[PAY_QUITRESULT][1], NULL, &paymentWindow.paymentPosition[PAY_QUITRESULT]);
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				paymentWindow.checkPay = false;
				paymentWindow.checkUpdateThanksSentence = true;
			}
		}
	}
}

void Menu::handleSummaryWindow(SDL_Renderer* render, Font& font, SDL_Event& e, SDL_Point& p, MapGame& maps, AllCharacters& characters, AllMonsters& monsters, BulletOnScreen& bulletOnScreen)
{
	if (appState.top() != STATE_SUMMARY) return;
	if (maps.result == "win")
	{
		summaryWindow.summaryFrame[SUMMARY_WIN_LOSE][0] = createTextureFromFont(font.villa, "WIN", font.allColor[COLOR_YEALLOW], render);
	}
	else
	{
		summaryWindow.summaryFrame[SUMMARY_WIN_LOSE][0] = createTextureFromFont(font.villa, "LOSE", font.allColor[COLOR_GRAY], render);
	}
	if (maps.currentMap == MAP_1) summaryWindow.summaryFrame[SUMMARY_SCORE_TIME][0] = createTextureFromFont(font.zag, "Time : " + to_string(playingWindow.passedTime), font.allColor[COLOR_ORANGE], render);
	if (maps.currentMap == MAP_2) summaryWindow.summaryFrame[SUMMARY_SCORE_TIME][0] = createTextureFromFont(font.zag, "Score : " + to_string(playingWindow.earnedScore), font.allColor[COLOR_ORANGE], render);
	for (int i = 0; i < ALLSUMMARY; i++)
	{
		SDL_RenderCopy(render, summaryWindow.summaryFrame[i][0], NULL, &summaryWindow.summaryPosition[i]);
	}
	summaryWindow.summaryPosition[SUMMARY_HPLEFT1].w = (int)(playingWindow.hpLeft[0] * SUMMARY_HPLEFT1_WIDTH / 2000);
	summaryWindow.summaryPosition[SUMMARY_HPLEFT2].w = (int)(playingWindow.hpLeft[1] * SUMMARY_HPLEFT2_WIDTH / 2000);
	summaryWindow.summaryPosition[SUMMARY_HPLEFT3].w = (int)(playingWindow.hpLeft[2] * SUMMARY_HPLEFT3_WIDTH / 2000);
	summaryWindow.summaryPosition[SUMMARY_HPLEFT4].w = (int)(playingWindow.hpLeft[3] * SUMMARY_HPLEFT4_WIDTH / 2000);
	for (int i = SUMMARY_HPLEFT1; i <= SUMMARY_HPLEFT4; i++)
	{
		SDL_RenderCopy(render, summaryWindow.summaryFrame[i][1], NULL, &summaryWindow.summaryPosition[i]);
	}
	if (checkPointInRect(p, summaryWindow.summaryPosition[SUMMARY_REPLAY]) == true)
	{
		SDL_RenderCopy(render, summaryWindow.summaryFrame[SUMMARY_REPLAY][1], NULL, &summaryWindow.summaryPosition[SUMMARY_REPLAY]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			appState.pop();
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
			return;
		}
	}
	if (checkPointInRect(p, summaryWindow.summaryPosition[SUMMARY_HOME]) == true)
	{
		SDL_RenderCopy(render, summaryWindow.summaryFrame[SUMMARY_HOME][1], NULL, &summaryWindow.summaryPosition[SUMMARY_HOME]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			while (appState.top() != STATE_LAYOUT)
			{
				appState.pop();
			}
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
			maps.currentMap = MAP_1;
			return;
		}
	}
	if (checkPointInRect(p, summaryWindow.summaryPosition[SUMMARY_NEXT]) == true)
	{
		SDL_RenderCopy(render, summaryWindow.summaryFrame[SUMMARY_NEXT][1], NULL, &summaryWindow.summaryPosition[SUMMARY_NEXT]);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			resetData(characters, monsters, maps, bulletOnScreen, font, render);
			if (maps.currentMap == MAP_1)
			{
				maps.currentMap = MAP_2;
				appState.push(STATE_MAP2);
			}
			else if (maps.currentMap == MAP_2)
			{
				maps.currentMap = MAP_BOSS;
				appState.push(STATE_MAPBOSS);
			}
		}
	}
}

void Menu::handlePlayingMap1(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render)
{
	if (appState.top() != STATE_MAP1) return;
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m)
	{
		appState.push(STATE_SETTING);
		return;
	}
	if (SDL_GetTicks() - playingWindow.beginTime >= 1000)
	{
		playingWindow.passedTime += 1000;
		playingWindow.remainingTime -= 1000;
		playingWindow.playingFrame[PLAYING_TIME][0] = createTextureFromFont(font.zag, "Time remaining " + milisecondsToMinutes(playingWindow.remainingTime), font.allColor[COLOR_WHITE], render);
		playingWindow.beginTime = SDL_GetTicks();
	}
	map_Display(maps, characters, render);
	SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_TIME][0], NULL, &playingWindow.playingPosition[PLAYING_TIME]);
	playingWindow.hpLeft[0] = characters.listOfChar[CHARACTER_1].stat[CHARACTER_HP];
	playingWindow.hpLeft[1] = characters.listOfChar[CHARACTER_2].stat[CHARACTER_HP];
	playingWindow.hpLeft[2] = characters.listOfChar[CHARACTER_3].stat[CHARACTER_HP];
	playingWindow.hpLeft[3] = characters.listOfChar[CHARACTER_4].stat[CHARACTER_HP];
	playingWindow.playingPosition[PLAYING_CURRENT_HP1].w = (int)(playingWindow.hpLeft[0] * PLAYING_TOTAL_HP1_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP2].w = (int)(playingWindow.hpLeft[1] * PLAYING_TOTAL_HP2_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP3].w = (int)(playingWindow.hpLeft[2] * PLAYING_TOTAL_HP3_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP4].w = (int)(playingWindow.hpLeft[3] * PLAYING_TOTAL_HP4_WIDTH / 2000);
	for (int i = PLAYING_AVATAR1; i <= PLAYING_AVATAR4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][0], NULL, &playingWindow.playingPosition[i]);
	}
	for (int i = PLAYING_TOTAL_HP1; i <= PLAYING_TOTAL_HP4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][0], NULL, &playingWindow.playingPosition[i]);
	}
	for (int i = PLAYING_CURRENT_HP1; i <= PLAYING_CURRENT_HP4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][1], NULL, &playingWindow.playingPosition[i]);
	}
	if (characters.selectedChar == CHARACTER_1) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR1][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR1]);
	if (characters.selectedChar == CHARACTER_2) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR2][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR2]);
	if (characters.selectedChar == CHARACTER_3) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR3][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR3]);
	if (characters.selectedChar == CHARACTER_4) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR4][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR4]);
	map_RandomItem(maps, render);
	map_ClearMap(maps, monsters, bulletOnScreen);
	character_Run(characters, render, e);
	character_PushBullet(characters, bulletOnScreen, e, p);
	character_Fire(characters, bulletOnScreen, render);
	character_UpdateHP(characters, render);
	character_Die(characters, render);
	monster_Random(monsters, (rand() + (int)SDL_GetTicks()) % 4);
	monster_Chase(monsters, characters, render);
	monster_BeAttacked(bulletOnScreen, monsters);
	monster_Attack(monsters, characters, bulletOnScreen, render);
	monster_Die(monsters, render, playingWindow.monsterScore, playingWindow.earnedScore);
	monster_UpdateHP(monsters, render);
	if (characters.allDied == true)
	{
		maps.result = "lose";
		appState.push(STATE_SUMMARY);
		return;
	}
	if (playingWindow.remainingTime <= 0)
	{
		if (characters.allDied == true)
		{
			maps.result = "lose";
		}
		else
		{
			maps.result = "win";
		}
		appState.push(STATE_SUMMARY);
	}
}

void Menu::handlePlayingMap2(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render)
{
	if (appState.top() != STATE_MAP2) return;
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m)
	{
		appState.push(STATE_SETTING);
		return;
	}
	playingWindow.playingFrame[PLAYING_SCORE][0] = createTextureFromFont(font.zag, "Score : " + to_string(playingWindow.earnedScore) + " / 10", font.allColor[COLOR_WHITE], render);
	map_Display(maps, characters, render);
	SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_SCORE][0], NULL, &playingWindow.playingPosition[PLAYING_SCORE]);
	playingWindow.hpLeft[0] = characters.listOfChar[CHARACTER_1].stat[CHARACTER_HP];
	playingWindow.hpLeft[1] = characters.listOfChar[CHARACTER_2].stat[CHARACTER_HP];
	playingWindow.hpLeft[2] = characters.listOfChar[CHARACTER_3].stat[CHARACTER_HP];
	playingWindow.hpLeft[3] = characters.listOfChar[CHARACTER_4].stat[CHARACTER_HP];
	playingWindow.playingPosition[PLAYING_CURRENT_HP1].w = (int)(playingWindow.hpLeft[0] * PLAYING_TOTAL_HP1_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP2].w = (int)(playingWindow.hpLeft[1] * PLAYING_TOTAL_HP2_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP3].w = (int)(playingWindow.hpLeft[2] * PLAYING_TOTAL_HP3_WIDTH / 2000);
	playingWindow.playingPosition[PLAYING_CURRENT_HP4].w = (int)(playingWindow.hpLeft[3] * PLAYING_TOTAL_HP4_WIDTH / 2000);
	for (int i = PLAYING_AVATAR1; i <= PLAYING_AVATAR4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][0], NULL, &playingWindow.playingPosition[i]);
	}
	for (int i = PLAYING_TOTAL_HP1; i <= PLAYING_TOTAL_HP4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][0], NULL, &playingWindow.playingPosition[i]);
	}
	for (int i = PLAYING_CURRENT_HP1; i <= PLAYING_CURRENT_HP4; i++)
	{
		SDL_RenderCopy(render, playingWindow.playingFrame[i][1], NULL, &playingWindow.playingPosition[i]);
	}
	if (characters.selectedChar == CHARACTER_1) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR1][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR1]);
	if (characters.selectedChar == CHARACTER_2) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR2][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR2]);
	if (characters.selectedChar == CHARACTER_3) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR3][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR3]);
	if (characters.selectedChar == CHARACTER_4) SDL_RenderCopy(render, playingWindow.playingFrame[PLAYING_AVATAR4][1], NULL, &playingWindow.playingPosition[PLAYING_AVATAR4]);
	map_RandomItem(maps, render);
	map_ClearMap(maps, monsters, bulletOnScreen);
	character_Run(characters, render, e);
	character_PushBullet(characters, bulletOnScreen, e, p);
	character_Fire(characters, bulletOnScreen, render);
	character_UpdateHP(characters, render);
	character_Die(characters, render);
	monster_Random(monsters, ((rand() + (int)SDL_GetTicks()) % 4) + 4);
	monster_Chase(monsters, characters, render);
	monster_BeAttacked(bulletOnScreen, monsters);
	monster_Attack(monsters, characters, bulletOnScreen, render);
	monster_Die(monsters, render, playingWindow.monsterScore, playingWindow.earnedScore);
	monster_UpdateHP(monsters, render);
	if (characters.allDied == true)
	{
		maps.result = "lose";
		appState.push(STATE_SUMMARY);
		return;
	}
	if (playingWindow.earnedScore >= playingWindow.passScore)
	{
		maps.result = "win";
		appState.push(STATE_SUMMARY);
		return;
	}
}

void Menu::handlePlayingMapBoss(AllCharacters& characters, AllMonsters& monsters, Boss& boss, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render)
{
	if (appState.top() != STATE_MAPBOSS) return;
	boss_Stand(boss, render);
	boss_Die(boss, render);
	boss_Attack(boss, render);
	boss_pushRock(bulletOnScreen, boss, characters, (rand() + (int)SDL_GetTicks()) % 4);
	boss_RandomSkeleton(monsters, boss);
	boss_Fire(bulletOnScreen, boss, render);
	boss_UpdateHP(boss, render);
	boss_BeAttack(boss, bulletOnScreen, render);
	boss_InflicDamage(characters, bulletOnScreen, boss);
	map_RandomItem(maps, render);
	map_ClearMap(maps, monsters, bulletOnScreen);
	character_Run(characters, render, e);
	character_PushBullet(characters, bulletOnScreen, e, p);
	character_Fire(characters, bulletOnScreen, render);
	character_UpdateHP(characters, render);
	character_Die(characters, render);
	monster_Chase(monsters, characters, render);
	monster_BeAttacked(bulletOnScreen, monsters);
	monster_Attack(monsters, characters, bulletOnScreen, render);
	monster_Die(monsters, render, playingWindow.monsterScore, playingWindow.earnedScore);
	monster_UpdateHP(monsters, render);
}

void Menu::resetData(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Renderer* render)
{
	for (int i = CHARACTER_1; i <= CHARACTER_4; i++)
	{
		characters.listOfChar[i].stat[CHARACTER_HP] = 2000;
		characters.listOfChar[i].stat[CHARACTER_ATK] = 100;
		characters.listOfChar[i].stat[CHARACTER_DEF] = 5;
		characters.listOfChar[i].stat[CHARACTER_SPEED] = 10;
		characters.listOfChar[i].delay.previousFrameTime[CHARACTER_RUN] = 0;
		characters.listOfChar[i].delay.previousFrameTime[CHARACTER_DIE] = 0;
		characters.listOfChar[i].delay.previousFrameTime[CHARACTER_ATTACK] = 0;
		characters.listOfChar[i].delay.previousSkillTime[CHARACTER_NORMAL] = 0;
		characters.listOfChar[i].delay.previousSkillTime[CHARACTER_ELEMENTAL] = 0;
		characters.listOfChar[i].delay.previousSkillTime[CHARACTER_ULTI] = 0;
		characters.listOfChar[i].isAlive = true;
	}
	characters.selectedChar = CHARACTER_1;
	characters.currentCharHP = &characters.listOfChar[CHARACTER_1].stat[CHARACTER_HP];
	characters.shield = false;
	characters.allDied = false;
	characters.baseATK = 10;
	characters.baseDEF = 1;
	characters.position = { 100, 100, CHARACTER_WIDTH, CHARACTER_HEIGHT };
	characters.flip = SDL_FLIP_NONE;
	characters.timeWhenDie = 0;
	monsters.previousRandomTime = SDL_GetTicks();
	for (int i = MONSTER_1; i <= MONSTER_8; i++)
	{
		monsters.monsterOnScreen[i].clear();
	}
	for (int i = 0; i < 12; i++)
	{
		bulletOnScreen.bulletCharacter[i].clear();
	}
	bulletOnScreen.bulletMonster.clear();
	maps.previousRandomItemTime = SDL_GetTicks();
	maps.result = "";
	for (int i = 0; i < 3; i++)
	{
		maps.itemOnScreen[i].clear();
	}
	playingWindow.earnedScore = 0;
	playingWindow.passScore = 10;
	playingWindow.beginTime = SDL_GetTicks();
	playingWindow.remainingTime = 2000;
	playingWindow.passedTime = 0;
	playingWindow.playingFrame[PLAYING_TIME][0] = createTextureFromFont(font.zag, "Time remaining " + milisecondsToMinutes(2000), font.allColor[COLOR_WHITE], render);
	for (int i = 0; i < 6; i++)
	{
		playingWindow.skillUnlocked[i] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		playingWindow.hpLeft[i] = 2000;
	}
}

void Menu::run(AllCharacters& characters, AllMonsters& monsters, Boss& boss, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, App& app)
{
	bool quit = false;
	SDL_Event e{};
	while (quit == false)
	{
		if (e.type == SDL_QUIT) quit = true;
		SDL_RenderClear(app.pen);
		SDL_Delay(15);
		SDL_GetMouseState(&app.mouseCoordinate.x, &app.mouseCoordinate.y);
		SDL_PollEvent(&e);
		handleMenuSetting(e, app.mouseCoordinate, app.pen, font, characters, monsters, maps, bulletOnScreen);
		handleStartScreen(e, app.mouseCoordinate, app.pen, font);
		handleLayoutScreen(e, app.mouseCoordinate, app.pen, font, characters, monsters, maps, bulletOnScreen);
		handleHelpWindow(e, app.mouseCoordinate, app.pen, font);
		handlePaymentWindow(e, app.mouseCoordinate, app.pen, font);
		handleSummaryWindow(app.pen, font, e, app.mouseCoordinate, maps, characters, monsters, bulletOnScreen);
		handlePlayingMap1(characters, monsters, maps, bulletOnScreen, font, e, app.mouseCoordinate, app.pen);
		handlePlayingMap2(characters, monsters, maps, bulletOnScreen, font, e, app.mouseCoordinate, app.pen);
		handlePlayingMapBoss(characters, monsters, boss, maps, bulletOnScreen, font, e, app.mouseCoordinate, app.pen);
		SDL_RenderPresent(app.pen);
	}
}