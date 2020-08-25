#pragma once

#include <map>
#include <string>
#include <vector>

enum ActionType {
    CHAT
};

struct Action {
    ActionType type;

    // CHAT
    std::string name;
    std::string chat;


    void set_chat(std::string name, std::string chat) {
        this->name = name;
        this->chat = chat;
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



