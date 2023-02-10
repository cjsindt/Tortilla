#include <iostream>
#include <cstddef>
#include <bitset>
#include "rom.h"

using namespace std;

#define TOTAL_RAM 4096
#define STACK_SIZE 16
#define FREQ 60
#define V_REGS 16
#define PROG_START 0x200

#define FONTSET_SIZE 80

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

const static uint8_t FONTSET[FONTSET_SIZE] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};


class CHIP8{
    private:
        uint8_t RAM[TOTAL_RAM];     // 4KB of RAM
        uint16_t STACK[STACK_SIZE]; // Stack
        uint8_t V[V_REGS];          // General Purpose Registers (0x0 - 0xF)
        uint16_t I;                 // I register
        uint16_t PC;                // Program Counter Register
        uint16_t SP;                // Stack Pointer Register
        uint8_t DELAY_TIMER;        // Delay Timer
        uint8_t SOUND_TIMER;        // Sound Timer
        uint16_t CURR_OP;           // Current op code

        uint8_t DISPLAY[SCREEN_HEIGHT][SCREEN_WIDTH];   // Display pixels


    public:
        CHIP8();

        /// @brief Prints the contents of ram from the min addr to max addr
        /// @param min starting addr
        /// @param max ending addr
        void printRAM(int min, int max);

        void loadROM();

        void parseInstruction();
};