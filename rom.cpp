#include "rom.h"

bool rom::openFile(char* filePath){
    rom_stream.open(filePath, std::ios::binary);

    if(!rom_stream){
        return false;
    }

    long rom_size = rom_stream.tellg();
    rom_stream.seekg(0);

    // check if rom is empty or too big for RAM
    // 0xDFF = 3583 = 4095 (Total RAM) - 512 (Reserved RAM)
    if(rom_size == 0 || rom_size > 0xDFF){
        return false;
    }

    return true;
}

std::string rom::data(){
    std::ostringstream ss;
    ss << rom_stream.rdbuf();
    return ss.str();
}

rom::~rom(){
    if(rom_stream){
        rom_stream.close();
    }
}