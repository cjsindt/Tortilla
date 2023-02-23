#include "OpCode.h"

OpCode::OpCode(uint16_t hex){
    i = hex >> 12;
    v = hex & 0x0FFF;
}

uint8_t OpCode::instr(){
    return i;
}

uint16_t OpCode::value(){
    return v;
}