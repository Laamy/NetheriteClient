#pragma once

class TextPacket : public Packet {
private:
    char gap0[0x28];
public:
    __int8 messageType;
private:
    char pad1[7];
public:
    TextHolder sourceName;
    TextHolder message;
private:
    char pad2[24];
public:
    bool translationNeeded = false;
private:
    char pad3[7];
public:
    TextHolder xboxUserId;
    TextHolder platformChatId;
};