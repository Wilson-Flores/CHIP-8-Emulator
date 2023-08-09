#include "Chip8.hpp"
#include "Platform.hpp"
#include <iostream>
#include <string>
#include <thread>


int main (int argc, char** argv){

    if (argc != 2){
        // std::cerr is specificially intended for error reporting
        std::cerr << "Usage: chip8 <ROM>\n";

        // std::exit is a function from <cstdlib> or stdlib.h
        // function takes an int param as its argument
        // EXIT_FAILURE/SUCCESS are macros to indicate failure/success exit statuses
        std::exit(EXIT_FAILURE);
    }

    const char* romFilename = argv[1];

    // create platform object 
    int width = 1024;
    int height = 512;
    Platform platform("CHIP-8 Emulator", width, height);

    // create chip8 object and load rom file
    Chip8 chip8;
    chip8.LoadROM(romFilename);

    // Emulation loop
    bool quit = false;
    while (!quit){
        quit = platform.ProcessInput(chip8.keypad);

        chip8.Cycle();

        if (chip8.drawFlag) {
            chip8.drawFlag = false;
            platform.update(chip8.video);
        }

        // Sleep to slow down emulation speed
        std::this_thread::sleep_for(std::chrono::microseconds(1200));
    }
    return 0;
}