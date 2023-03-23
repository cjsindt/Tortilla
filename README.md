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

## Mar 9 - Mar 30

I decided to work on the display code first so I could try and see my progress as I worked. I started by setting an array of Rectangles of 64x32 to match the size of the CHIP8 screen. The actual display is 640x320, so mapping the pixels to the screen is a simple 1:10 ratio.

### Accomplishments

- Display white bars

## Feb 16 - Mar 9

Made a parse tree for the different opcodes to be decoded into their respective instruction calls. These instruction calls are represented as methods in the CHIP8 class.

Up next is to fill out those instructions and test to see if the parse tree is working.

When testing the parse tree, I noticed that the instruction was being read one byte at a time, so I fixed that. Now instructions are reading correctly. The only way to know if it is actually working is to get a display running.

### Accomplishments

- Instruction parse tree
- Fixed OpCode class
- Fix instruction reading (was reading one byte, not two)

## Feb 2 - Feb 16

Starting development on CHIP-8. Had to start by making sure my project would build with cmake. Tested this by printing "test" to the console.

I was able to build an executable and, once I ran it, "test" showed up, so things seem to be working.

I also needed command line arguments for the user to specify which rom to be loaded.
So I made it so I can parse a file path from the command line.

The user can now specify a rom to load and it will be loaded into the CHIP8 RAM.

Up next, instruction parsing.

Started with making an OpCode class, because instructions are two bytes long and RAM is byte addressed.
All this class does is allow two bytes to be stored so opcodes can be accessed via their high and low bytes.

Then, I made functions for each of the instructions. The idea being I can parse an opcode then call the correct instruction in a switch statement.

Some instructions deal with the display, so I made a simple display class to handle those actions. I will add functionality as I develop the instructions.

### Accomplishments

- CMake files and build testing
- Command line arguments and test rom
- Stream rom data
- Load ROM into RAM
- Start of instruction parsing
- OpCode class
- Display class
