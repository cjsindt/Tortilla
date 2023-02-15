#include <stdint.h>

class OpCode{
    public:
        OpCode(unsigned short high_byte, unsigned short low_byte);

        uint8_t High();
        uint8_t Low();

    private:
        uint8_t high;
        uint8_t low;
};