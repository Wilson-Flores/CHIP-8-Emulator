# CHIP-8-Emulator

As a personal project, I am building a CHIP-8 emulator using C++ and following Austin Morlan's guide, "Building a CHIP-8 Emulator [C++]." The aim of this project is to learn the process of creating an emulator from scratch, and to gain experience in working with low-level programming concepts such as memory management, instruction set architecture, and graphics rendering.

## <span style="font-size: smaller;">Motivation</span>

I decided to work on this project because I wanted to challenge myself with a low-level programming task and learn about computer systems at a deeper level. By building an emulator, I can gain insight into how processors work, how memory is managed, and how software interacts with hardware.

## <span style="font-size: smaller;">Features</span>

My CHIP-8 emulator currently supports the following features:

- Loading and running CHIP-8 ROMs.
- Emulating the CHIP-8 CPU instructions and system memory.
- Handling input from a keyboard and mapping it to the CHIP-8 keypad.
- Rendering graphics on a simple screen using SDL2 library.
- Supporting sound playback for CHIP-8 sound effects.


## <span style="font-size: smaller;">Source</span>
This is project is based on the Austin Morlan's tutorial on "Building A CHIP-8 Emulator [C++]."

Link: https://austinmorlan.com/posts/chip8_emulator/#loading-a-rom


## <span style="font-size: smaller;">Conclusion</span>
I had a handful of issues with Austin Morlan's code. After doing some research on other people's CHIP8 emulator projects, JamesGriffin's CHIP-8-Emulator project gave me a lot of inspiration to re-writing my code. One of my main issues I had with my initial code was the window display. It would only show a black screen after running a CHIP8 rom file. I decided to remove OpenGL from my project and rework my Platform files to only use SDL2. 

This was an interesting project to work on. It took me many months to understand what was going on under the hood of a CHIP8 emulator, for example the way bits are manipulated during the execution of many of the opcodes. Understanding how to use SDL2 was also another issue since I had no experience using the library in the past. 

## <span style="font-size: smaller;">References</span>
These links were very helpful in my journey to making this emulator.

CHIP-8 Wikipedia:
- https://en.wikipedia.org/wiki/CHIP-8

JamesGriffin's CHIP-8-Emulator:
- https://github.com/JamesGriffin/CHIP-8-Emulator

Lazy Foo's Beginning Game Programming v2.0 (SDL2 Tutorial):
- https://lazyfoo.net/tutorials/SDL/index.php#Hello%20SDL  
