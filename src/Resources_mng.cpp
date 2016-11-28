#include "../include/Resources_mng.hpp"
#include "../include/Process.hpp"

//allocates every resource needed, doesn't allocates anything if not needed
bool Resources_mng::allocateResources(Process process) {
	if(!checkResourcesAvailability(process)) //check resources availability
		return false; //returns false if resources are unavailable

	//if needed, allocates the free scanner
	if(process.scanner) {
		for(bool &element : scanners)
			if(element == true) {
				element = false;
				break;
			}
	}

	//if needed, allocates the free printer
	if(process.printer) {
		for(bool &element : printers)
			if(element == true) {
				element = false;
				break;
			}
	}

	//if needed, allocates the free modem
	if(process.modem) {
		for(bool &element : modems)
			if(element == true) {
				element = false;
				break;
			}
	}

	//if needed, allocates the free sata
	if(process.sata) {
		for(bool &element : satas)
			if(element == true) {
				element = false;
				break;
			}
	}

	return true; //returns true if resources were allocated
}

//deallocate every resource in use
bool Resources_mng::deallocateResources(Process process) {
	//if needed, frees any used scanner
	if(process.scanner) {
		for(bool &element : scanners)
			if(element == false) {
				element = true;
				break;
			}
	}

	//if needed, frees any used printer
	if(process.printer) {
		for(bool &element : printers)
			if(element == false) {
				element = true;
				break;
			}
	}

	//if needed, frees any used modem
	if(process.modem) {
		for(bool &element : modems)
			if(element == false) {
				element = true;
				break;
			}
	}

	//if needed, frees any used sata
	if(process.sata) {
		for(bool &element : satas)
			if(element == false) {
				element = true;
				break;
			}
	}

	return true; //returns true if operation is successful
}

//check resources availability
bool Resources_mng::checkResourcesAvailability(Process process) const{
	bool available = false;

	//if needed, checks if there's a scanner available
	if(process.scanner) {
		available = false;
		for(const bool &element : scanners)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false; //returns false if there's no scanner available
	}

	//if needed, checks if there's a printer available
	if(process.printer) {
		available = false;
		for(const bool &element : printers)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false; //returns false if there's no printer available
	}

	//if needed, checks if there's a modem available
	if(process.modem) {
		available = false;
		for(const bool &element : modems)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false; //returns false if there's no modem available
	}

	//if needed, checks if there's a sata available
	if(process.sata) {
		available = false;
		for(const bool &element : satas)
			if(element == true) {
				available = true;
				break;
					//checks if scanner is available
			}
		if(!available)
			return false; //returns false if there's no sata available
	}

	return true; //returns true if all resources are available
}