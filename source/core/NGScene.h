class NGScene {
	private:
		std::vector<NGObject*> children;

	public:
		NGScene() {
		   initialize();
		}

		virtual ~NGScene() {
			
		}

		void preUpdate() {
			for (uint i=0; i<children.size(); i++) {
				children[i]->update();
			}

			update();
		}

		virtual void initialize() {}
		virtual void update() {}

		virtual void destroy() {
			removeChildAll();
		}

		// main function

		NGObject* addChild(NGObject* child) {
			if (children.size() == 255) {
				std::cout << "Max child size reached";
				return nullptr;
			}

			// push child
			children.push_back(child);

			// get the last index
			uint index = children.size() - 1;

			// render child
			child->draw(index);

			// return child pointer
			return child;
		}

		NGObject* getChildByName(std::string name) {
			for (unsigned int i=0; i<children.size(); i++) { 
				if (children[i]->getName() == name) {
					return children[i];
				}
			}
			
			return nullptr;
		}

		NGObject* getChildbyId(unsigned int id) {
			if (id >= children.size()) return nullptr;
			else return children[id];
		}

		bool removeChild(NGObject* child) {
			for (unsigned int i=0; i<children.size(); i++) {
				if (children[i] == child) {
					child->destroy();
					children.erase(children.begin() + i);
					delete child;
					return true;
				}
			}
			std::cout << "Failed to remove child" << std::endl;
			return false;
		}

		bool removeChildByName(std::string name) {
			NGObject* ptr = getChildByName(name);
			if (ptr != nullptr) {
				removeChild(ptr);
				return true;
			} else {
				std::cout << "Failed to remove " << name << std::endl;
				return false;
			}
		}

		bool removeChildById(unsigned int id) {
			NGObject* ptr = getChildbyId(id);

			if (ptr != nullptr) {
				removeChild(ptr);
				return true;
			} else {
				std::cout << "Failed to remove id " << id << std::endl;
				return false;
			}
		}

		bool removeChildAll() {
			for (unsigned int i=0; i<children.size(); i++) {
				children[i]->destroy();
				delete children[i];
			}

			children.clear();
			return true;
		}

		unsigned int numChildren() {
			return children.size();
		}

		// test function

		void printName() {
			for (unsigned int i=0; i<children.size(); i++) { 
				std::cout << children[i]->getId() << ":" << children[i]->getName() << " " << children[i]->x << ":" << children[i]->y << std::endl;
			}
		}
};