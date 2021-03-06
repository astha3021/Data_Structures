#include<stdio.h>
#define MAX 100

int n,max;
int adj[MAX][MAX],visited[MAX];
int queue[MAX], front = -1,rear = -1;

void create_graph(){
int count,origin,destin;

   printf("Enter number of vertices : ");
   scanf("%d",&n);

   printf("Enter number of edges : ");
   scanf("%d",&max);

   for(count=1; count<=max; count++)
   {
      printf("Enter edge %d : ",count);
      scanf("%d %d",&origin,&destin);

      if((origin == -1) && (destin == -1))
         break;

      if(origin>=n || destin>=n || origin<0 || destin<0)
      {
         printf("Invalid edge!\n");
         count--;
      }
      else
      {
         adj[origin][destin] = 1;   //adjacency matrix
         adj[destin][origin] = 1;
      }
  }
}
void enqueue(int vertex)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = vertex ;
   }
}

int isEmpty_queue()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}

int dequeue()
{
   int delete_item;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }

   delete_item = queue[front];
   front = front+1;
   return delete_item;
}

void BFS()
{
    int v;

   for(v=0; v<n; v++)
      visited[v] = 0;

   printf("Enter Start Vertex for BFS: \n");
   scanf("%d", &v);


   int i;

   enqueue(v);

   while(!isEmpty_queue())
   {

      v = dequeue( );
       if(visited[v])              //if it has already been visited by some other neighbouring vertex, it should not be printed again.
           continue;

      printf("%d ",v);
      visited[v] = 1;

      for(i=0; i<n; i++)
      {
         if(adj[v][i] == 1 && visited[i] == 0)
         {
            enqueue(i);
         }
      }
   }
   printf("\n");
}
int main()
{
   create_graph();
   BFS();
   return 0;
}

