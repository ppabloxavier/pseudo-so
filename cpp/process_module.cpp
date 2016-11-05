#include <stdio.h>
#include <stdlib.h>

#include "queues.h"

#define QUANTUM_VALUE 1
#define MAX_PROC 1000

/* initTime, priority, cpuTime, memBlocks, printerCode, scannerCode, modemCode, diskCode; */

typedef struct element  {
	int pid;
	int initTime;
	int priority;
	int memOffset;
	int cpuTime;
	int alocBlocks;
	int printer;
	int scanner;
	int driver;
	struct element *next;
} Process;

/*createProcess(initTime, priority, cpuTime, memBlocks, printerCode, scannerCode, modemCode, diskCode);*/
Process * createProcess(int initTime, int priority, int cpuTime, int memBlocks, int printerCode, int scannerCode, int modemCode, int diskCode) {
	Process *p;
	p = malloc(sizeof(Process));
	p->pid = 1; /* ************************** */
	p->initTime = initTime;
	p->priority = priority;
	p->cpuTime = cpuTime;
	p->memBlocks;
	p->printerCode;
	p->scannerCode;
	p->modemCode;
	p->diskCode;
	p->next = NULL;
	return p;
}

