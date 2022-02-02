#pragma once

class TextPacket : public Packet {
private:
    char gap0[0x28];
    __int8 messageType;
private:
    char pad1[7];
private:
    TextHolder sourceName;
    TextHolder message;
private:
    char pad2[24];
private:
    bool translationNeeded = false;
private:
    char pad3[7];
private:
    TextHolder xboxUserId;
    TextHolder platformChatId;
};