#pragma once

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

class MCM {
public:
    static auto findMultiLvlPtr(uintptr_t baseAddr, std::vector<unsigned int> offsets) -> uintptr_t {
        uintptr_t addr = baseAddr;

        for (int I = 0; I < offsets.size(); I++) {
            addr = *(uintptr_t*)(addr);
            if ((uintptr_t*)(addr) == nullptr)
                return addr;
            addr += offsets[I];
        };

        return addr;
    };

    static void patchBytes(BYTE* dst, BYTE* src, unsigned int size) {
        DWORD oldprotect;
        VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
        memcpy(dst, src, size);
        VirtualProtect(dst, size, oldprotect, &oldprotect);
    }

    static void setFloat(void* dst, float src) {
        DWORD oldprotect;
        VirtualProtect(dst, sizeof(float), PAGE_EXECUTE_READWRITE, &oldprotect);

        auto addr = reinterpret_cast<float*>(dst);
        *addr = src;

        VirtualProtect(dst, sizeof(float), oldprotect, &oldprotect);
    }

    static void setString(void* dst, TextHolder src, int size) {
        DWORD oldprotect;
        VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

        auto addr = reinterpret_cast<TextHolder*> (dst);
        addr->setText(src.getText());

        //VirtualProtect(dst, size, oldprotect, &oldprotect);
    }

    static uintptr_t findSig(const char* sig) {
        const char* pattern = sig;
        uintptr_t firstMatch = 0;
        static const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
        static MODULEINFO miModInfo;
        static bool init = false;
        if (!init) {
            init = true;
            GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
        }
        static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

        BYTE patByte = GET_BYTE(pattern);
        const char* oldPat = pattern;

        for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++) {
            if (!*pattern)
                return firstMatch;

            while (*(PBYTE)pattern == ' ')
                pattern++;

            if (!*pattern)
                return firstMatch;

            if (oldPat != pattern) {
                oldPat = pattern;
                if (*(PBYTE)pattern != '\?')
                    patByte = GET_BYTE(pattern);
            };

            if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte) {
                if (!firstMatch)
                    firstMatch = pCur;

                if (!pattern[2])
                    return firstMatch;

                pattern += 2;
            }
            else {
                pattern = sig;
                firstMatch = 0;
            };
        };
    };
};