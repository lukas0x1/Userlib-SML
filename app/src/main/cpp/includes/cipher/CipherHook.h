//
// Created by Lukas on 04/08/2022.
//

#ifndef SKY_MODLOADER_CIPHERHOOK_H
#define SKY_MODLOADER_CIPHERHOOK_H
#include <utility>
#include <vector>
#include "../KittyMemory/MemoryBackup.h"

class CipherHook {
private:
    const char *m_libName;
    uintptr_t p_Address;
    uintptr_t p_Callback;
    uintptr_t p_Hook;
    bool m_isLocal = true;
    bool m_isLocked = false;
    MemoryBackup *p_Backup;
    static inline std::vector<CipherHook *> m_HookVec;
public:
    CipherHook();
    ~CipherHook();
    CipherHook *set_libName(const char *libName);
    CipherHook *set_Address(uintptr_t address);
    CipherHook *set_Hook(uintptr_t Hook);
    CipherHook *set_Callback(uintptr_t Callback);
    CipherHook *set_Address(const char *Symbol);
    CipherHook *set_AdressType(bool type);
    CipherHook *set_Lock(bool isLocked);
    CipherHook *Fire();
};





#endif //SKY_MODLOADER_CIPHERHOOK_H
