typedef struct Vertice VERTICE;

struct Vertice
{
	double longitude;
	double latitude;
	double heuristic;
	int distance;
	int name;
	int c;
	VERTICE *previous;
	VERTICE *links[V];
	int weights[V];	
};

VERTICE *headers[V];

