#include "CHIP8.h"
#include <stdlib.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char** argv){
    if(argc==1){
        cout << "No ROM file given, loading space invaders" << endl;
    } else {
        cout << "Loading ROM from " << argv[1] << endl;
    }
    
    CHIP8 chip8;
    //chip8.printRAM(0, 4096);

    //sf::RenderWindow window(sf::VideoMode(800,600), "Tortilla");    // Game Window

    return 0;
}