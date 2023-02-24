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

// Returns the instr at the PC
uint16_t CHIP8::getInstruction(){
    if(PC < TOTAL_RAM){
        return RAM[PC++];
    } else {
        return RAM[PC];
    }

}

// A parsing function to determine which hex value is which opcode
void CHIP8::parseOpCode(OpCode op){
    switch(op.instr()){
        case 0x00:
            switch(op.value()){
                case 0xE0:
                    CLS(op);
                    break;
                case 0xEE:
                    RET(op);
                    break;
                default:
                    SYS_addr(op);
                    break;
            }
            break;

        case 0x01:
             JP_addr(op);
             break;
        
        case 0x02:
            CALL_addr(op);
            break;
        
        case 0x03:
            SE_Vx_byte(op);
            break;

        case 0x04:
            SNE_Vx_byte(op);
            break;

        case 0x05:
            SE_Vx_Vy(op);
            break;

        case 0x06:
            LD_Vx_byte(op);
            break;

        
        
        default: NIL();
    }
}

// INSTRUCTIONS

// clear screen
void CHIP8::CLS(OpCode op){
    screen.Clear();
}

// return to previous call (addr at top of stack)
void CHIP8::RET(OpCode op){
    PC = STACK[SP--];
}

// jump to machine routine at addr
void CHIP8::SYS_addr(OpCode op){
    PC = op.value();
}

void CHIP8::JP_addr(OpCode op){

}

void CHIP8::CALL_addr(OpCode op){

}

void CHIP8::SE_Vx_byte(OpCode op){

}

void CHIP8::SNE_Vx_byte(OpCode op){

}

void CHIP8::SE_Vx_Vy(OpCode op){

}

void CHIP8::LD_Vx_byte(OpCode op){

}

void CHIP8::ADD_Vx_byte(OpCode op){
}
void CHIP8::LD_Vx_Vy(OpCode op){
}
void CHIP8::OR_Vx_Vy(OpCode op){
}
void CHIP8::AND_Vx_Vy(OpCode op){
}
void CHIP8::XOR_Vx_Vy(OpCode op){
}
void CHIP8::ADD_Vx_Vy(OpCode op){
}
void CHIP8::SUB_Vx_Vy(OpCode op){
}
void CHIP8::SHR_Vx_Vy(OpCode op){
}
void CHIP8::SUBN_Vx_Vy(OpCode op){
}
void CHIP8::LD_I_addr(OpCode op){
}
void CHIP8::JP_V0_addr(OpCode op){
}
void CHIP8::RND_Vx_byte(OpCode op){
}
void CHIP8::DRW_Vx_Vy_nibble(OpCode op){
}
void CHIP8::SKP_Vx(OpCode op){
}
void CHIP8::SKNP_Vx(OpCode op){
}
void CHIP8::LD_Vx_DT(OpCode op){
}
void CHIP8::LD_Vx_K(OpCode op){
}
void CHIP8::LD_DT_Vx(OpCode op){
}
void CHIP8::LD_ST_Vx(OpCode op){
}
void CHIP8::ADD_I_Vx(OpCode op){
}
void CHIP8::LD_F_Vx(OpCode op){
}
void CHIP8::LD_B_Vx(OpCode op){
}
void CHIP8::LD_I_Vx(OpCode op){
}
void CHIP8::LD_Vx_I(OpCode op){
}


void CHIP8::NIL(){

}