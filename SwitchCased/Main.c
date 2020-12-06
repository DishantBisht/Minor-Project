#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999
#define V 20
#include"structure.h"
#include"psuedoGraph.h"
#include"min.h"
#include"infAssign.h"
#include"dijkstra.h"
#include"bellmanFord.h"
#include"floydWarshall.h"
#include"aStar.h"

 int main()
{
	int G[V][V],i,j,n,u,v,choice = 1;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	printf("\nEnter the destination node:");
	scanf("%d",&v);
	infAssign(G,n);
	psuedoGraph(G,n);
	
	while(choice != 5){
		printf("\nEnter Choice \n 1. Dijkstra \n 2. Bellman Ford \n 3. floyd Warshall \n 4. A star \n 5. Exit \n");
		scanf("%d",&choice);

		switch (choice)
		{
		case 1: dijkstra(G,n,u,v);
			break;
		case 2: bellmanFord(G,n,u,v);
			break;
		case 3: floydWarshall(G,n,u,v);
			break;
		case 4: aStar(n,u,v);
			break;
		case 5: return 0;
		default: printf("\n Invalid choice. Try Again!");
			break;
		}
	}
	
	return 0;
}