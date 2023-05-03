#include "help.h"
#include "enum.h"

void HelpWindow::initData(SDL_Renderer* render, Font& font)
{
	vector <SDL_Texture*> tempText;
	for (int i = 0; i < ALLHELP; i++)
	{
		helpFrame.push_back(tempText);
		helpPosition.push_back({ 0, 0, 0, 0 });
	}
	helpPosition[HELP_RULE1] = { HELP_RULE1_X, HELP_RULE1_Y, HELP_RULE1_WIDTH, HELP_RULE1_HEIGHT };
	helpPosition[HELP_RULE2] = { HELP_RULE2_X, HELP_RULE2_Y, HELP_RULE2_WIDTH, HELP_RULE2_HEIGHT };
	helpPosition[HELP_HOWTOPLAY] = { HELP_HOWTOPLAY_X, HELP_HOWTOPLAY_Y, HELP_HOWTOPLAY_WIDTH, HELP_HOWTOPLAY_HEIGHT };
	helpPosition[HELP_SKILL_CHAR1] = { HELP_SKILL_CHAR1_X, HELP_SKILL_CHAR1_Y, HELP_SKILL_CHAR1_WIDTH, HELP_SKILL_CHAR1_HEIGHT };
	helpPosition[HELP_SKILL_CHAR2] = { HELP_SKILL_CHAR2_X, HELP_SKILL_CHAR2_Y, HELP_SKILL_CHAR2_WIDTH, HELP_SKILL_CHAR2_HEIGHT };
	helpPosition[HELP_SKILL_CHAR3] = { HELP_SKILL_CHAR3_X, HELP_SKILL_CHAR3_Y, HELP_SKILL_CHAR3_WIDTH, HELP_SKILL_CHAR3_HEIGHT };
	helpPosition[HELP_SKILL_CHAR4] = { HELP_SKILL_CHAR4_X, HELP_SKILL_CHAR4_Y, HELP_SKILL_CHAR4_WIDTH, HELP_SKILL_CHAR4_HEIGHT };
	helpPosition[HELP_DOT1] = { HELP_DOT1_X, HELP_DOT1_Y, HELP_DOT1_WIDTH, HELP_DOT1_HEIGHT };
	helpPosition[HELP_DOT2] = { HELP_DOT2_X, HELP_DOT2_Y, HELP_DOT2_WIDTH, HELP_DOT2_HEIGHT };
	helpPosition[HELP_DOT3] = { HELP_DOT3_X, HELP_DOT3_Y, HELP_DOT3_WIDTH, HELP_DOT3_HEIGHT };
	helpPosition[HELP_DOT4] = { HELP_DOT4_X, HELP_DOT4_Y, HELP_DOT4_WIDTH, HELP_DOT4_HEIGHT };
	helpPosition[HELP_DOT5] = { HELP_DOT5_X, HELP_DOT5_Y, HELP_DOT5_WIDTH, HELP_DOT5_HEIGHT };
	helpPosition[HELP_DOT6] = { HELP_DOT6_X, HELP_DOT6_Y, HELP_DOT6_WIDTH, HELP_DOT6_HEIGHT };
	helpPosition[HELP_DOT7] = { HELP_DOT7_X, HELP_DOT7_Y, HELP_DOT7_WIDTH, HELP_DOT7_HEIGHT };
	loadImage(helpFrame[HELP_RULE1], "Image/Menu/Help Window/rule1_", 1, render);
	loadImage(helpFrame[HELP_RULE2], "Image/Menu/Help Window/rule2_", 1, render);
	loadImage(helpFrame[HELP_HOWTOPLAY], "Image/Menu/Help Window/howtoplay", 1, render);
	loadImage(helpFrame[HELP_SKILL_CHAR1], "Image/Menu/Help Window/skill character 1_", 1, render);
	loadImage(helpFrame[HELP_SKILL_CHAR2], "Image/Menu/Help Window/skill character 2_", 1, render);
	loadImage(helpFrame[HELP_SKILL_CHAR3], "Image/Menu/Help Window/skill character 3_", 1, render);
	loadImage(helpFrame[HELP_SKILL_CHAR4], "Image/Menu/Help Window/skill character 4_", 1, render);
	loadImage(helpFrame[HELP_DOT1], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT2], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT3], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT4], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT5], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT6], "Image/Menu/Help Window/dot", 2, render);
	loadImage(helpFrame[HELP_DOT7], "Image/Menu/Help Window/dot", 2, render);
	pageNumber = 1;
}