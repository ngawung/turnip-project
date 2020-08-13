#include <iostream>

#include <nds.h>
#include <nf_lib.h>

#include "NGMain.h"
#include "Assets.h"
#include "scene1.h"

int main() {


	NGMain* game = new NGMain(true);
	
	Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	Assets::load3dPallete("new/mist", "mist", 0);
	
	game->set_scene(new scene1());
	
	std::cout << "Done" << std::endl;

	while(1) {
		game->update();
	}

	return 0;

}