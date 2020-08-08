class TransformObject {
    public:
        // covert 0-360 to 0-512
        static int rotate(int angle) {
            // reduce the angle  
            angle =  angle % 360; 

            // force it to be the positive remainder, so that 0 <= angle < 360  
            angle = (angle + 360) % 360;

            int old_max = 360;
            int new_max = 512;

            return ((double)((double)(((double)angle) / ((double)old_max))) * ((double)new_max));
        }

        // convert 0-800% to 0-64-512 (64 = 100%)
        static int scale(int value) {
            value = std::clamp(value, 0, 800);

            int old_max = 800;
            int new_max = 512;

            return ((double)((double)(((double)value) / ((double)old_max))) * ((double)new_max));
        }
};