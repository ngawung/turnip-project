#include <nds.h>
#include <nf_lib.h>

#include <sstream>

#include "simplenfl.h"
#include "NG.h"

#define SCREEN_0 0
#define SCREEN_1 1

void setupScreen() {
	NF_Set3D(0, 0);
	NF_Set2D(1, 0);

	NF_SetRootFolder("NITROFS");
}

// 0 = 2d engine; 1 = 3d engine
void setupBuffer(char mode) {
	// setup background
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(SCREEN_0);
	NF_InitTiledBgSys(SCREEN_1);

	// setup sprite
	NF_InitSpriteBuffers();

	if (mode == 0) {
		NF_InitSpriteSys(SCREEN_0);
		NF_InitSpriteSys(SCREEN_1);
	} else {
		NF_Init3dSpriteSys();
	}
}

void renderScene(NGScene& scene) {
	
}

int main() {

	setupScreen();
	setupBuffer(1);

	// setup console
	consoleDemoInit();
	NG::log("Helloooooo");
	NG::log("test");

	NGScene myScene;

	for (unsigned int i = 0; i<5; i++) {
		std::stringstream ss;
		ss << "Object no " << i;
		NGObject myObject(ss.str());
		myScene.addChild(myObject);
	}
	
	NGObject dupe1("dupe");
	myScene.addChild(dupe1);

	NGObject dupe2("dupe");
	myScene.addChild(dupe2);

	myScene.printName();

	NF_LoadTiledBg("new/bg", "bg", 256, 256);
	NF_CreateTiledBg(0, 3, "bg");

	AssetsManager::load3dSprite("new/mist", "mist", 0, 64, 128, true);
	AssetsManager::load3dPallete("new/mist", "mist", 0);

	int i = 0;
	//NF_Create3dSprite(0, 0, 0, 20, 20);
	NF_Create3dSprite(0, AssetsManager::getSprite("mist"), AssetsManager::getPallete("mist"), 20, 20);

	while(1) {

		scanKeys();
		if(KEY_A & keysUp()) {
			iprintf("\nReset..!");
			// NF_ResetTiledBgBuffers();
			NF_DeleteTiledBg(0, 3);
		}
		
		if (KEY_B & keysUp()) {
			iprintf("\nCreate..!");
			NF_CreateTiledBg(0, 3, "bg");
		}

		if (KEY_X & keysUp()) {
			for (int y =0; y<255; y++) {
				int randX = rand() % 256 + 1;
				int randY = rand() % 192 + 1;
				NF_Create3dSprite(y, AssetsManager::getSprite("mist"), AssetsManager::getPallete("mist"), randX, randY);
			}
		}
		// NF_Create3dSprite(0, 0, 0, randX, randY);
		
		NF_Move3dSprite(0, 20 + i, 20);
		i++;
		if(i>(255 -20)) i = 0;
		// NF_SpriteOamSet(0);
		NF_Draw3dSprites();
		glFlush(0);
		swiWaitForVBlank();

		// oamUpdate(&oamMain);
	}

	return 0;

}