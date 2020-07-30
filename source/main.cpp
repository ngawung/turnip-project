#include <nds.h>
#include <nf_lib.h>

#include <sstream>

#include "simplenfl.h"
#include "NG.h"

void screenSetup() {
	NF_Set3D(0, 0);
	NF_Set2D(1, 0);

	NF_SetRootFolder("NITROFS");
}

void init_bg() {
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);

	NF_LoadTiledBg("new/bg", "bg", 256, 256);
	NF_CreateTiledBg(0, 3, "bg");
}

int main(int argc, char **argv) {

	screenSetup();
	init_bg();

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

	for (unsigned int i = 0; i<myScene.children.size(); i++) {
		NG::log(myScene.children[i].getName());
	}

	myScene.getChildbyId(3).x = 100;

	std::cout << myScene.children[3].x << std::endl;

	// std::cout << myScene.children.size() << std::endl;

	// setup sprite
	NF_InitSpriteBuffers();
	NF_Init3dSpriteSys();
	// NF_InitSpriteSys(0);

	NF_LoadSpriteGfx("new/mist", 0, 64, 128);
	NF_LoadSpritePal("new/mist", 0);

	NF_Vram3dSpriteGfx(0, 0, true);
	NF_Vram3dSpritePal(0, 0);

	int i = 0;
	NF_Create3dSprite(0, 0, 0, 20, 20);
	int id = 0;

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
				NF_Create3dSprite(y, 0, 0, randX, randY);
			}
		}

		int randX = rand() % 256 + 1;
		int randY = rand() % 192 + 1;
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