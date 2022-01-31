#pragma once

// Key ID's
/*


std::map<uint64_t, std::string> keymapNames;
void VF_c() {

	keymapNames[7] = "None";
	keymapNames[8] = "Backspace";
	keymapNames[9] = "Tab";

	keymapNames[13] = "Enter";

	keymapNames[16] = "Shift";
	keymapNames[17] = "Ctrl";
	keymapNames[18] = "Alt";
	keymapNames[19] = "Pause";
	keymapNames[20] = "CapsLock";

	keymapNames[27] = "Esc";

	keymapNames[32] = "Space";
	keymapNames[33] = "PageV";
	keymapNames[34] = "Page^";
	keymapNames[35] = "End";
	keymapNames[36] = "Home";
	keymapNames[37] = "<_Arrow";
	keymapNames[38] = "^_Arrow";
	keymapNames[39] = ">_Arrow";
	keymapNames[40] = "V_Arrow";

	keymapNames[44] = "PrtScn";
	keymapNames[45] = "Insert";
	keymapNames[46] = "Delete";

	keymapNames[48] = "0";
	keymapNames[49] = "1";
	keymapNames[50] = "2";
	keymapNames[51] = "3";
	keymapNames[52] = "4";
	keymapNames[53] = "5";
	keymapNames[54] = "6";
	keymapNames[55] = "7";
	keymapNames[56] = "8";
	keymapNames[57] = "9";

	keymapNames[65] = "A";
	keymapNames[66] = "B";
	keymapNames[67] = "C";
	keymapNames[68] = "D";
	keymapNames[69] = "E";
	keymapNames[70] = "F";
	keymapNames[71] = "G";
	keymapNames[72] = "H";
	keymapNames[73] = "I";
	keymapNames[74] = "J";
	keymapNames[75] = "K";
	keymapNames[76] = "L";
	keymapNames[77] = "M";
	keymapNames[78] = "N";
	keymapNames[79] = "O";
	keymapNames[80] = "P";
	keymapNames[81] = "Q";
	keymapNames[82] = "R";
	keymapNames[84] = "S";
	keymapNames[85] = "U";
	keymapNames[86] = "V";
	keymapNames[87] = "W";
	keymapNames[88] = "X";
	keymapNames[89] = "Y";
	keymapNames[90] = "Z";

	keymapNames[96] = "NumPad0";
	keymapNames[97] = "NumPad1";
	keymapNames[98] = "NumPad2";
	keymapNames[99] = "NumPad3";
	keymapNames[100] = "NumPad4";
	keymapNames[101] = "NumPad5";
	keymapNames[102] = "NumPad6";
	keymapNames[103] = "NumPad7";
	keymapNames[104] = "NumPad8";
	keymapNames[105] = "NumPad9";
	keymapNames[106] = "NumPad*";
	keymapNames[107] = "NumPad+";

	keymapNames[109] = "NumPad-";
	keymapNames[110] = "NumPad.";
	keymapNames[111] = "NumPad/";
	keymapNames[112] = "F1";
	keymapNames[113] = "F2";
	keymapNames[114] = "F3";
	keymapNames[115] = "F4";
	keymapNames[116] = "F5";
	keymapNames[117] = "F6";
	keymapNames[118] = "F7";
	keymapNames[119] = "F8";
	keymapNames[120] = "F9";
	keymapNames[121] = "F10";
	keymapNames[122] = "F11";
	keymapNames[123] = "F12";
	keymapNames[124] = "F13";
	keymapNames[125] = "F14";
	keymapNames[126] = "F15";
	keymapNames[127] = "F16";
	keymapNames[128] = "F17";
	keymapNames[129] = "F18";
	keymapNames[130] = "F19";
	keymapNames[131] = "F20";
	keymapNames[132] = "F21";
	keymapNames[133] = "F22";
	keymapNames[134] = "F23";
	keymapNames[135] = "F24";

	keymapNames[144] = "Numpad";
	keymapNames[145] = "ScrlLock";

	keymapNames[186] = ";";
	keymapNames[187] = "=";

	keymapNames[189] = "-";
	keymapNames[190] = ".";
	keymapNames[191] = "/";

	keymapNames[0x300] = "SpcPkt";
};

*/

class GameInput {
public: // keys
	static const uintptr_t KEY_NONE = 7; // No key
	static const uintptr_t KEY_BACKSPACE = 8; // Backspace key
	static const uintptr_t KEY_TAB = 9; // Tab key

	static const uintptr_t KEY_ENTER = 13; // Enter key

	static const uintptr_t KEY_SHIFT = 16; // Shift key
	static const uintptr_t KEY_CTRL = 17; // Control key
	static const uintptr_t KEY_ALT = 18; // Alt key
	static const uintptr_t KEY_PAUSE = 19; // Pause key
	static const uintptr_t KEY_CAPSLOCK = 20; // CapsLock key

	static const uintptr_t KEY_ESC = 27; // Escape key

	static const uintptr_t KEY_SPACEBAR = 32; // SpaceBar key
	static const uintptr_t KEY_PAGEUP = 33; // PageUp key
	static const uintptr_t KEY_PAGEDOWN = 34; // PageDown key
	static const uintptr_t KEY_END = 35; // End key
	static const uintptr_t KEY_HOME = 36; // Home key
	static const uintptr_t KEY_ARROW_LEFT = 37; // LeftArrow key
	static const uintptr_t KEY_ARROW_UP = 38; // UpArrow key
	static const uintptr_t KEY_ARROW_RIGHT = 39; // RightArrow key
	static const uintptr_t KEY_ARROW_DOWN = 40; // DownArrow key

	static const uintptr_t KEY_PRINTSCRN = 44; // PrintScreen key
	static const uintptr_t KEY_INSERT = 45; // Insert key
	static const uintptr_t KEY_DELETE = 46; // Delete key

	static const uintptr_t KEY_0 = 48; // 0 key
	static const uintptr_t KEY_1 = 49; // 1 key
	static const uintptr_t KEY_2 = 50; // 2 key
	static const uintptr_t KEY_3 = 51; // 3 key
	static const uintptr_t KEY_4 = 52; // 4 key
	static const uintptr_t KEY_5 = 53; // 5 key
	static const uintptr_t KEY_6 = 54; // 6 key
	static const uintptr_t KEY_7 = 55; // 7 key
	static const uintptr_t KEY_8 = 56; // 8 key
	static const uintptr_t KEY_9 = 57; // 9 key

	static const uintptr_t KEY_A = 65; // A key
	static const uintptr_t KEY_B = 66; // B key
	static const uintptr_t KEY_C = 67; // C key
	static const uintptr_t KEY_D = 68; // D key
	static const uintptr_t KEY_E = 69; // E key
	static const uintptr_t KEY_F = 70; // F key
	static const uintptr_t KEY_G = 71; // G key
	static const uintptr_t KEY_H = 72; // H key
	static const uintptr_t KEY_I = 73; // I key
	static const uintptr_t KEY_J = 74; // J key
	static const uintptr_t KEY_K = 75; // K key
	static const uintptr_t KEY_L = 76; // L key
	static const uintptr_t KEY_M = 77; // M key
	static const uintptr_t KEY_N = 78; // N key
	static const uintptr_t KEY_O = 79; // O key
	static const uintptr_t KEY_P = 80; // P key
	static const uintptr_t KEY_Q = 81; // Q key
	static const uintptr_t KEY_R = 82; // R key
	static const uintptr_t KEY_S = 83; // S key
	static const uintptr_t KEY_U = 85; // U key
	static const uintptr_t KEY_V = 86; // V key
	static const uintptr_t KEY_W = 87; // W key
	static const uintptr_t KEY_Y = 88; // Y key
	static const uintptr_t KEY_X = 89; // X key
	static const uintptr_t KEY_Z = 90; // Z key

	static const uintptr_t KEY_NUMPAD_0 = 96; // NumberPad0 key
	static const uintptr_t KEY_NUMPAD_1 = 97; // NumberPad1 key
	static const uintptr_t KEY_NUMPAD_2 = 98; // NumberPad2 key
	static const uintptr_t KEY_NUMPAD_3 = 99; // NumberPad3 key
	static const uintptr_t KEY_NUMPAD_4 = 100; // NumberPad4 key
	static const uintptr_t KEY_NUMPAD_5 = 101; // NumberPad5 key
	static const uintptr_t KEY_NUMPAD_6 = 102; // NumberPad6 key
	static const uintptr_t KEY_NUMPAD_7 = 103; // NumberPad7 key
	static const uintptr_t KEY_NUMPAD_8 = 104; // NumberPad8 key
	static const uintptr_t KEY_NUMPAD_9 = 105; // NumberPad9 key
	static const uintptr_t KEY_NUMPAD_TIMES = 106; // NumberPad* key
	static const uintptr_t KEY_NUMPAD_PLUS = 107; // NumberPad+ key

	static const uintptr_t KEY_NUMPAD_MINUS = 109; // NumberPad- key
	static const uintptr_t KEY_NUMPAD_FULLSTOP = 110; // NumberPad. key
	static const uintptr_t KEY_NUMPAD_SLASH = 111; // NumberPad/ key
	static const uintptr_t KEY_F1 = 112; // F1 key
	static const uintptr_t KEY_F2 = 113; // F2 key
	static const uintptr_t KEY_F3 = 114; // F3 key
	static const uintptr_t KEY_F4 = 115; // F4 key
	static const uintptr_t KEY_F5 = 116; // F5 key
	static const uintptr_t KEY_F6 = 117; // F6 key
	static const uintptr_t KEY_F7 = 118; // F7 key
	static const uintptr_t KEY_F8 = 119; // F8 key
	static const uintptr_t KEY_F9 = 120; // F9 key
	static const uintptr_t KEY_F10 = 121; // F10 key
	static const uintptr_t KEY_F11 = 122; // F11 key
	static const uintptr_t KEY_F12 = 123; // F12 key
	static const uintptr_t KEY_F13 = 124; // F13 key
	static const uintptr_t KEY_F14 = 125; // F14 key
	static const uintptr_t KEY_F15 = 126; // F15 key
	static const uintptr_t KEY_F16 = 127; // F16 key
	static const uintptr_t KEY_F17 = 128; // F17 key
	static const uintptr_t KEY_F18 = 129; // F18 key
	static const uintptr_t KEY_F19 = 130; // F19 key
	static const uintptr_t KEY_F20 = 131; // F20 key
	static const uintptr_t KEY_F21 = 132; // F21 key
	static const uintptr_t KEY_F22 = 133; // F22 key
	static const uintptr_t KEY_F23 = 134; // F23 key
	static const uintptr_t KEY_F24 = 135; // F24 key

	static const uintptr_t KEY_NUMPAD = 144; // Numpad key
	static const uintptr_t KEY_SCROLL_LOCK = 145; // ScrollLock key

	static const uintptr_t KEY_SHIFT_LEFT = 160; // LeftShift key (Wont work w/ keymap)
	static const uintptr_t KEY_SHIFT_RIGHT = 161; // RightShift key (Wont work w/ keymap)

	// 186
	static const uintptr_t KEY_SEMICOLON = 186; // ; key
	static const uintptr_t KEY_EQUALS = 187; // = key

	static const uintptr_t KEY_MINUS = 189; // - key
	static const uintptr_t KEY_FULLSTOP = 190; // . key
	static const uintptr_t KEY_SLASH = 191; // / key

	static const uintptr_t KEY_SP = 0x300; // SpeicalPacket key

public: // UI Details
	static const float UI_TEXT_DEFAULT; // Default Text Size
	static const float UI_TEXT_SMALL; // ArrayList Text Size
	static const float UI_TEXT_BIG; // ArrayList Text Size

	static const float UI_TEXTMEASURE_HEIGHT_DEFAULT; // Default Text Size Height (1f)
	static const float UI_TEXTMEASURE_HEIGHT_ARRAYLIST; // Default Text Size Height (1f)
};

const float GameInput::UI_TEXT_DEFAULT = 1.f;
const float GameInput::UI_TEXT_SMALL = 0.669f;
const float GameInput::UI_TEXT_BIG = 1.669f;

const float GameInput::UI_TEXTMEASURE_HEIGHT_DEFAULT = 24.f;
const float GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST = 16.f;

class Math {
public:
	const static double _pow(double a, double b) {
		double c = 1;
		for (int i = 0; i < b; i++)
			c *= a;
		return c;
	}

	const static double _fact(double x) {
		double ret = 1;
		for (int i = 1; i <= x; i++)
			ret *= i;
		return ret;
	}

	const static float sin(float x) {
		float res = 0, pow = x, fact = 1;
		for (int i = 0; i < 5; i++) {
			res += pow / fact;
			pow *= -1 * x * x;
			fact *= (2 * (i + 1)) * (2 * (i + 1) + 1);
		}
		return res;
	}

	const static double cos(double x) {
		double y = 1;
		double s = -1;
		for (int i = 2; i <= 100; i += 2) {
			y += s * (Math::_pow(x, i) / Math::_fact(i));
			s *= -1;
		}
		return y;
	}
};

class TextInput {
public:
	static const char* Merge(const char* a1, ...) {
		va_list a2;
		va_start(a2, a1);

		auto length = _vscprintf(a1, a2) + 1;
		if (length >= 500) return "";

		char message[300];
		vsprintf_s(message, 300, a1, a2);
		std::string msg(message);

		va_end(a2);
		return msg.c_str();
	}
	
public:
	static const char DarkBlue[4]; // dark colors
	static const char DarkGreen[4];
	static const char DarkAqua[4];
	static const char DarkRed[4];
	static const char DarkPurple[4];
	static const char DarkGray[4];

	static const char Black[4]; // colors
	static const char Gold[4];
	static const char Gray[4];
	static const char Blue[4];
	static const char Green[4];
	static const char Aqua[4];
	static const char Red[4];
	static const char Yellow[4];
	static const char White[4];

	static const char LightPurple[4]; // light colors

	static const char Obfuscated[4]; // extra formatting code
	static const char Bold[4];
	static const char StrikeThrough[4];
	static const char Underlined[4];
	static const char Italic[4];
	static const char Reset[4];
};

const char TextInput::Black[4] = "§0"; // numpad colors
const char TextInput::DarkBlue[4] = "§1";
const char TextInput::DarkGreen[4] = "§2";
const char TextInput::DarkAqua[4] = "§3";
const char TextInput::DarkRed[4] = "§4";
const char TextInput::DarkPurple[4] = "§5";
const char TextInput::Gold[4] = "§6";
const char TextInput::Gray[4] = "§7";
const char TextInput::DarkGray[4] = "§8";
const char TextInput::Blue[4] = "§9";

const char TextInput::Green[4] = "§a"; // text colors
const char TextInput::Aqua[4] = "§b";
const char TextInput::Red[4] = "§c";
const char TextInput::LightPurple[4] = "§d";
const char TextInput::Yellow[4] = "§e";
const char TextInput::White[4] = "§f";

const char TextInput::Obfuscated[4] = "§k"; // extra formatting code
const char TextInput::Bold[4] = "§l";
const char TextInput::StrikeThrough[4] = "§m";
const char TextInput::Underlined[4] = "§n";
const char TextInput::Italic[4] = "§o";
const char TextInput::Reset[4] = "§r";

class GameSigs {
public:
	static const char* SIG_ClientInstance; // Last Updated: v1.18.2
	static const char* SIG_RenderContext; // Last Updated: v1.18.2
	static const char* SIG_Tesselator; //v0.0.0
	static const char* SIG_Keymap; // Last Updated: v1.18.2
	static const char* SIG_Controller; // Last Updated: v1.18.2
	static const char* SIG_MenuSplash; // Last Updated: v1.18.2
	static const char* SIG_EntityList_Stablized; // Last Updated: v1.18.2
	static const char* SIG_ChatSend; // Last Updated: v1.18.2
	static const char* SIG_GameModeHook; // Last Updated: v1.18.2
	static const char* SIG_BobView; // Last Updated: v1.18.2

	static const char* SIG_AntiImmobile; // Last Updated: v1.18.2
	static const char* SIG_AnimationsState; // Last Updated: v1.18.2
	static const char* SIG_ShulkerNest; // Last Updated: v1.18.2
	static const char* SIG_ViewModel; // Last Updated: v1.18.2
	static const char* SIG_KnockBack; // Last Updated: v1.18.2
	static const char* SIG_Reach; // Last Updated: v1.18.2
	static const char* SIG_ShadowRenderer; // Last Updated: v1.18.2
	static const char* SIG_SetPosition; // Last Updated: v1.18.2
	static const char* SIG_CriticalHandler; // Last Updated: v1.18.2
	static const char* SIG_NoSlowDown; // Last Updated: v1.18.2
	static const char* SIG_NoSlowDown2; // Last Updated: v1.18.2
	static const char* SIG_StartDestroyBlock; // Last Updated: v1.18.2

	static const char* SIG_Animation_SmoothSwing; // Last Updated: v1.18.2
	static const char* SIG_Animation_QFlick; // Last Updated: v1.18.2
	static const char* SIG_Animation_OldCombat; // Last Updated: v1.18.2

	static const char* SIG_Environment_Time; // Last Updated: v1.18.2

	static const char* SIG_CompoundTag_putString; // Last Updated: v1.18.2
	static const char* SIG_CompoundTag_putFloat; // Last Updated: v1.18.2
	static const char* SIG_CompoundTag_putByte; // Last Updated: v1.18.2
	static const char* SIG_CompoundTag_putShort; // Last Updated: v1.18.2
	static const char* SIG_CompoundTag_putInt; // Last Updated: v1.18.2

	static const uintptr_t VTABLE_outOfWorld = 7;

	static const uintptr_t VTABLE_setPos = 19; // NoLagBack

	static const uintptr_t VTABLE_getPos = 22;
	static const uintptr_t VTABLE_getOldPos = 23;
	static const uintptr_t VTABLE_getExtrapolatedPos = 24;
	static const uintptr_t VTABLE_getAttachPos = 25;
	static const uintptr_t VTABLE_getFiringPos = 26;
	static const uintptr_t VTABLE_setRot = 27;

	static const uintptr_t VTABLE_isFireImmune = 40; // NoFire

	static const uintptr_t VTABLE_lerpMotion = 46; // NoKnockBack

	static const uintptr_t VTABLE_canShowNametag = 60;

	static const uintptr_t VTABLE_isInWater = 71; // NoWater - NoSlow mode

	static const uintptr_t VTABLE_canSeePos = 83;
	static const uintptr_t VTABLE_canSeeEntity = 84;

	static const uintptr_t VTABLE_isImmobile = 91; // AntiImmobile

	static const uintptr_t VTABLE_isOnFire = 102; // NoFire lmao

	static const uintptr_t VTABLE_isEnchanted = 129; // NoGlit - useful for NoRender

	static const uintptr_t VTABLE_heal = 209; // Regen

	static const uintptr_t VTABLE_isSprinting = 277; // AutoSprint
};

const char* GameSigs::SIG_ClientInstance = "48 8B 01 48 8D 54 24 ? FF 90 ? ? ? ? 90 48 8B 08 48 85 ? 0F 84 ? ? ? ? 48 8B 58 08 48 85 DB 74 0B F0 FF 43 08 48 8B 08 48 8B 58 08 48 89 4C 24 20 48 89 5C 24 28 48 8B 09 48 8B 01 4C 8B C7 48 8B";
const char* GameSigs::SIG_RenderContext = "48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B";
const char* GameSigs::SIG_Keymap = "48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA 89";
const char* GameSigs::SIG_Controller = "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 81 EC ? ? ? ? 0F 29 74 24 ? 0F 29 7C 24 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 49 8B F0";
const char* GameSigs::SIG_MenuSplash = "44 ? ? 11 48 8D 0D";
const char* GameSigs::SIG_EntityList_Stablized = "73 ? B0 ? C3 32 C0 C3 CC CC CC CC CC 48 83 EC"; // F3 ? ? 8A ? ? ? ? F3 ? ? A2
const char* GameSigs::SIG_ChatSend = "48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA 4C 8B F9 48 8B 49";
const char* GameSigs::SIG_GameModeHook = "48 83 EC ? 45 84 C0 74 1E";
const char* GameSigs::SIG_BobView = "48 89 5C ? ? 57 48 81 EC ? ? ? ? 48 8B D9 ? ? B4";

const char* GameSigs::SIG_AntiImmobile = "48 ? 5C 24 ? ? ? 74 ? ? 57 48 83 EC ? 48 8D ? 24 ? E8 ? ? ? ? 90 ? ? C8 ? ? ? ? ? 48 8B ? ? 8B C8 E8 ? ? ? ? 84";
const char* GameSigs::SIG_AnimationsState = "48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA";
const char* GameSigs::SIG_ShulkerNest = "48 89 5C 24 ? 57 48 83 EC ? 48 8B 41 ? 48 8B F9 48 85 C0 74";
const char* GameSigs::SIG_KnockBack = "89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? C3 CC CC CC CC CC 48 89 5C 24";
const char* GameSigs::SIG_ShadowRenderer = "48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? ? ? 70 B8 ? ? 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B F9 48 8D BA"; // mf
const char* GameSigs::SIG_SetPosition = "40 ? 48 ? EC 20 ? 02 ? 8B D9 ? ? D8";
const char* GameSigs::SIG_CriticalHandler = "73 5A 80 B9 D8 01 ? ? ? 75 51";
const char* GameSigs::SIG_StartDestroyBlock = "40 53 57 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 4D 8B F1";
// short
const char* GameSigs::SIG_Animation_SmoothSwing = "E8 ? ? ? ? F3 0F 10 0D ? ? ? ? 41 0F 28 C0";
const char* GameSigs::SIG_Animation_OldCombat = "F3 ? ? C1 ? ? C8 48 8D 15";
const char* GameSigs::SIG_Animation_QFlick = "F3 ? ? F0 ? ? C8 F3 ? ? C8";

const char* GameSigs::SIG_Environment_Time = "44 8B C2 B8 F1 19 76 05 F7 EA";

const char* GameSigs::SIG_ViewModel = "00 00 40 40 DB 0F";
const char* GameSigs::SIG_Reach = "00 00 40 40 DB 0F";

const char* GameSigs::SIG_NoSlowDown2 = "F3 0F 11 46 0C F3 0F 10 05";
const char* GameSigs::SIG_NoSlowDown = "F3 0F 11 46 0C 41 C7";