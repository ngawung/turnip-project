#include <random>
#include <iostream>
#include <fstream>

#include <nds.h>
#include <nf_lib.h>

#include <maxmod9.h>
#include <soundbank.h>

#include <Ephemeral.hpp>

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
	
	while(1) {
		scanKeys();
		

		// NF_UpdateTextLayers();
		swiWaitForVBlank();
	}

	return 0;

}
