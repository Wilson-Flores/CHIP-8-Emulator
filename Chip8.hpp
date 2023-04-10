#ifndef Chip8_hpp
#define Chip8_hpp


#include <cstdint>
#include <random>


class Chip8 {
public:
	uint8_t registers[16]{}; // 16 8-bit Registers
	uint8_t memory[4096]{}; // 4K Bytes of Memory
	uint16_t index{}; // 16-bit Index Register
	uint16_t pc{}; // 16-bit Program Counter
	uint16_t stack[16]{}; // 16-level Stack (It holds 16 different PCs)
	uint8_t sp{}; // 8-bit Stack Pointer
	uint8_t delayTimer{}; // 8-bit Delay Timer
	uint8_t soundTimer{}; // 8-bit Sound Timer
	uint8_t keypad[16]{}; // 16 Input Keys
	uint32_t video[64 * 32]{}; // 64x32 Monochrome Display Memory
	uint16_t opcode; // encodes an operation and relevant data into a number that a machine can read.

	Chip8();
	void LoadROM(char const* filename);

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;
};

#endif