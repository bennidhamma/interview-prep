#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 100

int count = 0;

sem_t counter_sem;

void * thread_add (void *a)
{
	int sem_val, mod;
	int i, tmp;
	
	mod = (int)a;
	
	if (mod == 0)
		sem_wait(&counter_sem);

	for(i = 0; i < NITER; i++)
	{
		sem_getvalue(&counter_sem, &sem_val);
		printf("Mod: %d, Count: %d, sem_val: %d, i: %d\n", mod, count, sem_val, i);
		tmp = count;
		tmp = tmp + 1;
		count = tmp;
	}
	sem_post(&counter_sem);
}

void main(void)
{
	pthread_t t1, t2;

	sem_init (&counter_sem, 0, 0);

	int value;

	pthread_create(&t1, NULL, thread_add, (void *)0);
	pthread_create(&t2, NULL, thread_add, (void *)1);

	pthread_join (t1, NULL);
	pthread_join (t2, NULL);

	printf("Count: %d\n", count);

	sem_destroy (&counter_sem);
	
	pthread_exit(NULL);
}
