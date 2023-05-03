#pragma once
#ifndef menu_h_
#define menu_h_

#include "game.h"
#include "payment.h"
#include "help.h"
#include "playing.h"
#include "summary.h"

class Menu
{
public:
	PaymentWindow paymentWindow;
	HelpWindow helpWindow;
	Playing playingWindow;
	Summary summaryWindow;
	stack <int> appState;
	vector <vector <SDL_Texture*>> menuFrame;
	vector <SDL_Rect> menuPosition;
	int mapNumber;
	Menu(SDL_Renderer* render, Font& font);
	void handleStartScreen(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font);
	void handleLayoutScreen(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font, AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen);
	void handleMenuSetting(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font, AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen);
	void handleHelpWindow(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font);
	void handlePaymentWindow(SDL_Event& e, SDL_Point& p, SDL_Renderer* render, Font& font);
	void handleSummaryWindow(SDL_Renderer* render, Font& font, SDL_Event& e, SDL_Point& p, MapGame& maps, AllCharacters& characters, AllMonsters& monsters, BulletOnScreen& bulletOnScreen);
	void handlePlayingMap1(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render);
	void handlePlayingMap2(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render);
	void handlePlayingMapBoss(AllCharacters& characters, AllMonsters& monsters, Boss& boss, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Event& e, SDL_Point& p, SDL_Renderer* render);
	void resetData(AllCharacters& characters, AllMonsters& monsters, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, SDL_Renderer* render);
	void run(AllCharacters& characters, AllMonsters& monsters, Boss& boss, MapGame& maps, BulletOnScreen& bulletOnScreen, Font& font, App& app);
};

#endif menu_h_