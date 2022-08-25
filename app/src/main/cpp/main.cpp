//
// Created by Lukas on 22/07/2022.
//

#include "includes/cipher/Cipher.h"
#include "includes/imgui/imgui.h"
#include "includes/misc/Logger.h"




void Menu() {
        ImGui::Checkbox("Relationships", (bool *)(Cipher::get_libBase() + 0x16A66F8));
}


void Init(){

};