#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INFINITY 999
#define V 100
#include"structure.h"
#include"psuedoGraph.h"
#include"min.h"
#include"infAssign.h"
#include"dijkstra.h"
#include"bellmanFord.h"
#include"floydWarshall.h"
#include"aStar.h"
#include"./datasets/heuristicsArray.h"
#include"./datasets/weightArray.h"

int main()
{
	int G[V][V],H[V],i,j,k;
	int u[8], v[8];
	int n[8] = {7, 8, 10, 11, 9, 12, 6, 5};
	double taStar[8], tDijkstra[8], tbellmanFord[8], tfloydWarshall[8];
		
	for (int i = 0 ; i < 8; i++){

		for(int j = 0; j<n[i] ; j++){
			for (int k = 0; k<n[i]; k++){
				G[j][k] =  weights[i][j][k];
			}
		}
	
		srandom(time(NULL)); 
		u[i] = random()%n[i];
		v[i] = random()%n[i];

		for(k = 0; k<n[i] ; k++){
			H[k] =  heuristics[i][v[i]][k];	
		}
	/*for(int j = 0; j<n[i] ; j++){
			for (int k = 0; k<n[i]; k++){
				printf("%d  ", G[j][k]);
			}
			printf("\n");
		}*/

	/* printf("\n %d ", u[i] );
	 printf("\n %d ", v[i] );  */

	infAssign(G,n[i]);
	psuedoGraph(G,n[i]);
	tDijkstra[i] = dijkstra(G,n[i],u[i],v[i]);
	tbellmanFord[i] = bellmanFord(G,n[i],u[i],v[i]);
	tfloydWarshall[i] = floydWarshall(G,n[i],u[i],v[i]);
	taStar[i] = aStar(n[i],u[i],v[i],H);
	}
	
	printf(" \n ---------------------------------------------------------------------------\nThe Final Output Table\n");
	printf("\n\tNodes\tSrc\tDest\tAstar\t\tFloyd Warshall\tDijkstra\tBellman Ford");
	for(i = 0; i< 8; i++){
		printf("\n\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%lf\n",n[i],u[i],v[i],taStar[i],tfloydWarshall[i],tDijkstra[i],tbellmanFord[i]);
	}
	printf("\n----------------------------------------------------------------------------\n");		
	return 0;
}
