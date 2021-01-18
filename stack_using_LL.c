#include<stdio.h>
#include<conio.h>
 void push(int);
 int pop();
 void display();

struct Node
{
  int data;  // data to be inserted
  struct Node* next; // next pointer
};
struct Node* top=NULL;

 void push(int element)
 {
 struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); // creating a temporary node pointer
 if(temp==NULL)
 {
     printf("stack overflow\n");
     return;
 }
 temp->data=element;
 temp->next=top;
 top=temp;
 }
int pop()
{
 struct Node *temp;
 int element;
 if(top==NULL)
 {
 printf("stack underflow\n");
 exit(1);
 }
 element=top->data;
 temp=top;
 top=top->next;
 free(temp);
 printf("%d has been deleted ", element);
 return(element);
 }
 void display()
 {
     struct Node *ptr;
     if(top==NULL)
     {
         printf("stack is empty");
         return;
     }
  ptr=top;
  printf("the items in the list are:\n");
  while(ptr!=NULL)
  {
      printf("%d\n",ptr->data);
      ptr=ptr->next;
  }
 }
main()
{
    int choice,item;
    while(1)
    {
        printf("enter your choice\n");
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
             printf("enter the no. to be inserted\n");
             scanf("%d",&item);
             push(item);
             break;
        case 2:
              item=pop();
              break;
        case 3:
               display();
               break;
        case 4:
            exit(0);
            break;
        default :
            printf("invalid choice");
            break;
        }

        }
    }

