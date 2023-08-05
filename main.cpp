#include "Chip8.hpp"
#include "Platform.hpp"
#include <string>


int main (int argv, char** args){

    //if (argc != 4){
    //    // std::cerr is specificially intended for error reporting
    //    std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";

    //    // std::exit is a function from <cstdlib> or stdlib.h
    //    // function takes an int param as its argument
    //    // EXIT_FAILURE/SUCCESS are macros to indicate failure/success exit statuses
    //    std::exit(EXIT_FAILURE);
    //}

    // std::stoi takes in std::string as input and returns an int value
    // interprets the characters in the string as an int and performs a conversion
    constexpr int videoScale = 10;
    constexpr int cycleDelay = 1;
    const std::string romFilename = "test_opcode.ch8";

    // create platform object 
    Platform platform("CHIP-8 Emulator", VIDEO_WIDTH * videoScale, VIDEO_HEIGHT * videoScale, VIDEO_WIDTH, VIDEO_HEIGHT);

    // create chip8 object and load rom file
    Chip8 chip8;
    chip8.LoadROM(romFilename.c_str());

    // videoPitch determines the offset between the start of each line in the video buffer
    int videoPitch = sizeof(chip8.video[0] * VIDEO_WIDTH);

    // capture the current time as a time point
    std::chrono::time_point<std::chrono::high_resolution_clock> lastCycleTime = std::chrono::high_resolution_clock::now();
    

    bool quit = false;

    while (!quit){
        quit = platform.ProcessInput(chip8.keypad);

        std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

        // delta time
        float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();
    
        if (dt > cycleDelay){
            lastCycleTime = currentTime;

            chip8.Cycle();

            platform.update(chip8.video, videoPitch);
        }
    }

    return 0;
}