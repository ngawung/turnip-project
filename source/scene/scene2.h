class scene2 : public NGScene {
    public:
        int i;
    private:

    public:
        scene2() {
            i = 0;
        }

        void initialize() override {
            std::cout << "initialize scene 2" << std::endl;
        }

        void update() override {
            if (KEY_LEFT & keysUp()) {
                NGMain::getInstance()->set_scene(new scene1());
            }

            if (KEY_DOWN & keysHeld()) {
                NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
                obj->x = Random::range(256);
                obj->y = Random::range(192);
                NGMain::getInstance()->get_scene()->addChild(obj);

                i++;
                std::cout << i << std::endl;
            }
        }
};