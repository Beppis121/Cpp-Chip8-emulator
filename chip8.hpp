#pragma once
#include <fstream>
#include <utility>
#include <string>
//#include <concepts>
class Chip8
{
private:
	
	// emulates the 4 kilobytes of memory
	uint8_t memory[4096];
	// program counter; points to current instruction in memory
	uint16_t pc;
	// index register; points at locations in memory
	uint16_t I;
	// Stack; for 16 bit addr, used to call subrounties or functions and return from them
	uint16_t stack[16];
	// Stack Pointer; points to locations in stack(assumed as of 2/5/22)
	uint16_t sp;
	// Delay Timer; decremented at a rate of 60 Hz until it reaches 0
	uint8_t delay_timer;
	// Sound Timer; functions like the delay timer, but which also gives off a beeping sound as long as it’s not 0
	uint8_t sound_timer;
	// General Purpose Variable Registers; numbered such as V0-VF, VF is known as a flag register will almost always be set to 0 or 1
	uint8_t V[16];
	// Current Opcode;
	uint16_t opcode;
public:
	// display using orginal 64 x 32 buffer
	uint8_t display[64 * 32];
	// Keypad
	uint8_t key[16];
	// checks if a draw has occured
	bool Draw;
	// Constructor
	Chip8(); 
	// Emulate as cycle
	void cycle();
	// load rom
	bool load_rom(const std::string& rom_path);
};