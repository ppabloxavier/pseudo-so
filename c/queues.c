
void initializeQueue(Process **q) {
	(*q) = NULL;
}

void addToQueue(Process **q, Process *p) {
	ProcQueue *ptr;

	ptr = (*q);
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
}