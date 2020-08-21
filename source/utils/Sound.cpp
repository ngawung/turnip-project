#include <iostream>
#include "Sound.hpp"

SFX::SFX() {

}

void SFX::initialize() {
    mmInitDefaultMem((mm_addr)soundbank_bin);
    
    file = nullptr;
	stream.buffer_length = 1024;
	stream.callback = SFX::streamCallback;
	stream.timer= MM_TIMER0;
	stream.manual = true;
}

void SFX::loadStream(std::string name, const char* file, mm_stream_formats format = mm_stream_formats::MM_STREAM_16BIT_MONO, mm_word rate = 22050) {
    for (unsigned int i=0; i<music.size(); i++) {
        if (music[i]->name == name) {
            std::cout << name << "already exist!" << std::endl;
            return;
        }
    }

    StreamSound* ss = new StreamSound(name, file, format, rate);
    music.push_back(ss);
}

void SFX::unloadStream(std::string name) {
    for (unsigned int i=0; i<music.size(); i++) {
        if (music[i]->name == name) {
			delete music[i];
            music.erase(music.begin() + i);
        }
    }
}

void SFX::playStream(std::string name) {
    for (unsigned int i=0; i<music.size(); i++) {
        if (music[i]->name == name) {
            if (file) {
                mmStreamClose();
                fclose(file);
            }

            file = fopen(music[i]->filename, "rb");
            stream.sampling_rate = music[i]->rate;
            stream.format = music[i]->format;
            mmStreamOpen(&stream);
            return;
        }
    }
}

void SFX::stopStream() {
    if (file) {
        mmStreamClose();
        fclose(file);
        file = nullptr;
    }
}

void SFX::loadEffect(std::string name, mm_word sampleId) {
    for (unsigned int i=0; i<sfx.size(); i++) {
        if (sfx[i]->name == name) {
            std::cout << name << "already exist!" << std::endl;
            return;
        }
    }

    SoundEffect* se = new SoundEffect(name, sampleId);
    sfx.push_back(se);

    mmLoadEffect(sampleId);
}

void SFX::unloadEffect(std::string name) {
    for (unsigned int i=0; i<sfx.size(); i++) {
        if (sfx[i]->name == name) {
            mmUnloadEffect(sfx[i]->sampleId);
            sfx.erase(sfx.begin() + i);
			delete sfx[i];
        }
    }
}

void SFX::playEffect(std::string name, bool lowPriority = false) {
    for (unsigned int i=0; i<sfx.size(); i++) {
        if (sfx[i]->name == name) {
            if (lowPriority) mmEffectRelease(mmEffect(sfx[i]->sampleId));
            else mmEffect(sfx[i]->sampleId);
            
            return;
        }
    }
}

void SFX::update() {
    if (file) mmStreamUpdate();
}

mm_word SFX::streamCallback(mm_word length, mm_addr dest, mm_stream_formats format) {
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
            mmStreamClose();
			fclose(file);
			length = 0;
		}
		
		return length;
	} 

	return 0;
}