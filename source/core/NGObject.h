class NGObject {
    public:
        int x;
        int y;

        static int objectNum;
    private:
        std::string _name;
    
    public:
        NGObject(std::string name) {
            _name = name;
        }

        std::string getName() {
            return _name;
        }
};

