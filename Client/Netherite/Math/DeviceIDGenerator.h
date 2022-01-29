#pragma once

#include <random>
#include <sstream>

class DeviceIDGenerator { // I'll finish this later w/ founder
public:
    const static std::string generate_uuid(uintptr_t seed) {
        std::mt19937                    gen(seed);
        std::uniform_int_distribution<> dis(0, 15);
        std::uniform_int_distribution<> dis2(8, 11);

        std::stringstream ss;
        ss.clear();
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) ss << dis(gen);
        ss << "-";
        for (i = 0; i < 4; i++) ss << dis(gen);
        ss << "-4";
        for (i = 0; i < 3; i++) ss << dis(gen);
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) ss << dis(gen);
        ss << "-";
        for (i = 0; i < 12; i++) ss << dis(gen);
        return ss.str();
    };

    const static void ChangeDeviceID(uintptr_t seed) {
        auto base = (uintptr_t)(GetModuleHandleA("Minecraft.Windows.exe")) + 0x0421B218;
        auto didPtr = MCM::findMultiLvlPtr(base, { 0x0, 0x20, 0x0 });

        MCM::setString((void*)didPtr, TextHolder(generate_uuid(seed)), 1080);
    }
};
