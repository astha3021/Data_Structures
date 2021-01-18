#include<stdio.h>
#define MAX 15

 int queue[MAX];
 void enqueue(int);
 int dequeue();
 void display();
 int front=-1;
 int rear=-1;

main()
{
int choice,num;

 while(1)
  {
  printf("enter your choice\n");
  printf("1.Add element\n");
  printf("2.delete\n");
  printf("3.display\n");
  printf("4.exit\n");
  scanf("%d",&choice);

  switch(choice)
  {
    case 1:
           printf("enter a no. to be inserted\n");
           scanf("%d",&num);
           enqueue(num);
           break;
    case 2:
            num=dequeue();
            break;
    case 3:
           display();
           break;
    case 4:
           exit(1);
           break;
    default:
            printf("invalid choice\n");
    }
  }
}
void enqueue(int element)
{
  if(rear==MAX-1)
  {
  printf("queue is full\n");
  return;
  }
  if(front==-1)
  {
    front=0;
  }
  queue[++rear]=element;
}
int dequeue()
{
 int element;
 if(front==-1||front==rear+1)
 {
 printf("queue is empty\n");
 return;
 }
 element=queue[front++];
 printf("%d has been deleted\n",element);
 return(element);
}
void display()
{
 if(front==-1||front==rear+1)
 {
 printf("queue is empty\n");
 return;
 }
 int i;
 for(i=front;i<=rear;i++)
 {
 printf("%d\n",queue[i]);
 }
}
