//
// Created by Lukas on 22/07/2022.
//

#include "main.h"
#include "include/Cipher/Cipher.h"
#include "include/imgui/imgui.h"
#include "include/misc/Logger.h"



// UI related functions
void Menu(bool *_pOpen) { // _pOpen is passed by canvas. Used to close and open the mod locally
    ImGui::Checkbox("Close me!", (bool *)(_pOpen));
}

// Called in a later stage of game initialisation
void InitLate() {

}

// Called at the start of the game
void Init() {

}