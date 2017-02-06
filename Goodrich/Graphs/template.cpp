#include<iostream>
using namespace std;


struct AdjListNode {
	int dest;
	struct AdjListNode *next;
};

struct AdjList {
	struct AdjListNode *head;
};


struct  Graph
{
	int V;
	struct AdjList *array;
};


struct AdjListNode* newAdjListNode(int dest) {
	struct AdjListNode* newNode = new AdjListNode();
	newNode->next = NULL;
	newNode->dest = dest;
	return newNode;
}

struct Graph *createGraph(int V) {
	struct Graph* graph = new Graph();
	graph->V = V;
	graph->array = new AdjList();
	for(int i=0; i<V; i++) {
		graph->array[i].head = NULL;
	}
	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	struct AdjListNode* newNode = new AdjListNode();
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;


}	

void printGraph
