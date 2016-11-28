/* Estrutura dos Recursos Disponíveis
O pseudo-SO deve, além de escalonar o processo no compartilhamento da CPU, e gerenciar o
espaço de memória de acordo com as áreas reservadas, ele deve gerenciar os seguintes recursos:
• 1 scanner
• 2 impressoras
• 1 modem
• 2 dispositivos SATA
Todos os processos, com exceção daqueles de tempo-real podem obter qualquer um desses
recursos. O pseudo-SO deve garantir que cada recurso seja alocado para um proceso por vez. Portanto, não
há preempção na alocação dos dispositivos de E/S.
Processos de tempo-real não precisam de recursos de I/O e podem ter tamanho fixo, ficando a cargo
do programador. */

#include "../include/Resources_mng.hpp"
#include "../include/Process.hpp"

bool Resources_mng::allocateResources(Process process) {
	if(!checkResourcesAvailability(process))
		return false;

	if(process.scanner) {
		for(bool &element : scanners)
			if(element == true) {
				element = false;
				break;
			}
	}

	if(process.printer) {
		for(bool &element : printers)
			if(element == true) {
				element = false;
				break;
			}
	}

	if(process.modem) {
		for(bool &element : modems)
			if(element == true) {
				element = false;
				break;
			}
	}

	if(process.sata) {
		for(bool &element : satas)
			if(element == true) {
				element = false;
				break;
			}
	}

	return true;
}

bool Resources_mng::deallocateResources(Process process) {
	if(process.scanner) {
		for(bool &element : scanners)
			if(element == false) {
				element = true;
				break;
			}
	}

	if(process.printer) {
		for(bool &element : printers)
			if(element == false) {
				element = true;
				break;
			}
	}

	if(process.modem) {
		for(bool &element : modems)
			if(element == false) {
				element = true;
				break;
			}
	}

	if(process.sata) {
		for(bool &element : satas)
			if(element == false) {
				element = true;
				break;
			}
	}

	return true;
}

bool Resources_mng::checkResourcesAvailability(Process process) const {
	bool available = false;

	if(process.scanner) {
		available = false;
		for(const bool &element : scanners)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false;
	}

	if(process.printer) {
		available = false;
		for(const bool &element : printers)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false;
	}

	if(process.modem) {
		available = false;
		for(const bool &element : modems)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false;
	}

	if(process.sata) {
		available = false;
		for(const bool &element : satas)
			if(element == true) {
				available = true;
				break;
			}
		if(!available)
			return false;
	}

	return true;
}