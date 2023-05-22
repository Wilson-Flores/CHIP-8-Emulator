#ifndef Chip8_hpp
#define Chip8_hpp


#include <cstdint>
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <cstring>

const unsigned int VIDEO_WIDTH = 64;
const unsigned int VIDEO_HEIGHT = 32;
const unsigned int REGISTER_COUNT = 16;
const unsigned int MEMORY_SIZE = 4096;
const unsigned int STACK_LEVELS = 16;
const unsigned int KEY_COUNT = 16;

class Chip8 {
public:
	uint8_t registers[REGISTER_COUNT]{}; // 16 8-bit Registers
	uint8_t memory[MEMORY_SIZE]{}; // 4K Bytes of Memory
	uint16_t index{}; // 16-bit Index Register
	uint16_t pc{}; // 16-bit Program Counter
	uint16_t stack[STACK_LEVELS]{}; // 16-level Stack (It holds 16 different PCs)
	uint8_t sp{}; // 8-bit Stack Pointer
	uint8_t delayTimer{}; // 8-bit Delay Timer
	uint8_t soundTimer{}; // 8-bit Sound Timer
	uint8_t keypad[KEY_COUNT]{}; // 16 Input Keys
	uint32_t video[VIDEO_WIDTH * VIDEO_HEIGHT]{}; // 64x32 Monochrome Display Memory
	uint16_t opcode; // encodes an operation and relevant data into a number that a machine can read.

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

	Chip8();
	void LoadROM(char const* filename);

	// function pointer tables with same first digits
	void Table0();
	void Table8();
	void TableE();
	void TableF();

	// create new type 'Chip8Func' 
	typedef void (Chip8::*Chip8Func)();
	Chip8Func table[0xF +1];
	Chip8Func table0[0xE +1];
	Chip8Func table8[0xE +1];
	Chip8Func tableE[0xE +1];
	Chip8Func tableF[0x65 +1];

	// Fetch, Decode, Execute instruction
	void Cycle();


	// Instructions

	// Do nothing
	void OP_NULL();

	// CLS
	void OP_00E0();

	// RET
	void OP_00EE();

	// JP addr
	void OP_1nnn();

	// CALL addr
	void OP_2nnn();

	// 3xkk - SE Vx, byte
	void OP_3xkk();

	// 4xkk - SNE Vx, byte
	void OP_4xkk();

	// 5xy0 - SE Vx, Vy
	void OP_5xy0();
	
	// 6xkk - LD Vx, byte
	void OP_6xkk();

	// 7xkk - ADD Vx, byte
	void OP_7xkk();

	// 8xy0 - LD Vx, Vy
	void OP_8xy0();

	// 8xy1 - OR Vx, Vy
	void OP_8xy1();

	// 8xy2 - AND Vx, Vy
	void OP_8xy2();
	
	// 8xy3 - XOR Vx, Vy
	void OP_8xy3();

	// 8xy4 - ADD Vx, Yv
	void OP_8xy4();

	// 8xy5 - SUB Vx, Vy
	void OP_8xy5();

	// 8xy6 - SHR vx
	void OP_8xy6();

	// 8xy7 - SUBN Vx, Vy
	void OP_8xy7();

	// 8xyE - SHL Vx {, Vy}
	void OP_8xyE();

	// 9xy0 - SNE Vx, Vy
	void OP_9xy0();

	// Annn - LD I, addr
	void OP_Annn();

	// Bnnn - JP V0, addr
	void OP_Bnnn();

	// Cxkk - RND Vx, byte
	void OP_Cxkk();

	// Dxyn - DRW Vx, Vy, nibble
	void OP_Dxyn();

	// Ex9E - SKP Vx
	void OP_Ex9E();

	// ExA1 - SKNP Vx
	void OP_ExA1();

	// Fx07 - LD Vx, DT
	void OP_Fx07();

	// Fx0A - LD Vx, K
	void OP_Fx0A();

	// Fx15 - LD DT, Vx
	void OP_Fx15();

	// Fx18 - LD ST, Vx
	void OP_Fx18();

	// Fx1E - ADD I, Vx
	void OP_Fx1E();

	// Fx29 - LD F, Vx
	void OP_Fx29();

	// Fx33 - LD B, Vx
	void OP_Fx33();

	// Fx55 - LD [I], Vx
	void OP_Fx55();

	// Fx65 - LD Vx, [I]
	void OP_Fx65();

};



#endif