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

		void preUpdate() {
			for (uint i=0; i<children.size(); i++) {
				children[i].update();
			}

			update();
		}

		void update() {
			
		}

		// main function

		NGObject* addChild(std::string name, u16 sprite, u16 pallete) {
			// check duplicate
			for (unsigned int i=0; i<children.size(); i++) { 
				if (name == children[i].getName()) {
					std::cout << "Nama " << name << " sudah ada." << std::endl;
					return nullptr;
				}
			}

			// create child
			NGObject child(name, sprite, pallete);

			// im assume child gonna destroyed after this block end
			// so i push duplicate instead
			children.push_back(child);

			// get the last index
			uint index = children.size() - 1;

			// render sprite
			children[index].draw(index);

			return &children[index];
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

		bool removeChild(NGObject* child) {
			for (unsigned int i=0; i<children.size(); i++) {
				if (&children[i] == child) {
					std::cout << "id from removeChild " << child->getId() << "\n";

					child->destroy();
					// erase call destructor before removing
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
				removeChild(ptr);
				return true;
			} else {
				std::cout << "Failed to remove " << name << std::endl;
				return false;
			}
		}

		bool removeChildById(unsigned int id) {
			NGObject* child = getChildbyId(id);

			if (child != nullptr) {
				child->destroy();
				// erase call destructor before removing
				children.erase(children.begin() + id);
				return true;
			} else {
				std::cout << "Failed to remove id " << id << std::endl;
				return false;
			}
		}

		bool removeChildAll() {
			for (unsigned int i=0; i<children.size(); i++) {
				children[i].destroy();
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
				std::cout << children[i].getId() << ":" << children[i].getName() << " " << children[i].x << ":" << children[i].y << std::endl;
			}
		}
};