#include <vector>

#ifndef MEMORY_MNG_HPP
#define MEMORY_MNG_HPP

#define REAL_TIME_START 0
#define REAL_TIME_END 63
#define USER_START 64
#define USER_END 1023

class Memory_mng {
public:
	bool ramMemory[1024];
	std::vector<int,int> processOffset;

	Memory_mng();

	allocateMemory(int pid);

	getProcessOffset(int pid);

	getSizeOfFreeMemory(int offset);

};

#endif
