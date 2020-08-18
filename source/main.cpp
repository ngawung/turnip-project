#include <iostream>

#include <nds.h>
#include <nf_lib.h>

#include "NGMain.hpp"
#include "Assets.hpp"
#include "scene3.hpp"

int main() {


	NGMain* game = new NGMain(1, true);
	
	// Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	// Assets::load3dPallete("new/mist", "mist", 0);
	
	game->set_mainScene(new scene3());

	while(1) {
		game->update();
	}

	return 0;

}