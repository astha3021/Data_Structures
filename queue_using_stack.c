#include<stdio.h>
#include<stdlib.h>
#define max 25

int stack1[max],stack2[max];
int top1 =-1,top2=-1;
int count =0;

void pushIntoStack1(int element) // push element into first stack
{
   stack1[++top1]=element;

}
void pushIntoStack2(int element) // push element into second stack
{
   stack2[++top2]=element;

}
int popFromStack1(element)  //pop element from first stack
{
   element=stack1[top1--];
   return(element);
}
int popFromStack2(element)  //pop element from second stack
{
   element=stack2[top2--];
   return(element);
}
void enqueue() // add element into queue
{
    int element, i;

    printf("Enter data into queue");
    scanf("%d", &element);
    pushIntoStack1(element);
    count++;
}

int dequeue()
{
    int i;

    for (i = 0;i <= count;i++)
    {
        pushIntoStack2(popFromStack1());
    }
    popFromStack2();
    count--;
    for (i = 0;i <= count;i++)
    {
        pushIntoStack1(popFromStack2());
    }
}

/*Function to display the elements in the stack*/

void display()
{
    int i;

    for (i = 0;i <= top1;i++)
    {
        printf(" %d ", stack1[i]);
    }
}
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
      case 1:enqueue(item);
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

