#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

	char c = '.';
	int i, procArguments[8];
	FILE *pFile;

	/* Ler arquivo de processos. */


	/* 
	<tempo de inicialização>,
	<prioridade>,
	<tempo de processador>,
	<blocos em memória>,
	<número-código da impressora requisitada>,
	<requisição do scanner>,
	<requisição do modem>,
	<número-código do disco>

	*/


	pFile = fopen(argv[1], "r");
	if(pFile != NULL) {
		while ( fscanf(pFile, "%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d", &procArguments[0],
																	  &c,
																	  &procArguments[1],
																	  &c,
																	  &procArguments[2],
																	  &c,
																	  &procArguments[3],
																	  &c,
																	  &procArguments[4],
																	  &c,
																	  &procArguments[5],
																	  &c,
																	  &procArguments[6],
																	  &c,
																	  &procArguments[7]) == 15) {
			
		}
	} else {
		printf("Error while opening the file.\n");
	}
	fclose(pFile);

	


	return 0;
}