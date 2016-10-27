#include <stdio.h>
#include <stdlib.h>

#include "filas.h"

#define QUANTUM_VALUE 1
#define MAX_PROC 1000

typedef struct element  {
	int pid;
	int timeInit;
	int priority;
	int memOffset;
	int cpuTime;
	int alocBlocks;
	int printer;
	int scanner;
	int driver;
	struct element *next;
} ProcQueue;

ProcQueue *q1, *q2;


int main () {

	initializeQueue(&q1);
	initializeQueue(&q2);
	
	ProcQueue *p1 = createProcess();

	addToQueue();
	
	return 0;
}