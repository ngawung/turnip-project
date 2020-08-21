#pragma once

#include <vector>
#include <string>
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

struct StreamSound {
    std::string name;
	const char* filename;
	const mm_stream_formats format;
	const mm_word rate;

    StreamSound(std::string _name, const char* _filename, const mm_stream_formats _format, const mm_word _rate)
        : name(_name), filename(_filename), format(_format), rate(_rate)
    {

    }
};

struct SoundEffect {
    std::string name;
    mm_word sampleId;
    SoundEffect(std::string _name, mm_word _sampleId) 
        : name(_name), sampleId(_sampleId)
    {

    }
};

class SFX {
    public:
        static inline FILE* file;
        static inline mm_stream stream;

    private:
        static inline std::vector<StreamSound*> music;
        static inline std::vector<SoundEffect*> sfx;
    
    public:
        SFX();
        static void initialize();

        static void loadStream(std::string name, const char* file, mm_stream_formats format, mm_word rate);
        static void unloadStream(std::string name);
        static void playStream(std::string name);
        static void stopStream();

        static void loadEffect(std::string name, mm_word sampleId);
        static void unloadEffect(std::string name);
        static void playEffect(std::string name, bool lowPriority);
        
        static void update();

    private:
        static mm_word streamCallback(mm_word length, mm_addr dest, mm_stream_formats format);
};