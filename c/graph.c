#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

#define MAXV	1000

typedef struct edgenode {
	int y; 					// adjacency info
	int weight; 			// edge weight, if any
	struct edgenode *next;
} edgenode;

typedef struct {
	edgenode *edges[MAXV+1];	// adjacency info
	int degree[MAXV+1]; 	// outdegree of each vertex
	int nvertices;			// number of vertices in graph
	int nedges;				// number of edges in graph
	bool directed;			// is the graph directed?
} graph;

void insert_edge (graph *g, int x, int y, bool directed);

init_graph(graph *g, bool directed)
{
	int i;

	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;

	for(i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for(i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

read_graph(graph *g, bool directed)
{
	int n;					// number of vertexes;
	int x, y;				// vertices in edge (x,y)

	init_graph(g, directed);
	
	n = 0;

	while(scanf("%d %d", &x, &y) == 2)
	{
		insert_edge(g, x, y, directed);
		if (x > n) n = x;
		if (y > n) n = y;	
	}

	g->nvertices = n;
}

void insert_edge (graph *g, int x, int y, bool directed)
{
	edgenode *e = malloc(sizeof(edgenode));
	e->y = y;
	e->weight = 0;
	e->next = g->edges[x];
	g->edges[x] = e;
	g->degree[x]++;
	if (directed == false)
		insert_edge (g, y, x, true);
	else
		g->nedges++;
}

print_graph(graph *g)
{
	int i;
	edgenode *p;

	for(i = 1; i <= g->nvertices; i++)
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL)
		{
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}

typedef struct {
	bool processed[MAXV+1];
	bool discovered[MAXV+1];
	int parent[MAXV+1];
	void (*process_vertex_early)(int);
	void (*process_vertex_late)(int);
	void (*process_edge)(edgenode *);
} searcher;

init_searcher(graph *g, searcher *s)
{
	s->process_vertex_early = NULL;
	s->process_vertex_late = NULL;
	s->process_edge = NULL;

	int i;

	for (i = 1; i <= g->nvertices; i++)
	{
		s->processed[i] = s->discovered[i] = false;
		s->parent[i] = -1;
	}
}

bfs (graph *g, int start, searcher *s)
{
	queue *q;				// queue of vertices to visit
	int v;					// current vertex
	int y;					// successor vertex
	edgenode *p;

	q = init_queue();
	enqueue(q, start);
	s->discovered[start] = true;

	while(queue_count(q))
	{
		v = dequeue(q);
		if (s->process_vertex_early != NULL)
			(*s->process_vertex_early)(v);
		s->processed[v] = true;
		p = g->edges[v];
		while (p != NULL)
		{
			y = p->y;
			if ((s->processed[y] == false || g->directed) &&
					s->process_edge != NULL)
				(*s->process_edge)(p);
			if (s->discovered[y] == false)
			{
				enqueue(q, y);
				s->discovered[y] = true;
				s->parent[y] = v;
			}
			p = p->next;
		}
		if (s->process_vertex_late != NULL)
			(*s->process_vertex_late)(v);
	}
}

void print_vertex_start (int v)
{
	printf("%d: ", v);
}

void print_edge (edgenode *e)
{
	printf(" %d", e->y);
}

void print_vertex_late (int v)
{
	printf("\n");
}

int main(int argc, const char *argv[])
{
	graph g;
	read_graph(&g, false);

	searcher s;
	init_searcher(&g, &s);

	s.process_vertex_early = &print_vertex_start;
	s.process_vertex_late = &print_vertex_late;
	s.process_edge = &print_edge;

	printf("simple print:\n");
	print_graph(&g);
	printf("bfs:\n");
	bfs (&g, 1, &s);

	return 0;
}
