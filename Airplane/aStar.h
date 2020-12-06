void aStar(int n,int src,int dest)
{
	VERTICE *curr = (VERTICE*)calloc(1,sizeof(VERTICE));
	curr = headers[src];
	VERTICE *temp = (VERTICE*)calloc(1,sizeof(VERTICE));
	int visited[n];
	int ch[n];
	double dlat = headers[dest]->latitude;
	double dlon = headers[dest]->longitude;

	for(int i = 0 ; i<n ; i++)
    {
        visited[i]=0;
		ch[i] = INF;
		double lat = headers[i]->latitude;
		double lon = headers[i]->longitude;
		headers[i]->heuristic = heuristicCalculator(dlat,dlon,lat,lon);
    }

    visited[curr->name] = 1;
	curr-> distance = 0;
	ch[curr->name] = curr->heuristic;
	int cname = curr->name;
	int cd ;
	
	while( (cname != dest) && curr != NULL )
	{	
		cd = curr->distance;
		for (int i = 0; i < curr->c; ++i)
		{
			temp = curr->links[i];
			if (visited[temp->name] == 0 )
			{
				if(ch[temp->name] > (temp->heuristic + curr->distance + curr->weights[i]))
				{
					ch[temp->name] = temp->heuristic + curr->distance + curr->weights[i];
					temp->distance = curr->distance + curr->weights[i];
					temp->previous = curr;
				}
			}
		}

		visited[cname] = 1;
		ch[cname] = INF;

		int min = INF;
		int index;
		for(int i = 0 ; i<n ; i++)
		{
			if(ch[i]<min){
				min = ch[i];
				index = i;
			}
		}	
		if (min == INF)
			curr = NULL;
		else{
			curr = headers[index];
			cname = curr->name;
		}
	}

	if(cname == dest){
		cd = curr->distance;
		temp = headers[dest];
		printf("\n Total Time = %d hrs and %d mins\n", cd/60,cd%60 );
		while(temp != NULL){
			cname = temp->name;
			printf("%s <-- " , location[cname]);
			temp = temp->previous;
		}
		printf("\n");
	}
}
