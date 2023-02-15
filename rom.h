#include <fstream>
#include <sstream>
#include <stdlib.h>


// reads in data from .c8 file
class rom{
    public:
        bool openFile(char* filePath);
        std::string data();
        //~rom();

    private:
        std::ifstream rom_stream;

};