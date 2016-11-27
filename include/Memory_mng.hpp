#include <iostream>
#include <map>
#include <vector>
#include "Process.hpp"

#ifndef MEMORY_MNG_HPP
#define MEMORY_MNG_HPP

#define REAL_TIME_START 0
#define REAL_TIME_END 63
#define USER_START 64
#define USER_END 1023

class Memory_mng {
	// our one and only RAM memory. 64 blocks for real-time process and 960 blocks to user processes
	std::array<bool,1024> ramMemory;

	// standard constructor
	Memory_mng();

public:
	// allocate memory to process sended. occupy RAM and mark the offset in the process
	void allocateMemory(Process process);

	// deallocate memory occupied by the process sended. deoccupy RAM. process will be dealt elsewhere
	void deallocateMemory(Process process);

	// get the size of memory available starting from the offset sended
	int getSizeOfFreeMemory(int offset);
};

#endif
