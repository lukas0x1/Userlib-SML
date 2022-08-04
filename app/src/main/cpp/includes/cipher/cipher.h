//
// Created by Lukas on 22/07/2022.
//

#ifndef USERLIB_CIPHER_H
#define USERLIB_CIPHER_H
#include <vector>
#include <utility>




typedef void (*func)();

class Cipher {
    unsigned long ID;
public:
    static void Init();
    static void Patch(uintptr_t address, uint patch);
    static void Restore(uintptr_t address);
    static void Hook(uintptr_t address, uintptr_t hookaddr, uintptr_t origin, int8_t flag = 0, bool isLocked = false,  const char *libName = get_libName());
    static void push_Cipher(Cipher *cipher);
    static uintptr_t get_libBase();
    static const char *get_libName();
    Cipher();
};







#endif //USERLIB_CIPHER_H