//
// Created by Lukas on 22/07/2022.
//

#include "cipher.h"
#include "../../main.h"
#include <pthread.h>

void *UserThread(void *cipher){
    ((Cipher *)cipher)->Init();
}

extern "C"
func UserlibInitialize(Cipher *cipher, uintptr_t libBase){
    pthread_t ptid{};
    pthread_create(&ptid, nullptr, UserThread, (void *)libBase);
    return &UserlibMenu;
}
