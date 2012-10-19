#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "heap.h"
#include "selection.h"
#include "merge.h"
#include "quick.h"

void print(int s[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d\n" , s[i]);
	}
	printf("\n");
}

void main (int argc, char** argv)
{
	char *algo = NULL;
	int number = 10;
	int print_flag = 0;
	int c;
	int i;

	while ((c = getopt(argc, argv, "n:pa:")) != -1)
	{
		switch (c)
		{
		case 'n':
			number = atoi(optarg);
			break;
		case 'p':
			print_flag = 1;
			break;
		case 'a':
			algo = optarg;
			break;
		}
	}

	int *numbers = malloc(sizeof(int)*number);
	for (i = 0; i < number; i++)
	{
		numbers[i] = rand() % number + 1;
	}

	if (print_flag)
	{
		printf("starting set:\n");
		print(numbers, number);
		printf("\n");
	}
	
	if (strcmp(algo, "selection") == 0)
		selection_sort (numbers, number);
	else if (strcmp(algo, "heap") == 0)
		heap_sort(numbers, number);
	else if (strcmp(algo, "merge") == 0)
		mergesort (numbers, 0, number - 1);
	else if (strcmp(algo, "quick") == 0)
		quicksort(numbers, 0, number - 1);

	if (print_flag)
	{
		printf("sorted set:\n");
		print(numbers, number);
	}
}
