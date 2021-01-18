#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct node {

    int data;
    struct node *left;
    struct node *right;

};
struct Stack
{
    int size;
    int top;
    struct node* *array;
};
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node**) malloc(stack->size * sizeof(struct node*));
    return stack;
}

int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }

int isEmpty(struct Stack* stack)
{  return stack->top == -1; }

void push(struct Stack* stack, struct node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

struct node* insert( struct node* root, int data ) {

	if(root == NULL) {

        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

	} else {
      struct node* cur;

		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}

		return root;
	}
}
void postOrder( struct node *root) {

    if (root == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    do
    {

        while (root)
        {

            if (root->right)
                push(stack, root->right);
            push(stack, root);


            root = root->left;
        }


        root = pop(stack);


        if (root->right && peek(stack) == root->right)
        {
            pop(stack);
            push(stack, root);
            root = root->right;

        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}
void preOrder(struct node *root) {

    struct node *p=root;

    if(p!=NULL)
    {
        printf("%d ",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }

}
void inOrder(struct node *root) {

if (root)
    {
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    }
}
int main() {

    struct node* root = NULL;

    int t;
    int data;
    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
    return 0;
}
