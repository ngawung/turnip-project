#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

int main(int argc, char **argv) {

	consoleDemoInit();		// Inicializa la consola de texto
	consoleClear();			// Borra la pantalla
	setBrightness(3, 0);	// Restaura el brillo

	iprintf("\n Hello World!");
	
	while(1) {

		swiWaitForVBlank();		// Espera al sincronismo vertical

	}

	return 0;

}
