#include "summary.h"
#include "enum.h"

void Summary::initData(SDL_Renderer* render, Font& font)
{
	vector <SDL_Texture*> tempText;
	for (int i = 0; i < ALLSUMMARY; i++)
	{
		summaryPosition.push_back({ 0, 0, 0, 0 });
		summaryFrame.push_back(tempText);
	}
	summaryPosition[SUMMARY_WINDOW] = { SUMMARY_WINDOW_X, SUMMARY_WINDOW_Y, SUMMARY_WINDOW_WIDTH, SUMMARY_WINDOW_HEIGHT };
	summaryPosition[SUMMARY_WIN_LOSE] = { SUMMARY_WIN_LOSE_X, SUMMARY_WIN_LOSE_Y, SUMMARY_WIN_LOSE_WIDTH, SUMMARY_WIN_LOSE_HEIGHT };
	summaryPosition[SUMMARY_SCORE_TIME] = { SUMMARY_SCORE_TIME_X, SUMMARY_SCORE_TIME_Y, SUMMARY_SCORE_TIME_WIDTH, SUMMARY_SCORE_TIME_HEIGHT };
	summaryPosition[SUMMARY_CHAR1] = { SUMMARY_CHAR1_X, SUMMARY_CHAR1_Y, SUMMARY_CHAR1_WIDTH, SUMMARY_CHAR1_HEIGHT };
	summaryPosition[SUMMARY_CHAR2] = { SUMMARY_CHAR2_X, SUMMARY_CHAR2_Y, SUMMARY_CHAR2_WIDTH, SUMMARY_CHAR2_HEIGHT };
	summaryPosition[SUMMARY_CHAR3] = { SUMMARY_CHAR3_X, SUMMARY_CHAR3_Y, SUMMARY_CHAR3_WIDTH, SUMMARY_CHAR3_HEIGHT };
	summaryPosition[SUMMARY_CHAR4] = { SUMMARY_CHAR4_X, SUMMARY_CHAR4_Y, SUMMARY_CHAR4_WIDTH, SUMMARY_CHAR4_HEIGHT };
	summaryPosition[SUMMARY_HPLEFT] = { SUMMARY_HPLEFT_X, SUMMARY_HPLEFT_Y, SUMMARY_HPLEFT_WIDTH, SUMMARY_HPLEFT_HEIGHT };
	summaryPosition[SUMMARY_HPLEFT1] = { SUMMARY_HPLEFT1_X, SUMMARY_HPLEFT1_Y, SUMMARY_HPLEFT1_WIDTH, SUMMARY_HPLEFT1_HEIGHT };
	summaryPosition[SUMMARY_HPLEFT2] = { SUMMARY_HPLEFT2_X, SUMMARY_HPLEFT2_Y, SUMMARY_HPLEFT2_WIDTH, SUMMARY_HPLEFT2_HEIGHT };
	summaryPosition[SUMMARY_HPLEFT3] = { SUMMARY_HPLEFT3_X, SUMMARY_HPLEFT3_Y, SUMMARY_HPLEFT3_WIDTH, SUMMARY_HPLEFT3_HEIGHT };
	summaryPosition[SUMMARY_HPLEFT4] = { SUMMARY_HPLEFT4_X, SUMMARY_HPLEFT4_Y, SUMMARY_HPLEFT4_WIDTH, SUMMARY_HPLEFT4_HEIGHT };
	summaryPosition[SUMMARY_TOTALHP1] = { SUMMARY_TOTALHP1_X, SUMMARY_TOTALHP1_Y, SUMMARY_TOTALHP1_WIDTH, SUMMARY_TOTALHP1_HEIGHT };
	summaryPosition[SUMMARY_TOTALHP2] = { SUMMARY_TOTALHP2_X, SUMMARY_TOTALHP2_Y, SUMMARY_TOTALHP2_WIDTH, SUMMARY_TOTALHP2_HEIGHT };
	summaryPosition[SUMMARY_TOTALHP3] = { SUMMARY_TOTALHP3_X, SUMMARY_TOTALHP3_Y, SUMMARY_TOTALHP3_WIDTH, SUMMARY_TOTALHP3_HEIGHT };
	summaryPosition[SUMMARY_TOTALHP4] = { SUMMARY_TOTALHP4_X, SUMMARY_TOTALHP4_Y, SUMMARY_TOTALHP4_WIDTH, SUMMARY_TOTALHP4_HEIGHT };
	summaryPosition[SUMMARY_REPLAY] = { SUMMARY_REPLAY_X, SUMMARY_REPLAY_Y, SUMMARY_REPLAY_WIDTH, SUMMARY_REPLAY_HEIGHT };
	summaryPosition[SUMMARY_HOME] = { SUMMARY_HOME_X, SUMMARY_HOME_Y, SUMMARY_HOME_WIDTH, SUMMARY_HOME_HEIGHT };
	summaryPosition[SUMMARY_NEXT] = { SUMMARY_NEXT_X, SUMMARY_NEXT_Y, SUMMARY_NEXT_WIDTH, SUMMARY_NEXT_HEIGHT };
	loadImage(summaryFrame[SUMMARY_WINDOW], "Image/Menu/window", 1, render);
	summaryFrame[SUMMARY_WIN_LOSE].push_back(createTextureFromFont(font.villa, "", font.allColor[COLOR_YEALLOW], render));
	summaryFrame[SUMMARY_SCORE_TIME].push_back(createTextureFromFont(font.zag, "", font.allColor[COLOR_WHITE], render));
	loadImage(summaryFrame[SUMMARY_CHAR1], "Image/Characters/AnemoChar/avatar", 1, render);
	loadImage(summaryFrame[SUMMARY_CHAR2], "Image/Characters/ElectroChar/avatar", 1, render);
	loadImage(summaryFrame[SUMMARY_CHAR3], "Image/Characters/HydroChar/avatar", 1, render);
	loadImage(summaryFrame[SUMMARY_CHAR4], "Image/Characters/PyroChar/avatar", 1, render);
	summaryFrame[SUMMARY_HPLEFT].push_back(createTextureFromFont(font.zag, "HP Left", font.allColor[COLOR_WHITE], render));
	loadImage(summaryFrame[SUMMARY_HPLEFT1], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_HPLEFT2], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_HPLEFT3], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_HPLEFT4], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_TOTALHP1], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_TOTALHP2], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_TOTALHP3], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_TOTALHP4], "Image/hp", 2, render);
	loadImage(summaryFrame[SUMMARY_REPLAY], "Image/Menu/replay", 2, render);
	loadImage(summaryFrame[SUMMARY_HOME], "Image/Menu/home", 2, render);
	loadImage(summaryFrame[SUMMARY_NEXT], "Image/Menu/next", 2, render);
}