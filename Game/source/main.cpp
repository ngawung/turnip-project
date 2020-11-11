#include <Ephemeral.hpp>

#include <maxmod9.h>
#include <soundbank.h>

class Game : public EE::App {
	public:
	private:

	public:
		Game() 
			: App(SCREEN_0, true)
		{

		}

		~Game () {

		}
	private:
};

EE::App* EE::CreateApp() {
	return new Game();
}


