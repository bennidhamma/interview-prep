#include <stdlib.h>
#include "common.h"

int partition (int s[], int l, int h);

void quicksort (int s[], int l, int h)
{
	int p;

	if ((h-l) > 0)
	{
		p = partition(s,l,h);
		quicksort(s,l, p-1);
		quicksort(s,p+1,h);
	}		
}

int partition (int s[], int l, int h)
{
	int i; //counter;
	int p; //pivot element index
	int firsthigh; //diviider position for pivot element

	//p = (rand() % (h-l)) + l;
	p = h;
	firsthigh = l;

	for (i = l; i<h; i++)
	{
		if (s[i] < s[p])
		{
			swap (&s[i], &s[firsthigh]);
			firsthigh++;
		}
	}
	swap (&s[p], &s[firsthigh]);

	return firsthigh;
}
