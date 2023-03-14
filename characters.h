#ifndef characters_h_
#define characters_h_

#include "initGame.h"

class bullet
{
public:
	string type;
	SDL_Rect currentBulletPos;
	int currentBulletFrame;
	int previousTime;
	int step;
	int existTime;
	int startTime;
	double a;
	double b;
	SDL_RendererFlip flip;
	bullet(string s, SDL_Rect pos, int f, int previous, int st);
};

class anemoChar
{
public:
	int hp;
	int atk;
	int def;
	int speed;

	int currentCharFrame;
	SDL_Rect currentCharPos;

	vector <bullet> bulletOnScreen;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;

	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	anemoChar(int x, int y, SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class electroChar
{
public:
	int hp;
	int atk;
	int def;
	int speed;

	int currentCharFrame;
	SDL_Rect currentCharPos;

	vector <bullet> bulletOnScreen;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;

	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	electroChar(int x, int y, SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class hydroChar
{
public:
	int hp;
	int atk;
	int def;
	int speed;
	bool use_E_skill = false;

	int currentCharFrame;
	SDL_Rect currentCharPos;

	vector <bullet> bulletOnScreen;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;

	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	hydroChar(int x, int y, SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class pyroChar
{
public:
	int hp;
	int atk;
	int def;
	int speed;

	int currentCharFrame;
	SDL_Rect currentCharPos;

	vector <bullet> bulletOnScreen;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;

	vector <SDL_Texture*> hpFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	pyroChar(int x, int y, SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

#endif characters_h_