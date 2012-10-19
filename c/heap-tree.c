#include <stdio.h>

typedef struct heap {
	int item;
	struct heap *left;
	struct heap *right;
} heap;

void insert (heap *h, int item)
{	
	heap **target;
	if (rand() % 2 == 0)
		target = &h->left;
	else
		target = &h->right;

	if (*target == NULL)
	{
		*target = malloc(sizeof(heap));
		(*target)->left = NULL;
		(*target)->right = NULL;

		if (item < h->item)
		{
			(*target)->item = h->item;
			h->item = item;
		}
		else
			(*target)->item = item;
	}
	else
	{
		if (item < h->item)
		{
			insert(*target, h->item);
			h->item = item;
		}
		else
			insert(*target, item);
	}
}

int extract_min(heap **h)
{
	heap *hp = *h;
	int result = hp->item;

	if (hp->left == NULL && hp->right == NULL)
	{
		free (hp);
		*h = NULL;
	}
	else if (hp->left == NULL && hp->right != NULL)
		hp->item = extract_min (&hp->right);
	else if (hp->left != NULL && hp->right == NULL)
		hp->item = extract_min (&hp->left);
	else if (hp->left->item < hp->right->item)
		hp->item = extract_min(&hp->left);	
	else
		hp->item = extract_min(&hp->right);

	return result;
}

void heap_sort (int s[], int n)
{
	heap *h = malloc(sizeof(heap));
	h->left = NULL;
	h->right = NULL;
	h->item = s[0];

	int i;
	
	for (i = 1; i < n; i++)
	{
		insert(h, s[i]);
	}

	for (i = 0; i < n; i++)
	{
		s[i] = extract_min (&h);
	}
}
