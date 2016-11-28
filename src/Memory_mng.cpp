#include "Memory_mng.hpp"

Memory_mng::Memory_mng() {

}

void Memory_mng::allocateMemory(Process process) {
	bool allocationOcurred = false;
	int i, j, begin, end, freeSize, offset;
	if(process.priority <= 0) {
		begin = REAL_TIME_START;
		end = REAL_TIME_END;
	} else {
		begin = USER_START;
		end = USER_END;
	}

	for(i = begin; i <= end; i=i) {
		// se memoria ocupada, pule até achar um espaço vazio
		if(ramMemory.at(i)) {
			while(ramMemory.at(i)) {
				i++;
			}
		} else {
			// se espaço vazio, conte quanto espaço vazio.
			offset = i;
			freeSize = 0;
			while(!ramMemory.at(i) && i<= end) {
				freeSize++;
				i++;
			}

			// serviu?
			if (freeSize >= process.memory_blocks) {
				process.memory_offset = offset;
				for (j=offset; j<i; j++) {
					ramMemory.at(j) = true;
				}
				allocationOcurred = true;
				break;
			} else {
				// nao serviu? pule este espaço pequeno
				i = i + freeSize;
			}
		}
	}

	if(!allocationOcurred) {
		std::cout << "Not enough memory for process with pid: " << process.pid << std::endl;
	}

}

void Memory_mng::deallocateMemory(Process process) {
	int i;
	for(i = process.memory_offset; i <= (process.memory_offset + process.memory_blocks); i++) {
		ramMemory.at(i) = false;
	}
}
