#include "CHIP8.h"

CHIP8::CHIP8(){

    // Load Fontset into RAM
    for(int i = 0; i < FONTSET_SIZE; i++){
        RAM[i] = FONTSET[i];
    }

    RAM[0] = *FONTSET;  //TEST THIS LINE. SHOULD REPLACE LOOP

    PC = PROG_START; // Set Program counter to proper location
}