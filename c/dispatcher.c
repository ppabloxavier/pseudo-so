#include <stdio.h>
#include <stdlib.h>

#include "process.h"

Process *q1, *q2;

int main (int argc, char *argv[]) {

	char c = '.';
	int i, initTime, priority, cpuTime, memBlocks, printerCode, scannerCode, modemCode, diskCode;
	FILE *pFile;
	Process *p;

	/* Ler arquivo de processos. */

	pFile = fopen(argv[1], "r");
	if(pFile != NULL) {
		while ( fscanf(pFile, "%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d", &initTime,
																	  &c,
																	  &priority,
																	  &c,
																	  &cpuTime,
																	  &c,
																	  &memBlocks,
																	  &c,
																	  &printerCode,
																	  &c,
																	  &scannerCode,
																	  &c,
																	  &modemCode,
																	  &c,
																	  &diskCode) == 15) {
			p = createProcess(initTime, priority, cpuTime, memBlocks, printerCode, scannerCode, modemCode, diskCode);
			addToQueue(&q1, p);
		}
	} else {
		printf("Error while opening the file.\n");
	}
	fclose(pFile);

	


	return 0;
}