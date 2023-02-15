#include <stdint.h>

class OpCode{
    public:
        OpCode(uint8_t high_byte, uint8_t low_byte);

        uint8_t high();
        uint8_t low();

    private:
        uint8_t h;  // high byte
        uint8_t l;  // low byte
};