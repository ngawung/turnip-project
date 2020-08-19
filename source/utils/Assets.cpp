#include <iostream>
#include <map>
#include <string>

#include "nf_lib.h"
#include "Assets.hpp"

// ram
bool Assets::loadSprite(const char* file, std::string name, uint16_t width, uint16_t height) {
	// find empty slot
	for (int i=0; i<256; i++) {
		// return if name already exist
		if (sprite[i].name == name) {
			std::cout << name << " already exist in ram" << std::endl;
			return false;
		}

		// skip
		if (sprite[i].name != "") continue;

		sprite[i].name = name;
		NF_LoadSpriteGfx(file, i, width, height);
		return true;
	}

	return false;
}

bool Assets::loadPallete(const char* file, std::string name) {
	// find empty slot
	for (int i=0; i<64; i++) {
		// return if name already exist
		if (pallete[i].name == name) {
			std::cout << name << " already exist in ram" << std::endl;
			return false;
		}

		// skip
		if (pallete[i].name != "") continue;

		pallete[i].name = name;
		NF_LoadSpritePal(file, i);
		return true;
	}

	return false;
}

bool Assets::unloadSprite(std::string name) {
	for (int i=0; i<256; i++) {
		if (sprite[i].name == name) {
			sprite[i].name = "";
			NF_UnloadSpriteGfx(i);
			return true;
		}
	}

	std::cout << "cannot find " << name << "in vram2D" << std::endl;
	return false;
}

bool Assets::unloadPallete(std::string name) {
	for (int i=0; i<64; i++) {
		if (pallete[i].name == name) {
			pallete[i].name = "";
			NF_UnloadSpriteGfx(i);
			return true;
		}
	}

	std::cout << "cannot find " << name << "in vram2D" << std::endl;
	return false;
}

// vram2DAssets::
bool Assets::loadSprite2D(std::string name, bool keepframes) {
	// find name in ram
	for (int i=0; i<256; i++) {
		if (sprite[i].name != name) continue;

		// find empty slot
		for (int j=0; j<128; j++) {
			// return if name already exist
			if (sprite2D[i].name == name) {
				std::cout << name << " already exist in vram2D" << std::endl;
				return false;
			}

			// skip
			if (sprite2D[i].name != "") continue;

			sprite2D[i].name = name;
			NF_VramSpriteGfx(1, i, j, keepframes);
			return true;
		}
	}

	return false;
}

bool Assets::loadPallete2D(std::string name) {
	// find name in ram
	for (int i=0; i<64; i++) {
		if (pallete[i].name != name) continue;

		// find empty slot
		for (int j=0; j<16; j++) {
			// return if name already exist
			if (pallete2D[i].name == name) {
				std::cout << name << " already exist in vram2D" << std::endl;
				return false;
			}

			// skip
			if (pallete2D[i].name != "") continue;

			pallete2D[i].name = name;
			NF_VramSpritePal(1, i, j);
			return true;
		}
	}

	return false;
}

bool Assets::freeSprite2D(std::string name) {
	for (int i=0; i<128; i++) {
		if (sprite2D[i].name == name) {
			sprite2D[i].name = "";
			NF_FreeSpriteGfx(1, i);
			return true;
		}
	}

	std::cout << "cannot find " << name << "in vram2D" << std::endl;
	return false;
}

bool Assets::freePallete2D(std::string name) {
	for (int i=0; i<16; i++) {
		if (pallete2D[i].name == name) {
			pallete2D[i].name = "";
			// there is no need to free pallete... just replace the id
			return true;
		}
	}

	std::cout << "cannot find " << name << "in vram2D" << std::endl;
	return false;
}

// vram3DAssets::
// bool Assets::loadSprite3D() {}
// bool Assets::loadPallete3D() {}

// bool Assets::freeSprite3D() {}
// bool Assets::freePallete3D() {}

// Get && Set
uint16_t Assets::get_sprite2D(std::string name) {
	for (int i=0; i<128; i++) {
		if (sprite2D[i].name == name) return i;
	}

	return 0;
}

uint16_t Assets::get_pallete2D(std::string name) {
	for (int i=0; i<16; i++) {
		if (pallete2D[i].name == name) return i;
	}

	return 0;
}

// uint16_t Assets::get_sprite3D(std::string name) {}
// uint16_t Assets::get_pallete3D(std::string name) {}

// // ram vram 256
// void Assets::load3dSprite(const char* file, std::string name, uint16_t ramslot, uint16_t width, uint16_t height, bool keepframe) {
// 	// ram
// 	NF_LoadSpriteGfx(file, ramslot, width, height);
	
// 	// vram
// 	NF_Vram3dSpriteGfx(ramslot, ramslot, keepframe);
	
// 	sprite.insert({name, ramslot});
// }

// // ram 64, vram 32
// void Assets::load3dPallete(const char* file, std::string name, uint16_t ramslot) {
// 	// ram
// 	NF_LoadSpritePal(file, ramslot);
	
// 	// vram
// 	NF_Vram3dSpritePal(ramslot, ramslot);

// 	pallete.insert({name, ramslot});
// }

// void Assets::unload3dSprite(std::string name) {
// 	// vram
// 	NF_Free3dSpriteGfx(getSprite(name));
	
// 	//ram
// 	NF_UnloadSpriteGfx(getSprite(name));

// 	sprite.erase(name);
// }

// void Assets::unload3dPallete(std::string name) {
// 	// ram
// 	NF_UnloadSpritePal(getPallete(name));
// 	pallete.erase(name);
// }

// void Assets::unload3dSpriteAll() {
// 	std::map<std::string, u16>::iterator it = sprite.begin();
// 	while(it != sprite.end()) {
// 		unload3dSprite(it->first);
// 		it++;
// 	}
// }

// void Assets::unload3dPalleteAll() {
// 	std::map<std::string, u16>::iterator it = pallete.begin();
// 	while(it != pallete.end()) {
// 		unload3dPallete(it->first);
// 		it++;
// 	}
// }

// uint16_t Assets::getSprite(std::string name) {
// 	auto it = sprite.find(name);
// 	if (it != sprite.end()) return it->second;
// 	else return -1;
// }

// uint16_t Assets::getPallete(std::string name) {
// 	auto it = pallete.find(name);
// 	if (it != pallete.end()) return it->second;
// 	else return -1;
// }