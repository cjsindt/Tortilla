#include "CHIP8.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char** argv){
    CHIP8 chip8;
    rom r;

    chip8.printRAM(PROG_START, TOTAL_RAM);

    if(argc==1){
        cout << "No ROM file given" << endl;
        exit(-1);
    } else {
        cout << "Loading ROM from " << argv[1] << endl;
        r.openFile(argv[1]);
    }

    chip8.loadROM(r.data());
    
    chip8.printRAM(PROG_START, TOTAL_RAM);

    //chip8.printRAM(0, 4096);

    //sf::RenderWindow window(sf::VideoMode(800,600), "Tortilla");    // Game Window

    return 0;
}