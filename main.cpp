#include "menu.h"
#include "enum.h"

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
	Boss boss(app.pen);
	Font font(app.pen);
	Menu menu(app.pen, font);
	menu.run(characters, monsters, boss, maps, bulletOnScreen, font, app);
	return 0;
}