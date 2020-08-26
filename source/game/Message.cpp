#include "Message.hpp"

MSG::MSG() {
    
}

void MSG::initialize() {
    // List
    _actionList[0].set_chatOpen();

    _actionList[1].set_chatUpdate("", "introducing.... npc spawn");

    _actionList[2].set_chatClose();

    _actionList[3].set_npcSpawn(0, "ricardo", "ricardo", -128, 192 - 160);
    _actionList[3].set_option(false, true);

    _actionList[4].set_npcUpdate(0, 0, 192 - 160, false);
    _actionList[4].set_option(false, true);

    _actionList[5].set_chatOpen();

    _actionList[6].set_chatUpdate("Ricardo", "Its me..... Ricardooo-kyuun");

    _actionList[7].set_chatClose();

    _actionList[8].set_npcSpawn(1, "ricardo", "ricardo", 256 + 128, 192 - 160, true);
    _actionList[8].set_option(false, true);

    _actionList[9].set_npcUpdate(1, 256 - 128, 192 - 160, false);
    _actionList[9].set_option(false, true);

    _actionList[10].set_chatOpen();

    _actionList[11].set_chatUpdate("Ricardo 2", "Kyaaaa ricardoo....");

    _actionList[12].set_chatUpdate("", "");
    _actionList[12].set_option(false, true);

    // Map
    _actionMap.insert({ "test", std::vector<uint16_t>{0,1,12,2,3,4,5,6,12,7,8,9,10,11} });

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