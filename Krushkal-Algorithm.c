#include<stdio.h>
#include<stdlib.h>

struct Edge{
	int source;
	int destination;
	int weight;
};
int parent[10001];
int Find(int i){
	if(parent[i]==-1)
		return i;
	return parent[i] = Find(parent[i]);
}

void merge(int a , int b){

  parent[a] = b;
}


int cmpfunc( const void* a, const void* b)
{
	int x = ((struct Edge*)a)->weight;
	int y = ((struct Edge*)b)->weight;

	return x - y;
}
int kruskal(struct Edge edges[],int m)
{
    int i , a , b , sum = 0;
    for(i=0;i<m;i++){

		a = Find(edges[i].source);
		b = Find(edges[i].destination);

		if(a != b)
        {
            sum+=edges[i].weight;
            merge(a,b);
        }
	}
	return sum;

}
int main(){
	int n,e,weight,i,sum=0;
	printf("enter number of vertices and edges");
	scanf("%d%d",&n,&e);
    struct Edge edges[e+1];
	for(i=1;i<=n;i++)
    {
        parent[i] = -1;
    }

    printf("Enter source vertex destination vertex and weight of edge");
	for(i=0;i<e;i++)
    {
		scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
	}

    qsort(edges, e+1, sizeof(struct Edge), cmpfunc);

	printf("minimum weight is :%d\n",kruskal(edges,e));
	return 0;
}
