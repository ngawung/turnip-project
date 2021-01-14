#include <Ephemeral.hpp>

#include <maxmod9.h>
#include <soundbank.h>

#include "scene/testScene.hpp"

class Game : public EE::App {
	public:
	private:

	public:
		Game() 
			: App(EE::ScreenPosition::BOTTOM, true)
		{

		}

		~Game () {

		}

		void handleOnStart() override {
			set_mainScene(new EE::Scene1());
			
		}

	private:
};

EE::App* EE::CreateApp() {
	return new Game();
}


