#include <nds.h>
#include <nf_lib.h>

#include "simplenfl.h"
#include "NG.h"

int main() {
	NGMain* game = new NGMain();
	game->enableConsole();

	std::cout << "Game initialize" << std::endl;

	while(1) {
		game->update();

		if (KEY_LEFT & keysUp()) {
			game->set_scene(new scene1());
		}
		
		if (KEY_RIGHT & keysUp()) {
			game->set_scene(new scene2());
		}

	}

	return 0;

}