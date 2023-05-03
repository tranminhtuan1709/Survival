#include "playing.h"
#include "enum.h"

void Playing::initData(SDL_Renderer* render, Font font)
{
	earnedScore = 0;
	passScore = 1000;
	beginTime = SDL_GetTicks();
	remainingTime = 2000;
	passedTime = 0;
	hpLeft = { 0, 0, 0, 0 };
	for (int i = 0; i < ALLMONSTER; i++)
	{
		monsterScore.push_back(0);
	}
	for (int i = 0; i < 6; i++)
	{
		skillUnlocked.push_back(0);
	}
	vector <SDL_Texture*> tempText;
	for (int i = 0; i < ALLPLAYING; i++)
	{
		playingPosition.push_back({ 0, 0, 0, 0 });
		playingFrame.push_back(tempText);
	}
	monsterScore[MONSTER_1] = 3;
	monsterScore[MONSTER_2] = 1;
	monsterScore[MONSTER_3] = 3;
	monsterScore[MONSTER_4] = 2;
	monsterScore[MONSTER_5] = 4;
	monsterScore[MONSTER_6] = 3;
	monsterScore[MONSTER_7] = 4;
	monsterScore[MONSTER_8] = 0;
	playingPosition[PLAYING_AVATAR1] = { PLAYING_AVATAR1_X, PLAYING_AVATAR1_Y, PLAYING_AVATAR1_WIDTH, PLAYING_AVATAR1_HEIGHT };
	playingPosition[PLAYING_AVATAR2] = { PLAYING_AVATAR2_X, PLAYING_AVATAR2_Y, PLAYING_AVATAR2_WIDTH, PLAYING_AVATAR2_HEIGHT };
	playingPosition[PLAYING_AVATAR3] = { PLAYING_AVATAR3_X, PLAYING_AVATAR3_Y, PLAYING_AVATAR3_WIDTH, PLAYING_AVATAR3_HEIGHT };
	playingPosition[PLAYING_AVATAR4] = { PLAYING_AVATAR4_X, PLAYING_AVATAR4_Y, PLAYING_AVATAR4_WIDTH, PLAYING_AVATAR4_HEIGHT };
	playingPosition[PLAYING_TOTAL_HP1] = { PLAYING_TOTAL_HP1_X, PLAYING_TOTAL_HP1_Y, PLAYING_TOTAL_HP1_WIDTH, PLAYING_TOTAL_HP1_HEIGHT };
	playingPosition[PLAYING_TOTAL_HP2] = { PLAYING_TOTAL_HP2_X, PLAYING_TOTAL_HP2_Y, PLAYING_TOTAL_HP2_WIDTH, PLAYING_TOTAL_HP2_HEIGHT };
	playingPosition[PLAYING_TOTAL_HP3] = { PLAYING_TOTAL_HP3_X, PLAYING_TOTAL_HP3_Y, PLAYING_TOTAL_HP3_WIDTH, PLAYING_TOTAL_HP3_HEIGHT };
	playingPosition[PLAYING_TOTAL_HP4] = { PLAYING_TOTAL_HP4_X, PLAYING_TOTAL_HP4_Y, PLAYING_TOTAL_HP4_WIDTH, PLAYING_TOTAL_HP4_HEIGHT };
	playingPosition[PLAYING_CURRENT_HP1] = { PLAYING_CURRENT_HP1_X, PLAYING_CURRENT_HP1_Y, PLAYING_CURRENT_HP1_WIDTH, PLAYING_CURRENT_HP1_HEIGHT };
	playingPosition[PLAYING_CURRENT_HP2] = { PLAYING_CURRENT_HP2_X, PLAYING_CURRENT_HP2_Y, PLAYING_CURRENT_HP2_WIDTH, PLAYING_CURRENT_HP2_HEIGHT };
	playingPosition[PLAYING_CURRENT_HP3] = { PLAYING_CURRENT_HP3_X, PLAYING_CURRENT_HP3_Y, PLAYING_CURRENT_HP3_WIDTH, PLAYING_CURRENT_HP3_HEIGHT };
	playingPosition[PLAYING_CURRENT_HP4] = { PLAYING_CURRENT_HP4_X, PLAYING_CURRENT_HP4_Y, PLAYING_CURRENT_HP4_WIDTH, PLAYING_CURRENT_HP4_HEIGHT };
	playingPosition[PLAYING_SCORE] = { PLAYING_SCORE_X, PLAYING_SCORE_Y, PLAYING_SCORE_WIDTH, PLAYING_SCORE_HEIGHT };
	playingPosition[PLAYING_TIME] = { PLAYING_TIME_X, PLAYING_TIME_Y, PLAYING_TIME_WIDTH, PLAYING_TIME_HEIGHT };
	loadImage(playingFrame[PLAYING_AVATAR1], "Image/Menu/Playing/ava1_", 2, render);
	loadImage(playingFrame[PLAYING_AVATAR2], "Image/Menu/Playing/ava2_", 2, render);
	loadImage(playingFrame[PLAYING_AVATAR3], "Image/Menu/Playing/ava3_", 2, render);
	loadImage(playingFrame[PLAYING_AVATAR4], "Image/Menu/Playing/ava4_", 2, render);
	loadImage(playingFrame[PLAYING_TOTAL_HP1], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_TOTAL_HP2], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_TOTAL_HP3], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_TOTAL_HP4], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_CURRENT_HP1], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_CURRENT_HP2], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_CURRENT_HP3], "Image/hp", 2, render);
	loadImage(playingFrame[PLAYING_CURRENT_HP4], "Image/hp", 2, render);
	playingFrame[PLAYING_SCORE].push_back(createTextureFromFont(font.zag, "Score : 10 / 1000", font.allColor[COLOR_WHITE], render));
	playingFrame[PLAYING_TIME].push_back(createTextureFromFont(font.zag, "Time remaining  01:30", font.allColor[COLOR_WHITE], render));
}