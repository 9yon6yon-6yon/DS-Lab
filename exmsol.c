/*#include <stdio.h>
int main()
{
	// declaring the variables
	int w[9], W, temp, sum_of_weight = 0, x[9], ab, j;
	// prompt user to enter the capacity of the bag
	printf("Please enter the capacity of the bag:\t");
	scanf("%d", &W);
	// prompt user to enter the weight of the various items
	printf("\nPlease enter the weights of various items:\t");
	for (ab = 0; ab < 9; ab++)
		scanf("%d", &w[ab]);
	temp = W;
	// Initializing the solution vector
	for (ab = 0; ab < 9; ab++)
	{
		x[ab] = 0; // all data in arrray is NULL
	}
	j = 0;
	// using for loop
	for (ab = 0; ab < 9; ab++)
	{
		if (temp >= w[ab])
		{
			x[j] = w[ab];			// updating NULL value of x array to a value(Weight)
			temp -= w[ab];			// deteling extra weight that was added to x array
			j++;					// updating j's value by 1
			sum_of_weight += w[ab]; // total weight
		}
	}
	// printing the item
	for (ab = 0; ab < 9; ab++)
	{
		if (x[ab] > 0)
			printf("%d\t", x[ab]);
	}
	// displaying the total weight of all items
	printf("Sum is = %d\t", sum_of_weight);
	return 0;
} // 1
*/
/*
// A C Program to demonstrate adjacency list
// representation of graphs
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode
{
	int dest;
	struct AdjListNode *next;
};

// A structure to represent an adjacency list
struct AdjList
{
	struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph
{
	int V;
	struct AdjList *array;
};

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
	struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->V = V;

	// Create an array of adjacency lists. Size of
	// array will be V
	graph->array = (struct AdjList *)malloc(
		V * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode *check = NULL;
	struct AdjListNode *newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL)
	{
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else
	{

		check = graph->array[src].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		// graph->array[src].head = newNode;
		check->next = newNode;
	}

	// Since graph is undirected, add an edge from
	// dest to src also
	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL)
	{
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else
	{
		check = graph->array[dest].head;
		while (check->next != NULL)
		{
			check = check->next;
		}
		check->next = newNode;
	}

	// newNode = newAdjListNode(src);
	// newNode->next = graph->array[dest].head;
	// graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph *graph)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjListNode *pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

// Driver program to test above functions
int main()
{
	// create the graph given in above fugure
	int V = 5;
	struct Graph *graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// print the adjacency list representation of the above
	// graph
	printGraph(graph);

	return 0;
}

// 2
*/