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

	// preload assets
	Assets::load3dSprite("new/mist", "mist", NG::getId(0), 64, 128, true);
	Assets::load3dPallete("new/mist", "mist", NG::getId(0));

	NGScene myScene;

	//myScene.addChild("mist", Assets::getSprite("mist"), Assets::getPallete("mist"));

	NF_LoadTiledBg("new/bg", "bg", 256, 256);
	NF_CreateTiledBg(0, 3, "bg");

	int i = 0;

	// for (int y =0; y<255; y++) {
	// 	int randX = rand() % 256 + 1;
	// 	int randY = rand() % 192 + 1;
	// 	NGObject m(std::to_string(y), Assets::getSprite("mist"), Assets::getPallete("mist"));
	// 	m.x = randX;
	// 	m.y = randY;
	// 	myScene.addChild(m);
	// }
	
	while(1) {

		scanKeys();
		if(KEY_A & keysUp()) {
			iprintf("\nReset..!");
			// NF_ResetTiledBgBuffers();
			NF_DeleteTiledBg(0, 3);
		}
		
		if (KEY_B & keysUp()) {
			i--;
			// myScene.removeChild(myScene.getChildByName(std::to_string(i)));
			// myScene.removeChildByName(std::to_string(i));
			// myScene.removeChildById(i);
			myScene.removeChildAll();
		}

		if (KEY_X & keysUp()) {
			int randX = rand() % 256 + 1;
			int randY = rand() % 192 + 1;
			NGObject* obj = myScene.addChild(std::to_string(i), Assets::getSprite("mist"), Assets::getPallete("mist"));
			obj->x = randX;
			obj->y = randY;
			obj->rotation = rand() % 360 + 1;
			obj->scaleX = rand() % 100 + 1;
			obj->scaleY = rand() % 100 + 1;
			i++;
		}
		
		if (KEY_Y & keysUp()) {
			myScene.printName();
		}

		myScene.preUpdate();
		
		// NF_SpriteOamSet(0);
		NF_Draw3dSprites();
		glFlush(0);
		swiWaitForVBlank();

		// oamUpdate(&oamMain);
	}

	return 0;

}