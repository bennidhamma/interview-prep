#include "stdio.h"

typedef struct tree {
	int item;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} tree;

void insert (tree **t, int i, tree *parent)
{
	tree *p;

	if (*t == NULL)
	{
		p = malloc(sizeof(tree));
		p->item = i;
		p->left = p->right = NULL;
		p->parent = parent;
		*t = p;
		return;
	}

	if ((*t)->item > i)
		insert(&((*t)->left), i, *t);
	else
		insert(&((*t)->right), i, *t);
}

void print (tree *t)
{
	if (t->left)
		print (t->left);
	printf("%d\n", t->item);
	if (t->right)
		print (t->right);
}

tree *search (tree *t, int x)
{
	if (t == NULL)
		return NULL;
	if (t->item == x)
		return t;
	else if (t->item > x)
		return search(t->left, x);
	else
		return search(t->right, x);
}

void main (int argc, char** argv)
{
	int n = 10;
	int items[10] = {5,4,1,9,8,10,11,3,0,-1};
	tree *t = NULL;
    tree *s = NULL;

	for (int i = 0; i < n; i++)
	{
		insert(&t, items[i], NULL);
	}

	print(t);

	s = search (t, 5);

	printf("5 is present? %p\n", s);

	s = search (t, 100);

	printf("100 is present? %p\n", s);
}

