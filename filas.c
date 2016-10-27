
void initializeQueue(ProcQueue **q) {
	(*q) = NULL;
}

ProcQueue * createProcess() {
	
}

void addToQueue(ProcQueue **q, ProcQueue *p) {
	ProcQueue *ptr;

	ptr = (*q);
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
}