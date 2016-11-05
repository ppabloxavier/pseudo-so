
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


// 2 queues: real time (priority 0 - FIFO) and user processes (priorities 1, 2 and 3.)

// maximum of 1000 processes for both queues