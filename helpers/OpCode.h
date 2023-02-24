#include <stdint.h>

// CHIP8 opcodes follow a format of Nxxx
// Where N denotes the instruction, and xxx is the value for that instruciton
class OpCode{
    public:
        OpCode(uint16_t hex);

        uint8_t instr();
        uint16_t value();

    private:
        uint8_t i;  // instruction (first 4 bits)
        uint16_t v;  // value (last 12 bits)
};