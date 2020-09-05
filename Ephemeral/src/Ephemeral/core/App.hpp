#pragma once

namespace EE {

    struct Stage {
        const uint8_t witdh = 256;
        const uint8_t height = 192;
    };

    class App {
        public:
        private:
        
        public:
            App();
            virtual ~App();

            void start();
        private:

    };

    App* CreateApp();

}