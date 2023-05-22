#include "Chip8.hpp"
#include "Platform.hpp"



int main (int argc, char **argv){

    if (argc != 4){
        // std::cerr is specificially intended for error reporting
        std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";

        // std::exit is a function from <cstdlib> or stdlib.h
        // function takes an int param as its argument
        // EXIT_FAILURE/SUCCESS are macros to indicate failure/success exit statuses
        std::exit(EXIT_FAILURE);
    }

    // std::stoi takes in std::string as input and returns an int value
    // interprets the characters in the string as an int and performs a conversion
    int videoScale = std::stoi(argv[1]);
    int cycleDelay = std::stoi(argv[2]);
    char const* romFilename = argv[3];


    return 0;
}