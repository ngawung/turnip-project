#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

int main(int argc, char **argv) {

	NF_Set2D(0, 0);
	NF_Set2D(1, 0);

	consoleDemoInit();
	iprintf("\nHelloooo....");

	NF_SetRootFolder("NITROFS");
	
	// setup bg
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(0);

	NF_LoadTiledBg("bg", "bg", 256, 256);
	NF_CreateTiledBg(0, 3, "bg");

	// setup sprite
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);

	NF_LoadSpriteGfx("cat", 0, 32, 32);
	NF_LoadSpritePal("cat", 0);

	NF_VramSpriteGfx(0, 0, 0, true);
	NF_VramSpritePal(0, 0, 0);

	int i = 0;

	while(1) {
		
		NF_CreateSprite(0, 0, 0, 0, 20 + i, 20);
		i++;

		NF_SpriteOamSet(0);
		swiWaitForVBlank();

		oamUpdate(&oamMain);

	}

	return 0;

}