#include <iostream>

#include <nds.h>
#include <nf_lib.h>


#include "NGMain.hpp"
#include "Assets.hpp"

#include "scene2.hpp"
#include "scene3.hpp"

int main() {

	NGMain* game = new NGMain(0, true);

	std::cout << "Initialize" << std::endl;
	
	// Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	// Assets::load3dPallete("new/mist", "mist", 0);

	NF_LoadTiledBg("new/bg", "nfl", 256, 256);
	NF_LoadTiledBg("bg", "nfl2", 256, 256);
	

	game->set_mainScene(new scene2());
	// game->set_subScene(new scene3());

	// loading sound
	SFX::loadEffect("boom", SFX_BOOM);
	SFX::loadEffect("ambulance", SFX_AMBULANCE);

    SFX::loadStream("main", "music.raw", mm_stream_formats::MM_STREAM_16BIT_MONO, 22050);

	while(1) {

		game->update();

		if (SNF::getKeys(Key::L, KeyPhase::release)) {
			SFX::playEffect("boom", true);
		}

		if (SNF::getKeys(Key::R, KeyPhase::release)) {
			SFX::playEffect("ambulance", true);
		}
		
		if (SNF::getKeys(Key::A, KeyPhase::release)) {
			SFX::playStream("main");
		}
	}

	return 0;

}