#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head;
void createnode(int n);
void display();
void insert_beg();
void insert_end();
void delete_first();
void delete_middle();
void delete_last();

void createnode(int n)
{
    node *newnode, *temp;
    int i;
    head= (node*)malloc(sizeof(node));
    head->next=NULL;
    printf("\n Enter data for Node 1: ");
    scanf("%d", &head->data);
    temp=head;
    for(i=2;i<=n;i++)
    {
      newnode=  (node*)malloc(sizeof(node));
      printf("\n Enter data for Node %d: ",i);
      scanf("%d", &newnode->data);
      newnode->next=NULL;
      temp->next=newnode;
      temp=temp->next;
    }
}

void insert_beg()
{
    node *newnode;

    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter data for beginning node: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert_end()
{
    node *temp,*newnode;
    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter data for last node: ");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
     newnode->next=NULL;
}
void display()
{
    node *temp;
    temp=head;
    printf("\n You have Successfully created the following linkedlist: \n");
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }

 // Delete LinkList Node
 void delete_first()
{
    node *temp;
    temp=head;
    head=temp->next;
    free(temp);
}

void delete_middle()
{
    int pos,i;
    node *current, *temp, *prev;
    printf("\nEnter the position of the node you want to delete  : ");
    scanf("%d",&pos);
    temp=head;
    for(i=1;i<pos;i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    free(current);
}
void delete_last()
{
node *temp, *prev;
temp=head;
while(temp->next!=NULL)
{
    prev=temp;
    temp=temp->next;
}
prev->next=NULL;
free(temp);
}


    int main()
{
    int n;
    printf("\n Enter total number of node: ");
    scanf("%d",&n);
    createnode(n);
    display();
    printf("\n Inserting new node at beginning...\n");
    insert_beg();
     display();
     printf("\n Inserting new node at the end...\n");
    insert_end();
     display();

  // Delete Node First
  delete_first();
  display();

  //Delete Middle /Any Node
  delete_middle();
  display();

  //Delete Last Node
  delete_last();
  display();

    return 0;
}
}
