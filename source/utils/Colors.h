struct RGB {
    int r;
    int g;
    int b;

    void convert(std::string mode) {
        int high = 0;
        int old_max = 0;
        int new_max = 0;

        if (mode == "255to31") {
            high = 255;
            old_max = 255;
            new_max = 31;
        } else if (mode == "31to255") {
            high = 31;
            old_max = 31;
            new_max = 255;
        }

        this->r = std::clamp(this->r, 0, high);
        this->g = std::clamp(this->g, 0, high);
        this->b = std::clamp(this->b, 0, high);

        this->r = ((double)((double)(((double)this->r) / ((double)old_max))) * ((double)new_max));
        this->g = ((double)((double)(((double)this->g) / ((double)old_max))) * ((double)new_max));
        this->b = ((double)((double)(((double)this->b) / ((double)old_max))) * ((double)new_max));
    }

    void set(u8 r, u8 g, u8 b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

class Colors {
    public:
        // color id 0-15, color 0-255
        static void defineTextRGB(u8 screen, u8 layer, u8 colorId, RGB rgb) {
            rgb.convert("255to31");
            NF_DefineTextColor(screen, layer, colorId, rgb.r, rgb.g, rgb.b);
        }

        static void defineTextHex(u8 screen, u8 layer, u8 colorId, uint hex) {
            RGB rgb = convertHex(hex);
            NF_DefineTextColor(screen, layer, colorId, rgb.r, rgb.g, rgb.b);
        }
    
    private:
        static RGB convertHex(uint hex) {
            RGB rgb;
            rgb.r = (hex & 0xff0000) >> 16;
            rgb.g = (hex & 0x00ff00) >> 8;
            rgb.b = (hex & 0x0000ff);
            rgb.convert("255to31");
            
            return rgb;
        }
};