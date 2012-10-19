#ifndef QUEUE
#define QUEUE

typedef struct {
	int *q;
	int head;
	int tail;
	int size;
} queue;

queue *init_queue ();
void enqueue (queue *q, int item);
int dequeue (queue *q);
int headq (queue *q);
void delete_queue(queue *q);
int queue_count (queue *q);

#endif
