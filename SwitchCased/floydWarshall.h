void floydWarshall (int G[V][V],int n,int src,int dest) 
{
	int dist[V][V], i, j, k; 
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			dist[i][j] = G[i][j]; 

	for (k = 0; k < n; k++) 
	{ 
		for (i = 0; i < n; i++) 
		{ 
			for (j = 0; j < n; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	printf ("\nTotal Distance  = %d", dist[src][dest]); 
} 