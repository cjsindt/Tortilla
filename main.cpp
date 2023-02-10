#include "CHIP8.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char** argv){
    CHIP8 chip8;
    rom r;

    if(argc==1){
        cout << "No ROM file given" << endl;
        exit(-1);
    } else {
        cout << "Loading ROM from " << argv[1] << endl;
        if(!r.openFile(argv[1])){
            cout << "file found" << endl;
        }
    }
    

    //chip8.printRAM(0, 4096);

    //sf::RenderWindow window(sf::VideoMode(800,600), "Tortilla");    // Game Window

    return 0;
}