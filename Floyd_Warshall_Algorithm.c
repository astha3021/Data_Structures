#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_VERTEX 400
int min(int a, int b)
{
    return (a < b ? a:b);
}

void printMatrix(int matrix[MAX_VERTEX][MAX_VERTEX], int v)
{
	int i,j;

	for(i=1; i<=v; i++)
	{
		for(j=1; j<=v; j++)
			printf("%d\t",matrix[i][j]);

		printf("\n");
	}

	printf("\n");
}
int main() {

   	int v,e;
   	printf("Enter number of vertex and edges:");
	scanf("%d%d", &v,&e);

	int i, j;
	int matrix[MAX_VERTEX][MAX_VERTEX];

	for(i=1; i<=v; i++)
	{
		for(j=1; j<=v; j++)
		{

			matrix[i][j] = 9999;
		}
	}
	printMatrix(matrix, v);

	for(i=0; i<e; i++)
	{
		int src, dst, weight;
		printf("enter source , dest and corres costs");
		scanf("%d%d%d", &src, &dst, &weight);
		matrix[src][dst] = weight;
	}


	for(i=1; i<=v; i++)
	{
		matrix[i][i] = 0;
	}
	int k;

	printMatrix(matrix, v);
	for(k=1; k<=v; k++)
	{
		for(i=1; i<=v; i++)
		{
			for(j=1; j<=v; j++)
			{

				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

			}
		}
		               printf("Iteration:%d\n",k);
		               printMatrix(matrix,v);
	}

	printf("Shortest distance between every pair of vertices is:\n");
	printMatrix(matrix, v);
	return 0;
}
