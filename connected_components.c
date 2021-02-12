#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

int main(int argc, char *argv[]) {

 FILE *fp = fopen(argv[1],"r");
 printf("Filename : %s\n", argv[1]);
 while  (!feof(fp)){
 int V = fgetc(fp) - 48;
 printf("\nnumber of vertex is %d\n",V);
 int E = fgetc(fp) - 48;
 printf("\nnumber of edges is %d\n",E);
  struct Graph* graph = createGraph(V+1);
  int i;
  for(i=0;i<E;i++)
  {
       int u = fgetc(fp)-48;
         int v = fgetc(fp)-48;
         
         printf("\nEdge in the file is %d->%d\n",u,v);
       addEdge(graph, u, v);
       addEdge(graph, v, u);
  }
  int j;
  int noOfConnectedComponents = 0;
  for(j=1;j<=V;j++)
  {
      if(graph->visited[j]!=1)
      {
          DFS(graph,j);
          noOfConnectedComponents++;
      }
  }
 printf("\nThe number of Connected component is");
 printf("%d",noOfConnectedComponents);

  return 0;
 }
}
