#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define INF 999
#define V 100
#include"math.h"
#include"datasets.h"
#include"structure.h"
#include"psuedoGraph.h"
#include"infAssign.h"
#include"degAndRad.h"
#include"heuristicCalculator.h"
#include"aStar.h"

int main()
{
	int i,j,u,v;
	int n=10;
	
	label:
	printf("\nThe locations Available!\n");
	for(i=0;i<10;i++)
		printf("%d. %s\n", i+1, location[i]);
	
	printf("\nSelect the starting point: ");
	scanf("%d",&u);
	u=u-1;
	printf("\nEnter the destination: ");
	scanf("%d",&v);
	v=v-1;
	if(u<0||u>9||v<0||v>9){
		printf("\nWrong Input! \n");
		goto label;
	}
	else if(u==v)
	{
		printf("\nStarting Point And Destination are same.\n");
		goto label;
	}
	infAssign(G,n);
	psuedoGraph(G,n);
	aStar(n,u,v);

}