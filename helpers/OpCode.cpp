#include "OpCode.h"

OpCode::OpCode(uint8_t high_byte, uint8_t low_byte){
    h = high_byte;
    l = low_byte;
}

uint8_t OpCode::high(){
    return h;
}

uint8_t OpCode::low(){
    return l;
}