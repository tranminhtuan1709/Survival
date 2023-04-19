#include "menu.h"

int main(int argc, char* argv[])
{
	App app;
	if (app.checkInit() == false)
	{
		cout << "Can not open game :(" << endl;
		return 0;
	}
	AllCharacters characters(app.pen);
	AllMonsters monsters(app.pen);
	MapGame maps(app.pen);
	BulletOnScreen bulletOnScreen(app.pen);
	Menu menu(app.pen);
	menu.play(characters, monsters, maps, bulletOnScreen, app);
	return 0;		
}
