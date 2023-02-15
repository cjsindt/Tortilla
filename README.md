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

# Progress Updates

## Feb 2 - Feb 16

Starting development on CHIP-8. Had to start by making sure my project would build with cmake. Tested this by printing "test" to the console.

Once I ran the executable, "test" showed up, so things seem to be working.

I also needed command line arguments for the user to specify which rom to be loaded.
So I made it so I can parse a file path from the command line.

### Accomplishments

- CMake files and build testing
- Command line arguments and test rom
- Stream rom data

