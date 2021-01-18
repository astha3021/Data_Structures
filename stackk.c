#include<stdio.h>
#include<conio.h>
#define MAX 15

  int stack[MAX];
  int top= -1; // initially no element is at the top
  void push(int);
  int pop();
  void display();

main()
{ int choice,item;
while(1)
{
  printf("enter your choice\n");
  printf("1.push\n");
  printf("2.pop\n");
  printf("3.display\n");
  printf("4.exit\n");
  scanf("%d",&choice);
 switch(choice)
 {
  case 1:
          printf("enter a no. to be inserted:");
          scanf("%d",&item);
          push(item);
          break;
  case 2:
          item=pop();
          break;
  case 3:
          display();
          break;
  case 4: exit(1);
          break;
  default:
          printf("invalid choice");
 }
 }
 }
void push(int element)
{
  if(top==MAX-1)
  {
  printf("stack overflow\n");
  return;
  }
  stack[++top]=element;// incrementing the top and adding element on to the top
 }
int pop(element)
{
 if(top==-1)
 {
 printf("stack underflow\n");
 return;
 }
 element=stack[top--]; // deleting element from top and decrementing top value
 printf("%d has been deleted\n",element);
 return(element);
}
void display()
{ int i;
  if(top==-1)
 {
  printf("stack is empty\n");
  return;
 }
 printf("\n\n");
 for(i=top;i>=0;i--)
 printf("%d\n",stack[i]);
}

