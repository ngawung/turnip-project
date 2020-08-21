#include <iostream>

#include <stdio.h>

#include <nds.h>
#include <nf_lib.h>


#include "NGMain.hpp"
#include "Assets.hpp"

#include "scene2.hpp"
#include "scene3.hpp"


#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

struct Song{
	const mm_word rate;
	const mm_stream_formats format;
	const char* filename;
};

const Song songs[] = {
	{22050,MM_STREAM_16BIT_MONO,"music.raw"},
};

FILE* file = 0;
mm_stream mystream;
mm_word stream(mm_word length, mm_addr dest, mm_stream_formats format);
mm_sfxhand amb = 0;

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
	// load sound effects
	mmLoadEffect( SFX_AMBULANCE );
	mmLoadEffect( SFX_BOOM );

	//Initialize stream parameters
	mm_stream mystream;
	mystream.buffer_length = 1024;
	mystream.callback = stream;
	mystream.timer= MM_TIMER0;
	mystream.manual = true;
	mystream.sampling_rate = 22050;
	mystream.format = MM_STREAM_16BIT_MONO;

	
    // NF_LoadRawSound("Ambulance", 1, 11025, 0);
    // NF_LoadRawSound("Boom", 2, 11025, 0);
    

	while(1) {
		//Fill buffer
		mmStreamUpdate();

		game->update();

		if (SNF::getKeys(Key::L, KeyPhase::release)) {
			//Play sound
			// NF_PlayRawSound(1, 127, 64, false, 0);
			mmEffect(SFX_BOOM);
		}

		if (SNF::getKeys(Key::R, KeyPhase::release)) {
			//Play sound
			// NF_PlayRawSound(2, 127, 64, false, 0);
		}
		
		if (SNF::getKeys(Key::A, KeyPhase::release)) {
			//Close current song
			if(file){
				mmStreamClose();
				fclose(file);
			}

			file = fopen("music.raw","rb");
			mmStreamOpen(&mystream);
		}
	}

	return 0;

}

mm_word stream(mm_word length, mm_addr dest, mm_stream_formats format) {
	if (file) {
		size_t samplesize = 0;
		switch(format){
			case MM_STREAM_8BIT_MONO: samplesize = 1; break;
			case MM_STREAM_8BIT_STEREO: samplesize = 2; break;
			case MM_STREAM_16BIT_MONO: samplesize = 2; break;
			case MM_STREAM_16BIT_STEREO: samplesize = 4; break;
		}
		
		int res = fread(dest, samplesize, length, file);
		if(res){
			length = res;
		} else {
			//End of file
			length = 0;
		}
		
		return length; //Return the number of samples read
	} 

	return 0;
}