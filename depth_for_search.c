#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define MAX 10
int stack[MAX],top =-1;
struct Vertex* lstVertices[MAX];

int adjMatrix[MAX][MAX];
int vertexCount = 0;

struct Vertex {
   char label;
   bool visited;
};
void push(int item) {
   stack[++top] = item;
}

int pop() {
   return stack[top--];
}

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
    printf("\nvisited->");
   printf("%c ",lstVertices[vertexIndex]->label);


}
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;

      }
   }

   return -1;
}

void depthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   displayVertex(0);
   //push into stack
   push(0);

   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //stack is empty, search is complete, reset the visited flag
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
}

int main() {
   int i, j;

   for(i = 0; i < MAX; i++)    {
      for(j = 0; j < MAX; j++)
         adjMatrix[i][j] = 0;
   }

   addVertex('S');
   addVertex('A');
   addVertex('B');
   addVertex('C');
   addVertex('D');
   addVertex('E');

   addEdge(0, 1);
   addEdge(0, 3);
   addEdge(1, 2);
   addEdge(1, 4);
   addEdge(4, 5);


   printf("Depth First Search: ");
   depthFirstSearch();

   return 0;
}
