class NGObject {
    public:
        int x;
        int y;
        int rotation;

        bool enableUpdate;

        static int objectNum;
    private:
        int _x;
        int _y;
        int _rotation;

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
            enableUpdate = true;
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
                    NF_Rotate3dSprite(_id, 0, 0, AngleConversion::rotate(rotation));
                    _rotation = rotation;
                }
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

