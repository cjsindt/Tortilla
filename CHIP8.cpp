#include "CHIP8.h"

CHIP8::CHIP8(){

    // Load Fontset into RAM
    for(int i = 0; i < FONTSET_SIZE; i++){
        RAM[i] = FONTSET[i];
    }

    PC = PROG_START; // Set Program counter to proper location
}

void CHIP8::printRAM(int min, int max){
    for(int i = min; i < max; i++){
        cout << (int)RAM[i];
        cout << "\n" << endl;
    }
}

void CHIP8::loadROM(){
}