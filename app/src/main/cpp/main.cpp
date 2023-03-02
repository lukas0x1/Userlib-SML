//
// Created by Lukas on 22/07/2022.
//

#include "main.h"
#include "include/cipher/Cipher.h"
#include "include/imgui/imgui.h"
#include "include/misc/Logger.h"




void Menu() {
        ImGui::Checkbox("Relationships", (bool *)(Cipher::get_libBase() + 0x16A66F8));
}


void Init(){

};
