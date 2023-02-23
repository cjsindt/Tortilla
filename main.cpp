#include "CHIP8.h"

using namespace std;

int main(int argc, char** argv){
    CHIP8 chip8;
    rom r;

    chip8.printRAM(PROG_START, TOTAL_RAM);

    if(argc==1){
        cout << "No ROM file given" << endl;
        exit(-1);
    }

    cout << "Loading ROM from " << argv[1] << endl;
    r.openFile(argv[1]);

    chip8.loadROM(r.data());
    
    chip8.printRAM(PROG_START, TOTAL_RAM);

    // while(true){
    //     uint16_t curr_opcode = chip8.getInstruction(0);
    // }
    
    return 0;
}