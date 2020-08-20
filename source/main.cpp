#include <iostream>

#include <nds.h>
#include <nf_lib.h>


#include "NGMain.hpp"
#include "Assets.hpp"

#include "scene2.hpp"
#include "scene3.hpp"


#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

const mm_word sounds[] = {
	SFX_BEEP,
	SFX_CANNON,
	SFX_EXPLOSION,
	SFX_SPLIT
};

int main() {


	NGMain* game = new NGMain(0, false);
	
	// Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	// Assets::load3dPallete("new/mist", "mist", 0);

	NF_LoadTiledBg("new/bg", "nfl", 256, 256);
	NF_LoadTiledBg("bg", "nfl2", 256, 256);
	

	game->set_mainScene(new scene2());
	game->set_subScene(new scene3());

	// setup sound
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	// loading sound
	for(int i=0; i<4; i++) {
		mmLoadEffect(sounds[i]);
	}

	while(1) {
		game->update();

		if (SNF::getKeys(Key::L, KeyPhase::release)) {
			//Play sound
			mm_sfxhand sound_handle = mmEffect(sounds[rand()%4]);

			//Allow sound to be interrupted
			mmEffectRelease(sound_handle);
		}
	}

	return 0;

}