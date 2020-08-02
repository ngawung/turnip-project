#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


// utils
#include "utils/TransformObject.h"
#include "utils/Assets.h"

// core
#include "core/NGObject.h"
#include "core/NGScene.h"

namespace NG {

    struct StageDimension {
        uint width = 256;
        uint height = 192;
    };

    // Quick log to console
    void log(std::string log) {
        std::cout << log << std::endl;
    }

    // return number for easier read
    u16 getId(u16 id) {
        return id;
    }

}