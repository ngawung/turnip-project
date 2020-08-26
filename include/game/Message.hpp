#pragma once

#include <map>
#include <string>
#include <vector>

enum ActionType {
    CHAT_OPEN,
    CHAT_UPDATE,
    CHAT_CLOSE,
    NPC_SPAWN,
    NPC_UPDATE,
    NPC_REMOVE
};

struct Action {
    ActionType type;

    // option
    bool autoSkip = false;
    bool skipOnLoad = false;

    // CHAT
    std::string chat_name;
    std::string chat_msg;
    uint8_t chat_speed;
    
    // NPC
    uint16_t npc_id;
    std::string npc_gfx;
    std::string npc_pal;

    int16_t npc_x;
    int16_t npc_y;
    bool npc_flip;

    void set_option(bool autoSkip, bool skipOnLoad) {
        this->autoSkip = autoSkip;
        this->skipOnLoad = skipOnLoad;
    }

    void set_chatOpen() {
        this->type = ActionType::CHAT_OPEN;
        this->autoSkip = true;
    }

    void set_chatUpdate(std::string name, std::string msg, uint8_t speed = 1) {
        this->type = ActionType::CHAT_UPDATE;
        this->chat_name = name;
        this->chat_msg = msg;
        this->chat_speed = speed;
    }

    void set_chatClose() {
        this->type = ActionType::CHAT_CLOSE;
        this->autoSkip = true;
    }

    void set_npcSpawn(uint16_t id, std::string gfx, std::string pal, int16_t x = 0, int16_t y = 0, bool flip = false) {
        this->type = ActionType::NPC_SPAWN;
        this->npc_id = id;
        this->npc_gfx = gfx;
        this->npc_pal = pal;
        this->npc_x = x;
        this->npc_y = y;
        this->npc_flip = flip;
    }

    void set_npcUpdate(uint16_t id, int16_t x = 0, int16_t y = 0, bool flip = false) {
        this->type = ActionType::NPC_UPDATE;
        this->npc_id = id;
        this->npc_x = x;
        this->npc_y = y;
        this->npc_flip = flip;
    }
};

class MSG {
    public:
    private:
        static inline uint16_t _actionSize = 50;
        static inline Action _actionList[50];
        static inline std::map<std::string, std::vector<uint16_t>> _actionMap;

    public:
        MSG();
        static void initialize();
        static std::vector<uint16_t>* getMap(std::string key);
        static Action* getAction(uint16_t id);
    private:
};



