#pragma once
#ifndef game_h_
#define game_h_

#include "bullet.h"
#include "map.h"
#include "characters.h"
#include "monsters.h"
#include "font.h"
#include "sound.h"

double calculateAlpha(SDL_Point p1, SDL_Point p2, int flip);
bool cooldown(int& previousTime, int delayFrameTime);
bool checkCollision(SDL_Rect a, SDL_Rect b);
bool checkOutOfScreen(SDL_Rect& pos);
bool checkPointInRect(SDL_Point p, SDL_Rect rec);
SDL_Rect randomPositionOnScreen(int sizeW, int sizeH);
string milisecondsToMinutes(int milisecond);

void character_PushBullet(AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Event& e, SDL_Point dot);
void character_Fire(AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Renderer* render);
void character_UpdateHP(AllCharacters& characters, SDL_Renderer* render);
void character_Run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e);
void character_Die(AllCharacters& characters, SDL_Renderer* render);

void map_Display(MapGame& maps, AllCharacters& characters, SDL_Renderer* render);
void map_RandomItem(MapGame& maps, SDL_Renderer* render);
void map_ClearMap(MapGame& maps, AllMonsters& monsters, BulletOnScreen& bulletOnScreen);

void monster_Random(AllMonsters& monsters, int type);
void monster_Chase(AllMonsters& monsters, AllCharacters& characters, SDL_Renderer* render);
void monster_BeAttacked(BulletOnScreen& bulletOnScreen, AllMonsters& monsters);
void monster_Attack(AllMonsters& monsters, AllCharacters& characters, BulletOnScreen& bulletOnScreen, SDL_Renderer* render);
void monster_Die(AllMonsters& monsters, SDL_Renderer* render, vector <int>& scoreOfMonster, int& currentScore);
void monster_UpdateHP(AllMonsters& monsters, SDL_Renderer* render);

void boss_Stand(Boss& boss, SDL_Renderer* render);
void boss_Attack(Boss& boss, SDL_Renderer* render);
void boss_Die(Boss& boss, SDL_Renderer* render);
void boss_pushRock(BulletOnScreen& bulletOnScreen, Boss& boss, AllCharacters& characters, int type);
void boss_RandomSkeleton(AllMonsters& monsters, Boss& boss);
void boss_Fire(BulletOnScreen& bulletOnScreen, Boss& boss, SDL_Renderer* render);
void boss_UpdateHP(Boss& boss, SDL_Renderer* render);
void boss_BeAttack(Boss& boss, BulletOnScreen& bulletOnScreen, SDL_Renderer* render);
void boss_InflicDamage(AllCharacters& characters, BulletOnScreen& bulletOnScreen, Boss& boss);

#endif game_h_