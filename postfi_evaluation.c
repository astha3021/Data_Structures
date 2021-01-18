#include <stdio.h>
#include <ctype.h>
#define SIZE 50 /* Size of Stack */

int stack[SIZE];
int top=-1; /* top of stack is empty initially */
int flag=0;
int pop()
{     int element;                 /* POP operation */
  element=stack[top--];
  return(element);
}

int push(int item)
{ /* PUSH operation */
  if(flag==1){
    int num;
    num=pop();
    stack[++top]=item + (10*num);
  }
  else if(flag==0){
    stack[++top]=item;
    flag=1;
  }
}


int main()
{
  char postfix[50],ch;
  int i=0,op1,op2;
  printf("Enter the Postfix Expression:");
  fgets(postfix,100,stdin);
  while( (ch=postfix[i++]) != '\n')
  {
    if(isdigit(ch)) push(ch-'0'); /* Push the operand */
    else if(ch==' ')  /* set flag to zero if space between characters*/
      flag=0;
    else
    {        /* if Operator,pop two  operands */
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push(op1+op2);
                 break;
        case '-':push(op1-op2);
                 break;
        case '*':push(op1*op2);
                 break;
        case '/':push(op1/op2);
                  break;
        default:
                 printf("invalid input\n");
                 return 0;
      }
    }
  }
  printf("Result: %d\n",s[top]);
}
