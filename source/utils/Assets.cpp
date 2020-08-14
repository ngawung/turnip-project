#include <map>
#include <string>

#include "nf_lib.h"
#include "Assets.h"

// ram vram 256
void Assets::load3dSprite(const char* file, std::string name, uint16_t ramslot, uint16_t width, uint16_t height, bool keepframe) {
	NF_LoadSpriteGfx(file, ramslot, width, height);
	NF_Vram3dSpriteGfx(ramslot, ramslot, keepframe);
	
	sprite.insert({name, ramslot});
}

// ram 64, vram 32
void Assets::load3dPallete(const char* file, std::string name, uint16_t ramslot) {
	NF_LoadSpritePal(file, ramslot);
	NF_Vram3dSpritePal(ramslot, ramslot);

	pallete.insert({name, ramslot});
}

void Assets::unload3dSprite(std::string name) {
	NF_Free3dSpriteGfx(getSprite(name));
	NF_UnloadSpriteGfx(getSprite(name));

	sprite.erase(name);
}

void Assets::unload3dPallete(std::string name) {
	NF_UnloadSpritePal(getPallete(name));
	pallete.erase(name);
}
void Assets::unload3dSpriteAll() {
	std::map<std::string, u16>::iterator it = sprite.begin();
	while(it != sprite.end()) {
		unload3dPallete(it->first);
		it++;
	}
}

void Assets::unload3dPalleteAll() {
	std::map<std::string, u16>::iterator it = pallete.begin();
	while(it != pallete.end()) {
		unload3dPallete(it->first);
		it++;
	}
}

uint16_t Assets::getSprite(std::string name) {
	auto it = sprite.find(name);
	if (it != sprite.end()) return it->second;
	else return -1;
}

uint16_t Assets::getPallete(std::string name) {
	auto it = pallete.find(name);
	if (it != pallete.end()) return it->second;
	else return -1;
}