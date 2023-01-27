#include "CHIP8.h"
#include <iostream>
#include <cstddef>
#include <bitset>
#include <SFML/Graphics.hpp>

using namespace std;

class CHIP8{
    public:
        CHIP8(){
            DISP = sf::RenderWindow(sf::VideoMode(64, 32), "CHIP-8");
            
        }

    private:
        char* RAM[4096];  // 4 KB of RAM
        sf::RenderWindow DISP;  // Display
        unsigned short int 
};