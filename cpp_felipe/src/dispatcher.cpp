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

using namespace std;

unsigned int globalProcessIds;

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

			for (i=0; i < processData.size(); i++) {
				cout << processData.at(i) << ' ';
			}

			processData.clear();
		}

		// close file
	    inputFile.close();
 	} else {
 		cout << "Error opening file." << endl;
 	}
}

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
	string file_name = argv[1];

	// leitura do arquivo que contém os processos a serem criados. le tudo de uma vez
	read_processes_file(file_name, process_mng.getProcesses());

	// fecha-se o arquivo (depende de como será o input)

	// começa-se a "contar o tempo"

	// Inicia cada processo do vetor de processos.
	start_processes(process_mng.getProcesses());



	return 0;
}
