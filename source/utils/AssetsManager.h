class AssetsManager {
	public:
		inline static std::map<std::string, u16> sprite;
		inline static std::map<std::string, u16> pallete;
		inline static std::string test;

	public:
		// ram vram 256
		static void load3dSprite(const char* file, std::string name, u16 ramslot, u16 width, u16 height, bool keepframe) {
			NF_LoadSpriteGfx(file, ramslot, width, height);
			NF_Vram3dSpriteGfx(ramslot, ramslot, keepframe);
			
			sprite.insert({name, ramslot});
		}

		// ram 64, vram 32
		static void load3dPallete(const char* file, std::string name, u16 ramslot) {
			NF_LoadSpritePal(file, ramslot);
			NF_Vram3dSpritePal(ramslot, ramslot);

			pallete.insert({name, ramslot});
		}

		static void unload3dSprite(std::string name) {
			NF_Free3dSpriteGfx(getSprite(name));
			NF_UnloadSpriteGfx(getSprite(name));

			sprite.erase(name);
		}

		static void unload3dPallete(std::string name) {
			NF_UnloadSpritePal(getPallete(name));
			pallete.erase(name);
		}

		static void unload3dSpriteAll() {
			std::map<std::string, u16>::iterator it = sprite.begin();
			while(it != sprite.end()) {
				unload3dPallete(it->first);
				it++;
			}
		}

		static void unload3dPalleteAll() {
			std::map<std::string, u16>::iterator it = pallete.begin();
			while(it != pallete.end()) {
				unload3dPallete(it->first);
				it++;
			}
		}

		static u16 getSprite(std::string name) {
			auto it = sprite.find(name);
			if (it != sprite.end()) return it->second;
		}

		static u16 getPallete(std::string name) {
			auto it = pallete.find(name);
			if (it != pallete.end()) return it->second;
		}
};