#include<stdio.h>
#define max 25
int postIndex ;
int stack[max];
int top =-1;

void pushIntoStack(int element) // push element into first stack
{
   stack[++top]=element;

}

int popFromStack(element)  //pop element from first stack
{
   element=stack[top--];
   return(element);
}

// A utility function to search data in in[]
int search(int inorder[], int data,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		if (inorder[i] == data)
			return i;
	return i;
}

// Fills preorder traversal of tree with given
// inorder and postorder traversals in a stack
void fillPre(int inorder[], int post[], int inStrt,
			int inEnd,int n,int stack[])
{
	if (inStrt > inEnd)
		return;

	// Find index of next item in postorder traversal in
	// inorder.
	int val = post[postIndex];
	int inIndex = search(inorder, val, n);
	postIndex--;

	// traverse right tree
	fillPre(inorder, post, inIndex + 1, inEnd, n,stack);

	// traverse left tree
	fillPre(inorder, post, inStrt, inIndex - 1,n,stack);

    pushIntoStack(val);
	//s.push(val);
}

// This function basically initializes postIndex
// as last element index, then fills stack with
// reverse preorder traversal using printPre
void printPreMain(int inorder[], int post[],int n)
{
	int len = n;
	postIndex = len - 1;
	int i;
	//stack<int> s ;
	fillPre(inorder, post, 0, len - 1, n,stack);
	if(top==-1)
 {
  printf("stack is empty\n");
  return;
 }
 printf("\n\n");
 for(i=top;i>=0;i--)
 printf("%d\n",stack[i]);
}

// Driver code
int main()
{
	int inorder[50],post[50],i,n ;
	scanf("%d",&n);

	for(i=0;i<n;i++){
	    scanf("%d",&inorder[i]);
	}
	for(i=0;i<n;i++){
	    scanf("%d",&post[i]);
	}
	printPreMain(inorder, post,n);
}

