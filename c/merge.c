#include <stdio.h>
#include "queue.h"

void merge (int s[], int low, int middle, int high);

void mergesort (int s[], int low, int high)
{
	int middle;

	if (low < high)
	{
		middle = (low+high)/2;
		mergesort (s, low, middle);
		mergesort (s, middle+1, high);
		merge(s, low, middle, high);
	}
}

void merge (int s[], int low, int middle, int high)
{
	int i;
	queue *q1, *q2;

	q1 = init_queue();
	q2 = init_queue();

	for (i = low; i <= middle; i++)
		enqueue (q1, s[i]);
	for (i = middle + 1; i <= high; i++)
		enqueue (q2, s[i]);

	i = low;

	while (queue_count(q1) && queue_count(q2))
	{
		if (headq(q1) <= headq(q2))
			s[i++] = dequeue(q1);
		else
			s[i++] = dequeue(q2);
	}

	while (queue_count(q1)) s[i++] = dequeue (q1);
	while (queue_count(q2)) s[i++] = dequeue (q2);

	delete_queue(q1);
	delete_queue(q2);
}
