class NGObject {
	public:
		int x;
		int y;
		int rotation;
		int scaleX;
		int scaleY;
		int layer;
		int frame;
		int delay;

		bool enableUpdate;
		bool enableAnimation;

		static int objectNum;
	private:
		int _x;
		int _y;
		int _rotation;
		int _scaleX;
		int _scaleY;
		int _layer;
		int _frame;

		std::map<std::string, std::vector<int>> _animationData;
		std::string _currentPlay;
		int _currentFrame;
		int _currentDelay;

		std::string _name;
		u16 _sprite;
		u16 _pallete;
		u16 _id;
	
	public:
		NGObject(std::string name, u16 sprite, u16 pallete) {
			_name = name;
			_sprite = sprite;
			_pallete = pallete;

			x = _x = 0;
			y = _y = 0;
			rotation = _rotation = 0;
			scaleX = _scaleX = 100;
			scaleY = _scaleY = 100;
			layer = _layer = -1;

			frame = _frame;
			enableUpdate = true;
			enableAnimation = false;
			delay = _currentDelay = 0;
		}

		void draw(u16 id) {
			_id = id;

			NF_Create3dSprite(_id, _sprite, _pallete, x, y);
		}

		void update() {
			if (enableUpdate) {
				if (_x != x || _y != y) {
					NF_Move3dSprite(_id, x, y);
					_x = x;
					_y = y;
				}

				if (_rotation != rotation) {
					NF_Rotate3dSprite(_id, 0, 0, TransformObject::rotate(rotation));
					_rotation = rotation;
				}

				if (_scaleX != scaleX || _scaleY != scaleY) {
					NF_Scale3dSprite(_id, TransformObject::scale(scaleX), TransformObject::scale(scaleY));
					_scaleX = scaleX;
					_scaleY = scaleY;
				}

				if (_layer != layer) {
					if (layer > 512) layer = 512;
					if (layer < -512) layer = -512;
					std::cout << "layer " << -layer << std::endl;
					NF_3dSpriteSetDeep(_id, -layer);
					_layer = layer;
				}

				if (_frame != frame) {
					if (frame < 0) frame = 0;
					NF_Set3dSpriteFrame(_id, frame);
				}

				if (enableAnimation) {
					frame = _animationData.find(_currentPlay)->second[_currentFrame];
					_currentDelay++;
					if (_currentDelay > delay) {
						_currentDelay = 0;
						_currentFrame++;
						if (_currentFrame > ((int)_animationData.find(_currentPlay)->second.size() - 1)) {
							_currentFrame = 0;
						}
					}
				}
			}
		}

		void destroy() {
			NF_Delete3dSprite(_id);
		}

		// Animation stuff

		void addAnimation(std::string name, std::vector<int> frames) {
			_animationData.insert({name, frames});
		}

		void updateAnimation(std::string name, std::vector<int> frames) {
			auto it = _animationData.find(name);
			if (it != _animationData.end()) {
				it->second = frames;
			} else {
				std::cout << "Cannot find " << name << " animation" << std::endl;
			}
		}

		void removeAnimation(std::string name) {
			_animationData.erase(name);
		}

		void clearAnimation(std::string name) {
			_animationData.clear();
			reset();
		}

		void quickPlay(std::vector<int> frames, int frameskip = 0) {
			auto it = _animationData.find("_quick");
			if (it != _animationData.end()) {
				it->second = frames;
			} else {
				addAnimation("_quick", frames);
			}

			play("_quick", frameskip);
		}

		void play(std::string name, int frameskip = 0) {
			auto it = _animationData.find(name);
			if (it != _animationData.end()) {
				_currentPlay = it->first;
				_currentFrame = 0;
				frame = it->second[0];
				delay = frameskip;
				enableAnimation = true;
			} else {
				std::cout << "Cannot find " << name << " animation" << std::endl;
			}
		}

		void stop(std::string name) {
			auto it = _animationData.find(name);
			if (it != _animationData.end()) {
				_currentPlay = it->first;
				frame = it->second[0];
				enableAnimation = false;
			} else {
				std::cout << "Cannot find " << name << " animation" << std::endl;
			}
		}

		void reset() {
			frame = 0;
			enableAnimation = false;
		}

		std::string getName() {
			return _name;
		}

		u16 getId() {
			return _id;
		}

};

