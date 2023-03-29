#pragma once
#ifndef game_h_
#define game_h_

#include "characters.h"

double checkPointOnLine(SDL_Point p, Line l);
void createLine(SDL_Point p1, SDL_Point p2, Line& l);
void createRectFromLine(SDL_Point p1, SDL_Point p2, SDL_Rect& rec);
bool cooldown(int& previousTime, int step);
bool collision_RECTxRECT(SDL_Rect a, SDL_Rect b);
bool collision_RECTxLINE(SDL_Rect rec, SDL_Point p1, SDL_Point p2, Line l);
void run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e);
void anemoAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void electroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void hydroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void pyroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);

#endif game_h_