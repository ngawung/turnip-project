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
            update(dt);
        }

        void update(double dt) {
            
        }

        // main function

        // nyalain force kalo kamu yakin ga ada name conflict, lebih cepat karna ga perlu loop children
        void addChild(NGObject& child, bool force = false) {
            if (force) {
                return children.push_back(child);
            } else {
                for (unsigned int i=0; i<children.size(); i++) { 
                    if (child.getName() == children[i].getName()) {
                        std::cout << "Nama " << child.getName() << " sudah ada." << std::endl;
                        return;
                    }
                }

                return children.push_back(child);
            }
        }

        bool removeChild(NGObject& child) {
            for (unsigned int i=0; i<children.size(); i++) {
                NGObject* current_child = &children[i];
                if (current_child == &child) {
                    children.erase(children.begin() + i);
                    return true;
                }
            }
            return false;
        }

        bool removeChildByName(std::string name) {
            NGObject* ptr = getChildByName(name);
            if (ptr != nullptr) {
                removeChild(*ptr);
                return true;
            } else return false;
        }

        bool removeChildById(unsigned int id) {
            if (id >= children.size()) return false;
            else {
                children.erase(children.begin() + id);
                return true;
            }
        }

        bool removeChildAll() {
            children.clear();
            return true;
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

        // test function

        void printName() {
            for (unsigned int i=0; i<children.size(); i++) { 
                std::cout << children[i].getName() << std::endl;
            }
        }
};