#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  Disjoin set adalah kumpulan data yg tidak saling berhubung
int parent[255] = {0};

struct Edge{
	int src, dst;
};

struct Graph{
	int vCount, eCount;
	Edge *edge;
};

Graph *createGraph(int vCount, int eCount){
	Graph *newGraph = (Graph *)malloc(sizeof(Graph));
	newGraph->vCount = vCount;
	newGraph->eCount = eCount;
	
	newGraph->edge = (Edge *)malloc(sizeof(Edge) * eCount);
	
	return newGraph;
}

void makeSet(int v){
	for(int i=0; i<v; i++){
		parent[i] = i;
	}
}

int getParent(int v){
	if(parent[v] == v){
		return v;
	}
	return parent[v] = getParent(parent[v]);
}

void join(int vX, int vY){
	int parentvX = getParent(vX);
	int parentvY = getParent(vY);
	
	parent[parentvX] = parentvY;
}

bool isSameSet(int vX, int vY){
	return getParent(vX) == getParent(vY);
}

void unionSet(int a, int b){
	parent[a] = b;
}

bool joinGraph(Graph *graph){
	for(int i=0; i<graph->eCount; i++){
		
		int srcParent = getParent(graph->edge[i].src);
		int dstParent = getParent(graph->edge[i].dst);
		
		if(srcParent == dstParent){
			return true;
		}
		
		unionSet(srcParent, dstParent);
	}
	
	return false;
}

bool isCyclic(Graph *graph){
	makeSet(graph->vCount);
	return joinGraph(graph);
}

int main(){
	
//	makeSet(6);
//	
//	join(1, 2);
//	join(2, 3);
//	join(3, 4);
//	
//	join(5, 6);
//	
//	if(isSameSet(1, 5)){
//		printf("Is Same Set\n");
//	}else{
//		printf("Not Same Set\n");
//	}

	Graph *graph = createGraph(4, 4);
	graph->edge[0].src = 1;	
	graph->edge[0].dst = 2;
	
	graph->edge[1].src = 2;	
	graph->edge[1].dst = 3;
	
	graph->edge[2].src = 3;	
	graph->edge[2].dst = 1;	
	
	graph->edge[3].src = 3;	
	graph->edge[3].dst = 4;
	
	
	
	
	
	return 0;
}
