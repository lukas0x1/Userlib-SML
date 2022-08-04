//
// Created by Lukas on 22/07/2022.
//

#include "includes/cipher/cipher.h"
#include "includes/imgui/imgui.h"
#include "includes/And64InlineHook/And64InlineHook.hpp"
#include "includes/KittyMemory/KittyMemory.h"





void UserlibMenu() {
        static int counter = 0;
        ImGui::Begin("Userlib Menu");
        if (ImGui::Button("counter")) counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
}

void Cipher::Init(){

    //A64HookFunction((void *)0x8, (void *)0x8, (void **)0x9);
};