#include "stdio.h"

typedef int data_type;
typedef unsigned int uint;

typedef struct tuple {
	char *key;
	data_type value;
} tuple;

typedef struct dynamic_array {
	int size;
	int count;
	tuple *data;
} dynamic_array;

typedef struct hashtable {
	int size;
	dynamic_array *array;
} hashtable;

hashtable *create_hashtable (int size)
{
	hashtable *h = malloc(sizeof(hashtable));
	h->size = size;
	h->array = malloc(sizeof(dynamic_array) * size);
	for(int i = 0; i < size; i++)
		h->array[i].size = h->array[i].count = 0;
	return h;
}

uint hash (char *key)
{
	int len = strlen (key);
	int i;
	int int_size = sizeof(int);
	uint hash = 0;
	
	for (i = 0; i < len; i+=int_size)
		hash += (int)key[i];

	return hash;
}

void insert (hashtable *h, char *key, data_type x)
{
	int index = hash (key) % h->size;
	printf ("inserting %s to hash %d\n", key, index);
	int i;
	tuple t;
	t.key = key;
	t.value = x;
	dynamic_array *d = &(h->array[index]);
	if (d->size == 0)
	{
		d->data = malloc(sizeof(tuple)*4);
		d->size = 4;
		d->data[0] = t;
		d->count = 1;
	}
	else if (d->count < d->size)
	{
		d->data[d->count++] = t;
	}
	else
	{
		tuple *new_arr = malloc(sizeof(tuple) * d->size * 2);
		for (i = 0; i < d->size; i++)
			new_arr[i] = d->data[i];
		d->data = new_arr;
		d->size *= 2;
		d->data[d->count++] = t;
	}
}

int search (hashtable *h, char *key, data_type *result)
{
	int index = hash(key) % h->size;
	printf ("searching for %s with hash %d\n", key, index);
	int i;

	dynamic_array *d = &(h->array[index]);

	if (d->size == 0)
	{
		printf("size is 0\n");
		return 0;
	}

	for (i = 0; i < d->count; i++)
	{
		if (d->data[i].key == key)
		{
			*result = d->data[i].value;
			return 1;
		}
	}

	printf("did not find");
	return 0;	
}

void main (int argc, char **argv)
{
	hashtable *h = create_hashtable(3);

	insert (h, "first", 1);
	insert (h, "second", 2);
	insert (h, "third", 3);
	insert (h, "Third", 4);

	data_type r;
   	int found = search (h, "first", &r);
	printf ("found ? r: %d, %d", r, found);
   	found = search (h, "second", &r);
	printf ("found ? r: %d, %d", r, found);
}
