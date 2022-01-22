#pragma once

#include <random>
#include <sstream>

class DeviceIDGenerator { // I'll finish this later w/ founder
public:
    std::string generate_uuid(uintptr_t seed) {
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

    void ChangeDeviceID(uintptr_t seed) {
//basically we gen a uuid, then replace our currentdid with it. if we can modify login packets we can do it there, otherwise we'll have to modify the profile one.
    }
};
