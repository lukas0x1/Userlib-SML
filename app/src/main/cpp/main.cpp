//
// Created by Lukas on 22/07/2022.
//

#include "includes/cipher/cipher.h"
#include "includes/imgui/imgui.h"
#include "includes/misc/Logger.h"


bool test = 0;
uintptr_t (*AvatarEnergy_Use)(uintptr_t thiz, unsigned int a2, float amount);
uintptr_t Hook_AvatarEnergy_Use(uintptr_t thiz, unsigned int a2, float amount){
        LOGD("hook 01");
        if(test){
                return AvatarEnergy_Use(thiz, 0, 0);
        }
        return AvatarEnergy_Use(thiz, a2, amount);
}

uintptr_t (*AvatarEnergy_Use2)(uintptr_t thiz, unsigned int a2, float amount);
uintptr_t Hook_AvatarEnergy_Use2(uintptr_t thiz, unsigned int a2, float amount){
        LOGD("hook 02");
        return AvatarEnergy_Use2(thiz, a2, amount);
}


void Menu() {
        ImGui::Checkbox("Relationships", (bool *)(Cipher::get_libBase() + 0x16A66F8));
        ImGui::Checkbox("Energy", &test);
}


void Init(){
        (new CipherHook())->set_Address(0x4F7474)->set_Hook((uintptr_t)Hook_AvatarEnergy_Use)->set_Callback((uintptr_t) &AvatarEnergy_Use)->Fire();
        (new CipherHook())->set_Address(0x4F7474)->set_Hook((uintptr_t)Hook_AvatarEnergy_Use2)->set_Callback((uintptr_t) &AvatarEnergy_Use2)->Fire();
    //A64HookFunction((void *)0x8, (void *)0x8, (void **)0x9);
};