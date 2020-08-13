#include <nds.h>
#include <nf_lib.h>

#include "NG.h"

int main() {
	NGMain* game = new NGMain();
	game->enableConsole();

	game->enableConsole();

	std::cout << "Game initialize" << std::endl;

	Assets::load3dSprite("new/mist", "mist", NG::getId(0), 64, 128, true);
	Assets::load3dPallete("new/mist", "mist", NG::getId(0));

	game->set_scene(new scene1());

	while(1) {
		game->update();
	}

	return 0;

}