#include "CHIP8.h"

CHIP8::CHIP8(){
    clearRAM();
    loadFontset();
    PC = PROG_START; // Set Program counter to proper location

    // init stack
    SP = 0;
    STACK[0] = 0;
}

void CHIP8::printRAM(int min, int max){
    for(int i = min; i < max; i++){
        cout << "addr: " << i << " - Val: " << (int)RAM[i] << endl;
    }
}

// Load ROM into RAM
void CHIP8::loadROM(string data){
    for (int i = 0; i < data.length(); i++){
        RAM[i+PROG_START] = data[i];
    }
}

// Clear the contents of RAM
void CHIP8::clearRAM(){
    for(int i = 0; i < TOTAL_RAM; i++){
        RAM[i] = 0;
    }
}

// Load fontset into RAM
void CHIP8::loadFontset(){
    for(int i = 0; i < FONTSET_SIZE; i++){
        RAM[i] = FONTSET[i];
    }
}

// A parsing function to determine which hex value is which opcode
Instruction CHIP8::parseOpCode(OpCode op){
    switch(op.high()){
        case 0x00:
            switch(op.low()){
                case 0xE0: CLS(op);
                case 0xEE: return Instruction::RET;
                default: return Instruction::NIL;
            }
        default: return Instruction::NIL;
    }
}

// INSTRUCTIONS

// clear screen
void CHIP8::CLS(OpCode op){
    screen.Clear();
}

// return to previous call (addr at top of stack)
void CHIP8::RET(OpCode op){
    PC = STACK[SP];
    SP--;
}

