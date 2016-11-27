#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "../include/Memory_mng.hpp"
#include "../include/Process_mng.hpp"
#include "../include/Process.hpp"
#include "../include/Resources_mng.hpp"

#define DEBUG

using namespace std;

// Printa as informações de um processo.
//
// Parâmetros:
//	process: processo que terá as informações printadas.
// Retorno:
//	void
void print_info(Process process) {
	cout << "PID: " << process.pid << '\n';
	cout << "Prioridade: " << process.priority << '\n';
	cout << "Offset de memória: " << process.memory_offset << '\n';
	cout << "Quantidade de blocos alocados: " << process.memory_blocks << '\n';
	cout << "Ultilização de impressora: " << process.printer << '\n';
	cout << "Ultilização de scanner: " << process.scanner << '\n';
	cout << "Ultilização de modem: " << process.modem << '\n';
	cout << "Ultilização de driver: " << process.sata << '\n';
}

// Lê o arquivo de processos e os adiona a um vetor.
//
// Parâmetros:
//	fileName: nome do arquivo com as informações dos processos.
//	*processes: ponteiro para o vetor no qual os processos serão salvos.
// Retorno:
//	void
void read_processes_file(string fileName, std::vector<Process> *processes) {
	ifstream inputFile;
    unsigned int i;
	vector<int> processData; /* param order
						1- init time
						2- priority
						3- cpuTime
						4- memBlocks
						5- printerCode
						6- scannerCode
						7- modemCode
						8- diskCode
						 */

    // open file for reading
    inputFile.open(fileName.c_str());

	if(inputFile.is_open()) {
 		// read file until the end
	    string str;

		while (getline(inputFile, str) && str.length() > 0) {
			cout << "Linha atual: [" << str << "]" << endl;
			stringstream ss(str);
			while(ss >> i) {
				processData.push_back(i);
				if (ss.peek() == ',') {
					ss.ignore();
				}
			}
			Process process(processData.at(0), processData.at(1), processData.at(2), processData.at(3), processData.at(4), processData.at(5),
							processData.at(6), processData.at(7));

			#ifdef DEBUG
			for (i=0; i < processData.size(); i++) {
				cout << processData.at(i) << ' ';
			}
			#endif

			(*processes).push_back(process);

			// Salva a posição do processo no vetor de processos. Isso
			// facilita a remoção do processo posteriormente.
			(*processes).back().it = (*processes).end() - 1;

			processData.clear();
		}

		// close file
	    inputFile.close();
 	} else {
 		cout << "Error opening file." << endl;
 	}
};

// Inicia cada processo do vetor de processos.
// Para cada processo é necessário:
// 1 - Alocar memória.
// 2 - Colocar o processo em uma das filas do gerenciador de processos.
// 3 - Chamar a função print_info para printar as informações de cada processo.
//
// Parâmetros:
//	*process: ponteiro para o vetor de processos.
// Retorno:
//	void
void start_processes(std::vector<Process> *processes) {
	std::vector<Process>::iterator it;

	// Printando as informações de todos os processos.
	for (it = processes->begin(); it != processes->end(); it++) {
		print_info(*it);
	}
}

int main (int argc, char *argv[]) {

/*
Na crição do processo, o dipatcher exibe as seguintes mensagens:
• PID (int); (uma variavel global de,no máximo, 1000)
• Prioridade do processo (int); (sera dado na entrada)
• Offset da memória (int); (local da memoria onde foi alocado)
• Quantidade de blocos alocados (int); (blocos contiguos ocupados)
• Utilização de impressora (bool); (pode ser um int por ter mais de uma?)
• Utilização de scanner (bool);
• Utilização de drivers (bool).

*/

	Process_mng process_mng = Process_mng::getInstance();
	uint64_t clock = 0;
	string file_name = argv[1];
	vector<Process> processes;
	vector<Process>::iterator it;

	// leitura do arquivo que contém os processos a serem criados. le tudo de uma vez
	read_processes_file(file_name, &processes);

	for (it = processes.begin(); it < processes.end(); it++) {
		// Primeiro verificar tempo de chegada (clock).

		// Checar recursos.

		// Depois checar se tem memória e alocar, caso possível.

		// Se tiver memória e recursos, adicionar nos processos prontos.
		if (process_mng.add_process(&*it) )
			it->executing = 1;
		else
			it->executing = 0;
	}

	// Começar a execução dos processos
	while(1) {
		this_thread::sleep_for(chrono::seconds(1));

		clock++;

		if (process_mng.exec() ) {
			// Retirar o processo das filas do gerenciador de processos.
			process_mng.del_process();
			// Liberar memória associada ao processo.
			// Liberar recursos associados ao processo.
		}

		// Adicionar processos que chegaram nesse instante ou processos
		// que estavam esperando por memória ou recursos.


	}






	return 0;
}
