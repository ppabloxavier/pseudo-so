#ifndef RESOURCES_MNG_HPP
#define RESOURCES_MNG_HPP

#include <array>
#include "Process.hpp"

#define N_RESOURCES 4 //resources quantity

class Resources_mng {
private:
	//each resource is represented by an array
	std::array<bool, 1> scanners;
	std::array<bool, 2> printers;
	std::array<bool, 1> modems;
	std::array<bool, 2> satas;

	//default constructor
	Resources_mng() {
		//set all resources to available (i.e. true)
		for(bool &element : scanners)
			element = true;
		for(bool &element : printers)
			element = true;
		for(bool &element : modems)
			element = true;
		for(bool &element : satas)
			element = true;
	};

	//default deconstructor
	~Resources_mng() {};

	//check resources availability
	//returns true if all resources are available
	bool checkResourcesAvailability(Process process) const;

public:
	//allocates every resource needed, doesn't allocates anything if not needed
	//returns true if resources were allocated
	//returns false if resources are unavailable
	bool allocateResources(Process process);

	//deallocate every resource in use
	//returns true if operation is successful
	bool deallocateResources(Process process);

};

#endif
