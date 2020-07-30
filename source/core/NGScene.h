#include <iostream>
#include <vector>
#include "NGObject.h"

class NGScene {
    public:
        std::vector<NGObject> children;

    public:
        NGScene() {
           initialize();
        }

        void initialize() {
             std::cout << "Scene initialize\n";
        }

        void preUpdate(double dt) {

        }

        void update(double dt) {
            
        }

        void addChild(NGObject& child) {
            children.push_back(child);
        }
};