#include <random>
#include <iostream>
#include <fstream>

#include <nds.h>
#include <nf_lib.h>

#include <maxmod9.h>
#include <soundbank.h>

#include <Ephemeral.hpp>
#include <simplenfl.h>
#include <STween.h>

class Game : public EE::App {
	public:
	private:

	public:
		Game() {

		}

		~Game () {

		}
	private:
};

EE::App* EE::CreateApp() {
	return new Game();
}

int main() {

	NF_Set2D(0, 0);
	NF_Set2D(1, 0);

	NF_SetRootFolder("NITROFS");

	consoleDemoInit();

	std::cout << "Hello World" << std::endl;

	auto ephemeral = EE::CreateApp();
	ephemeral->start();

	STween::STween<int> tween;
	
	while(1) {
		scanKeys();
		
		if (SNF::getTouch(SNF::release)) {
			std::cout << "Touch" << std::endl;
		}

		// NF_UpdateTextLayers();
		swiWaitForVBlank();
	}

	return 0;

}
