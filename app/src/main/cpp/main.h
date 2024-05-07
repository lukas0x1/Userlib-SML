//
// Created by Lukas on 01/08/2022.
//

#ifndef USERLIB_MAIN_H
#define USERLIB_MAIN_H

typedef void (*func)(bool*);
void Menu(bool *_pOpen);
void Init();
extern "C" void __attribute__((visibility("default"))) InitLate();

extern "C" func __attribute__((visibility ("default"))) Start() {
    Init();
    return &Menu;
}


#endif //USERLIB_MAIN_H
