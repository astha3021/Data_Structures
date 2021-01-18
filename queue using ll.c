#include<stdio.h>
struct node
{
 int data;
 struct node *next;
};
struct node *front=NULL; // front pointer will contain address of head node and initially queue is empty
struct node *rear=NULL;  // rear pointer will contain address of last node and initially queue is empty

void enqueue(int);
int dequeue();
void display();

main()
{ int choice,item;
 while(1)
     { printf("enter your choice\n");
       printf("1.Add element\n");
       printf("2.delete\n");
       printf("3.display\n");
       printf("4.exit\n");
       scanf("%d",&choice);

     switch(choice)
     {
      case 1:printf("enter no. to be inserted\n");
             scanf("%d",&item);
             enqueue(item);
             break;
      case 2:item=dequeue();
             break;
      case 3:display();
             break;
      case 4:exit(1);
      break;
    default:printf("wrong choice\n");
    }
     }
}
void enqueue(int element)
{
struct node*newNode;
newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=element;
newNode->next=NULL;
if(NULL == front && NULL == rear)
  front=rear=newNode;
  else
  {
   rear->next=newNode; //insertion is from rear
   rear=newNode;
  }
}
int dequeue()
{
 if(NULL == front)
  printf("\nqueue is empty");
  else
  {
   struct node*temp=front;
   front=front->next;
   printf("%d has been deleted\n",temp->data);
   free(temp);
  }
}
void display()
{
 if(NULL == front && NULL == rear)
 printf("\nqueue is empty");
 else
 {
  struct node*temp=front;
  while(temp!=NULL)
  {
   printf("%d-->\n",temp->data);
   temp=temp->next;
  }
 }

}


