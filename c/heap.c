#include <stdio.h>

typedef struct {
	int *q; //body of queue.
	int n; //number of queue elements.
} priority_queue;

void bubble_down(priority_queue *q, int p);

int pq_parent (int n)
{
	if (n == 1) return -1;
	else return n/2;
}

int pq_left (int n)
{
	return 2*n;
}

int pq_right (int n)
{
	return 2*n+1;
}

priority_queue *pq_create (int size)
{
	priority_queue *q = malloc(sizeof(priority_queue));
	q->q = malloc(sizeof(int)* (size + 1));
	q->n = 0;
	return q;
}

void pq_insert (priority_queue *q, int x)
{
	q->n++;
	int index = q->n;
	int parent_index = pq_parent(index);

	q->q[index] = x;

	while(parent_index != -1 && q->q[parent_index] > q->q[index])
	{
		q->q[index] = q->q[parent_index];
		q->q[parent_index] = x;
		index = parent_index;
		parent_index = pq_parent(index);
	}
}

void pq_insert_all (priority_queue *q, int s[], int n)
{
	int i;
	q->n = n;
	for (i = 1; i <= n; i++)
		q->q[i] = s[i-1];
	for (i = q->n/2; i>=1; i--) bubble_down(q, i);
}

void bubble_down(priority_queue *q, int p)
{
	int l,r; //children
	int x; //swap
	int min_index; //index of lightest element (self, left or right child)

	min_index = p;
	l = pq_left(p);
	r = l+1;

	if (l <= q->n && q->q[min_index] > q->q[l]) min_index = l;
	if (r <= q->n && q->q[min_index] > q->q[r]) min_index = r;

	if (min_index != p)
	{
		x = q->q[p];
		q->q[p] = q->q[min_index];
		q->q[min_index] = x;
		bubble_down(q, min_index);
	}
}

int pq_extract_min (priority_queue *q)
{
	if (q->n <= 0)
	{
		printf("Warning: empty priority queue.\n");
		return -1;
	}

	int min = q->q[1];
	q->q[1] = q->q[q->n];
	q->n--;
	bubble_down(q,1);
	return min;
}

void pq_print(priority_queue *q)
{
	int i;
	printf("number of elements in q: %d\n", q->n);
	for (i = 1; i <= q->n; i++)
		printf("%d  ", q->q[i]);
	printf("\n\n");
}

void heap_sort (int s[], int n)
{
	int i;
	priority_queue *q = pq_create(n);
	pq_insert_all(q, s, n);
	for (i = 0; i < n; i++)
		s[i] = pq_extract_min(q);
}
