#include "NGObject.h"
#include <algorithm>

class NGScene {
    private:
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

        void addChild(NGObject& child) {
            children.push_back(child);
        }

        bool removeChild(NGObject* child) {
            for (unsigned int i=0; i<children.size(); i++) {
                NGObject* current_child = &children[i];
                if (current_child == child) {
                    std::cout << "Removed\n";
                    children.erase(children.begin() + i);
                    return true;
                }
            }

            std::cout << "Not Found!\n";
            return false;
        }

        unsigned int numChildren() {
            return children.size();
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