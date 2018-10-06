#include <stdio.h>
#include <stdlib.h>

struct adjlistNode{
  int val;
  struct adjlistNode *next;
};

struct Graph{
	int V;
	struct adjlistNode **arr;
};

struct adjlistNode *createNewnode(int val){
	
	struct adjlistNode *node=(struct adjlistNode*)malloc(sizeof(struct adjlistNode));
	node->val=val;
	node->next=NULL;
}

// undirected
void addnode(struct Graph *graph,int src,int dest){

	struct adjlistNode *newnode=createNewnode(dest);
	newnode->next = graph->arr[src];
	graph->arr[src]=newnode;

    newnode = createNewnode(src); 
    newnode->next = graph->arr[dest]; 
    graph->arr[dest] = newnode; 

}

struct Graph *createGraph(int V){

	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V =V;
	graph->arr=(struct adjlistNode**)malloc(sizeof(struct adjlistNode*)*V);

	int i;
	for (i = 0; i < V; ++i)
		graph->arr[i]=NULL;

	return graph;
}

void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->V; ++v) 
    { 
        struct adjlistNode* pCrawl = graph->arr[v]; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->val); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

int main(){

  struct Graph *graph=createGraph(5);
    addnode(graph, 0, 1); 
    addnode(graph, 0, 4); 
    addnode(graph, 1, 2); 
    addnode(graph, 1, 3); 
    addnode(graph, 1, 4); 
    addnode(graph, 2, 3); 
    addnode(graph, 3, 4); 
    
    printGraph(graph); 

  return(0);
}
