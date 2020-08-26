#include "Message.hpp"

MSG::MSG() {
    
}

void MSG::initialize() {
    // List
    _actionList[0].set_chat("", "introducing.... npc spawn");

    _actionList[1].set_npcSpawn(0, "ricardo", "ricardo", 0, 192 - 160);
    _actionList[1].set_option(false, true);

    _actionList[2].set_chat("Ricardo", "Its mee.... ricardooo-kyun");

    _actionList[3].set_npcSpawn(1, "ricardo", "ricardo", 256 - 128, 192 - 160, true);
    _actionList[3].set_option(false, true);

    _actionList[4].set_chat("Ricardo 2", "Kyaaaa ricardoo....");

    // Map
    _actionMap.insert({ "test", std::vector<uint16_t>{0,1,2,3,4} });

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