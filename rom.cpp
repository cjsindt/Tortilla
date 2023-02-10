#include "rom.h"

bool rom::openFile(char* filePath){
    std::ifstream rom_stream;
    rom_stream.open(filePath);

    if(!rom_stream){
        return false;
    }

    return true;
}

std::string rom::data(){

}