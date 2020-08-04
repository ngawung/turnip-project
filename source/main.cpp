#include <nds.h>
#include <nf_lib.h>

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

	srand(time(NULL));

	// setup console
	consoleDemoInit();
	NG::log("Helloooooo");
	NG::log("test");

	// preload assets
	Assets::load3dSprite("new/mist", "mist", NG::getId(0), 64, 128, true);
	Assets::load3dPallete("new/mist", "mist", NG::getId(0));

	Assets::load3dSprite("new/anim", "anim", NG::getId(1), 32, 32, false);
	Assets::load3dPallete("new/anim", "anim", NG::getId(1));

	NGScene myScene;

	NF_3dSpritesLayer(3);

	NGObject* anim = myScene.addChild("anim", Assets::getSprite("anim"), Assets::getPallete("anim"));
	anim->quickPlay(std::vector<int>{1, 0});

	NF_LoadTiledBg("new/bg", "bg", 256, 256);
	// NF_CreateTiledBg(0, 3, "bg");

	int i = 0;

	// testing text
	NF_InitTextSys(SCREEN_0);
	NF_LoadTextFont("new/default", "font", 256, 256, 0);
	NF_CreateTextLayer(SCREEN_0, 2, 0, "font");
	NF_WriteText(SCREEN_0, 2, 0, 0, "Hellooo world...");
	NF_UpdateTextLayers();

	while(1) {

		scanKeys();
		if(KEY_A & keysUp()) {
			iprintf("\nReset..!");
			NF_DeleteTiledBg(0, 3);
		}
		
		if (KEY_B & keysUp()) {
			i--;
			// myScene.removeChild(myScene.getChildByName(std::to_string(i)));
			// myScene.removeChildByName(std::to_string(i));
			// myScene.removeChildById(i);
			myScene.removeChildAll();
		}

		if (KEY_X & keysHeld()) {
			int randX = rand() % 256 + 1;
			int randY = rand() % 192 + 1;
			NGObject* obj = myScene.addChild(std::to_string(i), Assets::getSprite("mist"), Assets::getPallete("mist"));
			obj->x = randX;
			obj->y = randY;
			obj->rotation = rand() % 360 + 1;
			obj->scaleX = rand() % 800 + 1;
			obj->scaleY = rand() % 800 + 1;
			obj->layer = i*2;
			i++;
		}
		
		if (KEY_Y & keysUp()) {

		}

		if (KEY_L & keysHeld()) {
			NGObject* obj = myScene.getChildByName("anim");
			obj->delay--;
			if (obj->delay < 0) obj->delay = 0;
			std::cout << obj->delay << std::endl;
		}

		if (KEY_R & keysHeld()) {
			NGObject* obj = myScene.getChildByName("anim");
			obj->delay++;
			if (obj->delay < 0) obj->delay = 0;
			std::cout << obj->delay << std::endl;
		}

		myScene.preUpdate();
		
		NF_Draw3dSprites();
		glFlush(0);
		swiWaitForVBlank();
		NF_Update3dSpritesGfx();
	}

	return 0;

}