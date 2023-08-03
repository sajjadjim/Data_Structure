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

    return 0;
}

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
}
