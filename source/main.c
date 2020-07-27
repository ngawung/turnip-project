#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

int main(int argc, char **argv) {

	NF_Set2D(0, 0);
	NF_Set2D(1, 0);

	consoleDemoInit();
	iprintf("\nHelloooo....");

	swiWaitForVBlank();

	NF_SetRootFolder("NITROFS");

	NF_InitSpriteBuffers();
	NF_InitSpriteSys(0);

	NF_LoadSpriteGfx("cat", 0, 32, 32);
	NF_LoadSpritePal("cat", 0);

	NF_VramSpriteGfx(0, 0, 0, true);
	NF_VramSpritePal(0, 0, 0);

	NF_CreateSprite(0, 0, 0, 0, 20, 20);

	
	
	while(1) {

		NF_SpriteOamSet(0);
		swiWaitForVBlank();

		oamUpdate(&oamMain);

	}

	return 0;

}
