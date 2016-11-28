#ifndef RESOURCES_MNG_HPP
#define RESOURCES_MNG_HPP

#include <array>
#include "Process.hpp"

#define N_RESOURCES 4

class Resources_mng {
	std::array<bool, 1> scanners;
	std::array<bool, 2> printers;
	std::array<bool, 1> modems;
	std::array<bool, 2> satas;

private:
	Resources_mng() {
		for(bool &element : scanners)
			element = true;
		for(bool &element : printers)
			element = true;
		for(bool &element : modems)
			element = true;
		for(bool &element : satas)
			element = true;
	};

	~Resources_mng() {};

public:

	bool allocateResources(Process process);

	bool deallocateResources(Process process);

	bool checkResourcesAvailability(Process process) const;
};

#endif
