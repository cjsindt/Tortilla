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
        uint16_t i = RAM[PC++] << 8;
        i |= RAM[PC++];
        return i;
    } else {
        return RAM[PC];
    }

}

void CHIP8::print(string s){
    cout << s << endl;
}

void CHIP8::paint(){
    screen.paint();
}

bool CHIP8::isOpen(){
    return screen.isOpen();
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

        case 0x07:
            ADD_Vx_byte(op);
            break;

        case 0x08:
            switch(op.value() & 0x000F){ // switch on last nibble
                case 0x00:
                    LD_Vx_Vy(op);
                    break;
                
                case 0x01:
                    OR_Vx_Vy(op);
                    break;

                case 0x02:
                    AND_Vx_Vy(op);
                    break;
                
                case 0x03:
                    XOR_Vx_Vy(op);
                    break;

                case 0x04:
                    ADD_Vx_Vy(op);
                    break;

                case 0x05:
                    SUB_Vx_Vy(op);
                    break;

                case 0x06:
                    SHR_Vx_Vy(op);
                    break;

                case 0x07:
                    SUBN_Vx_Vy(op);
                    break;

                case 0x0E:
                    SHL_Vx_Vy(op);
                    break;
                
                default:
                    NIL();
                    break;
            }
            break;

        case 0x09:
            SNE_Vx_Vy(op);
            break;

        case 0x0A:
            LD_I_addr(op);
            break;

        case 0x0B:
            JP_V0_addr(op);
            break;

        case 0x0C:
            RND_Vx_byte(op);
            break;

        case 0x0D:
            DRW_Vx_Vy_nibble(op);
            break;

        case 0x0E:
            switch(op.value() & 0x00FF){
                case 0x9E:
                    SKP_Vx(op);
                    break;
                
                case 0xA1:
                    SKNP_Vx(op);
                    break;
            }
            break;
        
        case 0x0F:
            switch(op.value() & 0x00FF){
                case 0x07:
                    LD_Vx_DT(op);
                    break;

                case 0x0A:
                    LD_Vx_K(op);
                    break;

                case 0x15:
                    LD_DT_Vx(op);
                    break;

                case 0x18:
                    LD_ST_Vx(op);
                    break;
                
                case 0x1E:
                    ADD_I_Vx(op);
                    break;

                case 0x29:
                    LD_F_Vx(op);
                    break;

                case 0x33:
                    LD_B_Vx(op);
                    break;
                
                case 0x55:
                    LD_I_Vx(op);
                    break;

                case 0x65: 
                    LD_Vx_I(op);
                    break;

                default:
                    NIL();
                    break;
            }
            break;
        
        default:
            NIL();
            break;
    }
}

// INSTRUCTIONS

// clear screen
void CHIP8::CLS(OpCode op){
    screen.clear();
}

// The interpreter sets the program counter to the address at the top of the stack, then subtracts 1 from the stack pointer.
void CHIP8::RET(OpCode op){
    PC = STACK[SP--];
    //print("ret");
}

// This instruction is only used on the old computers on which Chip-8 was originally implemented. It is ignored by modern interpreters.
void CHIP8::SYS_addr(OpCode op){
    PC = op.value();
    //print("sys");
}

// The interpreter sets the program counter to nnn.
void CHIP8::JP_addr(OpCode op){
    PC = op.value();
    //print("jp");
}

// The interpreter increments the stack pointer, then puts the current PC on the top of the stack. The PC is then set to nnn.
void CHIP8::CALL_addr(OpCode op){
    STACK[++SP] = PC;
    PC = op.value();
    //print("call");
}

// The interpreter compares register Vx to kk, and if they are not equal, increments the program counter by 2.
void CHIP8::SE_Vx_byte(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    x = x >> 8;
    if(V[x] = op.value() & 0x00FF){
        PC += 2;
    }
    //print("se");
}

// The interpreter compares register Vx to register Vy, and if they are equal, increments the program counter by 2.
void CHIP8::SNE_Vx_byte(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    x = x >> 8;
    if(V[x] != op.value() & 0x00FF){
        PC += 2;
    }
    //print("sne");
}

// The interpreter compares register Vx to register Vy, and if they are equal, increments the program counter by 2.
void CHIP8::SE_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    if(V[x] == V[y]){
        PC += 2;
    }
    //print("sevxvy");
}

// The interpreter puts the value kk into register Vx.
void CHIP8::LD_Vx_byte(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t kk = op.value() & 0x00FF;
    x = x >> 8;
    V[x] = kk;
    //print("ld");
}

// Adds the value kk to the value of register Vx, then stores the result in Vx. 
void CHIP8::ADD_Vx_byte(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t kk = op.value() & 0x00FF;
    x = x >> 8;
    V[x] += kk;
    //print("add");
}

// Stores the value of register Vy in register Vx.
void CHIP8::LD_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    V[x] = V[y];
    //print("ldvxvy");
}

// Performs a bitwise OR on the values of Vx and Vy, then stores the result in Vx. A bitwise OR compares the corrseponding bits from two values, and if either bit is 1, then the same bit in the result is also 1. Otherwise, it is 0.
void CHIP8::OR_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    V[x] |= V[y];
    //print("or");
}

// Performs a bitwise AND on the values of Vx and Vy, then stores the result in Vx. A bitwise AND compares the corrseponding bits from two values, and if both bits are 1, then the same bit in the result is also 1. Otherwise, it is 0.
void CHIP8::AND_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    V[x] &= V[y];
    //print("and");
}

// Performs a bitwise exclusive OR on the values of Vx and Vy, then stores the result in Vx. An exclusive OR compares the corrseponding bits from two values, and if the bits are not both the same, then the corresponding bit in the result is set to 1. Otherwise, it is 0.
void CHIP8::XOR_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    V[x] ^= V[y];
    //print("xor");
}

// The values of Vx and Vy are added together. If the result is greater than 8 bits (i.e., > 255,) VF is set to 1, otherwise 0. Only the lowest 8 bits of the result are kept, and stored in Vx.
void CHIP8::ADD_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    uint16_t sum = V[x] + V[y];
    if(sum > 255){
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
    V[x] = sum & 0x00FF;
    //print("addvxvy");
}

// If Vx > Vy, then VF is set to 1, otherwise 0. Then Vy is subtracted from Vx, and the results stored in Vx.
void CHIP8::SUB_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    if(V[x] > V[y]){
        V[0xF] = 1;     
    } else {
        V[0xF] = 0;
    }
    V[x] -= V[y];
    //print("sub");
}

// If the least-significant bit of Vx is 1, then VF is set to 1, otherwise 0. Then Vx is divided by 2.
void CHIP8::SHR_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    x = x >> 8;
    if(V[x]%2==1){
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
    V[x] = V[x] >> 1;
    //print("shr");
}

// If Vy > Vx, then VF is set to 1, otherwise 0. Then Vx is subtracted from Vy, and the results stored in Vx.
void CHIP8::SUBN_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    uint16_t y = op.value() & 0x00F0;
    x = x >> 8;
    y = y >> 4;
    if(V[y] > V[x]){
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
    V[x] = V[y] - V[x];
    //print("subn");
}

// If the most-significant bit of Vx is 1, then VF is set to 1, otherwise to 0. Then Vx is multiplied by 2.
void CHIP8::SHL_Vx_Vy(OpCode op){
    uint16_t x = op.value() & 0x0F00;
    x = x >> 8;
    if(V[x] >> 7 == 1){
        V[0xF] = 1;
    } else {
        V[0xF] = 0;
    }
    V[x] = V[x] << 1;
    //print("shl");
}

void CHIP8::SNE_Vx_Vy(OpCode op){
    print("snevxvy");
}
void CHIP8::LD_I_addr(OpCode op){
    print("ldiaddr");
}
void CHIP8::JP_V0_addr(OpCode op){
    print("jpv0");
}
void CHIP8::RND_Vx_byte(OpCode op){
    print("rnd");
}
void CHIP8::DRW_Vx_Vy_nibble(OpCode op){
    print("drw");
}
void CHIP8::SKP_Vx(OpCode op){
    print("skp");
}
void CHIP8::SKNP_Vx(OpCode op){
    print("sknp");
}
void CHIP8::LD_Vx_DT(OpCode op){
    print("ldvxdt");
}
void CHIP8::LD_Vx_K(OpCode op){
    print("ldvxk");
}
void CHIP8::LD_DT_Vx(OpCode op){
    print("lddtvx");
}
void CHIP8::LD_ST_Vx(OpCode op){
    print("ldstvx");
}
void CHIP8::ADD_I_Vx(OpCode op){
    print("addivx");
}
void CHIP8::LD_F_Vx(OpCode op){
    print("ldfvx");
}
void CHIP8::LD_B_Vx(OpCode op){
    print("ldbvx");
}
void CHIP8::LD_I_Vx(OpCode op){
    print("ldivx");
}
void CHIP8::LD_Vx_I(OpCode op){
    print("ldvxi");
}


void CHIP8::NIL(){
    print("NIL");

}