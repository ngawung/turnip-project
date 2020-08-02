#include "NGObject.h"
#include <algorithm>

class NGScene {
	private:
		std::vector<NGObject*> children;

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

		void addChild(NGObject& child) {
			// check duplicate
			for (unsigned int i=0; i<children.size(); i++) { 
				if (child.getName() == (*children[i]).getName()) {
					std::cout << "Nama " << child.getName() << " sudah ada." << std::endl;
					return;
				}
			}

			children.push_back(&child);
			// get the last index
			uint index = children.size() - 1;

			std::cout << "index no " << index << std::endl;
			
			// render sprite
			child.draw(index);
		}

		bool removeChild(NGObject& child) {
			for (unsigned int i=0; i<children.size(); i++) {
				if (children[i] == &child) {
					std::cout << "id from removeChild " << child.getId() << "\n";

					child.destroy();
					children.erase(children.begin() + i);
					return true;
				}
			}
			std::cout << "Failed to remove child" << std::endl;
			return false;
		}

		bool removeChildByName(std::string name) {
			NGObject* ptr = getChildByName(name);
			if (ptr != nullptr) {
				removeChild(*ptr);
				return true;
			} else {
				std::cout << "Failed to remove " << name << std::endl;
				return false;
			}
		}

		bool removeChildById(unsigned int id) {
			NGObject* child = getChildbyId(id);

			if (child) {
				(*child).destroy();
				children.erase(children.begin() + id);
				return true;
			} else {
				std::cout << "Failed to remove id " << id << std::endl;
				return false;
			}
		}

		bool removeChildAll() {
			for (unsigned int i=0; i<children.size(); i++) {
				(*children[i]).destroy();
			}

			children.clear();
			return true;
		}

		unsigned int numChildren() {
			return children.size();
		}

		NGObject* getChildByName(std::string name) {
			for (unsigned int i=0; i<children.size(); i++) { 
				if ((*children[i]).getName() == name) {
					return children[i];
				}
			}
			
			return nullptr;
		}

		NGObject* getChildbyId(unsigned int id) {
			if (id >= children.size()) return nullptr;
			else return children[id];
		}

		// test function

		void printName() {
			for (unsigned int i=0; i<children.size(); i++) { 
				std::cout << (*children[i]).getId() << ":" << (*children[i]).getName() << std::endl;
			}
		}
};