#include "epch.hpp"
#include "Scene.hpp"

EE::Scene::Scene()
    : _type(SceneType::NOT_DEFINED), _numSprite2D(0), _numSprite3D(0)
{

}

EE::Scene::~Scene() {

}

void EE::Scene::preUpdate() {
    for (uint i=0; i<children.size(); i++) {
        children[i]->preUpdate();
    }

    update();
}

void EE::Scene::destroy() {
    dbg("destroy scene");
    removeChildAll();
}

EE::Object* EE::Scene::addChild(Object* child) {
    switch(child->get_type()) {
        case ObjectCategory::SPRITE3D:
            if (_numSprite3D > 254) {
                dbg("Max Sprite3D limit reached");
                return nullptr;
            }
            _numSprite3D++;
            break;

        case ObjectCategory::SPRITE2D:
        if (_numSprite2D > 127) {
                dbg("Max Sprite2D limit reached");
                return nullptr;
            }
            _numSprite2D++;
            break;

        case ObjectCategory::BMFONT:
            break;

        case ObjectCategory::TILEDBG:
            break;

        case ObjectCategory::NONE:
            break;
    }

    // push child
    children.push_back(child);

    // get the last index
    uint index = children.size() - 1;

    // set child id to last index
    child->set_id(index);

    // set child screen
    child->set_screen(_screen);

    // initialize child (render)
    child->initialize();

    // return child pointer
    return child;
}

EE::Object* EE::Scene::getChildByName(std::string name) {
    for (unsigned int i=0; i<children.size(); i++) { 
        if (children[i]->get_name() == name) {
            return children[i];
        }
    }
    
    return nullptr;
}

EE::Object* EE::Scene::getChildbyId(unsigned int id) {
    if (id >= children.size()) return nullptr;
    else return children[id];
}

bool EE::Scene::removeChild(Object* child) {
    for (unsigned int i=0; i<children.size(); i++) {
        if (children[i] == child) {
            if (child->get_type() == ObjectCategory::SPRITE3D) _numSprite3D--;
            if (child->get_type() == ObjectCategory::SPRITE2D) _numSprite2D--;
            
            child->destroy();
            children.erase(children.begin() + i);
            delete child;
            return true;
        }
    }
    dbg("Failed to remove child");
    return false;
}

bool EE::Scene::removeChildByName(std::string name) {
    Object* ptr = getChildByName(name);
    if (ptr != nullptr) {
        removeChild(ptr);
        return true;
    } else {
        dbg(std::string("Failed to remove ") + name);
        return false;
    }
}

bool EE::Scene::removeChildById(unsigned int id) {
    Object* ptr = getChildbyId(id);

    if (ptr != nullptr) {
        removeChild(ptr);
        return true;
    } else {
        dbg(std::string("Failed to remove id ") + std::to_string(id));
        return false;
    }
}

bool EE::Scene::removeChildAll() {
    for (unsigned int i=0; i<children.size(); i++) {
        children[i]->destroy();
        delete children[i];

        _numSprite3D = _numSprite2D = 0;
    }

    children.clear();
    return true;
}

// Textlayer

bool EE::Scene::textlayer_check(uint8_t layer) { 
    return _TextLayer[layer];
}

void EE::Scene::textlayer_create(uint8_t layer, const char* fontname = "font", uint8_t rotation = 0) {
    NF_CreateTextLayer(_screen, layer, rotation, fontname);
}

void EE::Scene::textlayer_remove(uint8_t layer) {
    NF_DeleteTextLayer(_screen, layer);
}

void EE::Scene::textlayer_reset() {
    // this also reset the text system
    NF_InitTextSys(_screen);
}