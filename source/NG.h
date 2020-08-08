#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>


// utils
#include "utils/TransformObject.h"
#include "utils/Assets.h"
#include "utils/Colors.h"

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