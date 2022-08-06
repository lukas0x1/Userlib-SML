//
// Created by Lukas on 04/08/2022.
//

#ifndef SKY_MODLOADER_CIPHERPATCH_H
#define SKY_MODLOADER_CIPHERPATCH_H
#include "../KittyMemory/MemoryPatch.h"

class CipherPatch {
private:
    uintptr_t m_Address;
    static inline std::vector<CipherPatch *> PatchVec;

public:
    CipherPatch *set_Address;
};


#endif //SKY_MODLOADER_CIPHERPATCH_H
