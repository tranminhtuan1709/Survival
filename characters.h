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
	int previousFrameTime; int delayFrameTime; int currentFrame; bool checkFrame;
	int startTime; int existTime;
	bool checkExist;
	double alpha;
	double d;
	SDL_RendererFlip flip;
	bullet();
};

class anemoChar
{
public:
	bool isAlive;
	int HP;
	int atk;
	int def;
	int speed;
	int currentFrameHP;
	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun; int delayFrameTimeRun; int currentFrameRun; bool checkFrameRun = false;
	int previousFrameTimeDie; int delayFrameTimeDie; int currentFrameDie; bool checkFrameDie = false;
	int previousFrameTimeAttack; int delayFrameTimeAttack; int currentFrameAttack; bool checkFrameAttack = false;
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
	bool isAlive;
	int HP;
	int atk;
	int def;
	int speed;
	int currentFrameHP;
	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun; int delayFrameTimeRun; int currentFrameRun; bool checkFrameRun = false;
	int previousFrameTimeDie; int delayFrameTimeDie; int currentFrameDie; bool checkFrameDie = false;
	int previousFrameTimeAttack; int delayFrameTimeAttack; int currentFrameAttack; bool checkFrameAttack = false;
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
	bool isAlive;
	int HP;
	int atk;
	int def;
	int speed;
	int currentFrameHP;
	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun; int delayFrameTimeRun; int currentFrameRun; bool checkFrameRun = false;
	int previousFrameTimeDie; int delayFrameTimeDie; int currentFrameDie; bool checkFrameDie = false;
	int previousFrameTimeAttack; int delayFrameTimeAttack; int currentFrameAttack; bool checkFrameAttack = false;
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
	bool isAlive;
	int HP;
	int atk;
	int def;
	int speed;
	int currentFrameHP;
	int previousTimeN;
	int previousTimeE;
	int previousTimeQ;
	int previousFrameTimeRun; int delayFrameTimeRun; int currentFrameRun; bool checkFrameRun = false;
	int previousFrameTimeDie; int delayFrameTimeDie; int currentFrameDie; bool checkFrameDie = false;
	int previousFrameTimeAttack; int delayFrameTimeAttack; int currentFrameAttack; bool checkFrameAttack = false;
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
	int baseATK;
	int baseDEF;
	SDL_Rect currentCharPosition;
	SDL_RendererFlip flip;
	string currentCharDirection;
	vector <bullet> bulletCharacter;
	SDL_Texture* allDied;
	AllCharacters(SDL_Renderer* render);
};

void updateHPCharacters(AllCharacters& characters, SDL_Renderer* render);
void characterDie(AllCharacters& characters, SDL_Renderer* render);

#endif characters_h_