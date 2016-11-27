#include "../include/Memory_mng.hpp"

Memory_mng::Memory_mng() {

}

void Memory_mng::allocateMemory(int pid, int offset) {

}

int Memory_mng::getProcessOffset(int pid) {
	std::map<int,int>::iterator it = processOffset.find(pid);
	if (it != processOffset.end()) {
		return it->second;
	} else {
		std::cout << "Process not allocated" << std::endl;
		return -1;
	}
}

int Memory_mng::getSizeOfFreeMemory(int offset) {
	int i, size = 0;

	i = offset;
	while(!ramMemory[i] || i <= REAL_TIME_END || i <= USER_END) {
		size++;
	}
	return size;
}
