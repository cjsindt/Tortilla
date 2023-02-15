#include "OpCode.h"

OpCode::OpCode(uint8_t high_byte, uint8_t low_byte){
    high = high_byte;
    low = low_byte;
}

uint8_t OpCode::High(){
    return high;
}

uint8_t OpCode::Low(){
    return low;
}