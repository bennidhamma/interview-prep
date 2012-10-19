#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue *init_queue()
{
	queue *q = malloc(sizeof(queue));
	q->q = malloc(sizeof(int)*4);
	q->head = 0;
	q->tail = 0;
	q->size = 4;

	return q;
}

void enqueue (queue *q, int item)
{
	int i;
	if (q->tail >= q->size)
	{
		//first try and pull the items back to the front.
		if (q->head > 0)
		{
			for(i = q->head - 1; i < q->head; i++)
				q->q[i] = q->q[i+1];
			q->tail--;
			q->head--;
		}
		else
		{
			q->size *= 2;
			int *newq = malloc(sizeof(int)*q->size);
			for (i = 0; i < q->tail; i++)
				newq[i] = q->q[i];
			int *oldq = q->q;
			q->q = newq;
			free(oldq);
		}
	}
	q->q[q->tail++] = item;
}

int dequeue (queue *q)
{
	if (q->head > q->tail)
	{
		printf("Warning: dequeueuing an empty queue.\n");
		return -1;
	}
	return q->q[q->head++];
}

int headq (queue *q)
{
	if (q->head > q->tail)
	{
		printf("Warning: headqing an empty queue.\n");
		return -1;
	}
	return q->q[q->head];
}

void delete_queue(queue *q)
{
	if (q == NULL)
		return;
	free(q->q);
	free(q);
}

int queue_count(queue *q)
{
	return q->tail - q->head;
}

/*
int main(int argc, const char *argv[])
{
	int i;
	queue *q = init_queue();
	for (i = 0; i < 10; i++)
		enqueue (q, i);
	for(i = 0; i < 10; i++)
		printf ("%d ", dequeue(q));
	printf ("queue size: %d\n", q->tail - q->head);
	delete_queue(q);
	printf("Queue deleted.\n");
	return 0;
}
*/
