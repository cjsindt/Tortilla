#include <iostream>
#include <cstddef>
#include <bitset>
#include "helpers/rom.h"
#include "helpers/OpCode.h"
#include "helpers/Display.h"
#include <map>

using namespace std;

#define TOTAL_RAM 4096
#define STACK_SIZE 16
#define FREQ 60
#define V_REGS 16
#define PROG_START 0x200

#define FONTSET_SIZE 80

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

#define ROM_START 0x200

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

        Display screen;

        map<uint8_t, sf::Keyboard::Key> keyboard = {{0x0, sf::Keyboard::X},
                                                    {0x1, sf::Keyboard::Num1},
                                                    {0x2, sf::Keyboard::Num2},
                                                    {0x3, sf::Keyboard::Num3},
                                                    {0x4, sf::Keyboard::Q},
                                                    {0x5, sf::Keyboard::W},
                                                    {0x6, sf::Keyboard::E},
                                                    {0x7, sf::Keyboard::A},
                                                    {0x8, sf::Keyboard::S},
                                                    {0x9, sf::Keyboard::D},
                                                    {0xA, sf::Keyboard::Z},
                                                    {0xB, sf::Keyboard::C},
                                                    {0xC, sf::Keyboard::Num4},
                                                    {0xD, sf::Keyboard::R},
                                                    {0xE, sf::Keyboard::F},
                                                    {0xF, sf::Keyboard::V}};


    public:
        CHIP8();

        /// @brief Prints the contents of ram from the min addr to max addr
        /// @param min starting addr
        /// @param max ending addr
        void printRAM(int min, int max);

        void clearRAM();

        void loadFontset();

        void loadROM(string data);

        uint16_t getInstruction();

        void parseOpCode(OpCode op);

        void print(string s);

        bool isOpen();

        void paint();

        Display * getScreen();

        // Instruction set
        void CLS(OpCode op);
        void RET(OpCode op);
        void SYS_addr(OpCode op);
        void JP_addr(OpCode op);
        void CALL_addr(OpCode op);
        void SE_Vx_byte(OpCode op);
        void SNE_Vx_byte(OpCode op);
        void SE_Vx_Vy(OpCode op);
        void LD_Vx_byte(OpCode op);
        void ADD_Vx_byte(OpCode op);
        void LD_Vx_Vy(OpCode op);
        void OR_Vx_Vy(OpCode op);
        void AND_Vx_Vy(OpCode op);
        void XOR_Vx_Vy(OpCode op);
        void ADD_Vx_Vy(OpCode op);
        void SUB_Vx_Vy(OpCode op);
        void SHR_Vx_Vy(OpCode op);
        void SUBN_Vx_Vy(OpCode op);
        void SHL_Vx_Vy(OpCode op);
        void SNE_Vx_Vy(OpCode op);
        void LD_I_addr(OpCode op);
        void JP_V0_addr(OpCode op);
        void RND_Vx_byte(OpCode op);
        void DRW_Vx_Vy_nibble(OpCode op);
        void SKP_Vx(OpCode op);
        void SKNP_Vx(OpCode op);
        void LD_Vx_DT(OpCode op);
        void LD_Vx_K(OpCode op);
        void LD_DT_Vx(OpCode op);
        void LD_ST_Vx(OpCode op);
        void ADD_I_Vx(OpCode op);
        void LD_F_Vx(OpCode op);
        void LD_B_Vx(OpCode op);
        void LD_I_Vx(OpCode op);
        void LD_Vx_I(OpCode op);
        void NIL(); // unknown opcode
};