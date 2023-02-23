#include "OpCode.h"

OpCode::OpCode(uint8_t high_byte, uint8_t low_byte){
    h = high_byte;
    l = low_byte;
}

uint16_t OpCode::full(){
    return ((uint16_t)h << 8) | l;
}

uint8_t OpCode::high(){
    return h;
}

uint8_t OpCode::low(){
    return l;
}