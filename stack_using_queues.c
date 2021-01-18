#include<stdio.h>
#include<stdlib.h>

struct node // creating structure
{
    int data; // data to be inserted
    struct node * next; // next pointer
};

struct queue // creating a structure queue
{
    struct node *rear; // rear pointer
    struct node *front; // front pointer
};

void initial(struct queue *);
void queueAdd(struct queue *,int);
int queueDel(struct queue *);
void display(struct queue *);
void push(int);
void pop();

struct queue q1,q2; // two  queues q1 and q2
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
              pop();
              break;
        case 3:
               display(&q1);
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

void initial(struct queue *q)
{
    q->front=NULL; // initial value of front of queue
    q->rear=NULL; // initial value of rear of queue
}

void queueAdd(struct queue *q,int n)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node)); //creating a temporary node pointer

    temp->data=n;
    temp->next=NULL;

    if(NULL==q->front)
    {
        q->rear=temp;
        q->front=temp;
        return;
    }

    q->rear->next=temp;
    q->rear=temp;
}

int queueDel(struct queue *q)
{
    struct node *temp;
    int item;
    if(q->front==NULL)
    {
        printf("\nqueue is empty");
        return NULL;
    }

    temp=q->front;
    item=temp->data;
    q->front=temp->next;
    free(temp);
    return item;

}

void display(struct queue *q)
{
    struct node *temp;
    temp=q->front;
    while((temp)!=NULL)
    {
        printf("\n%d",(temp->data));
        temp=temp->next;
    }
    printf("\n");
}


void push(int val)
{
    struct queue temp;
    int j;
    queueAdd(&q2,val);

    while(((&q1)->front)!=NULL)
    {
        j=queueDel(&q1);
        queueAdd(&q2,j);
    }


    temp=q1;  //swap q1 and q2
    q1=q2;
    q2=temp;

    printf("\nelements after pushing are:\n");
    display(&q1);

}

void pop()
{
    printf("\n element deleted is %d",queueDel(&q1));
}
