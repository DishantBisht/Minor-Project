double aStar(int n,int src,int dest, int Heu[])
{
	VERTICE *curr = (VERTICE*)calloc(1,sizeof(VERTICE));
	curr = headers[src];
	VERTICE *temp = (VERTICE*)calloc(1,sizeof(VERTICE));
	int visited[n];
	int ch[n];
	clock_t time_req; 


	for(int i = 0 ; i<n ; i++)
    {
        visited[i]=0;
		headers[i]->distance = INFINITY;
		ch[i] = INFINITY;
		headers[i]->heuristic = Heu[i];
    }

    visited[curr->name] = 1;
	curr-> distance = 0;
	ch[curr->name] = curr->heuristic;
	int cname = curr->name;
	int cd ;
	
	
	time_req = clock();
	
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
		ch[cname] = INFINITY;

		int min = 0;
		for(int i = 0 ; i<n ; i++)
		{
			if(ch[i]<ch[min])
				min = i;
		}	
		if (ch[min] == INFINITY)
			curr = NULL;
		else{
			curr = headers[min];
			cname = curr->name;
		}
	}
	
	
	time_req = clock() - time_req ;
	
	
	return ((double)time_req/CLOCKS_PER_SEC);
	/* if(cname = dest){
		cd = curr->distance;
		temp = headers[dest];
		printf("\n Total Distance = %d \n", cd );
		while(temp != NULL){
			cname = temp->name;
			printf("%d<-" , cname);
			temp = temp->previous;
		}
	} */
}
