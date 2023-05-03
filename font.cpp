#include "font.h"
#include "enum.h"

Font::Font(SDL_Renderer* render)
{
	villa = loadFont("Font/Villa.ttf", 28);
	zag = loadFont("Font/Zag Regular.otf", 28);
	SDL_Color tempColor = { 0, 0, 0 };
	SDL_Texture* tempTexture = nullptr;
	allColor = { tempColor, tempColor, tempColor, tempColor, tempColor, tempColor };
	allColor[COLOR_WHITE] = { 255, 255, 255 };
	allColor[COLOR_YEALLOW] = { 255, 255, 0 };
	allColor[COLOR_GRAY] = { 128, 128, 128 };
	allColor[COLOR_ORANGE] = { 255, 128, 0 };
	allColor[COLOR_BROWN] = { 153, 76, 0 };
	allColor[COLOR_BLACK] = { 0, 0, 0 };
	for (int i = 0; i < ALLFONT; i++)
	{
		text.push_back(tempTexture);
	}
	text[FONT_CLIKTOPLAY] = createTextureFromFont(villa, "Click the start button to play !", allColor[COLOR_WHITE], render);
	text[FONT_MENU] = createTextureFromFont(villa, "MENU", allColor[COLOR_WHITE], render);
	text[FONT_MAP] = createTextureFromFont(villa, "MAP", allColor[COLOR_WHITE], render);
	text[FONT_MAP1] = createTextureFromFont(villa, "Prehistoric Time", allColor[COLOR_WHITE], render);
	text[FONT_MAP2] = createTextureFromFont(villa, "Machine War", allColor[COLOR_WHITE], render);
	text[FONT_MAPBOSS] = createTextureFromFont(villa, "Final Boss", allColor[COLOR_WHITE], render);
	text[FONT_TIME_REMAINING] = createTextureFromFont(villa, "Time remaining : ", allColor[COLOR_WHITE], render);
	text[FONT_SCORE] = createTextureFromFont(villa, "Your score : ", allColor[COLOR_WHITE], render);
}