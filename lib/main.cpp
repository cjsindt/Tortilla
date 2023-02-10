#include "CHIP8.h"
#include <stdlib.h>

using namespace std;

int main(){
    cout << "test" << endl;
    CHIP8 chip8;
    chip8.printRAM(0, 4096);
    return 0;
}