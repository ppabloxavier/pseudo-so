#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "../include/Memory_mng.hpp"
#include "../include/Process_mng.hpp"
#include "../include/Process.hpp"
#include "../include/Resources_mng.hpp"

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
//	file_name: nome do arquivo com as informações dos processos.
//	*processes: ponteiro para o vetor no qual os processos serão salvos.
// Retorno:
//	void
void read_process_file(string file_name, std::vector<Process> *processes) {

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

	string file_name;
	std::vector<Process> processes;

	// leitura do arquivo que contém os processos a serem criados. le tudo de uma vez e armazena num vetor de vetores de inteiros
	// ou vai fazendo um por um?
	read_process_file(file_name, &processes);

	// fecha-se o arquivo (depende de como será o input)

	// começa-se a "contar o tempo"

	// Inicia cada processo do vetor de processos.
	start_processes(&processes);



	return 0;
}
