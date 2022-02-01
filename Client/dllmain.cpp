#pragma region Imports

// import windows
#include <vcruntime_string.h>
#include <corecrt_malloc.h>
#include <windows.h>
#include <Psapi.h>
#include <cstdint>
#include <string>
#include <map>
#include <vector>
#include <random>
#include <sstream>
#include <cassert>

// import key math
#include "Netherite/Math/ExtraKeys.h"

// import subSDK
#include "Memory/SDK/SubSDK/TextHolder.h"

// import other
#include <MinHook.h>
#include "Memory/MCM.h"

// Library Information
HMODULE DLLModule;
/*HMODULE GetDllHMod() {
    MEMORY_BASIC_INFORMATION info;
    size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)GetDllHMod, &info, sizeof(info));
    assert(len == sizeof(info));
    return len ? (HMODULE)info.AllocationBase : NULL;
}*/
void DestoryClient() {
    MH_DisableHook(MH_ALL_HOOKS);
    MH_RemoveHook(MH_ALL_HOOKS);
    FreeLibraryAndExitThread(DLLModule, 0);
}

#include "Netherite/Notifications/Notification.h"

std::vector<Notification> notifications;

void CreateNotification(const char* text, float timer = 5)
{
    notifications.push_back(Notification(text, timer));
}

bool c = false;
uint64_t c_value;

// import math
// AABB.h
#include "Netherite/Math/CaretMeasureData.h"
#include "Netherite/Math/UIColor.h"
#include "Netherite/Math/Vector2.h"
#include "Netherite/Math/Vector3.h"
#include "Netherite/Math/Vector3i.h"
#include "Netherite/Math/Vector4.h"
#include "Netherite/Math/DeviceIDGenerator.h"


#include <algorithm>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_relational.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/mat4x4.hpp>
#include <glm/trigonometric.hpp>

#include "Netherite/Math/AABB.h" // requires Vector3

// hooks
#include "Memory/Hooks/VirtualHook.h"
#include "Memory/Hooks/GameHook.h"

// import sdk
#include "Memory/SDK/Block.h"
#include "Memory/SDK/GameMode.h"
#include "Memory/SDK/CompoundTag.h"
#include "Memory/SDK/Weather.h"
#include "Memory/SDK/Actor.h"
#include "Memory/SDK/Dimension.h"
#include "Memory/SDK/BlockSource.h"
#include "Memory/SDK/Level.h"
#include "Memory/SDK/BitmapFont.h"
#include "Memory/SDK/HIDController.h"
#include "Memory/SDK/GuiData.h"
#include "Memory/SDK/MinecraftGame.h"

std::map<uint64_t, Actor*> entitylist = std::map<uint64_t, Actor*>();

#include "Memory/SDK/ClientInstance.h"
#include "Memory/SDK/MinecraftUIRenderContext.h"

// import USDK
#include "Memory/Utils/DrawUtils.h"

// client/SDK handlers
#include "Netherite/Handlers/SubRenderContextHandle.h"

// SDK help
GameMode* _gm = nullptr;
ClientInstance* clientInst = nullptr;
Level* level = nullptr;
HIDController* controllerInst = nullptr;
DrawUtils* renderer = nullptr;

#include "Netherite/Math/GameCursors.h"

// pointers
std::vector<class Module*>* _modules;
std::map<std::string, Vector2>* _categories;

// maps
std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

// module stuff
#include "Netherite/Module/ModuleOption.h"
#include "Netherite/Module/ModuleSettings/ModuleSetting.h"
#include "Netherite/Module/ModuleSettings/ModuleSlider.h"
#include "Netherite/Command/Command.h"
#include "Netherite/Command/CommandManager.h"
#include "Netherite/Module/Module.h"
#include "Netherite/Module/ModuleManager.h"

#pragma endregion

// handlers
SubRenderContextHandle subRenderer = SubRenderContextHandle();
class ModuleManager moduleManager;

#pragma region MainHooks Define

typedef void(__thiscall* ClientInstanceHook)(ClientInstance*, void*);
typedef void(__thiscall* RenderContextHook)(void*, MinecraftUIRenderContext*);
typedef void(__thiscall* KeymapHook)(uintptr_t, bool);
typedef void(__thiscall* HIDControllerHook)(HIDController*, void*, void*);
typedef void(__thiscall* SplashTickHook)(uintptr_t, const char*);
typedef void(__thiscall* ActorTickHook)(Actor*, void*);
typedef void(__thiscall* _GameModeHook)(GameMode*);
typedef void(__thiscall* SendChatHook)(void*, TextHolder);
typedef void(__thiscall* BobViewHook)(uintptr_t, glm::mat4x4&, uintptr_t);

ClientInstanceHook _CIHook;
RenderContextHook _RCHook;
KeymapHook _SendKey;
HIDControllerHook _TickController;
SplashTickHook _SplashCharacter;
ActorTickHook _TickActor;
_GameModeHook _GameMode;
SendChatHook _SendChat;
BobViewHook _BobViewTick;

#pragma endregion

#pragma region MainHooks

void BobViewCallback(uintptr_t a1, glm::mat4x4 &matrix, uintptr_t a3) {

    glm::mat4 View = matrix;
    matrix = View;

    for (auto mod : moduleManager.modules) {
        if (mod->enabled && mod->name == "FakeBlocking")
        {
            if (controllerInst->rightClickDown) {
                matrix = glm::rotate<float>(matrix, 2, glm::vec3(-0.5f, 0.5f, 0.5f));
                matrix = glm::translate<float>(matrix, glm::vec3(0, 0, 0.3f));
            }
        }
        if (mod->enabled && mod->name == "Killaura") // autoblock
        {
            if (controllerInst->rightClickDown && mod->moduleSettings[2]->currentIndex == 1) {
                matrix = glm::rotate<float>(matrix, 2, glm::vec3(-0.5f, 0.5f, 0.5f));
                matrix = glm::translate<float>(matrix, glm::vec3(0, 0, 0.3f));
            }
        }
        if (mod->enabled && mod->name == "Animations" && mod->moduleSettings[1]->currentIndex == 1)
        {
            matrix = glm::rotate<float>(matrix, 2, glm::vec3(-0.6f, 0.6f, 0.6f));
            matrix = glm::translate<float>(matrix, glm::vec3(0, 0.3f, 0.6f));
        }
    }

    _BobViewTick(a1, matrix, a3);
}

float GameModeCallback(GameMode* gm) {
    _gm = gm;
    _GameMode(gm);

    for (auto mod : moduleManager.modules)
        if (mod->enabled && clientInst->getLocalPlayer() != nullptr)
            mod->onGameTick(gm);

    for (auto mod : moduleManager.modules)
        if (mod->enabled && mod->name == "BlockReach")
            return 256;
    return 6;
}

void ActorTickCallback(Actor* ent, void* a2) {
    entitylist[reinterpret_cast<uintptr_t>(ent)] = ent;
}

void ClientInstanceCallback(ClientInstance* ci, void* a2) {
    clientInst = ci;
    _CIHook(ci, a2);
}

void ChatPallWack(void* a1, TextHolder txt) {
    _SendChat(a1, txt);
}

int frames = 0;
void RenderContextCallback(void* a1, MinecraftUIRenderContext* ctx) {

    renderer = new DrawUtils();

    GameCursors::HandRenderer(renderer);

    auto font = clientInst->mcGame->mcFont;
    auto guiDat = clientInst->getGuiData();

    renderer->Init(ctx, guiDat, font); // setup render utils

    _RCHook(a1, ctx);

    frames++;
    if (frames == 3) {
        frames = 0;

        subRenderer.OnRender(renderer);

        for (auto mod : moduleManager.modules)
            if (mod->enabled && mod->name != "ClickGUI")
                mod->onThirdFrameRender(renderer);
        for (auto mod : moduleManager.modules)
            if (mod->enabled && mod->name == "ClickGUI") {
                mod->onThirdFrameRender(renderer);
                *clientInst->getLocalPlayer()->getSwingState() = 0;
            }
    }

    for (auto mod : moduleManager.modules)
        if (mod->enabled)
            mod->onFrameRender(renderer);
}

void KeymapCallback(uint64_t key, bool held) {

    if (keymap[GameInput::KEY_CTRL] && key == GameInput::KEY_L && held) // only eject if control was pressed before L
        DestoryClient();

    bool handled = false;
    for (auto mod : *_modules) {
        if (mod->keybind == key &&
            mod->keybindTogglable && held) {
            if (clientInst->mcGame->canUseMoveKeys()) {
                mod->enabled = !mod->enabled;
                if (mod->enabled)
                    mod->onEnable();
                else mod->onDisable();

                if (mod->name == "ClickGUI") handled = true;
            }
        }
    }
    for (auto mod : moduleManager.modules)
        if (mod->enabled && mod->name == "ClickGUI" && !handled && held) {
            if (key == GameInput::KEY_ESC) {
                mod->enabled = !mod->enabled;
                mod->onDisable();
            }
            else if (key == mod->keybind) {
                mod->enabled = !mod->enabled;
                mod->onDisable();
            }
        }

    for (auto note : notifications)
    {
        if (note.timer == 0) {
            note.fade -= 1;
        }
        //if (note.fade = 60)
        //    notifications.
    }

    _SendKey(key, held);
    keymap[key] = held;
}

void ControllerTickCallback(HIDController* controller, void* a2, void* a3) {
    _TickController(controller, a2, a3);
    controllerInst = controller;
}

void SplashTickCharacter(uintptr_t a1, const char* curChar) {
    _SplashCharacter(a1, curChar); // 16
}

#pragma endregion

void moduleThread(LPVOID a) {
    while (true) {
        if (clientInst == nullptr) continue;

        for (auto mod : moduleManager.modules)
            if (mod->enabled)
                mod->onCITick(clientInst);
        Sleep(1);
    }
};

void onTickTimer(LPVOID a) {
    while (true) {
        Sleep(50);
        if (clientInst == nullptr) continue;

        for (auto mod : moduleManager.modules)
            if (mod->enabled)
                mod->onTick();

        for (auto note : notifications)
            if (note.timer != 0)
                note.timer -= 1 / 20; // 20 ticks :)
    }
};

void Init(LPVOID c) { // when the dllmain is bri ish
    if (MH_Initialize() == MH_OK) {
        moduleManager.Initialize();

        uintptr_t clientinstance_Addr = MCM::findSig(GameSigs::SIG_ClientInstance);
        if (MH_CreateHook((void*)clientinstance_Addr, &ClientInstanceCallback, reinterpret_cast<LPVOID*>(&_CIHook)) == MH_OK) {
            MH_EnableHook((void*)clientinstance_Addr);
        };

        uintptr_t bobview_Addr = MCM::findSig(GameSigs::SIG_BobView);
        if (MH_CreateHook((void*)bobview_Addr, &BobViewCallback, reinterpret_cast<LPVOID*>(&_BobViewTick)) == MH_OK) {
            MH_EnableHook((void*)bobview_Addr);
        };

        uintptr_t gamdeMode_Addr = MCM::findSig(GameSigs::SIG_GameModeHook);
        if (MH_CreateHook((void*)gamdeMode_Addr, &GameModeCallback, reinterpret_cast<LPVOID*>(&_GameMode)) == MH_OK) {
            MH_EnableHook((void*)gamdeMode_Addr);
        };

        uintptr_t renderContext_Addr = MCM::findSig(GameSigs::SIG_RenderContext);
        if (MH_CreateHook((void*)renderContext_Addr, &RenderContextCallback, reinterpret_cast<LPVOID*>(&_RCHook)) == MH_OK) {
            MH_EnableHook((void*)renderContext_Addr);
        };

        uintptr_t keymap_Addr = MCM::findSig(GameSigs::SIG_Keymap);
        if (MH_CreateHook((void*)keymap_Addr, &KeymapCallback, reinterpret_cast<LPVOID*>(&_SendKey)) == MH_OK) {
            MH_EnableHook((void*)keymap_Addr);
        };

        uintptr_t controller_Addr = MCM::findSig(GameSigs::SIG_Controller);
        if (MH_CreateHook((void*)controller_Addr, &ControllerTickCallback, reinterpret_cast<LPVOID*>(&_TickController)) == MH_OK) {
            MH_EnableHook((void*)controller_Addr);
        };

        uintptr_t menusplash_Addr = MCM::findSig(GameSigs::SIG_MenuSplash);
        if (MH_CreateHook((void*)menusplash_Addr, &SplashTickCharacter, reinterpret_cast<LPVOID*>(&_SplashCharacter)) == MH_OK) {
            MH_EnableHook((void*)menusplash_Addr);
        };

        uintptr_t entitylist_addr = MCM::findSig(GameSigs::SIG_EntityList_Stablized);
        if (MH_CreateHook((void*)entitylist_addr, &ActorTickCallback, reinterpret_cast<LPVOID*>(&_TickActor)) == MH_OK) {
            MH_EnableHook((void*)entitylist_addr);
        };

        uintptr_t sendChat_Addr = MCM::findSig(GameSigs::SIG_ChatSend);
        if (MH_CreateHook((void*)sendChat_Addr, &ChatPallWack, reinterpret_cast<LPVOID*>(&_SendChat)) == MH_OK) {
            //MH_EnableHook((void*)sendChat_Addr);
        };

        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)moduleThread, c, 0, 0);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)onTickTimer, c, 0, 0);

    }
}

BOOL APIENTRY DllMain(HMODULE a, DWORD b, LPVOID c)
{
    DLLModule = a;
    if (b == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, a, 0, 0);
    return TRUE;
}