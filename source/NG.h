#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>

// lib
#include "lib/simplenfl.h"
// #include "lib/tweeny-3.1.1.h"

// utils
#include "utils/TransformObject.h"
#include "utils/Assets.h"
#include "utils/Colors.h"
#include "utils/Random.h"
#include "utils/Constant.h"

// core
#include "core/NGObject.h"
#include "core/NGScene.h"
#include "core/NGMain.h"

//scene
#include "scene/scene1.h"
#include "scene/scene2.h"

namespace NG {
    // Quick log to console
    void log(std::string log) {
        std::cout << log << std::endl;
    }

    // return number for easier read
    u16 getId(u16 id) {
        return id;
    }

}