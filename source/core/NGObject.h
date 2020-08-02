class NGObject {
    public:
        int x;
        int y;

        bool enableUpdate;

        static int objectNum;
    private:
        std::string _name;
        u16 _sprite;
        u16 _pallete;
        u16 _id;
    
    public:
        NGObject(std::string name, u16 sprite, u16 pallete) {
            _name = name;
            _sprite = sprite;
            _pallete = pallete;

            x = 0;
            y = 0;
            enableUpdate = false;
        }

        ~NGObject() {
            
        }

        void draw(u16 id) {
            _id = id;

            std::cout << "draw at " << _id << std::endl;

            NF_Create3dSprite(_id, _sprite, _pallete, x, y);
        }

        void update() {
            if (enableUpdate) {
                NF_Move3dSprite(_id, x, y);
            }
        }

        void destroy() {
            NF_Delete3dSprite(_id);
        }

        std::string getName() {
            return _name;
        }

        u16 getId() {
            return _id;
        }

};

