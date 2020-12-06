double floydWarshall (int G[V][V],int n,int src,int dest) 
{
	int dist[V][V], i, j, k; 
	clock_t time_req; 
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			dist[i][j] = G[i][j]; 
	

    time_req = clock();
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
	
	time_req = clock() - time_req;
	
	return (double)time_req/CLOCKS_PER_SEC;

	// printf ("\n Floyd Warshals \n Total Distance  = %d \n", dist[src][dest]); 
} 
