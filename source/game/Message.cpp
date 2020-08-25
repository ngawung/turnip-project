#include "Message.hpp"

MSG::MSG() {
    
}

void MSG::initialize() {
    // List
    _actionList[0].set_chat(
        "Ferdian",
        "This is action no 1...................."
    );

    _actionList[1].set_chat(
        "Ferdian",
        "This is action no 2...................."
    );

    _actionList[2].set_chat(
        "Ferdian",
        "This is action no 3...................."
    );

    // Map
    _actionMap.insert({ "test", std::vector<uint16_t>{0,1,2} });

}

std::vector<uint16_t>* MSG::getMap(std::string key) {
    for (auto it = _actionMap.find(key); it != _actionMap.end(); it++) {
        return &it->second;
    }
  
    return nullptr;
}

Action* MSG::getAction(uint16_t id) {
    if (id > _actionSize) return nullptr;

    return &_actionList[id];
}