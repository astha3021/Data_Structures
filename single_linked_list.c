#include<stdio.h>
#include<stdlib.h>

typedef struct node {
int data;
struct node *next;
}node;
node *head, *last = NULL;

void create_linked_list()
{
   int data;
   struct node *newNode= (node*)malloc(sizeof(node));
    printf("enter data : ");
    scanf("%d",&newNode->data);
    newNode->next =NULL;

    if(head == NULL) {
        //If list is empty, both head and end will point to new node
        head = newNode;
        last = newNode;
    }
     else {
        //newNode will be added after last such that last's node next will point to newNode
        last->next = newNode;
        //newNode will become new last of the list
        last = newNode;
    }
}
void insert_at_first(int value){

struct node *temp=(node*)malloc(sizeof(node));
temp->data = value;
temp->next=head;
head=temp;

}
void insert_after(int key, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    node *temp = head;
    while((temp->data)!=key){
        temp = temp->next;
    }
    newNode->data=value;
    newNode->next = temp->next;
    temp->next=newNode;
    printf("%d is inserted after %d\n", value, key);
}
void insert_at_last(int value)
{
    struct node *temp =head;
    node *newNode = (node *)malloc(sizeof(node));
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->data=value;
    newNode->next=NULL;

}
void search_item(int value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->data==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}
void delete_item(int value)
{
    node *temp = head, *previous=NULL;
    int flag = 0;

    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            if(previous==NULL)
                head = temp->next;
            else
                previous->next = temp->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(temp); //need to free up the memory to prevent memory leak
            break;
        }

        previous = temp;
        temp = temp->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}

void reverse(){
struct node *current =head;
struct node *prev , *nextNode= NULL;
while(current){
nextNode = current->next;
current->next = prev;
prev = current;
current = nextNode;
}
head = prev;
}
void display(){
 struct node *current = head;
  if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list: \n");
    while(current != NULL) {
        //Prints each node by incrementing pointer
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

}
int main()
{
  int choice,value,key;
  create_linked_list();
  display();
  while(1){

   printf("enter your choice\n");
   printf("1.add item at first:\n");
   printf("2.add item after some key element :\n");
   printf("3.add item at the end:\n");
   printf("4.search an item\n");
   printf("5.delete an item\n");
   printf("6.reverse linked list\n");
   printf("7.exit\n");
   scanf("%d",&choice);
   switch(choice){
   case 1:
          printf("enter a no. to be inserted:");
          scanf("%d",&value);
          insert_at_first(value);
          display();
          break;
  case 2:
          printf("\nEnter a KEY (existing item of List), after that you want to insert a value\n");
          scanf("%d", &key);
          printf("\nInsert new item after %d KEY\n", key);
          scanf("%d", &value);
          insert_after(key, value);
          display();
          break;
  case 3:
          printf("\nInsert new item at last\n");
          scanf("%d", &value);
          insert_at_last(value);
          display();
          break;
  case 4: printf("\nEnter an item to search it from List\n");
          scanf("%d", &value);
          search_item(value);
          display();
          break;
  case 5: printf("\nEnter a value, which you want to delete from list\n");
          scanf("%d", &value);
          delete_item(value);
          display();
          break;
  case 6:
          reverse();
          display();
          break;
  case 7: exit(1);
          break;
  default:
          printf("invalid choice");

   }
  }
}
