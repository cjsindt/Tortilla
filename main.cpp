#include "CHIP8.h"
#include <stdlib.h>

using namespace std;

int main(){
    cout << "test" << endl;
    CHIP8 chip8;
    chip8.printRAM(0, 4096);
    sf::RenderWindow window(sf::VideoMode(800,600), "Tortilla");    // Game Window
    return 0;
}