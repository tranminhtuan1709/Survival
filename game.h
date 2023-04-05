#pragma once
#ifndef game_h_
#define game_h_

#include "characters.h"

void calculateAlpha(bullet& bull, SDL_Point p1, SDL_Point p2, SDL_RendererFlip flip);
bool cooldown(int& previousTime, int delayFrameTime);
bool checkCollision(SDL_Rect a, SDL_Rect b);
void run(AllCharacters& characters, SDL_Renderer* render, SDL_Event& e);
void anemoAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void electroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void hydroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);
void pyroAttack(AllCharacters& characters, SDL_Renderer* render, SDL_Point dot, SDL_Event& e);

#endif game_h_