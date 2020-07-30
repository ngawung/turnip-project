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

        // main function

        unsigned int numChildren() {
            return children.size();
        }

        void addChild(NGObject& child) {
            children.push_back(child);
        }

        NGObject* getChildByName(std::string name) {
            for (unsigned int i=0; i<children.size(); i++) {
                if (children[i].getName() == name) {
                    return &children[i];
                }
            }
            
            return nullptr;
        }

        NGObject* getChildbyId(unsigned int id) {
            if (id >= children.size()) return nullptr;
            else return &children[id];
        }
};