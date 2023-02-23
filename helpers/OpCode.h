#include <stdint.h>

class OpCode{
    public:
        OpCode(uint16_t hex);

        uint8_t instr();
        uint16_t value();

    private:
        uint8_t i;  // instruction (first 4 bits)
        uint16_t v;  // value (last 12 bits)
};