# Tortilla
CHIP-8 Interpreter

This was made as a part of my undergraduate senior capstone.

For a great spec of CHIP8, see [here](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM)

# Build with CMake

Clone the repository into your favorite folder.

Build the executable.

Enjoy!

```
git clone https://github.com/cjsindt/Tortilla.git
cd Tortilla
mkdir build
cd build
cmake ..
make
```

At this point you should have an executable located at build/Tortilla

# Running Tortilla

Once you have the executable, you need to pass it a rom to execute.

```
./Tortilla <rom_file_path>
```

# Progress Updates

## Feb 2 - Feb 16

Starting development on CHIP-8. Had to start by making sure my project would build with cmake. Tested this by printing "test" to the console.

I was able to build an executable and, once I ran it, "test" showed up, so things seem to be working.

I also needed command line arguments for the user to specify which rom to be loaded.
So I made it so I can parse a file path from the command line.

The user can now specify a rom to load and it will be loaded into the CHIP8 RAM.

Up next, instruction parsing.

Started with making an OpCode class, because instructions are two bytes long and RAM is byte addressed.
All this class does is allow two bytes to be stored so opcodes can be accessed via their high and low bytes.

Then, I made functions for each of the instructions. The idea being I can parse an opcode, then call the correct instruction in a switch statement.

### Accomplishments

- CMake files and build testing
- Command line arguments and test rom
- Stream rom data
- Load ROM into RAM
- Start of instruction parsing
- OpCode class
