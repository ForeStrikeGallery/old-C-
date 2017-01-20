#include<iostream>
using namespace std;

struct AdjListNode{
	int dest;
	struct AdjListNode* next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int V;
	struct AdjList* array;
};

int main()
{
 
 return 0;
}
