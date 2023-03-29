#ifndef characters_h_
#define characters_h_

#include "initGame.h"

class bullet
{
public:
	string type;
	SDL_Rect currentBulletPos;
	SDL_Rect boom;
	int damage;
	int currentBulletFrame;
	int previousFrameTime;
	int step;
	int existTime;
	int startTime;
	bool check;
	double a;
	double b;
	SDL_RendererFlip flip;
	Line bulletLine;
	bullet();
};

class anemoChar
{
public:
	int HP;
	int atk;
	int def;
	int speed;

	int currentHPFrame;
	int currentRunFrame;
	int currentAttackFrame;
	int currentDieFrame;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun;
	int previousFrameTimeDie;
	int previousTimeAttack;

	vector <SDL_Texture*> HPFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	anemoChar();
	void loadData(SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class electroChar
{
public:
	int HP;
	int atk;
	int def;
	int speed;

	int currentHPFrame;
	int currentRunFrame;
	int currentAttackFrame;
	int currentDieFrame;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun;
	int previousFrameTimeDie;
	int previousTimeAttack;

	vector <SDL_Texture*> HPFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	electroChar();
	void loadData(SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class hydroChar
{
public:
	int HP;
	int atk;
	int def;
	int speed;
	bool use_E_skill = false;

	int currentHPFrame;
	int currentRunFrame;
	int currentAttackFrame;
	int currentDieFrame;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun;
	int previousFrameTimeDie;
	int previousTimeAttack;

	vector <SDL_Texture*> HPFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	hydroChar();
	void loadData(SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class pyroChar
{
public:
	int HP;
	int atk;
	int def;
	int speed;

	int currentHPFrame;
	int currentRunFrame;
	int currentAttackFrame;
	int currentDieFrame;

	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun;
	int previousFrameTimeDie;
	int previousTimeAttack;

	vector <SDL_Texture*> HPFrame;
	vector <SDL_Texture*> runFrame;
	vector <SDL_Texture*> attackFrame;
	vector <SDL_Texture*> dieFrame;
	vector <SDL_Texture*> normalFrame;
	vector <SDL_Texture*> elementalFrame;
	vector <SDL_Texture*> ultiFrame;

	pyroChar();
	void loadData(SDL_Renderer* render);
	void updateStat(string type, anemoChar& char1, int& currentHP);
};

class AllCharacters
{
public:
	anemoChar char1;
	electroChar char2;
	hydroChar char3;
	pyroChar char4;

	int selectedChar;
	int* currentCharHP;
	bool shield;
	SDL_Rect currentCharPosition;
	string currentCharDirection;

	vector <bullet> bulletCharacter;

	AllCharacters(SDL_Renderer* render);
};

#endif characters_h_