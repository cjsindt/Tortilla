#include "OpCode.h"

OpCode::OpCode(unsigned short high_byte, unsigned short low_byte){
    high = high_byte;
    low = low_byte;
}

uint8_t OpCode::High(){
    return high;
}

uint8_t OpCode::Low(){
    return low;
}