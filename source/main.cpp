#include <nds.h>
#include <nf_lib.h>

#include "simplenfl.h"
#include "NG.h"

int main() {
	new NGMain();
	//game->enableConsole();

	NGMain::getInstance()->enableConsole();

	std::cout << "Game initialize" << std::endl;

	Assets::load3dSprite("new/mist", "mist", NG::getId(0), 64, 128, true);
	Assets::load3dPallete("new/mist", "mist", NG::getId(0));

	NGMain::getInstance()->set_scene(new scene1());

	int i = 0;

	while(1) {
		NGMain::getInstance()->update();

		if (KEY_LEFT & keysUp()) {
			NGMain::getInstance()->set_scene(new scene1());
		}
		
		if (KEY_RIGHT & keysUp()) {
			NGMain::getInstance()->set_scene(new scene2());
		}

		// std::cout << KEY_RIGHT << ":" << keysUp() << std::endl;

		if (KEY_DOWN & keysHeld()) {
			NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
			obj->x = Random::range(256);
			obj->y = Random::range(192);
			NGMain::getInstance()->get_scene()->addChild(obj);

			i++;
			std::cout << i << std::endl;
		}

	}

	return 0;

}