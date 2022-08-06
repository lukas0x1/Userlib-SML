//
// Created by Lukas on 22/07/2022.
//

#ifndef USERLIB_CIPHER_H
#define USERLIB_CIPHER_H
#include <vector>
#include <utility>
#include "CipherHook.h"
#include "CipherPatch.h"



typedef void (*func)();

class Cipher {
public:
    static uintptr_t get_libBase();
    static const char *get_libName();
};







#endif //USERLIB_CIPHER_H