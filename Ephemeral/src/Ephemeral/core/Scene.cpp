#include "epch.hpp"
#include "Scene.hpp"

EE::BasicScene::BasicScene() {
    
}

EE::BasicScene::~BasicScene() {
    
}

void EE::BasicScene::preUpdate() {
    // for (uint i=0; i<children.size(); i++) {
    //     children[i]->preUpdate();
    // }

    // update();
}

void EE::BasicScene::destroy() {
    #ifdef DEBUG
        std::cout << "Destroy scene" << std::endl; 
    #endif
    removeChildAll();
}

EE::Object* EE::BasicScene::addChild(Object* child) {
    // switch(child->get_type()) {
    //     case ObjectCategory::SPRITE3D:
    //         if (_type != SceneType::SCENE3D) {
    //             #ifdef DEBUG
    //                 std::cout << "Cannot add child except Sprite3D" << std::endl; 
    //             #endif
    //         }

    //         if (_numSprite3D >= 254) {
    //             #ifdef DEBUG
    //                 std::cout << "Max Sprite3D limit reached" << std::endl; 
    //             #endif
    //             return nullptr;
    //         }
    //         _numSprite3D++;
    //         break;

    //     case ObjectCategory::SPRITE2D:
    //     if (_type != SceneType::SCENE2D) {
    //         #ifdef DEBUG
    //             std::cout << "Cannot add child except Sprite3D" << std::endl; 
    //         #endif
    //     }
        
    //     if (_numSprite2D >= 127) {
    //             #ifdef DEBUG
    //                 std::cout << "Max Sprite2D limit reached" << std::endl; 
    //             #endif
    //             return nullptr;
    //         }
    //         _numSprite2D++;
    //         break;

    //     case ObjectCategory::BMFONT:
    //         break;

    //     case ObjectCategory::TILEDBG:
    //         break;

    //     case ObjectCategory::NONE:
    //         break;
    // }

    // push child
    children.push_back(child);

    // get the last index
    uint index = children.size() - 1;

    // set child id to last index
    child->set_id(index);

    // // set child screen
    // child->set_screen(_screen);

    // initialize child (render)
    child->initialize();

    // return child pointer
    return child;
}

EE::Object* EE::BasicScene::getChildByName(std::string name) {
    for (unsigned int i=0; i<children.size(); i++) { 
        if (children[i]->get_name() == name) {
            return children[i];
        }
    }
    
    return nullptr;
}

EE::Object* EE::BasicScene::getChildbyId(unsigned int id) {
    if (id >= children.size()) return nullptr;
    else return children[id];
}

bool EE::BasicScene::removeChild(Object* child) {
    for (unsigned int i=0; i<children.size(); i++) {
        if (children[i] == child) {
            // if (child->get_type() == ObjectCategory::SPRITE3D) _numSprite3D--;
            // if (child->get_type() == ObjectCategory::SPRITE2D) _numSprite2D--;
            
            child->destroy();
            children.erase(children.begin() + i);
            delete child;
            return true;
        }
    }
    #ifdef DEBUG
        std::cout << "Failed to remove child (" << child->get_name() << ")" << std::endl; 
    #endif
    return false;
}

bool EE::BasicScene::removeChildByName(std::string name) {
    Object* ptr = getChildByName(name);
    if (ptr != nullptr) {
        removeChild(ptr);
        return true;
    } else {
        #ifdef DEBUG
            std::cout << "Failed to remove child byName (" << name << ")" << std::endl; 
        #endif
        return false;
    }
}

bool EE::BasicScene::removeChildById(unsigned int id) {
    Object* ptr = getChildbyId(id);

    if (ptr != nullptr) {
        removeChild(ptr);
        return true;
    } else {
        #ifdef DEBUG
            std::cout << "Failed to remove child byId (" << id << ")" << std::endl; 
        #endif
        return false;
    }
}

bool EE::BasicScene::removeChildAll() {
    for (unsigned int i=0; i<children.size(); i++) {
        children[i]->destroy();
        delete children[i];

        // _numSprite3D = _numSprite2D = 0;
    }

    children.clear();
    return true;
}

// // Textlayer

// bool EE::Scene::textlayer_check(uint8_t layer) { 
//     return _TextLayer[layer];
// }

// void EE::Scene::textlayer_create(uint8_t layer, const char* fontname = "font", uint8_t rotation = 0) {
//     NF_CreateTextLayer(_screen, layer, rotation, fontname);
// }

// void EE::Scene::textlayer_remove(uint8_t layer) {
//     NF_DeleteTextLayer(_screen, layer);
// }

// void EE::Scene::textlayer_reset() {
//     // this also reset the text system
//     NF_InitTextSys(_screen);
// }