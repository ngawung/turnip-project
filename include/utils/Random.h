#pragma once

#include <string>

class Random {
    public:
        // generate random string
        static std::string string(size_t length);
        
        // random 0-1
        static float simple();

        // random 0-max
        static int range(int max);
    private:
};