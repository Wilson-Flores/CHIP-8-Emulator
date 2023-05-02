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

	std::default_random_engine randGen;
	std::uniform_int_distribution<uint8_t> randByte;

	Chip8();
	void LoadROM(char const* filename);



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

};



#endif